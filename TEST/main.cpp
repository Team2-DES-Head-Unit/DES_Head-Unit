#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QWindow>  // QWindow 헤더 파일 포함
#include <QScreen>  // QScreen 헤더 파일 포함
#include <QQmlContext>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QObject *object = engine.rootObjects().isEmpty() ? nullptr : engine.rootObjects().first();
    if (!object) {
        qCritical() << "No root objects found!";
        return -1;
    }

    // QScreen을 이용한 모니터 선택
    QList<QScreen*> screens = QGuiApplication::screens();
    if (screens.size() > 1) {
        qDebug() << "Second screen detected: " << screens.at(1)->name();
        QWindow *window = qobject_cast<QWindow*>(object);
        if (window) {
            window->setScreen(screens.at(1));  // 두 번째 모니터 설정
            window->showFullScreen();          // 전체 화면 모드로 실행
        }
    } else {
        qDebug() << "Only one screen detected.";
        QWindow *window = qobject_cast<QWindow*>(object);
        if (window) {
            window->setScreen(screens.at(0));  // 첫 번째 모니터 설정
            window->showFullScreen();          // 전체 화면 모드로 실행
        }
    }

    return app.exec();
}
