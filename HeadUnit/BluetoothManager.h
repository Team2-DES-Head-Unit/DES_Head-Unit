#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothLocalDevice>
#include <QBluetoothSocket>
#include <QBluetoothDeviceInfo>

class BluetoothManager : public QObject
{
    Q_OBJECT
public:
    explicit BluetoothManager(QObject *parent = nullptr);
    ~BluetoothManager();

    Q_INVOKABLE void startDiscovery();
    Q_INVOKABLE void stopDiscovery();  // 중지 메서드 추가
    void connectToDevice(const QBluetoothDeviceInfo &deviceInfo);

signals:
    void deviceDiscovered(const QString &deviceName, const QString &deviceType);
    void discoveryFinished();
    void connectedToDevice();

private slots:
    void deviceDiscoveredHandler(const QBluetoothDeviceInfo &deviceInfo);
    void discoveryFinishedHandler();
    void connectedHandler();

private:
    QString getDeviceType(const QBluetoothDeviceInfo &deviceInfo) const;  // deviceType 가져오는 메서드 추가

    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothLocalDevice *localDevice;
    QBluetoothSocket *socket;
};
