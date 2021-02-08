import QtQuick 2.9
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Window {
    id: mainWindow
    visible: true
    width: 1200
    height: 680
    title: qsTr("Имитация трапеции")

    maximumHeight : 680
    maximumWidth : 1200
    minimumHeight : 680
    minimumWidth : 1200
    property bool runAnim: false
    property string stMenu: "start"
    property int rtnCode: 0

    flags: Qt.WindowTitleHint


    Item {
        id: item1
        x: 10
        y: 10
        width: 1171
        height: 654
        opacity: 1


        Connections
        {
            target: itemMenu
            onMyClickCheck:
            {
                itemMenu.state = "start"
                itemStatus.state = "btw1"
                itemStatus.timerToBtw2Bool = true
                itemClose.enabled = false
            }
        }


        Connections
        {
            target: itemStatus
            onTrigTimerToBtw2:
            {
                mainWindow.runAnim = true
            }
        }


        Rectangle {
            id: backGround
            x: 0
            y: 0
            width: 1172
            height: 653
            color: "#67c8cf"
            border.width: 0
        }





        DropShadow{
            anchors.fill: backGround
            horizontalOffset: 3
            verticalOffset: 3
            radius: 8.0
            samples: 17
            color: "#80000000"
            source: backGround
        }

        Rectangle {
            id: circleBack
            x: 467
            y: 222
            width: 223
            height: 210
            color: "#f7f6f6"
            radius: 105

            SequentialAnimation {
                running: runAnim
                NumberAnimation { target: circleBack; property: "scale"; easing.type: Easing.InCubic; to: 1.5; duration: 1500 }
                NumberAnimation { target: circleBack; property: "scale"; easing.type: Easing.OutCubic; to: 1; duration: 1500 }
                loops: Animation.Infinite
            }

        }

        Image {
            id: aerial
            x: 505
            y: 164
            width: 191
            height: 289
            source: "img/path580.png"
        }


        Image {
            id: arrow
            x: 688
            y: 146
            width: 65
            height: 66
            clip: false
            rotation: 135
            visible: true
            fillMode: Image.Stretch
            source: "img/arrow.png"

            PropertyAnimation on x{
                duration: 1500
                easing.type: Easing.OutQuad
                from: item1.width-50
                to: item1.width*0.5-25
                running: runAnim
                loops: Animation.Infinite
            }

            NumberAnimation on y{
                duration: 1500
                easing.type: Easing.OutQuad
                from: -20
                to: item1.height*0.5-75
                running: runAnim
                loops: Animation.Infinite
            }
        }

        Image {
            id: arrow2
            x: 702
            y: 128
            width: 65
            height: 66
            clip: false
            rotation: 135
            visible: true
            fillMode: Image.Stretch
            source: "img/arrow.png"

            PropertyAnimation on x{
                duration: 1500
                easing.type: Easing.OutQuad
                from: item1.width-80
                to: item1.width*0.5-25
                running: runAnim
                loops: Animation.Infinite
            }

            NumberAnimation on y{
                duration: 1500
                easing.type: Easing.OutQuad
                from: -60
                to: item1.height*0.5-75
                running: runAnim
                loops: Animation.Infinite
            }
        }


        Image {
            id: arrow3
            x: 702
            y: 128
            width: 65
            height: 66
            clip: false
            rotation: 135
            visible: true
            fillMode: Image.Stretch
            source: "img/arrow.png"

            PropertyAnimation on x{
                duration: 1500
                easing.type: Easing.OutQuad
                from: item1.width-20
                to: item1.width*0.5-25
                running: runAnim
                loops: Animation.Infinite
            }

            NumberAnimation on y{
                duration: 1500
                easing.type: Easing.OutQuad
                from: 20
                to: item1.height*0.5-75
                running: runAnim
                loops: Animation.Infinite
            }
        }




        Image {
            id: wave
            x: 623
            y: 164
            width: 73
            height: 75
            source: "img/g22.png"

            SequentialAnimation {
                running: runAnim
                NumberAnimation { target: wave; property: "scale"; easing.type: Easing.InBack; to: 1.05; duration: 500 }
                NumberAnimation { target: wave; property: "scale"; easing.type: Easing.OutBack; to: 1; duration: 500 }
                loops: Animation.Infinite
            }
        }


        ItemMenu {
            id: itemMenu
            height: 120
            state: stMenu
            width: 299
            x: 0
            y: 22
        }

        Item {
            id: itemClose
            x: 1046
            y: -45
            width: 60
            height: 60

            Rectangle {
                id: rectClose
                x: 0
                y: 0
                width: 60
                height: 60
                color: "#fe7878"
            }

            Rectangle {
                id: rectLine1
                x: 4
                y: 28
                width: 52
                height: 4
                color: "#ffffff"
                rotation: 45
            }

            Rectangle {
                id: rectLine2
                x: 4
                y: 29
                width: 52
                height: 4
                color: "#ffffff"
                rotation: 135
            }

            MouseArea {
                id: mouseAreaClose
                x: 0
                y: -77
                width: 60
                height: 137

                hoverEnabled:  true

                onClicked:
                {
                    Qt.exit(1)
                }

                onEntered:
                {
                    itemClose.state = "finish"
                }

                onExited:
                {
                    itemClose.state = "start"
                }
            }

            state: "start"


            states: [
                State {
                    name: "start"
                    PropertyChanges { target: itemClose; y: -45 }
                },
                State {
                    name: "finish"
                    PropertyChanges { target: itemClose; y: -10 }
                }
            ]


            transitions: [
                Transition {
                    PropertyAnimation {
                        target: itemClose;
                        properties: "y";
                        duration: 1000;
                        easing.type: Easing.InOutQuad
                    }
                }
            ]
        }

        ProgressBar {
            id: progressBar
            x: 14
            y: 606
            width: 1145
            height: 31
            indeterminate: false
            value: 0.0

            style: ProgressBarStyle {
                background: Rectangle {
                    radius: 2
                    color: "lightgray"
                    border.color: "gray"
                    border.width: 1
                    implicitWidth: 200
                    implicitHeight: 24
                }
                progress: Rectangle {
                    color: "#e67e22"
                    border.color: "#c74c02"
                }
            }

            Timer{
                id: timerProgress
                interval: 1000; running: runAnim; repeat: true
                onTriggered:
                {

                    if (progressBar.value < 0.9)
                    {
                        progressBar.value+=0.1
                    }
                    else if (progressBar.value >= 0.9 && progressBar.value < 1.0)
                    {
                        if(itemStatus.state != "btw3")
                        {
                            if(rtnCode === 1)
                            {
                                itemStatus.stateDownload = "<font color='red' size='5'>с ошибкой!</font>";
                                rectStatus.dopStatus = "<font color='red' size='5'>с ошибкой!</font>";
                            }

                            itemStatus.state = "btw3"
                            rectStatus.state = "finish"
                        }

                        timerProgress.interval = 3000

                        progressBar.value+=0.03

                    }
                    else
                    {

                        //Qt.exit(rtnCode)
                        //rectStatus.state = "finish"
                    }
                }

            }

            Text {
                id: text1
                x: 560
                y: -30
                width: 26
                height: 27
                text: Math.round(progressBar.value*100)+"%"
                font.family: "Courier"
                font.pixelSize: 32
            }

        }

        ItemStatus {
            id: itemStatus
            height: 59
            width: 423
            x: 376
            y: 503
        }




        RectStatus {
            id: rectStatus
            color: "#ffffff"
            height: 465
            opacity: 0
            radius: 5
            state: "start"
            width: 785
            x: 223
            y: 90
        }

        DropShadow{
            anchors.fill: rectStatus
            horizontalOffset: 2
            verticalOffset: 2
            radius: 8.0
            samples: 17
            color: "#80000000"
            source: rectStatus
        }




    }
}
