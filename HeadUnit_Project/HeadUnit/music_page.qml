import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12

Window{
    id: music_window
    visible: true
    width: 618
    height: 480
    color: "transparent"
    flags: Qt.FramelessWindowHint
    Connections{
        target: musicPlayer
        onNextSongInfo:{
            console.log("Title: " + title);
            console.log("Artist: " + artist);
            console.log("Cover Path: " + coverPath);
            song_title.text = title;
            singer.text = artist;
            album_cover.source = coverPath;
        }

        onMusicProgressChanged: {
            //                console.log(musicPlayer.music_position());
            //                console.log(musicPlayer.music_duration());
            music_progress_fill.width = (parseFloat(musicPlayer.music_position() / musicPlayer.music_duration()) * music_progress_bar.width)
            music_start.text = formatTime(musicPlayer.music_position())
            music_end.text = formatTime(musicPlayer.music_duration())
        }
    }

    Image {
        id: base_window
        fillMode: Image.PreserveAspectFit
        anchors.fill: parent
        source: "HU_Assets/Background/basic_window.png"

        Image {
            id: music_bar
            x: 15
            y: 12
            fillMode: Image.PreserveAspectFit
            source: "HU_Assets/Background/music_bar.png"


            Rectangle {
                id: music
                x: 27
                y: 22
                width: 101
                height: 30
                color: "transparent"

                Image {
                    id: music_icon
                    width: 28
                    source: "HU_Assets/Icons/music.png"
                    fillMode: Image.PreserveAspectFit
                    anchors{
                        verticalCenter: music.verticalCenter
                        left: music.left
                    }
                }

                Text {
                    id: music_text
                    x: 40
                    y: 2
                    width: 61
                    height: 22
                    text: qsTr("Music")
                    font.pixelSize: 20
                    color: "#ffffff"
                    anchors{
                        verticalCenter: music.verticalCenter
                        right: music.right
                    }
                }
            }

            Text {
                id: now_playing
                y: 68
                anchors.horizontalCenter: music_bar.horizontalCenter
                text: "Now Playing"
                anchors.horizontalCenterOffset: 0
                font.pixelSize: 17
                color: "#B0B0B0"
            }

            Image {
                id: album_cover
                y: 96
                anchors.horizontalCenter: music_bar.horizontalCenter
                width: 175
                height: 175
                anchors.horizontalCenterOffset: 0
                fillMode: Image.PreserveAspectFit
                source: musicPlayer.getCoverForSong(songTitle)
            }

            Text {
                id: song_title
                anchors.horizontalCenter: music_bar.horizontalCenter
                y: 285
                text: musicPlayer.getTitleForSong(songTitle)
                anchors.horizontalCenterOffset: 0
                font.pixelSize: 18
                color: "#ffffff"
            }

            Text {
                id: singer
                anchors.horizontalCenter: music_bar.horizontalCenter
                y: 312
                text: musicPlayer.getArtistForSong(songTitle)
                anchors.horizontalCenterOffset: 0
                font.pixelSize: 16
                color: "#B0B0B0"
            }

            Row{
                id: music_menu
                anchors.horizontalCenter: music_bar.horizontalCenter
                y: 349
                spacing: 17

                Image {
                    id: skip_back
                    anchors.verticalCenter: music_menu.verticalCenter
                    fillMode: Image.PreserveAspectFit
                    source: "HU_Assets/Components/Music/skip_back.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            musicPlayer.skipPrevious();
                            play_button.visible = false;
                            stop_button.visible = true;
                        }
                    }
                }

                Image {
                    id: skip_back2
                    anchors.verticalCenter: music_menu.verticalCenter
                    fillMode: Image.PreserveAspectFit
                    source: "HU_Assets/Components/Music/skip_back2.png"
                }

                Image {
                    id: music_button
                    anchors.verticalCenter: music_menu.verticalCenter
                    fillMode: Image.PreserveAspectFit
                    source: "HU_Assets/Components/Music/music_button_ring.png"
                    Component.onCompleted: {
                        musicPath = musicPlayer.getPathForSong(songTitle);
                        console.log("file path : " + musicPath);
                        ////////////////////////////////////////////////////////////////////////////
//                        var musicFiles = musicPlayer.getCurrentPlayList(songTitle);
//                        console.log(musicFiles.length);
//                        for (var i = 0; i < musicFiles.length; i++){
//                            console.log("playlist " + musicPlayer.getTitleForSong(musicFiles[i]));
//                        }

                        musicPlayer.setMusic(musicPath)
                    }

                    Image {
                        id: play_button
                        anchors.verticalCenterOffset: 1
                        anchors.horizontalCenterOffset: 1
                        anchors{
                            verticalCenter: music_button.verticalCenter
                            horizontalCenter: music_button.horizontalCenter
                        }
                        fillMode: Image.PreserveAspectFit
                        source: "HU_Assets/Components/Music/play.png"
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                console.log("play button")
                                musicPlayer.playMusic(musicPath);
                                play_button.visible = false;
                                stop_button.visible = true;
                                console.log("Current play state: " + musicPlayer.playState());
                            }
                        }
                    }
                    Image {
                        id: stop_button
                        anchors.verticalCenterOffset: 0
                        anchors.horizontalCenterOffset: 1
                        anchors.centerIn: music_button
                        fillMode: Image.PreserveAspectFit
                        source: "HU_Assets/Components/Music/stop.png"
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                console.log("stop button")
                                musicPlayer.pauseMusic();
                                stop_button.visible = false;
                                play_button.visible = true;
                                console.log("Current play state: " + musicPlayer.playState());
                            }
                        }
                    }
                }

                Image {
                    id: skip_front2
                    anchors.verticalCenter: music_menu.verticalCenter
                    fillMode: Image.PreserveAspectFit
                    source: "HU_Assets/Components/Music/skip_front2.png"
                }

                Image {
                    id: skip_front
                    anchors.verticalCenter: music_menu.verticalCenter
                    fillMode: Image.PreserveAspectFit
                    source: "HU_Assets/Components/Music/skip_front.png"
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            musicPlayer.skipNext();
                            play_button.visible = false;
                            stop_button.visible = true;
                        }
                    }
                }
                Component.onCompleted: {
                    //                musicPlayer.playMusic(musicPlayer.getPathForSong(songTitle));
                    play_button.visible = true;
                    stop_button.visible = false;
                }
            }

            Rectangle {
                id: music_progress_bar
                anchors.horizontalCenter: music_bar.horizontalCenter
                y: 412
                width: 194
                height: 5
                radius: 3
                color: "#87888C"
            }
            Rectangle {
                id: music_progress_fill
                width: (musicPlayer.music_position() / musicPlayer.music_duration()) * music_progress_bar.width
                height: music_progress_bar.height
                anchors{
                    left: music_progress_bar.left
                    verticalCenter: music_progress_bar.verticalCenter
                }
                radius: 3
                color: "#58C7A4"
            }

            Text {
                id: music_start
                x: 40
                y: 391
                text: formatTime(musicPlayer.music_position()) // "0:00"
                color: "#828282"
                font.pixelSize: 12
            }
            Text {
                id: music_end
                x: 208
                y: 391
                text: formatTime(musicPlayer.music_duration())
                color: "#828282"
                font.pixelSize: 12
            }

