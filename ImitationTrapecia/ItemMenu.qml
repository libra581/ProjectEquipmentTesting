import QtQuick 2.9
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    id: itemMenu
    width: 291
    height: 134

    signal myClickCheck()

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 291
        height: 134
        color: "#b3e6ec"
    }
    
    

    DropShadow{
        anchors.fill: rectangle
        horizontalOffset: 3
        verticalOffset: 3
        radius: 8.0
        samples: 17
        color: "#80000000"
        source: rectangle
    }
    

    MouseArea {
        id: mouseAreaGo
        x: 83
        y: 82
        width: 104
        height: 37

        onClicked:
        {
            itemMenu.myClickCheck()
            mouseAreaArrow.enabled = false
        }

        hoverEnabled: true

        onEntered:
        {
            mouseAreaGo.state = "finish"
        }

        onExited:
        {
            mouseAreaGo.state = "start"
        }



        Rectangle {
            id: rectangleGo
            x: 0
            y: 0
            width: 37
            height: 37
            color: "#ff6600"
            radius: 19
        }

        Rectangle {
            id: rectArr1
            x: 11
            y: 11
            width: 19
            height: 3
            color: "#ffffff"
            radius: 1
            rotation: 45
        }

        Rectangle {
            id: rectArr2
            x: 10
            y: 23
            width: 20
            height: 3
            color: "#ffffff"
            radius: 2
            rotation: -45
        }

        Text {
            id: textGo
            x: 43
            y: 4
            width: 42
            height: 19
            text: qsTr("Пуск")
            font.pixelSize: 22
        }

        Rectangle {
            id: rectArr3
            x: 5
            y: 17
            width: 30
            height: 3
            color: "#ffffff"
            radius: 1
            opacity: 0.0
        }



        state: "start"

        states: [
            State {
                name: "start"
                PropertyChanges { target: rectangleGo; width: 37 }
                PropertyChanges { target: textGo; color: "black" }
                PropertyChanges { target: rectArr1; x: 11 }
                PropertyChanges { target: rectArr2; x: 10 }
                PropertyChanges { target: rectArr3; opacity: 0.0 }
            },
            State {
                name: "finish"
                PropertyChanges { target: rectangleGo; width: 105 }
                PropertyChanges { target: textGo; color: "white" }
                PropertyChanges { target: rectArr1; x: 21 }
                PropertyChanges { target: rectArr2; x: 20 }
                PropertyChanges { target: rectArr3; opacity: 1.0 }
            }
        ]


        transitions: [
            Transition {
                PropertyAnimation {
                    target: rectangleGo;
                    properties: "width";
                    duration: 1000;
                    easing.type: Easing.InOutQuad
                }

                PropertyAnimation {
                    target: textGo;
                    properties: "color";
                    duration: 1000;
                    easing.type: Easing.InOutQuad
                }

                PropertyAnimation {
                    target: rectArr3;
                    properties: "opacity";
                    duration: 700;
                    easing.type: Easing.InOutQuad
                }

                PropertyAnimation {
                    target: rectArr1;
                    properties: "x";
                    duration: 1000;
                    easing.type: Easing.InOutQuad
                }

                PropertyAnimation {
                    target: rectArr2;
                    properties: "x";
                    duration: 1000;
                    easing.type: Easing.InOutQuad
                }
            }
        ]
    }

    Item {
        id: itemCheck
        x: 83
        y: 14
        width: 104
        height: 46
        


        Rectangle {
            id: rectMenuCheck
            x: 0
            y: 1
            width: 105
            height: 45
            color: "#ffffff"
            radius: 27
        }

        DropShadow{
            anchors.fill: rectMenuCheck
            horizontalOffset: 0
            verticalOffset: 0
            radius: 3.0
            samples: 17
            color: "#80000000"
            source: rectMenuCheck
        }

        DropShadow{
            anchors.fill: rectMenuCheck1
            horizontalOffset: 3
            verticalOffset: 3
            radius: 8.0
            samples: 17
            color: "#80000000"
            source: rectMenuCheck1
        }

        Rectangle {
            id: rectMenuCheck1
            x: 60
            y: 3
            width: 40
            height: 40
            color: "#ee661a"
            radius: 25
        }
        
        MouseArea {
            id: mouseAreaCheck
            x: 0
            y: 0
            width: 104
            height: 46
            
            onClicked:
            {
                (itemCheck.state === "start") ? itemCheck.state = "finish" : itemCheck.state = "start";
                (mainWindow.rtnCode === 0) ? mainWindow.rtnCode = 1 : mainWindow.rtnCode = 0;
            }
        }


        
        
        state: "start"
        
        states: [
            State {
                name: "start"
                PropertyChanges { target: rectMenuCheck1; x: 56 }
                PropertyChanges { target: rectMenuCheck; color: "#66CC66" }
            },
            State {
                name: "finish"
                PropertyChanges { target: rectMenuCheck1; x: 6 }
                PropertyChanges { target: rectMenuCheck; color: "#CC3333" }
            }
        ]
        
        
        transitions: [
            Transition {
                PropertyAnimation {
                    target: rectMenuCheck1;
                    properties: "x";
                    duration: 1000;
                    easing.type: Easing.InOutQuad
                }

                PropertyAnimation {
                    target: rectMenuCheck;
                    properties: "color";
                    duration: 1000;
                    easing.type: Easing.InOutQuad
                }
            }
        ]
    }
    
    MouseArea {
        id: mouseAreaArrow
        x: 232
        y: 0
        width: 59
        height: 134
        
        Image {
            id: imageArrowMenu
            x: 18
            y: 50
            width: 24
            height: 34
            source: "img/arrowMenu.png"
            scale:1.0

        }
        
        onClicked:
        {
            (itemMenu.state === "start") ? itemMenu.state = "finish" : itemMenu.state = "start";
        }

    }



    
    
    states: [
        State {
            name: "start"
            PropertyChanges { target: itemMenu; x: -230 }
            PropertyChanges { target: imageArrowMenu; rotation: 0}
            PropertyChanges { target: itemMenu; scale: 0.9}
        },
        State {
            name: "finish"
            PropertyChanges { target: itemMenu; x: -10 }
            PropertyChanges { target: imageArrowMenu; rotation: 180}
            PropertyChanges { target: itemMenu; scale: 1.2}
        }
    ]
    
    
    transitions: [
        Transition {
            PropertyAnimation {
                target: itemMenu;
                properties: "x";
                duration: 1000;
                easing.type: Easing.InOutQuad
            }
            
            
            PropertyAnimation {
                target: imageArrowMenu;
                properties: "rotation";
                duration: 1000;
                easing.type: Easing.InOutQuad
            }
            
            PropertyAnimation {
                target: itemMenu;
                properties: "scale";
                duration: 1000;
                easing.type: Easing.InOutQuad
            }
            
        }
    ]
}
