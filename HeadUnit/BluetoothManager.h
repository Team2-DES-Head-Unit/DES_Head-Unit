#include <QObject>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothLocalDevice>
#include <QBluetoothSocket>
#include <QBluetoothDeviceInfo>
#include <QList>  // QList 추가

class BluetoothManager : public QObject
{
    Q_OBJECT
public:
    explicit BluetoothManager(QObject *parent = nullptr);
    ~BluetoothManager();

    Q_INVOKABLE void startDiscovery();
    Q_INVOKABLE void stopDiscovery();

    // QML에서 장치 이름으로 연결할 수 있는 메서드 추가
    Q_INVOKABLE void connectToDevice(const QString &deviceName);

signals:
    void deviceDiscovered(const QString &deviceName, const QString &deviceType);
    void discoveryFinished();
    void connectedToDevice();

private slots:
    void deviceDiscoveredHandler(const QBluetoothDeviceInfo &deviceInfo);
    void discoveryFinishedHandler();
    void connectedHandler();

private:
    QString getDeviceType(const QBluetoothDeviceInfo &deviceInfo) const;

    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothLocalDevice *localDevice;
    QBluetoothSocket *socket;

    // 발견된 장치를 저장하는 리스트 추가
    QList<QBluetoothDeviceInfo> discoveredDevices;
};
