import QtQuick 2.12
import QtQuick.Window 2.12
import QtMultimedia 5.12

Window{
    id: media_window
    visible: true
    width: 618
    height: 480
    color: "transparent"
    flags: Qt.FramelessWindowHint

    onVisibleChanged: {
        if(visible){
            media_window.x = main_window.x + 393;
            media_window.y = main_window.y + 40;
        }
    }

    Image {
        id: base_window
        fillMode: Image.PreserveAspectFit
        anchors.fill: parent
        source: "HU_Assets/Background/basic_window.png"

        //        Rectangle {
        //            id: media
        //            x: 27
        //            y: 22
        //            width: 101
        //            height: 30
        //            color: "transparent"

        //            Image {
        //                id: media_icon
        //                width: 28
        //                source: "HU_Assets/Icons/media.png"
        //                fillMode: Image.PreserveAspectFit
        //                anchors{
        //                    verticalCenter: media.verticalCenter
        //                    left: media.left
        //                }
        //            }
        //            Text {
        //                id: media_text
        //                x: 47
        //                width: 61
        //                height: 22
        //                text: qsTr("Media")
        //                font.pixelSize: 20
        //                color: "#ffffff"
        //                anchors{
        //                    verticalCenter: media.verticalCenter
        //                    right: media.right
        //                }
        //            }
        //        }

        Rectangle {
            id: library
            x: 27
            y: 33
            width: 164
            height: 30
            color: "transparent"

            Image {
                id: library_icon
                width: 28
                source: "HU_Assets/Icons/library.png"
                fillMode: Image.PreserveAspectFit
                anchors{
                    verticalCenter: library.verticalCenter
                    left: library.left
                }
            }
            Text {
                id: library_text
                x: 47
                width: 131
                height: 22
                text: qsTr("Your Library")
                font.pixelSize: 23
                color: "#ffffff"
                anchors{
                    verticalCenter: library.verticalCenter
                    right: library.right
                    bottom: library.bottom
                }
            }
        }

        Rectangle {
            id: base_line
            x: 33
            y: 76
            width: 565
            height: 2
            color: "#424343"
        }

        Grid {
            id: video_grid
            x: 36
            y: 93
            width: 560
            height: 361
            spacing: 20
            rows: 2
            columns: 2

            Rectangle {
                id: video_1
                width: 270
                height: 170
                color: "transparent"

                Image {
                    id: video1_thumbnail
                    width: 270
                    height: 135
                    source: "Thumbnail/Pomeranian_Grooming_Teddy_bear_style.png"
                    fillMode: Image.Stretch
                }
                Text {
                    id: video1_title
                    text: qsTr("Pomeranian Grooming Teddy bear style")
                    color: "#ffffff"
                    font.pixelSize: 13
                    anchors{
                        bottom: video_1.bottom
                        bottomMargin: 16
                    }
                }
                Text {
                    id: video1_channel
                    text: qsTr("SHU AND TREE")
                    color: "#CBC8C8"
                    font.pixelSize: 11
                    anchors{
                        bottom: video_1.bottom
                    }
                }

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        video_player.source = "file:///home/llj/catkin_ws/src/video_player_test/SHU_AND_TREE.mp4";
                        video_player.visible = true;
                        video_player.play();
                        video_controls.visible = true;
                        base_window.visible = false;
                    }
                }
            }

            Rectangle {
                id: video_2
                width: 270
                height: 170
                color: "#00000000"
                Image {
                    id: video2_thumbnail
                    width: 270
                    height: 135
                    source: "Thumbnail/Once_upon_a_time_there_was_one_cutest_kitten.png"
                    fillMode: Image.Stretch
                }

                Text {
                    id: video2_title
                    color: "#ffffff"
                    text: qsTr("Once upon a time there was one cutest kitten")
                    anchors.bottomMargin: 16
                    font.pixelSize: 13
                    anchors.bottom: video_2.bottom
                }

                Text {
                    id: video2_channel
                    color: "#cbc8c8"
                    text: qsTr("Teddy Kittens")
                    font.pixelSize: 11
                    anchors.bottom: video_2.bottom
                }
            }

            Rectangle {
                id: video_3
                width: 270
                height: 170
                color: "#00000000"
                Image {
                    id: video3_thumbnail
                    width: 270
                    height: 135
                    source: "Thumbnail/World_premiere-The_all_new_Tayron.png"
                    fillMode: Image.Stretch
                }

                Text {
                    id: video3_title
                    color: "#ffffff"
                    text: qsTr("World_premiere-The_all_new_Tayron")
                    anchors.bottomMargin: 16
                    font.pixelSize: 13
                    anchors.bottom: video_3.bottom
                }

                Text {
                    id: video3_channel
                    color: "#cbc8c8"
                    text: qsTr("Volkswagen")
                    font.pixelSize: 11
                    anchors.bottom: video_3.bottom
                }
            }
        }
    }

    Video{
        id: video_player
        visible: false
        width: 600
        height: 480
        anchors.centerIn: parent
        source: ""
        autoPlay: false

        onPlaying: {
            video_controls.visible = true;
        }

        onPaused: {
            video_controls.visible = true;
        }
    }

    Rectangle{
        id: video_controls
        width: 600
        height: 50
        color: "black"
        anchors.bottom: video_player.bottom
        anchors.horizontalCenter: video_player.horizontalCenter
        visible: false

        Row{
            spacing: 10
            anchors.centerIn: parent

            Image {
//                    source: video_player.playbackState === Video.PlayingState ? "HU_Assets/Icons/pause.png" : "HU_Assets/Icons/play.png"
                source: "HU_Assets/Components/Music/play.png"
                width: 30
                height: 30
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        if (video_player.playbackState === Video.PlayingState) {
                            video_player.pause();
                        } else {
                            video_player.play();
                        }
                    }
                }
            }

            Image {
                source: "HU_Assets/Components/Music/skip_back2.png"
                width: 30
                height: 30
                MouseArea {
                    anchors.fill: parent
//                        onClicked: {
//                            // Logic for skipping to the previous video
//                            video_player.source = "Videos/Pomeranian_Grooming.mp4";
//                            video_player.play();
//                        }
                }
            }

            Image {
                source: "HU_Assets/Components/Music/skip_front2.png"
                width: 30
                height: 30
                MouseArea {
                    anchors.fill: parent
//                        onClicked: {
//                            // Logic for skipping to the next video
//                            video_player.source = "Videos/Next_Video.mp4";
//                            video_player.play();
//                        }
                }
            }

//                Image {
//                    source: ""
//                    width: 30
//                    height: 30
//                    MouseArea {
//                        anchors.fill: parent
//                        onClicked: {
//                            media_window.showFullScreen();
//                        }
//                    }
//                }

//                Slider {
//                    id: volume_slider
//                    width: 100
//                    from: 0
//                    to: 1
//                    value: video_player.volume
//                    onValueChanged: video_player.volume = value
//                }

            Image {
                source: "HU_Assets/Components/Video/screen_off.png"
                width: 30
                height: 30
                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        video_player.stop();
                        video_controls.visible = false;
                    }
                }
            }
        }
    }

    Image {
        id: window_close_button
        x: 550
        y: 20
        width: 50
        height: 50
        fillMode: Image.PreserveAspectFit
        source: "HU_Assets/Icons/tap_close_button.png"

        MouseArea{
            anchors.fill: parent
            onClicked: {
                media_window.visible = false;
                icon_line.x = 138;
            }
        }
    }

}

/*##^##
Designer {
    D{i:6;anchors_y:98}
}
##^##*/