//            Connections {
//                target: musicPlayer
//                onMusicProgressChanged: {
//    //                console.log(musicPlayer.music_position());
//    //                console.log(musicPlayer.music_duration());
//                    music_progress_fill.width = (parseFloat(musicPlayer.music_position() / musicPlayer.music_duration()) * music_progress_bar.width)
//                    music_start.text = formatTime(musicPlayer.music_position())
//                    music_end.text = formatTime(musicPlayer.music_duration())
//                }
//            }
        }

        Rectangle {
            id: track
            x: 318
            y: 101
            width: 260
            height: 350
            color: "transparent"

            Text {
                id: playing_next
                text: "Playing Next"
                font.pixelSize: 15
                color: "#CBC8C8"
            }

            ListView{
                id: musicplayList
                width: track.width
                height: track.height - 20
                anchors.bottom: track.bottom
                clip: true
                model: ListModel{
                    Component.onCompleted: {
                        var musicFilesList = musicPlayer.getMusics(); // musicPlayer.getCurrentPlayList(songTitle);
                        for (var i = 0; i < musicFilesList.length; i++){
                            var music_f = musicFilesList[i];
                            var title = musicPlayer.getTitleForSong(music_f);
                            var singer = musicPlayer.getArtistForSong(music_f);
                            var cover_path = musicPlayer.getCoverForSong(music_f);
                            var mp3_path = musicPlayer.getPathForSong(music_f)
//                            console.log("title : " + title + " , singer : " + singer + " , cover_path : " + cover_path);
                            append({
                                title: title,
                                singer: singer,
                                cover_path: cover_path,
                                mp3_path: mp3_path,
                            });
                        }
                    }
                }
                delegate: ItemDelegate{
//                    text: model.title + " - " + model.singer
                    id: playlist_item
                    width: musicplayList.width
                    height: 65

                    Image {
                        id: song_cover
                        source: model.cover_path
                        width: 53
                        height: 53
                        anchors.verticalCenter: playlist_item.verticalCenter
                    }
                    Text {
                        id: song_titlename
                        text: model.title
                        font.pixelSize: 16
                        anchors{
                            left: song_cover.right
                            leftMargin: 15
                        }
                        y: 10
                        color: "#ffffff"
                    }
                    Text {
                        id: singer_name
                        text: model.singer
                        font.pixelSize: 13
                        anchors{
                            left: song_cover.right
                            leftMargin: 15
                        }
                        y: 30
                        color: "#CBC8C8"
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            console.log("clicked song title : " + model.title + " , singer : " + model.singer + " , cover path : " + model.cover_path + " , mp3_path : " + model.mp3_path)
                            musicPlayer.setMusic(model.mp3_path);
                            musicPlayer.playMusic(model.mp3_path);
                            album_cover.source = model.cover_path;
                            song_titlename.text = model.title;
                            singer.text = model.singer;
                            play_button.visible = false;
                            stop_button.visible = true;
                        }
                    }
                }

                ScrollBar.vertical: ScrollBar{
                    policy: ScrollBar.AlwaysOn
                }
            }
        }

        Text {
            id: track_list
            x: 318
            y: 30
            text: "Track List"
            font.pixelSize: 25
            color: "#ffffff"
        }

        Image {
            id: sequential_icon
            x: 349
            y: 65
            fillMode: Image.PreserveAspectFit
            source: "HU_Assets/Components/Music/sequential.png"
        }

        Image {
            id: shuffle_icon
            x: 318
            y: 65
            fillMode: Image.PreserveAspectFit
            source: "HU_Assets/Components/Music/shuffle.png"
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
                music_window.visible = false;
                icon_line.x = 138;
            }
        }
    }
}
