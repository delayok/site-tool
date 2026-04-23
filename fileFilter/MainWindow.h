#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QString>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// 文件处理工作线程
class FileProcessWorker : public QObject
{
    Q_OBJECT

public:
    explicit FileProcessWorker(QObject *parent = nullptr);
    
public slots:
    void processFiles(const QString &sourcePath, 
                     const QString &targetPath,
                     bool useFileNameRule);

signals:
    void progressChanged(int value);
    void statusMessage(const QString &message);
    void logMessage(const QString &message);
    void finished();
    void errorOccurred(const QString &error);

private:
    bool m_stopRequested;
    
    // 辅助函数
    QString getFilenameCode(const QString &filename);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonBrowseSource_clicked();
    void on_pushButtonBrowseTarget_clicked();
    void on_pushButtonStart_clicked();
    void on_pushButtonStop_clicked();
    void on_pushButtonClearLog_clicked();
    void on_pushButtonExit_clicked();
    void on_actionExit_triggered();
    void on_actionAbout_triggered();
    
    // 工作线程相关槽函数
    void onWorkerProgressChanged(int value);
    void onWorkerStatusMessage(const QString &message);
    void onWorkerLogMessage(const QString &message);
    void onWorkerFinished();
    void onWorkerError(const QString &error);

private:
    Ui::MainWindow *ui;
    QThread *m_workerThread;
    FileProcessWorker *m_worker;
    bool m_processing;
    
    void setupConnections();
    void addLog(const QString &message);
    void updateUIForProcessing(bool processing);
};
#endif // MAINWINDOW_H
