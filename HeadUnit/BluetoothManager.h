#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothLocalDevice>
#include <QBluetoothSocket>

class BluetoothManager : public QObject
{
    Q_OBJECT
public:
    explicit BluetoothManager(QObject *parent = nullptr);
    ~BluetoothManager();

    void startDiscovery();
    void stopDiscovery();  // 중지 메서드 추가
    void connectToDevice(const QBluetoothDeviceInfo &deviceInfo);

signals:
    void deviceDiscovered(const QString &deviceName);
    void discoveryFinished();
    void connectedToDevice();

private slots:
    void deviceDiscoveredHandler(const QBluetoothDeviceInfo &deviceInfo);
    void discoveryFinishedHandler();
    void connectedHandler();

private:
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothLocalDevice *localDevice;
    QBluetoothSocket *socket;
};
