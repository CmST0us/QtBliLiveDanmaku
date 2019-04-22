import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

Window {
    id: danmaku_screen
    visible: true
    width: 640
    height: 480
    title: qsTr("DanmakuScreen")

    ListView {
        id: listView
        anchors.leftMargin: 106
        anchors.fill: parent
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                spacing: 10
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: name
                    anchors.verticalCenter: parent.verticalCenter
                    font.bold: true
                }
            }
        }
    }

    TextEdit {
        id: textEdit
        y: 422
        width: 70
        height: 20
        text: qsTr("524")
        anchors.left: parent.left
        anchors.leftMargin: 16
        anchors.bottom: button.top
        anchors.bottomMargin: 6
        horizontalAlignment: Text.AlignHCenter
        textFormat: Text.PlainText
        font.family: "Times New Roman"
        font.capitalization: Font.MixedCase
        font.pixelSize: 11
    }

    Text {
        id: live_room_id_label
        y: 397
        width: 60
        height: 19
        text: "Live_Room"
        anchors.bottom: textEdit.top
        anchors.bottomMargin: 6
        anchors.left: parent.left
        anchors.leftMargin: 20
        font.family: "Arial"
        textFormat: Text.PlainText
        font.pixelSize: 12
    }

    Button {
        id: button
        y: 448
        width: 100
        height: 32
        text: qsTr("Connect")
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        onClicked: {
            danmakuScreen.connectLiveRoom(Number(textEdit.text))
        }
    }

}






/*##^## Designer {
    D{i:1;anchors_height:480;anchors_width:538;anchors_x:102;anchors_y:0}D{i:11;anchors_x:16}
D{i:12;anchors_height:19;anchors_x:20;anchors_y:397}D{i:13;anchors_x:0}
}
 ##^##*/
