import QtQuick 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Make transition")

    Rectangle {
        id: scene
        anchors.fill: parent
        state: "InitialState"

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
            Text {
                id: move_id
                anchors.centerIn: parent
                text: "move"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    ball.x += 30
                    if (ball.x > rightRectangle.x - rightRectangle.width / 2) // the edge of the circle moves to the center of the square
                    {
                        scene.state = "InitialState"
                    } else
                    {
                        scene.state = "OtherState"
                    }
                }
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
            Text {
                id: return_id
                anchors.centerIn: parent
                text: "return"
            }

            MouseArea {
                anchors.fill: parent
                onClicked: {
                    scene.state = "InitialState"
                }
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
                name: "InitialState"
                PropertyChanges {
                    target: ball
                    x: leftRectangle.x + 5
                }
            },
            State {
                name: "OtherState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            }
        ]

        transitions: [
            Transition {
                from: "OtherState"
                to: "InitialState"

                NumberAnimation {
                    properties: "x,y"
                    duration: 1000
                    easing.type: Easing.OutBounce
                }
            }
        ]
    }
}
