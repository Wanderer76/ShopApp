#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QQmlContext>
#include"gridmodel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();
    ReciveData _sendToServer;
    context->setContextProperty("toServer",&_sendToServer);
     qmlRegisterType<GridModel>("GridModel",1,0,"GridModel");

     //qmlRegisterType<ReciveData>("Recive",1,0,"Recive");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
