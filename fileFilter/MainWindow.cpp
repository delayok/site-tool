#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDateTime>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QTextStream>
#include <QDebug>
#include <QStandardPaths>
#include <QThread>
#include <QCoreApplication>
#include <QProgressDialog>
#include <QRegExp>
#include <QProcess>

// FileProcessWorker 实现
FileProcessWorker::FileProcessWorker(QObject *parent)
    : QObject(parent)
    , m_stopRequested(false)
{
}

void FileProcessWorker::processFiles(const QString &sourcePath, 
                                   const QString &targetPath,
                                   bool useFileNameRule)
{
    m_stopRequested = false;
    
    emit statusMessage("正在扫描源文件夹...");
    emit logMessage(QString("源文件夹: %1").arg(sourcePath));
    emit logMessage(QString("目标文件夹: %1").arg(targetPath));
    
    // 检查源文件夹是否存在
    QDir sourceDir(sourcePath);
    if (!sourceDir.exists()) {
        emit errorOccurred(QString("源文件夹不存在: %1").arg(sourcePath));
        return;
    }
    
    // 检查目标文件夹是否存在，不存在则创建
    QDir targetDir(targetPath);
    if (!targetDir.exists()) {
        if (!targetDir.mkpath(".")) {
            emit errorOccurred(QString("无法创建目标文件夹: %1").arg(targetPath));
            return;
        }
        emit logMessage(QString("已创建目标文件夹: %1").arg(targetPath));
    }
    
    // 获取所有文件
    QStringList filters;
    filters << "*.*";
    
    QStringList files = sourceDir.entryList(filters, QDir::Files | QDir::NoDotAndDotDot);
    int totalFiles = files.count();
    
    if (totalFiles == 0) {
        emit statusMessage("源文件夹中没有文件");
        emit logMessage("源文件夹中没有文件");
        emit finished();
        return;
    }
    
    emit statusMessage(QString("找到 %1 个文件，开始处理...").arg(totalFiles));
    
    int processedFiles = 0;
    int copiedFiles = 0;
    int skippedFiles = 0;
    
    // 用于记录已创建的文件夹
    QSet<QString> createdFolders;
    foreach (const QString &fileName, files) {
        if (m_stopRequested) {
            emit logMessage("处理被用户中断");
            break;
        }
        
        QFileInfo fileInfo(sourceDir.absoluteFilePath(fileName));
        
        // 根据选择的规则构建分类路径
        QStringList pathComponents;

        // 2. 按文件名分类（根据您的需求，这是主要功能）
        if (useFileNameRule) {
            QString fileNameBase = getFilenameCode(fileName);
            if (!fileNameBase.isEmpty()) {
                pathComponents << fileNameBase;
            }
        }
        
        // 如果没有选择任何规则，则直接复制到目标文件夹
        QString targetFilePath;
        if (pathComponents.isEmpty()) {
            targetFilePath = targetDir.absoluteFilePath(fileName);
        } else {
            // 构建完整的分类路径
            QString categoryPath = targetDir.absolutePath();
            foreach (const QString &component, pathComponents) {
                categoryPath = QDir(categoryPath).absoluteFilePath(component);
            }
            
            // 确保目标文件夹存在
            if (!createdFolders.contains(categoryPath)) {
                QDir categoryDir(categoryPath);
                if (!categoryDir.exists()) {
                    if (!categoryDir.mkpath(".")) {
                        emit logMessage(QString("无法创建文件夹: %1").arg(categoryPath));
                        skippedFiles++;
                        processedFiles++;
                        int progress = (processedFiles * 100) / totalFiles;
                        emit progressChanged(progress);
                        continue;
                    }
                    emit logMessage(QString("已创建文件夹: %1").arg(categoryPath));
                    createdFolders.insert(categoryPath);
                }
            }
            
            // 构建目标文件路径
            targetFilePath = QDir(categoryPath).absoluteFilePath(fileName);
        }
        
        // 检查文件是否已存在
        if (QFile::exists(targetFilePath)) {
            emit logMessage(QString("跳过已存在文件: %1").arg(fileName));
            skippedFiles++;
            processedFiles++;
            int progress = (processedFiles * 100) / totalFiles;
            emit progressChanged(progress);
            continue;
        }
        
        // 复制文件
        if (QFile::copy(fileInfo.absoluteFilePath(), targetFilePath)) {
            // 清除Zone.Identifier，防止Win7安全警告
            QString targetNative = QDir::toNativeSeparators(targetFilePath);
            QProcess::execute("powershell", 
                QStringList() << "-Command" 
                << QString("Remove-Item -Path '%1' -Stream 'Zone.Identifier' -ErrorAction SilentlyContinue").arg(targetNative));
            
            QString logMsg = QString("成功复制: %1").arg(fileName);
            if (!pathComponents.isEmpty()) {
                logMsg += QString(" -> %1").arg(pathComponents.join("/"));
            }
            emit logMessage(logMsg);
            copiedFiles++;
        } else {
            emit logMessage(QString("复制失败: %1").arg(fileName));
            skippedFiles++;
        }
        
        processedFiles++;
        int progress = (processedFiles * 100) / totalFiles;
        emit progressChanged(progress);
        
        // 处理事件循环，避免界面卡顿
        QCoreApplication::processEvents();
    }
    


    //修改文件名
    for (auto filedir : createdFolders)
    {
        QDir tdir(filedir);
        QStringList files = tdir.entryList(filters, QDir::Files | QDir::NoDotAndDotDot);
        QString shortest;

        QString parentDir = QFileInfo(filedir).absolutePath();
         for (const QString &f : files)
         {
             if (shortest.isEmpty() || f.length() < shortest.length())
             {
                 shortest = f;
             }
         }
         shortest = QFileInfo(shortest).completeBaseName();
         QString newfiledir = QDir(parentDir).filePath(shortest);
         tdir.rename(filedir,newfiledir);
    }


    emit statusMessage(QString("处理完成! 已复制: %1, 跳过: %2, 总数: %3")
                      .arg(copiedFiles).arg(skippedFiles).arg(totalFiles));
    emit logMessage(QString("=== 处理统计 ==="));
    emit logMessage(QString("总文件数: %1").arg(totalFiles));
    emit logMessage(QString("成功复制: %1").arg(copiedFiles));
    emit logMessage(QString("跳过文件: %1").arg(skippedFiles));
    
    emit finished();
}

