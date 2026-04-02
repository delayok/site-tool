#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QSystemTrayIcon>
#include <QStyle>
#include <QMenu>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);

    qDebug() << "SSL supported:" << QSslSocket::supportsSsl();
    qDebug() << "Build SSL:" << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << "Runtime SSL:" << QSslSocket::sslLibraryVersionString();

    fetcher = new StockPriceFetcher();
    //fetcher->setStockCode("sh600519"); // 贵州茅台
    fetcher->start(1000);              // 每秒刷新

    connect(fetcher, &StockPriceFetcher::jsonUpdated, this, [=](StockPriceFetcher::JsonPkg price){
            ui->label->setText(price.name + QString::number(price.price) + "  分时均线" +  QString::number(price.mhmov));

            QString c1 = price.price > price.open ? "red":"green";
            QString c2 = price.price > price.mhmov ? "red":"green";
            QString c3 = price.increase > 0 ? "red":"green";

            QString info =QString("<font color='%1'>实 %2  </font> <font color='%3'>幅 %4 % </font> <font color='%5'>均 %6</font>").arg(c1).arg(price.price)
                    .arg(c3).arg(price.increase) .arg(c2).arg(price.mhmov);
            m_statusWid->updateInfo(info);
    });

    connect(fetcher, &StockPriceFetcher::jsonNameUpdated, this, [=](QString ret){
           ui->textEdit->setText(ret);
           int index = ret.indexOf("[");
           int indexend = ret.indexOf("]");
           m_findcode = ret.mid(index+ 1, indexend -index - 1 );
           qDebug()<<"code="<<m_findcode;
    });

    initTrayicon();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTrayicon()
{

    m_statusWid = new ButtomStatusWidget();
    m_statusWid->hide();

    QMenu *menu = new QMenu;

    QAction *settingAction = menu->addAction("显示设置界面");
    QAction *showAction = menu->addAction("显示状态栏");
    QAction *hideAction = menu->addAction("隐藏状态栏");
    menu->addSeparator();
    QAction *quitAction = menu->addAction("退出");

    m_tray = new QSystemTrayIcon();
    m_tray->setIcon(QApplication::style()->standardIcon(QStyle::SP_ComputerIcon));
    m_tray->setToolTip("后台服务运行中");

    m_tray->setContextMenu(menu);
    m_tray->show();

    connect(settingAction,  &QAction::triggered, this, &MainWindow::show);
    connect(showAction,     &QAction::triggered, m_statusWid, &ButtomStatusWidget::show);
    connect(hideAction,     &QAction::triggered, m_statusWid, &ButtomStatusWidget::hide);
    connect(quitAction,     &QAction::triggered, qApp, &QApplication::quit);
}


void MainWindow::on_pushButton_clicked()
{
    //
    fetcher->setStockCode(ui->lineEdit->text());
}

void MainWindow::on_pushButton_2_clicked()
{
    fetcher->setStockName(ui->lineEdit_2->text());
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    fetcher->setUrlType(index);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->lineEdit->setText(m_findcode);
    on_pushButton_clicked();
}
