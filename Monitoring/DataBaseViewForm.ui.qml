import QtQuick 2.4
import QtQuick.Controls 2.15

import "creatorTableView.js" as GeneratorTableView

Item {
    id: rootItem
    width: 800
    height: 400

    property variant matrixSelect: []
    property variant table_list: ["Equipment", "EMode", "Testing", "MoscowTime", "Request", "TestingData", "OneTimeCommands", "TMI", "Session", "FAnalyze"]

    signal btnDataBaseOn(string table);

    property variant pointerTableView: 0

    Component.onDestruction:
    {
        if(rootItem.pointerTableView != 0)
            rootItem.pointerTableView.destroy()
    }

    ComboBox {
        id: comboBoxTables
        x: 48
        y: 2
        width: 352
        height: 40
        currentIndex: 0
        textRole: ""
        model: table_list
    }

    Connections
    {
        target: root

        onSelectTable:
        {
            rootItem.matrixSelect = matrixSelect

            if(rootItem.pointerTableView != 0)
            {
                rootItem.pointerTableView.destroy()
                rootItem.pointerTableView = 0
            }

            rootItem.pointerTableView = GeneratorTableView.createSpriteObjects({
                                                       x: 2,
                                                       y: 46,
                                                       width: 797,
                                                       height: 316,
                                                       doubleArrayOfData: matrixSelect,
                                                       titleTable: comboBoxTables.currentText,
                                                       visible: true
                                                   });
        }
    }

    Button {
        id: buttonView
        x: 411
        y: 2
        width: 340
        height: 40
        text: qsTr("Отобразить")

        onClicked:
        {
            rootItem.btnDataBaseOn(comboBoxTables.currentText.toLowerCase())
        }
    }

//    CustomTableWidget {
//        id: customTableWidget
//        x: 2
//        y: 46
//        width: 797
//        height: 316
//        visible: false
//    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.8999999761581421}
}
##^##*/

