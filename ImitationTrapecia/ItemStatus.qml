import QtQuick 2.9
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Item {
    id: itemStatus
    property bool timerToBtw2Bool: false
    property string stateDownload: "<font color='green' size='5'>успешно!</font>"
    signal trigTimerToBtw2()


    Text {
        id: textStatus
        x: 92
        y: 16
        width: 239
        height: 27
        text: qsTr("Подготовка приема...")
        font.pixelSize: 32
        font.family: "Courier"
        opacity: 0.0
    }

    Timer{
        id: timerToBtw2
        interval: 5000
        running: timerToBtw2Bool
        repeat: false
        onTriggered:
        {
            trigTimerToBtw2()
            parent.state = "btw2"
        }
    }

    Text {
        id: textStatus1
        x: 92
        y: 12
        width: 239
        height: 27
        text: qsTr("Прием информации...")
        font.pixelSize: 32
        font.family: "Courier"
        opacity: 0
    }

    Text {
        id: textStatus2
        x: 16
        y: 12
        width: 323
        height: 27
        text: qsTr("Прием информации завершен " + stateDownload)
        font.pixelSize: 32
        opacity: 0
        font.family: "Courier"
    }
    
    state: "start"

    states: [
        State {
            name: "start"
            PropertyChanges { target: textStatus; opacity: 0.0 }
            PropertyChanges { target: textStatus; y: -10 }
        },
        State {
            name: "btw1"
            PropertyChanges { target: textStatus; opacity: 1.0 }
            PropertyChanges { target: textStatus; y: 5 }
            PropertyChanges { target: textStatus1; y: -20 }
        },
        State {
            name: "btw2"
            PropertyChanges { target: textStatus; opacity: 0.0 }
            PropertyChanges { target: textStatus; y: 15 }
            PropertyChanges { target: textStatus1; opacity: 1.0 }
            PropertyChanges { target: textStatus1; y: 5 }
            PropertyChanges { target: textStatus2; y: -20 }
        },
        State {
            name: "btw3"
            PropertyChanges { target: textStatus1; opacity: 0.0 }
            PropertyChanges { target: textStatus1; y: 15 }
            PropertyChanges { target: textStatus2; opacity: 1.0 }
            PropertyChanges { target: textStatus2; y: 5 }
        }
    ]


    transitions: [
        Transition {

            PropertyAnimation {
                target: textStatus;
                properties: "opacity";
                duration: 1000;
                easing.type: Easing.InOutQuad
            }
            PropertyAnimation {
                target: textStatus;
                properties: "y";
                duration: 1000;
                easing.type: Easing.InOutQuad
            }

            PropertyAnimation {
                target: textStatus1;
                properties: "opacity";
                duration: 1000;
                easing.type: Easing.InOutQuad
            }
            PropertyAnimation {
                target: textStatus1;
                properties: "y";
                duration: 1000;
                easing.type: Easing.InOutQuad
            }

            PropertyAnimation {
                target: textStatus2;
                properties: "opacity";
                duration: 1000;
                easing.type: Easing.InOutQuad
            }
            PropertyAnimation {
                target: textStatus2;
                properties: "y";
                duration: 1000;
                easing.type: Easing.InOutQuad
            }

        }
    ]
}
