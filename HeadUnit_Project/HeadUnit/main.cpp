#include <QGuiApplication>
#include <QQmlApplicationEngine>
//#include <QCommandLineParser>
#include <QQmlContext>
//#include <QWindow>
//#include <QProcess>
#include <QtWebEngine>
#include <QtWebEngineWidgets/QWebEngineSettings>
#include "basic_func.h"
#include "weather_provider.h"
#include "music_player.h"
#include "youtube_player.h"
#include "bluetoothmanager.h"

int main(int argc, char *argv[])
{
    // GPU 가속 비활성화 관련 설정
    qputenv("QTWEBENGINE_CHROMIUM_FLAGS", "--disable-gpu --disable-gpu-compositing --disable-gpu-rasterization");
    qputenv("QMLSCENE_DEVICE", "softwarecontext");
    qputenv("QT_QUICK_BACKEND", "software");
    QCoreApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
    QCoreApplication::setAttribute(Qt::AA_UseSoftwareOpenGL);
    QtWebEngine::initialize();
    QGuiApplication app(argc, argv);
    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::WebGLEnabled, false);
    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::AcceleratedCompositingEnabled, false);
    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::Accelerated2dCanvasEnabled, false);
    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::PlaybackRequiresUserGesture, false);
    
    QQmlApplicationEngine engine;

    // register TimeProvider class(set on basic_func) to use on Qml
    //    qmlRegisterType<TimeProvider>("timeprovider", 1, 0, "TimeProvider");

    TimeProvider timeProvider;
    SpeedProvider speedProvider;
    WeatherProvider weatherProvider;
    MusicPlayer musicPlayer;
    YoutubePlayer youtubePlayerProvider;
    BluetoothManager btManager;

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
    engine.rootContext()->setContextProperty("youtubePlayerProvider", &youtubePlayerProvider);
    engine.rootContext()->setContextProperty("btManager", &btManager);
    qmlRegisterType<YoutubePlayer>("youtubePlayer", 1, 0, "YoutubePlayer");

//    // music test
    QString songtitle = "Hanumankind-Big_Dawgs.mp3";
    musicPlayer.playMusic(musicPlayer.getPathForSong(songtitle));

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