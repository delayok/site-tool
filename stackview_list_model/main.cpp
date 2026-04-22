#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include <QStyle>
#include "StockManager.h"
#include "RealtimeCurveItem.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication::setQuitOnLastWindowClosed(false);

    QApplication app(argc, argv);


    QQmlApplicationEngine engine;
    
    // 添加 Qt Charts QML 模块路径
    QString chartPath = QCoreApplication::applicationDirPath() + "/QtCharts";
    engine.addImportPath(chartPath);

    
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QApplication::exit(-1);
    }, Qt::QueuedConnection);

    qmlRegisterType<MapTableModel>("myapp",1,0,"MapTableModel");
    qmlRegisterType<RealtimeCurveItem>("myapp",1,0,"RealtimeCurveItem");

    StockManager *stockmgr = new StockManager();
    engine.rootContext()->setContextProperty("stockManager",stockmgr);
    engine.load(url);

    return app.exec();
}
