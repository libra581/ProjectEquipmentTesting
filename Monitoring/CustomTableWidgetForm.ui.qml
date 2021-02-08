import QtQuick 2.4
import QtGraphicalEffects 1.0

import "creatorRowOfTalbe.js" as GeneratorRowOfTable
import "keeperTablesInfo.js" as KeeperColumnsTable

Item {
    id: itemRoot
    width: 900
    height: 300

    property variant arrayOfPointerToRows: []
    property variant doubleArrayOfData: [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    property variant doubleArrayOfDataOpposite: [[1, 2, 3, 4], [4, 5, 6, 7], [7, 8, 9, 10]]
    property string titleTable: "Блок Д1"
    property string stateBase: "check"
    property string stateReserve: "uncheck"
    readonly property int heightRow: 40

    DropShadow {
        anchors.fill: rectBackground
        horizontalOffset: 0
        verticalOffset: 4
        radius: 6.0
        samples: 17
        color: "#80000000"
        source: rectBackground
    }

    Rectangle {
        id: rectBackground
        x: 0
        y: 0
        width: 900
        height: 300
        color: "#ffffff"
        border.color: "#000000"

        Text {
            id: textTitle
            x: 51
            y: 18
            text: qsTr(titleTable)
            font.bold: true
            font.pixelSize: 24
            font.family: itemSettings.webFontLightName
        }

        DropShadow {
            anchors.fill: rectBckgroundCheckBox_basis
            horizontalOffset: 0
            verticalOffset: 4
            radius: 6.0
            samples: 17
            color: "#80000000"
            source: rectBckgroundCheckBox_basis
        }



        RectBckgroundCheckBox {
            id: rectBckgroundCheckBox_basis
            x: 187
            y: 16
            text_title: "Основа"
            state: stateBase

            mouseArea.enabled: false

            onCheckChange: {
                if(stateCheckBox === "check")
                {
                    itemRoot.height += doubleArrayOfData.length * 40

                    var koefForShiftY = (arrayOfPointerToRows.length < 2) ? heightRow : 0

                    //console.log( arrayOfPointerToRows[arrayOfPointerToRows.length - 1].y )
                    var lastIndexInTable = arrayOfPointerToRows[arrayOfPointerToRows.length - 1].idRow
                    for (var i = lastIndexInTable; i < lastIndexInTable + doubleArrayOfData.length; ++i) {
                        var evenIndex = i % 2
                        var colorBckGrnd = (evenIndex) ? "#19b9b9b9" : "#80000000"
                        var opacityRowColor = (evenIndex) ? 1.0 : 0.5

                         arrayOfPointerToRows.push( GeneratorRowOfTable.createSpriteObjects({
                                                                    y: heightRow * (i -1) + heightRow + koefForShiftY,
                                                                    color: colorBckGrnd ,
                                                                    opacity: opacityRowColor,
                                                                    arrayOfData: doubleArrayOfData[i - lastIndexInTable],
                                                                    idRow: i+1,
                                                                    typeMode: true
                                                                })
                                                   )
                    }

                }
                else
                {
                   itemRoot.height -= doubleArrayOfData.length * 40

                   for (var i = 0; i < doubleArrayOfData.length; ++i)
                   {
                       var tmp_for_destroy = arrayOfPointerToRows.splice(1,1)
                       tmp_for_destroy[0].destroy()
                   }
                }
            }
        }

        DropShadow {
            anchors.fill: rectBckgroundCheckBox_reserve
            horizontalOffset: 0
            verticalOffset: 4
            radius: 6.0
            samples: 17
            color: "#80000000"
            source: rectBckgroundCheckBox_reserve
        }

        RectBckgroundCheckBox {
            id: rectBckgroundCheckBox_reserve
            x: 338
            y: 16
            text_title: "Резерв"
            state: stateReserve

            onCheckChange: {
                if(stateCheckBox === "check")
                {
                    itemRoot.height += doubleArrayOfDataOpposite.length * 40

                    var koefForShiftY = (arrayOfPointerToRows.length < 2) ? heightRow : 0

                    //console.log( arrayOfPointerToRows[arrayOfPointerToRows.length - 1].y )
                    var lastIndexInTable = arrayOfPointerToRows[arrayOfPointerToRows.length - 1].idRow
                    for (var i = lastIndexInTable; i < lastIndexInTable + doubleArrayOfDataOpposite.length; ++i) {
                        var evenIndex = i % 2
                        var colorBckGrnd = (evenIndex) ? "#19b9b9b9" : "#80000000"
                        var opacityRowColor = (evenIndex) ? 1.0 : 0.5

                         arrayOfPointerToRows.push( GeneratorRowOfTable.createSpriteObjects({
                                                                    y: heightRow * (i -1) + heightRow + koefForShiftY,
                                                                    color: colorBckGrnd ,
                                                                    opacity: opacityRowColor,
                                                                    arrayOfData: doubleArrayOfDataOpposite[i - lastIndexInTable],
                                                                    idRow: i+1,
                                                                    typeMode: false
                                                                })
                                                   )
                    }

                }
                else
                {
                   itemRoot.height -= doubleArrayOfDataOpposite.length * 40

                   for (var i = 0; i < doubleArrayOfDataOpposite.length; ++i)
                   {
                       var tmp_for_destroy = arrayOfPointerToRows.pop()
                       tmp_for_destroy.destroy()
                   }
                }
            }
        }




        Component.onCompleted: {

            if (doubleArrayOfData.length > 3)
                itemRoot.height += (doubleArrayOfData.length - 3) * 40

            arrayOfPointerToRows.push( GeneratorRowOfTable.createSpriteObjects({
                                                        y: 0,
                                                        color: "#b9b9b9" ,
                                                        opacity: 0.03,
                                                        arrayOfData: KeeperColumnsTable.createArrayColumnsTable(itemRoot.titleTable),
                                                        idRow: 0
                                                    })
                                      )

            for (var i = 0; i < doubleArrayOfData.length; ++i) {                
                var evenIndex = i % 2
                var colorBckGrnd = (evenIndex) ? "#19b9b9b9" : "#80000000"
                var opacityRowColor = (evenIndex) ? 1.0 : 0.5

                arrayOfPointerToRows.push( GeneratorRowOfTable.createSpriteObjects({
                                                            y: heightRow * i + heightRow,
                                                            color: colorBckGrnd ,
                                                            opacity: opacityRowColor,
                                                            arrayOfData: doubleArrayOfData[i],
                                                            idRow: i+1,
                                                            typeMode: true
                                                        })
                                          )
            }
        }
    }


    onHeightChanged:
    {
        rectBackground.height = itemRoot.height
    }
}
