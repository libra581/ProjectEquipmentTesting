import QtQuick 2.4

Rectangle {

    //color: 'teal'
    //Layout.fillWidth: true
    id: rectRoot
    property string textLabel: "Text"
    property bool disabledToolTip: false
    color: "#00ffffff"
    z: 0

    Text {
        id: text1
        text: textLabel
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.centerIn: parent

        Item {
            id: itemInfo
            x: 20
            y: -3
            width: 69
            height: 20
            visible: true
            anchors.right: parent.right
            anchors.rightMargin: -68
            opacity: 0.0

            Rectangle {
                id: rectTriangle
                x: 6
                y: 5
                width: 10
                height: 10
                color: "#f5a70e"
                border.color: "#060303"
                rotation: 45
            }

            Rectangle {
                id: rectInfo
                x: 11
                y: -5
                width: 79
                height: 30
                color: "#f5a70e"
                border.color: "#060303"

                Rectangle {
                    id: rectTriangle1
                    x: -3
                    y: 10
                    width: 8
                    height: 9
                    color: "#f5a70e"
                    rotation: 45
                    border.color: "#00060303"
                }
                Text {
                    id: text2
                    x: 3
                    y: 8
                    text: qsTr("Информация")
                    anchors.verticalCenter: parent.verticalCenter
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    font.pixelSize: 12
                }
            }
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        onEntered: itemInfo.opacity = 1.0

        onExited: itemInfo.opacity = 0.0
    }

    Component.onCompleted:
    {
        if(rectRoot.disabledToolTip)
          mouseArea.visible = false
    }
}
