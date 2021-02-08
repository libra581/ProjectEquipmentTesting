import QtQuick 2.4

Item {
    id: rootItem

    width: 40
    height: 20

    property alias rectBackGrnd: rectBackGrnd
    property bool typeMode: true

    Rectangle {
        id: rectBackGrnd
        x: 0
        width: 20
        color: "#ffffff"
        radius: 5
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.top: parent.top
        border.color: "#2e2c2c"
        border.width: 1

        Text {
            id: text1
            width: 20
            text: qsTr((typeMode) ? "O" : "Р")
            anchors.bottomMargin: 1
            anchors.rightMargin: 0
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 10
        }
    }
}
