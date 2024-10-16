#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include <QCommandLineParser>
#include <QQmlContext>
//#include <QWindow>
//#include <QProcess>

#include "basic_func.h"
#include "weather_provider.h"
#include "music_player.h"
#include "youtube_player.h"

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
//    YoutubePlayer youtubePlayer;

//    QCommandLineParser parser;
//    parser.setApplicationDescription("Qt Wayland Application");
//    parser.addHelpOption(); // --help option
//    parser.addOption({{"fullscreen"}, "Enable fullscreen mode."}); // --fullscreen option
//    parser.addOption({{"display"}, "Set display output.", "display"}); // --display option
//    parser.process(app);

//    QWindow mainWindow;

//    if (parser.isSet("fullscreen")) {
//        qDebug() << "Fullscreen mode enabled.";
//        mainWindow.showFullScreen();
//    }else{
//        mainWindow.show();
//    }

//    // --display option
//    if (parser.isSet("display")) {
//        QString displayValue = parser.value("display");
        
//        if (displayValue == 'dashboard'){
//            mainWindow.setPosition(1000, 0);
//        }
//        else if (displayValue == 'infortainment'){
//            mainWindow.setPosition(0,0);
//        }
//    }

    engine.rootContext()->setContextProperty("timeProvider", &timeProvider);
    engine.rootContext()->setContextProperty("speedProvider", &speedProvider);
    engine.rootContext()->setContextProperty("weatherProvider", &weatherProvider);
    engine.rootContext()->setContextProperty("musicPlayer", &musicPlayer);
    qmlRegisterType<YoutubePlayer>("youtubePlayer", 1, 0, "YoutubePlayer");
//    engine.rootContext()->setContextProperty("youtubePlayer", &youtubePlayer);

//    // music test
//    QString songtitle = "Hanumankind-Big_Dawgs.mp3";
//    musicPlayer.playMusic(musicPlayer.getPathForSong(songtitle));

//    // playlist test
//    QString songtitle = "Hanumankind-Big_Dawgs.mp3";
//    musicPlayer.getCurrentPlayList(songtitle);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
