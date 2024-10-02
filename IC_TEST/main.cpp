#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
//    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling); //추가
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

//    QObject::connect(
//        &engine,
//        &QQmlApplicationEngine::objectCreationFailed,
//        &app,
//        []() { QCoreApplication::exit(-1); },
//        Qt::QueuedConnection);
//    engine.loadFromModule("IC_TEST", "Main");

    const QUrl url(QStringLiteral("/home/llj/catkin_ws/src/DES_Head-Unit/IC_TEST/main.qml"));
//    const QUrl url(u"qrc:main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl){
            QCoreApplication::exit(-1);
        }
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
