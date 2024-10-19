#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtWebEngine>
#include <QWindow>
#include <QScreen>

#include "basic_func.h"
#include "weather_provider.h"
#include "music_player.h"
#include "youtube_player.h"
#include "bluetoothmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QtWebEngine::initialize();
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    TimeProvider timeProvider;
    SpeedProvider speedProvider;
    WeatherProvider weatherProvider;
    MusicPlayer musicPlayer;
    YoutubePlayer youtubePlayerProvider;
    BluetoothManager btManager;

    engine.rootContext()->setContextProperty("timeProvider", &timeProvider);
    engine.rootContext()->setContextProperty("speedProvider", &speedProvider);
    engine.rootContext()->setContextProperty("weatherProvider", &weatherProvider);
    engine.rootContext()->setContextProperty("musicPlayer", &musicPlayer);
    engine.rootContext()->setContextProperty("youtubePlayerProvider", &youtubePlayerProvider);
    engine.rootContext()->setContextProperty("btManager", &btManager);
    qmlRegisterType<YoutubePlayer>("youtubePlayer", 1, 0, "YoutubePlayer");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QList<QScreen*> screens = QGuiApplication::screens();
    if (screens.size() > 1) {
        qDebug() << "Second screen detected: " << screens.at(0)->name();
        QObject *object = engine.rootObjects().first();  // 첫 번째 루트 객체를 가져옴
        QWindow *window = qobject_cast<QWindow*>(object);
        if (window) {
            window->setScreen(screens.at(0));  // 두 번째 모니터 설정
            window->showFullScreen();          // 전체 화면 모드로 실행
        }
    } else {
        qDebug() << "Only one screen detected.";
        QObject *object = engine.rootObjects().first();
        QWindow *window = qobject_cast<QWindow*>(object);
        if (window) {
            window->setScreen(screens.at(0));  // 첫 번째 모니터 설정
            window->showFullScreen();          // 전체 화면 모드로 실행
        }
    }

    return app.exec();
}
