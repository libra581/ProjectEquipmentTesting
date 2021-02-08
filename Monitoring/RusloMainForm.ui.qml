import QtQuick 2.4

import "creatorWidgetBlock.js" as GeneratorWdgBlock

Item {
    id: itemRoot
    width: 1024
    height: 768
    antialiasing: true

    Rectangle {
        id: backGround
        color: "#ffffff"
        z: -15
        anchors.fill: parent
    }

    Rectangle {
        id: topLeftRect
        width: 300
        height: 40
        color: "#a9a9a9"
        radius: 20
        anchors.top: parent.top
        anchors.topMargin: -20
        anchors.left: parent.left
        anchors.leftMargin: 0
        z: 0
        antialiasing: true
    }

    Rectangle {
        id: topRightRect
        x: 724
        width: 300
        height: 40
        color: "#a9a9a9"
        radius: 20
        anchors.top: parent.top
        anchors.topMargin: -20
        anchors.right: parent.right
        anchors.rightMargin: 0
        antialiasing: true
    }

    Rectangle {
        id: leftRect
        width: 20
        color: "#a9a9a9"
        radius: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        rotation: 0
        antialiasing: false
    }

    Rectangle {
        id: rightRect
        x: 1004
        width: 20
        color: "#a9a9a9"
        radius: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        transformOrigin: Item.Center
        anchors.right: parent.right
        anchors.rightMargin: 0
        rotation: 0
        antialiasing: false
    }

    Rectangle {
        id: bottomRect
        y: 748
        height: 20
        color: "#a9a9a9"
        radius: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        rotation: 0
        antialiasing: false
    }

    Item {
        id: itemAngleCircle_top_left
        width: 60
        height: 60
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        z: -1

        Rectangle {
            id: angleRectGray
            x: 0
            y: 0
            width: 40
            height: 40
            color: "#a9a9a9"
            z: -1
        }

        Rectangle {
            id: angleRectWhite
            x: 20
            y: 20
            width: 40
            height: 40
            color: "#ffffff"
            radius: 20
            z: -1
        }
    }

    Item {
        id: itemAngleCircle_top_right
        x: 964
        width: 60
        height: 60
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        rotation: 90
        Rectangle {
            id: angleRectGray1
            x: 0
            y: 0
            width: 40
            height: 40
            color: "#a9a9a9"
            z: -1
        }

        Rectangle {
            id: angleRectWhite1
            x: 20
            y: 20
            width: 40
            height: 40
            color: "#ffffff"
            radius: 20
            z: -1
        }
        z: -1
    }

    Item {
        id: itemAngleCircle_bottom_right
        x: 964
        y: 708
        width: 60
        height: 60
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        rotation: 180
        Rectangle {
            id: angleRectGray2
            x: 0
            y: 0
            width: 40
            height: 40
            color: "#a9a9a9"
            z: -1
        }

        Rectangle {
            id: angleRectWhite2
            x: 20
            y: 20
            width: 40
            height: 40
            color: "#ffffff"
            radius: 20
            z: -1
        }
        z: -1
    }

    Item {
        id: itemAngleCircle_bottom_left
        y: 708
        width: 60
        height: 60
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        rotation: -90
        Rectangle {
            id: angleRectGray3
            x: 0
            y: 0
            width: 40
            height: 40
            color: "#a9a9a9"
            z: -1
        }

        Rectangle {
            id: angleRectWhite3
            x: 20
            y: 20
            width: 40
            height: 40
            color: "#ffffff"
            radius: 20
            z: -1
        }
        z: -1
    }

    Item {
        id: item2
        x: 362
        y: 0
        width: 300
        height: 119
        anchors.horizontalCenter: parent.horizontalCenter
        z: -2

        Rectangle {
            id: topRightRect1
            x: 0
            y: -21
            width: 300
            height: 40
            color: "#a9a9a9"
            radius: 20
            antialiasing: true
        }

        Rectangle {
            id: rectangle
            x: 90
            y: -28
            width: 120
            height: 120
            color: "#a9a9a9"
            radius: 60
            z: -1
        }

        Rectangle {
            id: rectangle1
            x: -59
            y: 18
            width: 158
            height: 122
            color: "#ffffff"
            radius: 60
            z: -2
        }

        Rectangle {
            id: rectangle3
            x: 50
            y: -37
            width: 200
            height: 94
            color: "#a9a9a9"
            z: -3
        }

        Rectangle {
            id: rectangle2
            x: 201
            y: 18
            width: 158
            height: 122
            color: "#ffffff"
            radius: 60
            z: -2
        }

        Text {
            id: bcvm
            x: 114
            y: 47
            width: 75
            height: 26
            text: qsTr("Испытания")
            font.pointSize: 13
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            // font.family: "Times New Roman"
            renderType: Text.NativeRendering
            textFormat: Text.AutoText
            font.family: itemSettings.webFontName
        }
    }

//    CustomTableWidget {
//        id: customTableWidget
//        x: 71
//        y: 362
//        width: 797
//        height: 316
//        doubleArrayOfData: [[9, 8, 7, 1], [6, 5, 4, 2], [3, 2, 1, 3]]
//        titleTable: "Блок Д1"
//    }

    property variant arrayOfPointerWidgets: []

    Component.onCompleted: {
        arrayOfPointerWidgets.push(GeneratorWdgBlock.createSpriteObjects({
                                                  "x": "114",
                                                  "y": "250",
                                                  "text_title": "БАСИ",
                                                  "status": "NOT_INFORMATION"
                                              }));

        arrayOfPointerWidgets.push(GeneratorWdgBlock.createSpriteObjects({
                                                  "x": "314",
                                                  "y": "250",
                                                  "text_title": "БАППД",
                                                  "status": "NOT_INFORMATION"
                                              }));
    }

//    WidgetBlock
//    {
//        x: 114
//        y: 250
//        text_title: "БАСИ"
//        status: "NOT_INFORMATION"
//        width: 285
//        height: 306
//        antialiasing: false
//        z: -1
//    }

//    WidgetBlock
//    {
//        x: 314
//        y: 250
//        text_title: "БАППД"
//        status: "NOT_INFORMATION"
//        width: 285
//        height: 306
//        antialiasing: false
//        z: -1
//    }


}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/
