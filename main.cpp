#include "MainWindow.h"

#include <QApplication>
#include <QSystemTrayIcon>
#include <QStyle>
#include <QMenu>

int main(int argc, char *argv[])
{

    QApplication::setQuitOnLastWindowClosed(false);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