QString FileProcessWorker::getFilenameCode(const QString &filename)
{
    QString code= "";
    QString beginChar = "Q";
    int len = 13;
    int index = filename.indexOf(beginChar);
    code = filename.mid(index,len);
    return code;
}

// MainWindow 实现
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_workerThread(nullptr)
    , m_worker(nullptr)
    , m_processing(false)
{
    ui->setupUi(this);
   // setupConnections();
    
}

MainWindow::~MainWindow()
{
    if (m_workerThread) {
        m_workerThread->quit();
        m_workerThread->wait();
        delete m_workerThread;
    }
    delete ui;
}



void MainWindow::setupConnections()
{
    // UI按钮连接
    connect(ui->pushButtonBrowseSource, &QPushButton::clicked,
            this, &MainWindow::on_pushButtonBrowseSource_clicked);
    connect(ui->pushButtonBrowseTarget, &QPushButton::clicked,
            this, &MainWindow::on_pushButtonBrowseTarget_clicked);
    connect(ui->pushButtonStart, &QPushButton::clicked,
            this, &MainWindow::on_pushButtonStart_clicked);
    connect(ui->pushButtonStop, &QPushButton::clicked,
            this, &MainWindow::on_pushButtonStop_clicked);
    connect(ui->pushButtonClearLog, &QPushButton::clicked,
            this, &MainWindow::on_pushButtonClearLog_clicked);
    connect(ui->pushButtonExit, &QPushButton::clicked,
            this, &MainWindow::on_pushButtonExit_clicked);
    
    // 菜单动作连接
    connect(ui->actionExit, &QAction::triggered,
            this, &MainWindow::on_actionExit_triggered);
    connect(ui->actionAbout, &QAction::triggered,
            this, &MainWindow::on_actionAbout_triggered);
}

void MainWindow::addLog(const QString &message)
{
    QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");
    ui->textEditLog->append(QString("[%1] %2").arg(timestamp).arg(message));
}

void MainWindow::updateUIForProcessing(bool processing)
{
    m_processing = processing;
    
    ui->pushButtonStart->setEnabled(!processing);
    ui->pushButtonStop->setEnabled(processing);
    ui->pushButtonBrowseSource->setEnabled(!processing);
    ui->pushButtonBrowseTarget->setEnabled(!processing);
    ui->checkBoxFileNameRule->setEnabled(!processing);
    
    if (!processing) {
        ui->progressBar->setValue(0);
    }
}

// 槽函数实现
void MainWindow::on_pushButtonBrowseSource_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "选择源文件夹",
                                                    QDir::homePath(),
                                                    QFileDialog::ShowDirsOnly);
    if (!dir.isEmpty()) {
        ui->lineEditSourcePath->setText(dir);
        addLog(QString("选择源文件夹: %1").arg(dir));
    }
}

void MainWindow::on_pushButtonBrowseTarget_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, "选择目标文件夹",
                                                    QDir::homePath(),
                                                    QFileDialog::ShowDirsOnly);
    if (!dir.isEmpty()) {
        ui->lineEditTargetPath->setText(dir);
        addLog(QString("选择目标文件夹: %1").arg(dir));
    }
}

