import QtQuick 2.12
import QtQuick.Controls 2.5
import QtQuick.Dialogs 1.1
import QtQuick.Controls.Styles 1.4

import myProcess 1.0
import CObserver 1.0

ApplicationWindow {
    id: applicationWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Менеджер управления испытаниями БАСИ")

    property string pathFilePlan: "C:\\Users\\sds\\Documents\\Plan"
    property string pathFileAnalyze: "C:\\Users\\sds\\Documents\\FormAnalyze"
    property string pathFileTMI: "C:\\Users\\sds\\Documents\\FormTMI"

    property string pointDateInputData: ""
    property string pointDateAnalyze: ""

    property alias ipAddress: textInputIP.text
    property alias port: textInputPort.text

    ItemEquipments{ id: typeEquipments }

    property int typeEquipment: typeEquipments.tBAPPD
    property string sTypeEquipment: typeEquipments.sBASI

    Component.onCompleted:
    {
        if(typeEquipment === typeEquipments.tBAPPD)
            sTypeEquipment = typeEquipments.sBAPPD
        else
            sTypeEquipment = typeEquipments.sBASI
    }



    CObserver
    {
        id: cObserver
        typeEquipment: applicationWindow.typeEquipment
        pathFilePlan: applicationWindow.pathFilePlan
        Component.onCompleted:
        {
            cObserver.setClientProperty(ipAddress, Number(port))
            cObserver.initDB()
            //console.log(cObserver.matrix_select)
            //cObserver.insertInputData();
            //cObserver.insertAnalyze()
        }

        onErrorClient:
        {
            messageDialogCritical.title = "Ошибка соединения с сервером"
            messageDialogCritical.text = strError
            messageDialogCritical.visible = true
        }

        onErrorFilePlan:
        {
            messageDialogCritical.title = "Ошибка файла"
            messageDialogCritical.text = "Ошибка открытия файла плана"
            messageDialogCritical.visible = true
        }
    }

    ItemCodeExec
    {
        id: execCode
    }

    MessageDialog
    {
        id: messageDialogWarning
        title: "May I have your attention please"
        text: "It's so cool that you are using Qt Quick."
        icon: StandardIcon.Warning
        onAccepted: {
            console.log("And of course you could only agree.")
        }
        Component.onCompleted: visible = false
    }

    MessageDialog
    {
        id: messageDialogCritical
        title: ""
        text: ""
        icon: StandardIcon.Critical
        Component.onCompleted: visible = false
    }

    Item
    {
        id: clock
        x: 0
        width: 43
        height: 12

        Text
        {
            id: time
            text: observer.currentDate
        }

    }

    ItemObserver
    {
        id: observer

        onEqualTimesInputData:
        {
            console.log("onEqualTimes " + pTime)
            textAreaTesting.text += "Запуск InputData ( " + pTime + " );\n"
        }

        onEqualTimesAnalyze:
        {
            console.log("onEqualTimes " + pTime)
            textAreaTesting.text += "Запуск Analyze ( " + pTime + " );\n"
        }

        onResultExecute:
        {
            console.log("Connections " + result + " " + moduleName)

            messageDialogWarning.visible = true
            messageDialogWarning.text = "Модуль " + moduleName

            switch(result)
            {
                case execCode.iErrorPort:
                    messageDialogWarning.icon = StandardIcon.Critical
                    messageDialogWarning.text += " завершен с ошибкой порта!"
                    break
                case execCode.iError:
                    messageDialogWarning.icon = StandardIcon.Critical
                    messageDialogWarning.text += " завершен с ошибкой!"
                    break
                case execCode.iWaiting:
                    messageDialogWarning.icon = StandardIcon.Warning
                    messageDialogWarning.text += " запущен, но не завершен!"
                    break
                case execCode.iPortEmpty:
                    messageDialogWarning.icon = StandardIcon.Warning
                    messageDialogWarning.text += " завершен, но порт пуст!"
                    break
                case execCode.iAnalyzeError:
                    messageDialogWarning.icon = StandardIcon.Warning
                    messageDialogWarning.text += " завершен, но планы не совпадают!"
                    break
                default:
                    messageDialogWarning.icon = StandardIcon.Information
                    messageDialogWarning.text += " успешно завершен!"
                    break
            }

            textAreaTesting.text += "Код возврата " + moduleName + ": " + result + ";\n"

            if(moduleName === "inputData")
            {                
                if(result !== execCode.iSuccess)
                {
                    cObserver.sendToServer(execCode.serverCodeExec.iEFInputData)
                }
                else
                {
                    cObserver.sendToServer(execCode.serverCodeExec.iFInputData)
                }
            }
            else if(moduleName === "analyze")
            {
                if(result !== execCode.iSuccess)
                {
                    cObserver.sendToServer(execCode.serverCodeExec.iEFAnalyze)
                }
                else
                {
                    cObserver.sendToServer(execCode.serverCodeExec.iFAnalyze)
                    cObserver.insertAnalyze()
                }
            }
        }
    }

    Process
    {
        id: processCyclegramm

        onStarted:
        {
            textAreaCyclegramma.text += "Запуск Cyclegramma ( " + time.text + " );\n"
        }

        onFinished:
        {
            var result_c = readAll()

            messageDialogWarning.visible = true
            messageDialogWarning.text = "Циклограмма "

            if(result_c !== execCode.iSuccess)
            {
                messageDialogWarning.icon = StandardIcon.Critical
                messageDialogWarning.text += " завершена с ошибкой!"

                cObserver.sendToServer(execCode.serverCodeExec.iEFCyclegramma)
            }
            else
            {
                messageDialogWarning.icon = StandardIcon.Information
                messageDialogWarning.text += " успешно завершена!"

                cObserver.readFilePlan();
                cObserver.insertInputData();

                console.log("CYCLEPLAN DATE I " + cObserver.dateInputData)
                console.log("CYCLEPLAN DATE A " + cObserver.dateAnalyze)

                applicationWindow.pointDateInputData = cObserver.dateInputData;
                applicationWindow.pointDateAnalyze = cObserver.dateAnalyze;

                textAreaCyclegramma.text += "Дата испытания: " + cObserver.dateInputData +";\n"
                textAreaCyclegramma.text += "Дата анализа: " + cObserver.dateAnalyze +";\n"

                cObserver.sendToServer(execCode.serverCodeExec.iFCyclegramma)
            }

            textAreaCyclegramma.text += "Код возврата Cyclegramm: " + result_c + ";\n"


        }
    }



    Rectangle {
        id: rectCyclegramma
        x: 214
        y: 136
        width: 212
        height: 49
        color: "#c4c4c4"
        radius: 5

        MouseArea {
            id: mouseAreaCycleGramma
            anchors.fill: parent

            onClicked: {
                console.log("Запуск циклограммы");
                processCyclegramm.start("C:\\Users\\sds\\Documents\\build-CycleGramma-Desktop_Qt_5_15_0_MinGW_64_bit-Release\\release\\CycleGramma.exe",
                                        [applicationWindow.pathFilePlan, sTypeEquipment ]);
                cObserver.sendToServer(execCode.serverCodeExec.iSCyclegramma)
            }
        }

        TextArea {
            id: textAreaCyclegramma
            x: 0
            y: 44
            width: 212
            height: 49
            readOnly: true
            color: "#000000"
            text: ""
            wrapMode: Text.NoWrap
            font.bold: false
            font.pointSize: 7
            placeholderText: qsTr("Статус:")
        }

        Text {
            id: textCyclegramma
            x: 44
            y: 9
            text: qsTr("Циклограмма")
            font.pixelSize: 20
        }

        Rectangle {
            id: rectCyclegramma1
            x: 0
            y: 44
            width: 212
            height: 49
            opacity: 0.3
            color: "#c4c4c4"
        }


    }

    Rectangle {
        id: rectTesting
        x: 214
        y: 292
        width: 212
        height: 49
        color: "#c4c4c4"
        radius: 5

        MouseArea {
            id: mouseAreaTesting
            anchors.fill: parent

            onClicked: {
                console.log("Запуск испытания")

                observer.pointDateInputData = applicationWindow.pointDateInputData
                observer.pointDateAnalyze = applicationWindow.pointDateAnalyze

                //Testing
                observer.processInputData.start("C:\\Users\\sds\\Documents\\build-inputData-Desktop_Qt_5_15_0_MinGW_64_bit-Release\\release\\inputData.exe",
                                        [applicationWindow.sTypeEquipment, applicationWindow.pathFilePlan ]);
                observer.processAnalyze.start("C:\\Users\\sds\\Documents\\build-AnalyzeResult-Desktop_Qt_5_15_0_MinGW_64_bit-Release\\release\\AnalyzeResult.exe",
                                       [applicationWindow.sTypeEquipment, applicationWindow.pathFilePlan,
                                        applicationWindow.pathFileAnalyze, applicationWindow.pathFileTMI ]);

                cObserver.sendToServer("Анализ запущен. Параметры( "+applicationWindow.sTypeEquipment+
                                       ", " + applicationWindow.pathFilePlan +
                                       ", " + applicationWindow.pathFileAnalyze +
                                       ", " + applicationWindow.pathFileTMI + " )")
                cObserver.sendToServer(execCode.serverCodeExec.iSAnalyze)
            }
        }

        TextArea {
            id: textAreaTesting
            x: 0
            y: 45
            width: 212
            height: 76
            readOnly: true
            color: "#000000"
            font.pointSize: 7
            placeholderText: qsTr("Статус:")
        }

        Text {
            id: textTesting
            x: 23
            y: 9
            text: qsTr("Запуск испытания")
            font.pixelSize: 20
        }

        Rectangle {
            id: rectTesting1
            x: 0
            y: 39
            width: 212
            height: 82
            opacity: 0.3
            color: "#c4c4c4"
        }


    }

    Text {
        id: textTitle
        x: 82
        y: 50
        text: qsTr("Менеджер управления испытаниями БАСИ")
        font.pixelSize: 24
        font.family: "Arial"
    }

    Image {
        id: image
        x: 156
        y: 136
        width: 52
        height: 49
        source: "img/icons8-combo-chart-100.png"
        fillMode: Image.PreserveAspectFit
    }

    Image {
        id: image1
        x: 156
        y: 292
        width: 52
        height: 49
        source: "img/icons8-repository-64.png"
        fillMode: Image.PreserveAspectFit
    }

    Rectangle {
        id: rectHelp
        x: -20
        y: 80
        width: 40
        height: 40
        color: "#c4c4c4"
        radius: 3
        border.width: 0

        Text {
            id: textHelp
            x: 24
            y: 11
            text: qsTr("?")
            font.pixelSize: 16
        }

        MouseArea {
            id: mouseAreaHelp
            x: 0
            y: 0
            width: 40
            height: 40
            onClicked:
            {
                messageDialogWarning.title = "О программе"
                messageDialogWarning.text = "Программа разработана АО 'ЦНИРТИ им. ак. А.И. Берга'"
                messageDialogWarning.icon = StandardIcon.Information
                messageDialogWarning.visible = true;
            }
        }
    }

    Text {
        id: text1
        x: 412
        y: 0
        width: 61
        height: 17
        text: qsTr("IP address:")
        font.pixelSize: 12
        z: 1


    }

    Text {
        id: text2
        x: 565
        y: 0
        width: 29
        height: 17
        text: qsTr("Port:")
        font.pixelSize: 12
        z: 1
    }

    TextInput {
        id: textInputPort
        x: 594
        y: 0
        width: 59
        height: 20
        text: qsTr("2323")
        font.pixelSize: 12
        z: 1
    }

    TextInput {
        id: textInputIP
        x: 479
        y: 0
        width: 59
        height: 20
        text: qsTr("localhost")
        font.pixelSize: 12
        z: 1
    }

    Rectangle {
        id: rectangle
        x: 404
        y: 0
        width: 236
        height: 41
        color: "#ffffff"
        border.color: "#020202"
        z: 0
    }

    Button {
        id: button
        x: 565
        y: 17
        width: 70
        height: 19
        text: qsTr("Задать")
        z: 1

        onClicked:
        {
            cObserver.setClientProperty(ipAddress, Number(port))
        }
    }



}




