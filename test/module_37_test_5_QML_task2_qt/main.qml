import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Video player")
    Column {
        spacing: 2
        width: parent.width
        height: parent.height
        Rectangle {
            width: parent.width - 40
            height: parent.height - 80
            color: "black"
            anchors.horizontalCenter: parent.horizontalCenter
            Image {
                width: parent.width - 5
                height: parent.height - 50
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                source: "21stcenturyfox.png"
            }
        }

        Row {
            anchors.left: parent.left
            anchors.leftMargin: 20
            Button {
                id: play
                width: 50
                height: 50
                text: "▶️"
                font.pointSize: 24
                ToolTip.visible: hovered
                ToolTip.text: qsTr("Play")
            }
            Button {
                id: pause
                width: 50
                height: 50
                text: "⏸️"
                font.pointSize: 20
                ToolTip.visible: hovered
                ToolTip.text: qsTr("Pause")
            }
            Button {
                id: stop
                width: 50
                height: 50
                text: "⏹"
                font.pointSize: 20
                ToolTip.visible: hovered
                ToolTip.text: qsTr("Stop")
            }
            Button {
                id: rewind
                width: 50
                height: 50
                text: "⏪️"
                font.pointSize: 20
                ToolTip.visible: hovered
                ToolTip.text: qsTr("Rewind")
            }
            Button {
                id: forward
                width: 50
                height: 50
                text: "⏩️"
                font.pointSize: 20
                ToolTip.visible: hovered
                ToolTip.text: qsTr("Forward")
            }
        }
        ProgressBar {
            width: parent.width - 40
            height: 10
            anchors.horizontalCenter: parent.horizontalCenter
            value: 0.3
        }
    }
}