void MainWindow::on_pushButtonStart_clicked()
{
    QString sourcePath = ui->lineEditSourcePath->text().trimmed();
    QString targetPath = ui->lineEditTargetPath->text().trimmed();
    bool useFileNameRule = ui->checkBoxFileNameRule->isChecked();
    
    // 验证输入
    if (sourcePath.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择源文件夹");
        return;
    }
    
    if (targetPath.isEmpty()) {
        QMessageBox::warning(this, "警告", "请选择目标文件夹");
        return;
    }
    
    if (!useFileNameRule) {
        QMessageBox::warning(this, "警告", "请启用文件名分类规则");
        return;
    }
    
    addLog("=== 开始文件分类拷贝 ===");
    addLog(QString("源文件夹: %1").arg(sourcePath));
    addLog(QString("目标文件夹: %1").arg(targetPath));
    addLog(QString("按文件名分类: %1").arg(useFileNameRule ? "启用" : "禁用"));
    
    // 创建并启动工作线程
    updateUIForProcessing(true);
    
    m_workerThread = new QThread();
    m_worker = new FileProcessWorker();
    
    m_worker->moveToThread(m_workerThread);
    
    // 连接工作线程信号
    connect(m_worker, &FileProcessWorker::progressChanged,
            this, &MainWindow::onWorkerProgressChanged);
    connect(m_worker, &FileProcessWorker::statusMessage,
            this, &MainWindow::onWorkerStatusMessage);
    connect(m_worker, &FileProcessWorker::logMessage,
            this, &MainWindow::onWorkerLogMessage);
    connect(m_worker, &FileProcessWorker::finished,
            this, &MainWindow::onWorkerFinished);
    connect(m_worker, &FileProcessWorker::errorOccurred,
            this, &MainWindow::onWorkerError);
    
    // 连接线程清理
    connect(m_workerThread, &QThread::started, [=]() {
        m_worker->processFiles(sourcePath, targetPath, useFileNameRule);
    });
    
    connect(m_worker, &FileProcessWorker::finished, m_workerThread, &QThread::quit);
    connect(m_worker, &FileProcessWorker::finished, m_worker, &QObject::deleteLater);
    connect(m_workerThread, &QThread::finished, m_workerThread, &QObject::deleteLater);
    
    m_workerThread->start();
}

void MainWindow::on_pushButtonStop_clicked()
{
    if (m_worker) {
        // 发送停止信号给工作线程
        // 注意：这里需要在线程安全的上下文中设置停止标志
        addLog("正在停止处理...");
        ui->pushButtonStop->setEnabled(false);
        
        // 在实际实现中，应该在FileProcessWorker中添加停止机制
        // 这里简化处理，直接终止线程
        if (m_workerThread && m_workerThread->isRunning()) {
            m_workerThread->quit();
            m_workerThread->wait();
            addLog("处理已停止");
            updateUIForProcessing(false);
        }
    }
}

void MainWindow::on_pushButtonClearLog_clicked()
{
    ui->textEditLog->clear();
    addLog("日志已清空");
}

void MainWindow::on_pushButtonExit_clicked()
{
    close();
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "关于文件过滤分类工具",
                      "<h3>文件过滤分类工具 v2.1</h3>"
                      "<p>本工具可以将指定文件夹中的文件按照分类规则自动分类并拷贝到目标文件夹。</p>"
                      "<p>主要功能：</p>"
                      "<ul>"
                      "<li><b>按括号内文字分类：</b>提取文件名中括号()内的文字进行分类</li>"
                      "<li><b>按文件名分类：</b>按文件名（不带扩展名）进行分类，相同文件名的文件放在同一文件夹</li>"
                      "<li><b>副本文件归属：</b>带副本标识的文件会自动归属到原始文件名对应的文件夹</li>"
                      "<li><b>按编辑时间分类：</b>按文件最新修改时间进行分类</li>"
                      "</ul>"
                      "<p>按文件名分类示例：</p>"
                      "<ul>"
                      "<li>文件\"报告.docx\"、\"报告 - 副本.pdf\"、\"报告 - 副本(2).txt\"都将复制到\"报告\"文件夹</li>"
                      "<li>文件\"图片1.jpg\"和\"图片1 - 副本.png\"都将复制到\"图片1\"文件夹</li>"
                      "</ul>"
                      "<p>支持的副本标识：</p>"
                      "<ul>"
                      "<li>文件 - 副本.扩展名</li>"
                      "<li>文件 - 副本(2).扩展名</li>"
                      "<li>文件 - 副本 2.扩展名</li>"
                      "</ul>");
}

// 工作线程信号处理
void MainWindow::onWorkerProgressChanged(int value)
{
    ui->progressBar->setValue(value);
}

void MainWindow::onWorkerStatusMessage(const QString &message)
{
    ui->labelStatus->setText(message);
    ui->statusbar->showMessage(message, 3000);
}

void MainWindow::onWorkerLogMessage(const QString &message)
{
    addLog(message);
}

void MainWindow::onWorkerFinished()
{
    addLog("=== 处理完成 ===");
    updateUIForProcessing(false);
    
    // 清理工作线程
    if (m_workerThread) {
        m_workerThread->quit();
        m_workerThread->wait();
        m_workerThread = nullptr;
    }
    m_worker = nullptr;
}

void MainWindow::onWorkerError(const QString &error)
{
    addLog(QString("错误: %1").arg(error));
    QMessageBox::critical(this, "错误", error);
    updateUIForProcessing(false);
}

