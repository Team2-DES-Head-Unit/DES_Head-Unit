#include "bluetoothmanager.h"
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

    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
            this, &BluetoothManager::deviceDiscoveredHandler);
    connect(discoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished,
            this, &BluetoothManager::discoveryFinishedHandler);

    connect(socket, &QBluetoothSocket::connected,
            this, &BluetoothManager::connectedHandler);
    connect(socket, &QBluetoothSocket::disconnected,
            this, &BluetoothManager::disconnectedHandler);
    connect(socket, QOverload<QBluetoothSocket::SocketError>::of(&QBluetoothSocket::error),
            this, &BluetoothManager::socketErrorHandler);

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
        discoveredDevices.clear();
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

void BluetoothManager::connectToDevice(const QString &deviceName)
{
    qDebug() << "Attempting to connect to device:" << deviceName;

    for (const QBluetoothDeviceInfo &deviceInfo : discoveredDevices) {
        if (deviceInfo.name() == deviceName) {
            qDebug() << "Device found, checking pairing status:" << deviceName;

            QBluetoothLocalDevice::Pairing pairingStatus = localDevice->pairingStatus(deviceInfo.address());
            if (pairingStatus == QBluetoothLocalDevice::Unpaired) {

                qDebug() << "Requesting pairing for device:" << deviceName;
                localDevice->requestPairing(deviceInfo.address(), QBluetoothLocalDevice::Paired);
            } else {

                qDebug() << "Device already paired. Connecting to service...";
                socket->connectToService(deviceInfo.address(), QBluetoothUuid(QBluetoothUuid::SerialPort), QIODevice::ReadWrite);
            }
            return;
        }
    }

    qWarning() << "Device not found in discovered devices:" << deviceName;
}

void BluetoothManager::deviceDiscoveredHandler(const QBluetoothDeviceInfo &deviceInfo)
{
    QString deviceName = deviceInfo.name();
    QString deviceType = getDeviceType(deviceInfo);

    discoveredDevices.append(deviceInfo);

    emit deviceDiscovered(deviceName, deviceType);
}

QString BluetoothManager::getDeviceType(const QBluetoothDeviceInfo &deviceInfo) const
{
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
            return "Unknown";
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

void BluetoothManager::readSocketData()
{
    QByteArray data = socket->readAll();
    qDebug() << "Data received:" << data;
    emit dataReceived(data);
}

void BluetoothManager::sendData(const QByteArray &data)
{
    if (socket->state() == QBluetoothSocket::ConnectedState) {
        socket->write(data);
        qDebug() << "Data sent:" << data;
    } else {
        qWarning() << "Socket is not connected.";
    }
}
