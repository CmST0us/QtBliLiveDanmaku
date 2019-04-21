import QtQuick 2.12
import QtQuick.Window 2.12
Window {
    id: danmaku_window
    visible: true
    width: 640
    height: 480
    property alias danmaku_window: danmaku_window
    title: qsTr("DanmakuScreen")

    Connections {
        target: danmaku_window
        onAfterRendering: {
            myClass.onViewDidLoad()
        }
    }

}
