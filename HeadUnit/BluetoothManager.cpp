#include "BluetoothManager.h"
#include <QBluetoothDeviceInfo>
#include <QBluetoothUuid>
#include <QBluetoothLocalDevice>
#include <QBluetoothSocket>
#include <QDebug>

BluetoothManager::BluetoothManager(QObject *parent) :
    QObject(parent),
    discoveryAgent(new QBluetoothDeviceDiscoveryAgent(this)),
    localDevice(new QBluetoothLocalDevice),
    socket(new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol, this))
{
    // 장치 발견 시 시그널 처리
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BluetoothManager::deviceDiscoveredHandler);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &BluetoothManager::discoveryFinishedHandler);
    connect(socket, &QBluetoothSocket::connected,
            this, &BluetoothManager::connectedHandler);
}

BluetoothManager::~BluetoothManager()
{
    delete discoveryAgent;
    delete localDevice;
    delete socket;
}

void BluetoothManager::startDiscovery()
{
    if (localDevice->isValid()) {
        discoveryAgent->start();
    }
}

void BluetoothManager::stopDiscovery()  // 장치 검색 중지 메서드
{
    if (discoveryAgent->isActive()) {
        discoveryAgent->stop();
    }
}

void BluetoothManager::connectToDevice(const QBluetoothDeviceInfo &deviceInfo)
{
    socket->connectToService(deviceInfo.address(), QBluetoothUuid(QBluetoothUuid::SerialPort), QIODevice::ReadWrite);
}

void BluetoothManager::deviceDiscoveredHandler(const QBluetoothDeviceInfo &deviceInfo)
{
    // 장치 발견 시 디바이스 이름과 타입을 QML로 전송
    QString deviceName = deviceInfo.name();
    QString deviceType = getDeviceType(deviceInfo);  // 장치 종류 가져오기
    emit deviceDiscovered(deviceName, deviceType);    // deviceType 포함하여 emit
}

QString BluetoothManager::getDeviceType(const QBluetoothDeviceInfo &deviceInfo) const
{
    // 장치 종류를 결정하는 로직
    int majorClass = deviceInfo.majorDeviceClass();

    switch (majorClass) {
        case 0: // Miscellaneous
            return "Miscellaneous";
        case 1: // Computer
            return "Computer";
        case 2: // Phone
            return "Phone";
        case 4: // Audio
            return "Audio";
        case 5: // Peripheral
            return "Peripheral";
        case 6: // Wearable
            return "Wearable";
        default:
            return "Unknown"; // 알 수 없는 장치
    }
}

void BluetoothManager::discoveryFinishedHandler()
{
    emit discoveryFinished();
}

void BluetoothManager::connectedHandler()
{
    emit connectedToDevice();
}
