#include <QGuiApplication>
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "StockManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    
    // 添加 Qt Charts QML 模块路径
    QString chartPath = QCoreApplication::applicationDirPath() + "/QtCharts";
    engine.addImportPath(chartPath);
    
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    qmlRegisterType<CurveEntity>("myapp",1,0,"CurveEntity");
    qmlRegisterType<MapTableModel>("myapp",1,0,"MapTableModel");

    StockManager *stockmgr = new StockManager();
    engine.rootContext()->setContextProperty("stockManager",stockmgr);
    engine.load(url);

    return app.exec();
}
