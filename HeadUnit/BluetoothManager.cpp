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
        discoveredDevices.clear(); // 새로운 검색 시작 시 목록 초기화
        discoveryAgent->start();
    }
}

void BluetoothManager::stopDiscovery()
{
    if (discoveryAgent->isActive()) {
        discoveryAgent->stop();
    }
}

// 장치 이름으로 연결하는 메서드 추가
void BluetoothManager::connectToDevice(const QString &deviceName)
{
    // 발견된 장치 중 이름이 일치하는 장치를 찾음
    for (const QBluetoothDeviceInfo &deviceInfo : discoveredDevices) {
        if (deviceInfo.name() == deviceName) {
            qDebug() << "Connecting to device:" << deviceName;
            socket->connectToService(deviceInfo.address(), QBluetoothUuid(QBluetoothUuid::SerialPort), QIODevice::ReadWrite);
            return;
        }
    }
    qDebug() << "Device not found:" << deviceName;
}

void BluetoothManager::deviceDiscoveredHandler(const QBluetoothDeviceInfo &deviceInfo)
{
    // 페어링 상태 확인
    QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(deviceInfo.address());

    // 페어링되지 않은 장치만 QML로 전송
    if (pairingStatus == QBluetoothLocalDevice::Unpaired) {
        QString deviceName = deviceInfo.name();
        QString deviceType = getDeviceType(deviceInfo);

        // 발견된 장치 목록에 추가
        discoveredDevices.append(deviceInfo);

        // QML로 발견된 장치 전송
        emit deviceDiscovered(deviceName, deviceType);
    }
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
