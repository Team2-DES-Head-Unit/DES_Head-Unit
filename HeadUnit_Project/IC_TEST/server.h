#ifndef SERVER_H
#define SERVER_H

#include <vsomeip/vsomeip.hpp>
#include <iostream>
#include <memory>
#include <vector>
#include <cstring>
#include <thread>
#include <QObject>

#define SAMPLE_SERVICE_ID 0x1234
#define SAMPLE_INSTANCE_ID_1 0x5678
#define SAMPLE_INSTANCE_ID_2 0x5679
#define SAMPLE_METHOD_ID 0x0421

extern std::shared_ptr<vsomeip::application> app;

struct ControlData {
    float throttle;
    float steering;
    uint8_t gear_P;
    uint8_t gear_D;
    uint8_t gear_R;
    uint8_t gear_N;
    uint8_t indicator_left;
    uint8_t indicator_right;
};

class Server : public QObject {
    Q_OBJECT
    Q_PROPERTY(int gear READ gear NOTIFY gearChanged)
    Q_PROPERTY(bool indicatorLeft READ indicatorLeft NOTIFY indicatorLeftChanged)
    Q_PROPERTY(bool indicatorRight READ indicatorRight NOTIFY indicatorRightChanged)

public:
    explicit Server(QObject *parent = nullptr) : QObject(parent), m_gear(0), m_indicatorLeft(false), m_indicatorRight(false) {}
    // m_gear(0)
    int gear() const { return m_gear; }
    bool indicatorLeft() const { return m_indicatorLeft; }
    bool indicatorRight() const { return m_indicatorRight; }

    void updateGui(const ControlData &data) {
//        m_gear = data.gear_P ? 1 : data.gear_D ? 2 : data.gear_R ? 3 : data.gear_N ? 4 : 0;
        m_indicatorLeft = data.indicator_left;
        m_indicatorRight = data.indicator_right;

        int newGear = data.gear_P ? 1 : data.gear_D ? 2 : data.gear_R ? 3 : data.gear_N ? 4 : 0;
        if(newGear != m_gear){
            m_gear = newGear;
            emit gearChanged();
        }
//        emit gearChanged();
        emit indicatorLeftChanged();
        emit indicatorRightChanged();
    }

signals:
    void gearChanged();
    void indicatorLeftChanged();
    void indicatorRightChanged();

private:
    int m_gear;
    bool m_indicatorLeft;
    bool m_indicatorRight;
};

extern Server server;

void start_server();

#endif // SERVER_H
