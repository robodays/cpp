import QtQuick 2.6
import QtQuick.Window 2.11

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")


    FibonacciScreen{
        anchors.fill: parent
    }

}
