import QtQuick 2.9
import QtQuick.Layouts 1.0
import "keeperTablesInfo.js" as GeneratorTables

Rectangle {
    id: rectTable

    property string text_title: "Text Text Text Text Text Text Text"

    anchors.horizontalCenter: parent.horizontalCenter
    anchors.horizontalCenterOffset: -10

    color: "#c4c4c4"
    height: 33
    radius: 10
    width: 147

    Connections {
        target: parent.parent.parent

        onRootWidgetStatusChanged: {
            console.log("!!!!!!!!!!! - > " + status)
        }
    }

    Layout.alignment: Qt.AlignHCenter | Qt.AlignTop

    Text {
        id: textRectTable
        text: qsTr(text_title)
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        z: 1
        elide: Text.ElideNone
        fontSizeMode: Text.FixedSize
        anchors.fill: parent
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 12
    }

    Rectangle {
        id: leftAngleRect
        x: 0
        y: 0
        width: 15
        height: 16
        color: "#c4c4c4"
        radius: 0
    }

    MouseArea {
        id: msAreaTable
        x: 0
        y: 0
        width: 147
        height: 33
    }

    Rectangle {
        id: circleStatus
        x: 156
        y: 12
        width: 10
        height: 10
        color: "#ffffff"
        radius: 5

        Item {

            id: itemError
            visible: true
            anchors.centerIn: parent

            Rectangle {
                id: rectangle
                x: -1
                y: -4
                width: 2
                height: 8
                color: "white"
                rotation: 45
            }

            Rectangle {
                id: rectangle1
                x: -1
                y: -4
                width: 2
                height: 8
                color: "white"
                rotation: -45
            }
        }

        Item {

            id: itemCorrect
            visible: true
            anchors.centerIn: parent

            Rectangle {
                id: rectangle2
                x: 0
                y: -3
                width: 2
                height: 7
                color: "white"
                rotation: 30
            }

            Rectangle {
                id: rectangle3
                x: -3
                y: 0
                width: 2
                height: 4
                color: "white"
                rotation: -60
            }
        }

        Item {

            id: itemWait
            x: -82
            y: 5
            visible: false
            anchors.centerIn: parent

            Rectangle {
                id: rectangle4
                x: -3
                y: -3
                width: 6
                height: 6
                color: "orange"
                radius: 4
                border.width: 1
            }
        }
    }

    state: "notInformation"

    states: [
        State {
            name: "correct"
            PropertyChanges {
                target: circleStatus
                color: "green"
            }
            PropertyChanges {
                target: itemCorrect
                visible: true
            }
            PropertyChanges {
                target: itemError
                visible: false
            }
            PropertyChanges {
                target: itemWait
                visible: false
            }
        },

        State {
            name: "error"
            PropertyChanges {
                target: circleStatus
                color: "red"
            }
            PropertyChanges {
                target: itemCorrect
                visible: false
            }
            PropertyChanges {
                target: itemError
                visible: true
            }
            PropertyChanges {
                target: itemWait
                visible: false
            }
        },

        State {
            name: "notInformation"
            PropertyChanges {
                target: circleStatus
                color: "gray"
            }
            PropertyChanges {
                target: itemCorrect
                visible: false
            }
            PropertyChanges {
                target: itemError
                visible: false
            }
            PropertyChanges {
                target: itemWait
                visible: false
            }
        },

        State {
            name: "wait"
            PropertyChanges {
                target: circleStatus
                color: "orange"
            }
            PropertyChanges {
                target: itemCorrect
                visible: false
            }
            PropertyChanges {
                target: itemError
                visible: false
            }
            PropertyChanges {
                target: itemWait
                visible: true
            }
        }
    ]
}

/*##^##
Designer {
    D{i:0;formeditorZoom:16}
}
##^##*/

