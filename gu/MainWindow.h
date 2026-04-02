#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "StockPriceFetcher.h"
#include <QSystemTrayIcon>
#include "ButtomStatusWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initTrayicon();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    StockPriceFetcher * fetcher;
    QSystemTrayIcon * m_tray;
    ButtomStatusWidget * m_statusWid;
    QString m_findcode;
};
#endif // MAINWINDOW_H
