import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12


Window{
    id: bluetooth_window
    visible: true
    width: 413
    height: 445
    color: "transparent"
    flags: Qt.FramelessWindowHint

    property bool isSearching: false  // 검색 상태를 추적하는 변수
    property bool isStopped: true

    Image {
        id: bluetooth_close_button
        x: 350
        y: 6
        width: 50
        height: 50
        fillMode: Image.PreserveAspectFit
        source: clickNotifier.clicked ? "HU_Assets/light/Icons/close_icon_l.png" : "HU_Assets/Icons/tap_close_button.png"

        MouseArea{
            anchors.fill: parent
            onClicked: {
                bluetooth_window.visible = false;
                service_selected.visible = false;
            }
        }
        Connections {
            target: service_selected
        }
    }

    Column {
        id: bluetooth_discovery
        spacing: 30
        Item {
            id: topmargin_Item
            width: parent.width
            height: 45  // topMargin을 주는 효과
        }
        Row {
            id: bdbutton_row
            spacing: 20
            Item{
                id: leftmargin_Item
                width: 25
                height: 20
            }

            Text {
                id: bluetoothd_txt
                text: qsTr("Bluetooth Discovery")
                font.pixelSize: 20
                color: clickNotifier.clicked ? "#414141" : "white"
            }
            Button {
                id: bdbutton_on
                text: qsTr("On")
                width: 50
                height: 25
//                onClicked: {
//                    btManager.startDiscovery();
//                    isSearching = true;  // 검색 상태 시작
//                    isStopped = false;   // 검색 중지 상태 해제
//                    deviceModel.clear(); // 장치 목록 초기화
//                }
            }
            Button {
                id: bdbutton_off
                text: qsTr("Off")
                width: 50
                height: 25
//                onClicked: {
//                    btManager.stopDiscovery();
//                    isSearching = false;  // 검색 중지
//                    isStopped = true;     // 검색 중지 상태 설정
//                    deviceModel.clear(); // 장치 목록 초기화
//                }
            }

        }

        // 헤더 섹션
        Row {
            spacing: 20
            width: bd_list.width
            height: 30

            Item {
                id: name_gap
                width: 10
                height: 30
            }

            // Name 헤더
            Text {
                text: "Name"
                font.bold: true
                color: clickNotifier.clicked ? "#414141" : "white"
            }

            Item {
                id: type_gap
                width: 150
                height: 30
            }

            // Type 헤더
            Text {
                text: "Type"
                font.bold: true
                color: clickNotifier.clicked ? "#414141" : "white"
            }
        }
        // 스크롤 가능한 ListView
        Flickable {
            id: flick
            width: parent.width
            height: 250
            contentHeight: bd_list.contentHeight

            ListView {
                id: bd_list
                width: parent.width - 70
                height: 250
                anchors.left: parent.left
                anchors.leftMargin: 55
                model: ListModel {
                    id: deviceModel
                }

                // 각 아이템의 delegate 설정
                delegate: Item {
                    width: bd_list.width
                    height: 30  // 각 아이템의 높이 설정

                    Row {
                        spacing: 30
                        anchors.fill: parent

                        Text {
                            text: model.deviceName
                            font.bold: true
                            color: clickNotifier.clicked ? "#414141" : "white"  // 볼드체 흰색 글씨
                        }

                        Text {
                            text: "/"
                            color: clickNotifier.clicked ? "#414141" : "white"
                        }

                        Text {
                            text: model.deviceType  // 추가된 deviceType 표시
                            font.bold: true
                            color: clickNotifier.clicked ? "#414141" : "white"  // 일반 흰색 글씨
                        }
                    }
//                    MouseArea {
//                        anchors.fill: parent
//                        onClicked: {
//                            // 선택된 장치 이름을 전달하여 연결 시도
//                            btManager.connectToDevice(model.deviceName);
//                        }
//                    }
                }

                // 스크롤 동작을 최상단에 고정
                onContentYChanged: {
                    if (contentY < 0) {
                        contentY = 0;  // 스크롤을 최상단으로 고정
                    }
                }

                // 검색 상태에 따라 표시할 텍스트 관리
                Component.onCompleted: {
                    deviceModel.clear();  // 장치 목록 초기화
                }

                // 표시할 내용 제어 (검색 상태 및 장치 목록에 따라)
                Text {
                    id: n_o
                    anchors.top: parent.top  // 상단에 배치
                    anchors.horizontalCenter: parent.horizontalCenter  // 수평 가운데 정렬
                    anchors.topMargin: 10  // 상단 여백 설정 (필요에 따라 조정 가능)
                    color: clickNotifier.clicked ? "#414141" : "white"
                    font.pixelSize: 25
                    font.bold: true
                    text: {
                        if (isStopped) {
                            return "Off";  // 검색이 중지되면 "Off" 표시
                        } else if (isSearching && deviceModel.count === 0) {
                            return "None";  // 검색 중, 장치 없음
                        } else {
                            return ""; // 아무 값도 설정하지 않음 (빈 문자열 반환)
                        }
                    }
                    visible: deviceModel.count === 0  // 장치가 없을 때만 표시
                }
            }

            // 스크롤바 추가
            ScrollBar.vertical: ScrollBar {
                policy: ScrollBar.AsNeeded
            }
        }

//        Connections {
//            target: btManager

//            onDeviceDiscovered: function(deviceName, deviceType) {
//                deviceModel.append({"deviceName": deviceName, "deviceType": deviceType});
//            }

//            onDiscoveryFinished: {
//                console.log("Discovery finished.");
//                isSearching = false;  // 검색 상태 중지
//            }
//        }
    }

}
