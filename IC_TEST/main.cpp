#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
#include <QDebug>
#include <QElapsedTimer>
#include <QQmlContext>
#include <QCoreApplication>
#include <QPropertyAnimation>
#include <deque>

#include <DateClock.h>
#include <receiver.h>
#include <Weather.h>
#include <Gauge.h>
#include <get_battery.h>

int i2c_fd;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    DateClock clock;
    DateClock date;
    Receiver receiver;

    receiver.initialize();
    receiver.start();


    engine.rootContext()->setContextProperty("Clock", &clock);
    engine.rootContext()->setContextProperty("Date", &date);
    engine.rootContext()->setContextProperty("Receiver", &receiver);

    Weather weather;

    engine.rootContext()->setContextProperty("Weather", &weather);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
