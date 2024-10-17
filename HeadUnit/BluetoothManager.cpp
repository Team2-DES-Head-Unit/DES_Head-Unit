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

    // 소켓 연결, 끊김, 에러 처리
    connect(socket, &QBluetoothSocket::connected,
            this, &BluetoothManager::connectedHandler);
    connect(socket, &QBluetoothSocket::disconnected,
            this, &BluetoothManager::disconnectedHandler);
    connect(socket, QOverload<QBluetoothSocket::SocketError>::of(&QBluetoothSocket::error),
            this, &BluetoothManager::socketErrorHandler);

    // 페어링 완료 처리
    connect(localDevice, &QBluetoothLocalDevice::pairingFinished,
            this, &BluetoothManager::pairingFinishedHandler);
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
        qDebug() << "Starting device discovery...";
        discoveredDevices.clear(); // 새로운 검색 시작 시 목록 초기화
        discoveryAgent->start();
    }
}

void BluetoothManager::stopDiscovery()
{
    if (discoveryAgent->isActive()) {
        qDebug() << "Stopping device discovery...";
        discoveryAgent->stop();
    }
}

// 장치 이름으로 연결하는 메서드
void BluetoothManager::connectToDevice(const QString &deviceName)
{
    qDebug() << "Attempting to connect to device:" << deviceName;

    // 발견된 장치 중 이름이 일치하는 장치를 찾음
    for (const QBluetoothDeviceInfo &deviceInfo : discoveredDevices) {
        if (deviceInfo.name() == deviceName) {
            qDebug() << "Device found, attempting to connect:" << deviceName;
            socket->connectToService(deviceInfo.address(), QBluetoothUuid(QBluetoothUuid::SerialPort), QIODevice::ReadWrite);
            return;
        }
    }

    qWarning() << "Device not found in discovered devices:" << deviceName;
}

void BluetoothManager::deviceDiscoveredHandler(const QBluetoothDeviceInfo &deviceInfo)
{
    // 페어링 상태 확인
    QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(deviceInfo.address());

    QString deviceName = deviceInfo.name();
    QString deviceType = getDeviceType(deviceInfo);

    // 발견된 장치 목록에 추가
    discoveredDevices.append(deviceInfo);

    // QML로 발견된 장치 전송
    emit deviceDiscovered(deviceName, deviceType);

    // 페어링되지 않은 장치일 경우 페어링 시도
    if (pairingStatus == QBluetoothLocalDevice::Unpaired) {
        qDebug() << "Requesting pairing for device:" << deviceName;
        localDevice->requestPairing(deviceInfo.address(), QBluetoothLocalDevice::Paired);
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
    qDebug() << "Device discovery finished.";
    emit discoveryFinished();
}

void BluetoothManager::connectedHandler()
{
    qDebug() << "Connected to device.";
    emit connectedToDevice();
}

void BluetoothManager::disconnectedHandler()
{
    qWarning() << "Bluetooth connection lost.";
    emit connectionLost();
}

void BluetoothManager::socketErrorHandler(QBluetoothSocket::SocketError error)
{
    qWarning() << "Bluetooth connection error:" << error << socket->errorString();
    emit connectionFailed(socket->errorString());
}

void BluetoothManager::pairingFinishedHandler(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing)
{
    if (pairing == QBluetoothLocalDevice::Paired || pairing == QBluetoothLocalDevice::AuthorizedPaired) {
        qDebug() << "Pairing successful, attempting to connect.";
        // 페어링된 장치에 연결 시도
        for (const QBluetoothDeviceInfo &deviceInfo : discoveredDevices) {
            if (deviceInfo.address() == address) {
                connectToDevice(deviceInfo.name());
                return;
            }
        }
    } else {
        qWarning() << "Pairing failed or unpaired.";
    }
}

// 소켓에서 데이터 읽기
void BluetoothManager::readSocketData()
{
    QByteArray data = socket->readAll();
    qDebug() << "Data received:" << data;
    emit dataReceived(data);
}

// 소켓으로 데이터 전송
void BluetoothManager::sendData(const QByteArray &data)
{
    if (socket->state() == QBluetoothSocket::ConnectedState) {
        socket->write(data);
        qDebug() << "Data sent:" << data;
    } else {
        qWarning() << "Socket is not connected.";
    }
}
