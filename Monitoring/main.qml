import QtQuick 2.12
import QtQuick.Controls 2.5
import CObserver 1.0

ApplicationWindow {
    id:root
    width: 1024
    height: 768
    visible: true
    title: qsTr("Мониторинг тех. процесса")

    minimumWidth: 930
    minimumHeight: 300

    property int port: 2323
    property variant matrixSelect: []

    CObserver
    {
        id: cObserver
    }

    Component.onCompleted:
    {
        cObserver.createServerTCP(root.port)
        cObserver.initDB()
        cObserver.select("emode")
        matrixSelect = cObserver.matrix_select
        console.log(matrixSelect)
    }

    Connections
    {
        target: cObserver

        onMsgClient:
        {
            console.log(typeEquipment, codeExec);

            if(typeEquipment === 0)
            {
                mainItem.arrayOfPointerWidgets[0].codeExecute = codeExec

                if( codeExec > 0 )
                {
                    var tmp_arr_errors_states =
                             mainItem.arrayOfPointerWidgets[0].arrayOfRows.filter(
                                function(item) {
                                  return item.state === "error";
                                })

                    if(tmp_arr_errors_states.length <= 0)
                    {
                        mainItem.arrayOfPointerWidgets[0].status = "CORRECT"
                    }
                    else
                    {
                        mainItem.arrayOfPointerWidgets[0].status = "ERROR"
                    }
                }
                else
                {
                   mainItem.arrayOfPointerWidgets[0].status = "ERROR"
                }

                mainItem.arrayOfPointerWidgets[0].statusChanged();
            }
            else if(typeEquipment === 1)
            {
                mainItem.arrayOfPointerWidgets[1].codeExecute = codeExec

                if( codeExec > 0)
                {
                    var tmp_arr_errors_states_2 =
                             mainItem.arrayOfPointerWidgets[1].arrayOfRows.filter(
                                function(item) {
                                  return item.state === "error";
                                })

                    if(tmp_arr_errors_states_2.length <= 0)
                    {
                        mainItem.arrayOfPointerWidgets[1].status = "CORRECT"
                    }
                    else
                    {
                        mainItem.arrayOfPointerWidgets[1].status = "ERROR"
                    }
                }
                else
                {
                   mainItem.arrayOfPointerWidgets[1].status = "ERROR"
                }

                mainItem.arrayOfPointerWidgets[1].statusChanged();
            }
        }
    }

    SettingsMainForm
    {
        id: itemSettings
    }

    RusloMain
    {
        id: mainItem
        anchors.fill: parent
    }

    DataBaseView
    {
        id:dataBaseView
        anchors.centerIn: parent
    }

    signal selectTable(variant matrixSelect)

    Connections
    {
        target: dataBaseView

        onBtnDataBaseOn:
        {
            cObserver.select(table)
            matrixSelect = []
            matrixSelect = cObserver.matrix_select
            root.selectTable(root.matrixSelect)
        }
    }
}
