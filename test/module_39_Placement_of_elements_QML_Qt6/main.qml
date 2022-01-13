import QtQuick
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
    id: main
    width: 640
    height: 480
    visible: true
    Column {
        id: mainElements
        anchors.fill: parent
        spacing: 10
        Row {
            spacing: 5
            width: parent.width - 20
            SpinBox {
                id: spacingSpinBox
                onValueChanged: {
                    mainElements.spacing = value
                }
            }
            ComboBox {
                id: currentColor
                width: parent.width * 2/3
                model: ["red", "yellow", "green"]
            }
            CheckBox {
                id: hasBorder
                onCheckStateChanged: {
                    if(checkState == Qt.Checked)
                    {
                        colorBox.border.width = 10
                    }
                    else
                    {
                        colorBox.border.width = 0
                    }
                }
            }
            Button {
                text: "quit"
                onClicked: Qt.quit()
            }
        }
        Rectangle {
            id: colorBox
            width: parent.width - 20
            height: parent.height - 40
            color: currentColor.currentText
            border.width: 0
            border.color: "black"
        }
    }
    //title: qsTr("Hello World")
}
