import QtQuick 2.4
import QtQuick.Layouts 1.3

import "creatorCellOfTable.js" as GeneratorCellOfTable

Rectangle {

    property variant arrayOfData: [1, 1, 1]
    property int idRow: 0
    property variant arrayOfFirstColumns: ["", "Обозначение", "Значение", "Разрядность (бит)", "Обозначение", "Значение", "Разрядность (бит)"]
    property double opacityBackGrnd: 0.9
    property string colorBackGrnd: "#19b9b9b9"
    property bool typeMode: true

    id: rectRoot
    x: 39
    y: 64
    width: 822
    height: 40

    Rectangle{
        anchors.fill: parent
        color: colorBackGrnd
        opacity: opacityBackGrnd
    }

    RowLayout {
        id: rowLayout
        anchors.fill: parent
        spacing: 1

        function createSpriteObjectsItemTypeAndStateRow(opacity, typeMode, state) {
            var component = Qt.createComponent("ItemTypeAndStateRow.qml");
            var sprite = component.createObject(rowLayout, {opacity: opacity, typeMode: typeMode, state: state});

            if (sprite == null) {
                // Error Handling
                console.log("Error creating object");
            }

            return component
        }

        Component.onCompleted: {

            //rectRoot.arrayOfData.unshift(rowLayout.createSpriteObjects().)
            if(rectRoot.idRow != 0)
                rowLayout.createSpriteObjectsItemTypeAndStateRow(1.0, rectRoot.typeMode, "correct")
            else
                rowLayout.createSpriteObjectsItemTypeAndStateRow(0.0)


//            rectRoot.arrayOfData.unshift(
//                        rectRoot.arrayOfFirstColumns[rectRoot.idRow])


            for (var i = 0; i < rectRoot.arrayOfData.length; ++i) {
                var disabledToolTip = (i == 0 || idRow == 0) ? true : false

                GeneratorCellOfTable.createSpriteObjects({
                                                             text: String(
                                                                       rectRoot.arrayOfData[i]),
                                                             disabledToolTip: disabledToolTip
                                                         })
            }
            arrayOfData.shift()
        }
    }
}
