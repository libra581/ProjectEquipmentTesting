import QtQuick 2.9
import QtQuick.Window 2.2
import QtGraphicalEffects 1.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: rectStatus
    property string dopStatus: "<font color='green' size='3'>успешно!</font>"
    
    Rectangle {
        id: rectangle
        x: 19
        y: 407
        width: 740
        height: 4
        color: "#e9e8e8"
        radius: 2
    }
    
    Label {
        id: labelStatus
        x: 69
        y: 73
        width: 647
        height: 252
        color: "#08b7c1"
        text: "Прием информации завершен " + rectStatus.dopStatus
        bottomPadding: 0
        leftPadding: 0
        padding: 0
        topPadding: 0
        font.letterSpacing: 3
        font.wordSpacing: 10
        style: Text.Normal
        font.weight: Font.ExtraBold
        font.capitalization: Font.AllUppercase
        font.italic: false
        font.bold: true
        styleColor: "#ffffff"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        font.pointSize: 22
    }
    
    Rectangle {
        id: rectangleBack
        x: 623
        y: 424
        width: 84
        height: 22
        color: "#4ca3a3a3"
        radius: 11
        opacity: 0
    }
    
    Label {
        id: labelBtn
        x: 623
        y: 424
        color: "#707070"
        text: qsTr("Закрыть")
        font.pointSize: 14
        font.family: "Courier"
        
        MouseArea {
            id: mouseAreaBtnClose
            x: 0
            y: -1
            width: 84
            height: 23
            
            hoverEnabled: true
            
            onClicked:
            {
                Qt.exit(rtnCode)
            }
            
            onEntered:
            {
                rectangleBack.opacity = 1.0
            }
            
            onExited:
            {
                rectangleBack.opacity = 0.0
            }
        }
    }

    state: "start"
    
    
    states: [
        State {
            name: "start"
            PropertyChanges { target: rectStatus; opacity: 0 }
            PropertyChanges { target: rectStatus; y: 1000 }
        },
        State {
            name: "finish"
            PropertyChanges { target: rectStatus; opacity: 1 }
            PropertyChanges { target: rectStatus; y: 90 }
        }
    ]
    
    
    transitions: [
        Transition {
            
            PropertyAnimation {
                target: rectStatus;
                properties: "opacity";
                duration: 1000;
                easing.type: Easing.InOutQuad
            }
            
            PropertyAnimation {
                target: rectStatus;
                properties: "y";
                duration: 1000;
                easing.type: Easing.OutQuart
            }
        }
    ]
}
