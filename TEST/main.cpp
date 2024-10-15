#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QTimer>
#include <QDebug>
#include <QElapsedTimer>
#include <QQmlContext>
#include <QCoreApplication>
#include <QPropertyAnimation>
#include <deque>
#include <QScreen>  // QScreen 추가

#include <DateClock.h>
#include <receiver.h>
#include <Weather.h>
//#include <Gauge.h>
#include <get_battery.h>
#include <DataProvider.h>

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

    // QScreen을 이용한 모니터 선택
    QObject *object = engine.rootObjects().isEmpty() ? nullptr : engine.rootObjects().first();
    if (!object) {
        qCritical() << "No root objects found!";
        return -1;
    }

    QWindow *window = qobject_cast<QWindow*>(object);
    if (!window) {
        qCritical() << "Object is not a QWindow instance!";
        return -1;
    }

    QList<QScreen*> screens = QGuiApplication::screens();
    if (screens.size() > 1) {
        qDebug() << "Second screen detected: " << screens.at(1)->name();
        window->setScreen(screens.at(1));  // 두 번째 모니터 설정
        window->showFullScreen();          // 전체 화면 모드로 실행
    } else {
        qDebug() << "Only one screen detected.";
        window->setScreen(screens.at(0));  // 첫 번째 모니터 설정
        window->showFullScreen();          // 전체 화면 모드로 실행
    }

    // 모니터 정보 출력 (디버깅 용도)
    qDebug() << "Using screen:" << window->screen()->name() << "with resolution" << window->screen()->geometry();

    return app.exec();
}
