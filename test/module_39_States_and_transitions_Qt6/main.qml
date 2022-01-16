import QtQuick 2.15


Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Make transition")

    Rectangle {
        id: scene
        anchors.fill: parent
        state: "LeftState"

        Rectangle {
            id: leftRectangle
            x: 50
            y: 200
            color: "lightgrey"
            width: 200
            height: 200
            border.color: "black"
            border.width: 3
            radius: 5

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    scene.color = 'red'
                    scene.state = "LeftState"
                }
                //onClicked: { scene.color = 'red'}
                //onClicked:  scene.state = "LeftState"
             }
        }
        Rectangle {
            id: rightRectangle
            x: 400
            y: 200
            color: "lightgrey"
            width: 200
            height: 200
            border.color: "black"
            border.width: 3
            radius: 5

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    scene.color = 'blue'
                    scene.state = "RightState"
                }
                //onClicked: { scene.color = 'blue' }
                //onClicked:  scene.state = "RightState"
             }
        }

        Rectangle {
            id: ball
            x: leftRectangle.x + 5
            y: leftRectangle.y + 5
            color: "darkgreen"
            width: leftRectangle.width - 10
            height: leftRectangle.height - 10
            border.color: "black"
            radius: width / 2
        }

        states: [
            State {
                name: "RightState"
                PropertyChanges {
                    target: ball
                    x: rightRectangle.x + 5
                }
            },
            State {
                name: "LeftState"
                PropertyChanges {
                    target: ball
                    x: leftRectangle.x + 5
                }
            }
        ]

        transitions: [
            Transition {
                from: "LeftState"
                to: "RightState"


                NumberAnimation {
                    properties: "x,y"
                    duration: 1000
                    easing.type: Easing.InOutExpo
                }
            },
            Transition {
                from: "RightState"
                to: "LeftState"

                NumberAnimation {
                    properties: "x,y"
                    duration: 1000
                    easing.type: Easing.OutBounce
                }
            }
        ]
    }
}
