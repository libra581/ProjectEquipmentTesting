import QtQuick 2.9
import QtQuick.Layouts 1.3

import "keeperTablesInfo.js" as GeneratorTables
import "creatorItemsTables.js" as GeneratorWidgetsTables
import "creatorWidgetBlock.js" as GeneratorWidgetsBlock

Item {
    id: itemRoot
    width: 200
    height: 300
    z: 0

    ItemCodeExec
    {
        id: codeExec
    }

    readonly property variant colorsStatus: GeneratorWidgetsBlock.getArrayStatus()
    property string status: GeneratorWidgetsBlock.getStatusNotInformation(
                                ) //"NOT_INFORMATION"
    property int codeExecute: 0

    signal rootWidgetStatusChanged(string status)
    onStatusChanged:
    {
        console.log(status, codeExecute)
        switch(itemRoot.codeExecute)
        {
            case codeExec.serverCodeExec.iSCyclegramma:
                itemRoot.arrayOfRows[0].state = "wait"
                break;

            case codeExec.serverCodeExec.iSInputData:
                itemRoot.arrayOfRows[1].state = "wait"
                break;

            case codeExec.serverCodeExec.iSAnalyze:
                itemRoot.arrayOfRows[2].state = "wait"
                break;

            case codeExec.serverCodeExec.iFCyclegramma:
                itemRoot.arrayOfRows[0].state = "correct"
                break;

            case codeExec.serverCodeExec.iFInputData:
                itemRoot.arrayOfRows[1].state = "correct"
                break;

            case codeExec.serverCodeExec.iFAnalyze:
                itemRoot.arrayOfRows[2].state = "correct"
                break;

            case codeExec.serverCodeExec.iEFCyclegramma:
                itemRoot.arrayOfRows[0].state = "error"
                break;

            case codeExec.serverCodeExec.iEFInputData:
                itemRoot.arrayOfRows[1].state = "error"
                break;

            case codeExec.serverCodeExec.iEFAnalyze:
                itemRoot.arrayOfRows[2].state = "error"
                break;
        }
    }

    property string text_title: ""

    readonly property string text_basis: "Основа"
    readonly property string text_reserve: "Резерв"

    readonly property int startHeightOfBackGrnd: 48 //Синглтон????
    property variant tablesNames: GeneratorTables.createArrayTables(
                                      text_title) //Создание таблиц взависимости от типа
    property int countTable: tablesNames.length
    property int heightColumnLayoutWithTables: countTable * 50 + startHeightOfBackGrnd //Вычисляем высоту бэкграунда item по количеству таблиц
    property int backHeightOfCountTables: heightColumnLayoutWithTables + 40

    Rectangle {
        id: centerRect
        x: 14
        y: 16
        width: 147
        height: 33
        color: "#c4c4c4"
        anchors.horizontalCenterOffset: -10
        anchors.horizontalCenter: parent.horizontalCenter

        Text {
            id: text1
            text: qsTr(text_title)
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            font.pixelSize: 12
            font.family: itemSettings.webFontName
        }
    }

    Rectangle {
        id: rightBtn
        x: 167
        y: 16
        width: 13
        height: 33
        color: "#c4c4c4"
        anchors.horizontalCenterOffset: 76
        anchors.horizontalCenter: parent.horizontalCenter

        Rectangle {
            id: rectangleAngle
            x: 2
            y: 12
            width: 9
            height: 9
            color: "#c4c4c4"

            Canvas {
                anchors.fill: parent

                onPaint: {
                    var context = getContext("2d")

                    context.beginPath()
                    context.moveTo(0, 3)
                    context.lineTo(9, 3)
                    context.lineTo(4.5, 9)
                    context.closePath()

                    context.fillStyle = "#FFFFFF"
                    context.fill()
                }
            }
        }

        MouseArea {
            id: mouseAreaRightBtn
            z: 2
            anchors.fill: parent
        }
    }

    Rectangle {
        id: backgroundRect
        x: 8
        y: 8
        width: 179
        height: 48
        color: colorsStatus[status] //"#80c5c5c5"
        anchors.horizontalCenterOffset: -1
        anchors.horizontalCenter: parent.horizontalCenter
        z: -1
        opacity: 0.4
    }

    Connections {
        target: mouseAreaRightBtn
        onClicked: {
            itemRoot.state == "pass" ? itemRoot.state = "return" : itemRoot.state = "pass"
        }
    }

    property variant arrayOfRows: []

    Item {
        id: itemContent
        x: 0
        y: 55
        width: 200
        height: 245
        anchors.horizontalCenter: parent.horizontalCenter

        opacity: 1

        ColumnLayout {
            id: columnLayoutTables
            x: 16
            y: 39
            width: 166
            height: heightColumnLayoutWithTables
            spacing: -35

            Component.onCompleted: {
                console.log(countTable)
                for (var i = 0; i < itemRoot.countTable; ++i) {
                    arrayOfRows.push(GeneratorWidgetsTables.createSpriteObjects(
                                itemRoot.tablesNames[i]))
                }
            }

        }

        ItemGroupMode {
            id: itemGroupMode
            height: 21
            width: 166
            x: 16
            y: 7
        }
    }

    state: "return"

    //Состояния корневой формы блока
    //Включает в себя 2 состояния WidgetBlock: открыть, закрыть.
    states: [
        State {
            name: "pass"
            PropertyChanges {
                id: animHeightBgdRectPass
                target: backgroundRect
                height: backHeightOfCountTables //250
            }

            PropertyChanges {
                id: animAngleRotateStart
                target: rectangleAngle
                rotation: 180
            }

            PropertyChanges {
                id: animItemContentOn
                target: itemContent
                opacity: 1.0
            }
        },

        State {
            name: "return"
            PropertyChanges {
                id: animHeightBgdRectReturn
                target: backgroundRect
                height: 48
            }
            PropertyChanges {
                id: animItemContentOff
                target: itemContent
                opacity: 0.0
            }
        }
    ]

    transitions: [
        Transition {
            from: "return"
            to: "pass"
            PropertyAnimation {
                target: backgroundRect
                duration: 500
                property: "height"
                easing.type: Easing.InQuad
                easing.amplitude: 2.0
                easing.period: 1.5
            }

            PropertyAnimation {
                target: rectangleAngle
                duration: 500
                property: "rotation"
                easing.type: Easing.OutCirc
                easing.amplitude: 2.0
                easing.period: 1.5
            }

            PropertyAnimation {
                target: itemContent
                duration: 500
                property: "opacity"
                easing.type: Easing.OutCubic
                easing.amplitude: 2.0
                easing.period: 1.5
            }
        },
        Transition {
            from: "pass"
            to: "return"
            PropertyAnimation {
                target: backgroundRect
                duration: 500
                property: "height"
                easing.type: Easing.OutQuad
                easing.amplitude: 2.0
                easing.period: 1.5
            }

            PropertyAnimation {
                target: rectangleAngle
                duration: 500
                property: "rotation"
                easing.type: Easing.OutCirc
                easing.amplitude: 2.0
                easing.period: 1.5
            }

            PropertyAnimation {
                target: itemContent
                duration: 500
                property: "opacity"
                easing.type: Easing.OutCubic
                easing.amplitude: 2.0
                easing.period: 1.5
            }
        }
    ]
}
