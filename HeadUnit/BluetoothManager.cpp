#include "BluetoothManager.h"
#include <QBluetoothDeviceInfo>

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
    // 장치 발견 시 디바이스 이름을 QML로 전송
    emit deviceDiscovered(deviceInfo.name());
}

void BluetoothManager::discoveryFinishedHandler()
{
    emit discoveryFinished();
}

void BluetoothManager::connectedHandler()
{
    emit connectedToDevice();
}
