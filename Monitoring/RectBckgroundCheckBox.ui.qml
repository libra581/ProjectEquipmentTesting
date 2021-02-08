import QtQuick 2.4
import QtGraphicalEffects 1.0

Rectangle {
    id: rectBckgroundCheckBox
    color: "#cdcdcd"
    height: 33
    width: 111

    property string text_title: "Text"
    signal checkChange(string textTitle, string stateCheckBox)
    property alias mouseArea: mouseAreaCheck

    Rectangle {
        id: rectBtnCheck
        x: 16
        y: 6
        width: 20
        height: 20
        color: "#ffffff"
        radius: 4

        Item {
            id: itemGroupArrow
            visible: false
            anchors.fill: parent

            Rectangle {
                id: rectArrowRight
                x: 11
                y: 4
                width: 2
                height: 12
                color: "#000000"
                rotation: 45
                z: 1
            }

            Rectangle {
                id: rectArrowLeft
                x: 6
                y: 9
                width: 2
                height: 6
                color: "#000000"
                rotation: -45
                z: 1
            }
        }

        MouseArea {
            id: mouseAreaCheck
            anchors.fill: parent

            onClicked:
            {
                (rectBckgroundCheckBox.state
                        === "uncheck") ? rectBckgroundCheckBox.state
                                         = "check" : rectBckgroundCheckBox.state = "uncheck"

                rectBckgroundCheckBox.checkChange( rectBckgroundCheckBox.text_title, rectBckgroundCheckBox.state )
            }
        }
    }

    Text {
        id: textTitleCheckBox
        x: 68
        y: 7
        text: qsTr(text_title)
        verticalAlignment: Text.AlignBottom
        horizontalAlignment: Text.AlignRight
        anchors.right: parent.right
        anchors.rightMargin: 16
        font.pixelSize: 14
        font.family: itemSettings.webFontLightName
    }

    state: "uncheck"

    //Состояния корневой формы блока
    //Включает в себя 2 состояния WidgetBlock: открыть, закрыть.
    states: [
        State {
            name: "check"
            PropertyChanges {
                id: animRectArrowAppear
                target: itemGroupArrow
                visible: true
            }
        },

        State {
            name: "uncheck"
            PropertyChanges {
                id: animRectArrowHide
                target: itemGroupArrow
                visible: false
            }
        }
    ]
}
