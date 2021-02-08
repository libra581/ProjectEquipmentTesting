import QtQuick 2.9
import QtQuick.Layouts 1.0

Item {
    id: itemGroupMode
    width: 166
    height: 21
    Rectangle {
        id: lineBetweenBasisReserve
        x: 100
        y: 3
        width: 1
        height: 15
        color: "#c4c4c4"
        radius: 0
    }
    
    Rectangle {
        id: rightRectReserve
        x: 156
        y: 0
        width: 10
        height: 21
        color: "#c4c4c4"
        radius: 0
    }
    
    Rectangle {
        id: leftRectBasis
        x: 0
        y: 0
        width: 10
        height: 21
        color: "#c4c4c4"
        radius: 0
    }
    
    Rectangle {
        id: reserve
        x: 106
        y: 0
        width: 60
        height: 21
        color: "#c4c4c4"
        radius: 5
        
        Text {
            id: textReserve
            x: -100
            y: 4
            text: qsTr(text_reserve)
            anchors.left: parent.left
            anchors.leftMargin: 6
            font.pixelSize: 10
            font.family: itemSettings.webFontName
        }

        MouseArea {
            id: mouseAreaReserve
            x: 1
            y: 0
            width: 59
            height: 21

            onClicked: itemGroupMode.state = "reserve"
        }
    }
    
    Rectangle {
        id: basis
        x: 0
        y: 0
        width: 94
        height: 21
        color: "#c4c4c4"
        radius: 5
        
        Text {
            id: textBasis
            x: 128
            y: 4
            text: qsTr(text_basis)
            anchors.right: parent.right
            anchors.rightMargin: 5
            font.pixelSize: 10
            font.family: itemSettings.webFontName
        }

        MouseArea {
            id: mouseAreaBasis
            x: 0
            y: 0
            width: 94
            height: 21

            anchors.fill: parent

            onClicked: itemGroupMode.state = "basis"
        }
    }

    state: "basis"

    //Состояния корневой формы блока
    //Включает в себя 2 состояния WidgetBlock: открыть, закрыть.
    states: [
        State {
            name: "basis"
            PropertyChanges {
                id: animWidthBasisOn
                target: basis
                width: 94
            }

            PropertyChanges {
                id: animWidthReserveOff
                target: reserve
                width: 60
            }

            PropertyChanges {
                id: animXReserveOff
                target: reserve
                x: 106
            }

            PropertyChanges {
                id: animLineOn
                target: lineBetweenBasisReserve
                x: 100
            }

        },

        State {
            name: "reserve"
            PropertyChanges {
                id: animWidthBasisOff
                target: basis
                width: 60
            }

            PropertyChanges {
                id: animWidthReserveOn
                target: reserve
                width: 90
            }

            PropertyChanges {
                id: animXReserveOn
                target: reserve
                x: 74
            }

            PropertyChanges {
                id: animLineOff
                target: lineBetweenBasisReserve
                x: 66
            }
        }
    ]
    

    transitions: [
        Transition {

            PropertyAnimation {
                target: basis
                duration: 500
                property: "width"
                easing.type: Easing.InQuad
                easing.amplitude: 2.0
                easing.period: 1.5
            }

            PropertyAnimation {
                target: reserve
                duration: 500
                property: "x"
                easing.type: Easing.InQuad
                easing.amplitude: 2.0
                easing.period: 1.5
            }
            PropertyAnimation {
                target: reserve
                duration: 500
                property: "width"
                easing.type: Easing.InQuad
                easing.amplitude: 2.0
                easing.period: 1.5
            }

            PropertyAnimation {
                target: lineBetweenBasisReserve
                duration: 500
                property: "x"
                easing.type: Easing.InQuad
                easing.amplitude: 2.0
                easing.period: 1.5
            }
        }
    ]

}
