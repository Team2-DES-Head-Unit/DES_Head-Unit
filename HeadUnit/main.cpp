#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "basic_func.h"
#include "weather_provider.h"
#include "music_player.h"
#include "BluetoothManager.h"
#include "ClickNotier.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // register TimeProvider class(set on basic_func) to use on Qml
//    qmlRegisterType<TimeProvider>("timeprovider", 1, 0, "TimeProvider");

    TimeProvider timeProvider;
    SpeedProvider speedProvider;
    WeatherProvider weatherProvider;
    MusicPlayer musicPlayer;
    ClickNotifier clickNotifier;

    engine.rootContext()->setContextProperty("timeProvider", &timeProvider);
    engine.rootContext()->setContextProperty("speedProvider", &speedProvider);
    engine.rootContext()->setContextProperty("weatherProvider", &weatherProvider);
    engine.rootContext()->setContextProperty("musicPlayer", &musicPlayer);
    engine.rootContext()->setContextProperty("clickNotifier", &clickNotifier);

//    BluetoothManager btManager;
//    engine.rootContext()->setContextProperty("btManager", &btManager);

//    // music test
//    QString songtitle = "Hanumankind-Big_Dawgs.mp3";
//    musicPlayer.playMusic(musicPlayer.getPathForSong(songtitle));

//    // playlist test
//    QString songtitle = "Hanumankind-Big_Dawgs.mp3";
//    musicPlayer.getCurrentPlayLIst(songtitle);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
