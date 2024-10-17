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

    Q_INVOKABLE void startDiscovery();  // 장치 검색 시작
    Q_INVOKABLE void stopDiscovery();   // 장치 검색 중지

    // QML에서 장치 이름으로 연결할 수 있는 메서드
    Q_INVOKABLE void connectToDevice(const QString &deviceName);

    // 블루투스 소켓을 통해 데이터를 보내는 메서드
    Q_INVOKABLE void sendData(const QByteArray &data);

signals:
    void deviceDiscovered(const QString &deviceName, const QString &deviceType);  // 장치 발견 시
    void discoveryFinished();          // 검색 완료 시
    void connectedToDevice();          // 장치 연결 성공 시
    void connectionLost();             // 연결이 끊길 때
    void connectionFailed(const QString &error);  // 연결 실패 시 에러 메시지 전달
    void dataReceived(const QByteArray &data);    // 데이터 수신 시

private slots:
    void deviceDiscoveredHandler(const QBluetoothDeviceInfo &deviceInfo);  // 장치 발견 시 처리
    void discoveryFinishedHandler();    // 장치 검색 완료 시 처리
    void connectedHandler();            // 장치 연결 성공 시 처리
    void disconnectedHandler();         // 장치 연결 끊김 시 처리
    void socketErrorHandler(QBluetoothSocket::SocketError error);  // 소켓 에러 처리
    void pairingFinishedHandler(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing);  // 페어링 완료 처리
    void readSocketData();              // 소켓으로부터 데이터 읽기

private:
    QString getDeviceType(const QBluetoothDeviceInfo &deviceInfo) const;  // 장치 유형 결정

    QBluetoothDeviceDiscoveryAgent *discoveryAgent;   // 장치 검색 에이전트
    QBluetoothLocalDevice *localDevice;               // 로컬 블루투스 장치
    QBluetoothSocket *socket;                         // 블루투스 소켓

    QList<QBluetoothDeviceInfo> discoveredDevices;    // 발견된 장치 목록 저장
};
