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
//#include <Gauge.h>
#include <get_battery.h>
#include <DataProvider.h>

int i2c_fd;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

//    qmlRegisterType<SpeedGauge>("com.myapp.gauge", 1, 0, "SpeedGauge");
//    qmlRegisterType<RpmGauge>("com.myapp.gauge", 1, 0, "RpmGauge");

    QQmlApplicationEngine engine;

//    i2c_fd = open(I2C_BUS, O_RDWR);
//    if (i2c_fd < 0) {
//        return -1;
//    }
//    if (ioctl(i2c_fd, I2C_SLAVE, INA219_ADDRESS) < 0) {
//        close(i2c_fd);
//        return -1;
//    }

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

    QObject *object = engine.rootObjects().isEmpty() ? nullptr : engine.rootObjects().first();
    if (!object) {
        qCritical() << "No root objects found!";
        return -1;
    }



    /*///////////////////////////////////////////////////////// test Battery gauge with random value */
//    qreal battery = 0.0;
//    qreal previousBattery = 0.0;
//    const qreal b_threshold = 2.0; // 1.0

//    std::deque<qreal> batteryValues;
//    const int smoothWindowSize = 10; //5

//    std::srand(std::time(nullptr));
//    QTimer *timer_test_rpm = new QTimer(&app);

//    QPropertyAnimation animation(speedometerObj, "battery");
//    animation.setDuration(1000);
//    animation.setEasingCurve(QEasingCurve::OutCubic);

//    QObject::connect(timer_test_rpm, &QTimer::timeout, [&](){

//        battery = readVoltage(i2c_fd);
//        batteryValues.push_back(battery);

//        if (batteryValues.size() > smoothWindowSize){
//            batteryValues.pop_front();
//        }

//        qreal batterySum = std::accumulate(batteryValues.begin(), batteryValues.end(), 0.0) / batteryValues.size();
//        int batteryPercentage = calculateBatteryPercentage(batterySum); // battery

//        qDebug() << "battery gap : " << batteryPercentage - previousBattery;
//        if (std::fabs(batteryPercentage - previousBattery) >= b_threshold){

//            animation.setStartValue(speedometerObj->property("battery"));
//            animation.setEndValue(batteryPercentage); // battery
//            animation.start();
//            previousBattery = batteryPercentage;

//        }
//        engine.rootContext()->setContextProperty("battery_value", batteryPercentage); //static_cast<int>(battery)

//        qDebug() << "Battery : " << battery;
//        qDebug() << "Battery percentage : " << batteryPercentage;
//    });
//    timer_test_rpm->start(1000);

    return app.exec();
}
