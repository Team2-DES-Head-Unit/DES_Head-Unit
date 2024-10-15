#include "BluetoothManager.h"
#include <QBluetoothDeviceInfo>
#include <QBluetoothUuid>
#include <QBluetoothLocalDevice>
#include <QBluetoothSocket>

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
    // 장치 종류를 결정하는 간단한 로직
    switch (deviceInfo.majorDeviceClass()) {
        case 0x00000000: // Miscellaneous
            return "Miscellaneous";
        case 0x00000001: // Computer
            return "Computer";
        case 0x00000002: // Phone
            return "Phone";
        case 0x00000004: // Audio
            return "Audio";
        case 0x00000005: // Peripheral
            return "Peripheral";
        case 0x00000006: // Wearable
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
