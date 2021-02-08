/***************************************************************
** ItemObserver - объект-наблюдатель, реализующий логику работы
** с программными модулями по плану испытаний.
****************************************************************
** Назначение класса: используется для запуска программных модулей
** по определенному планом времени, для анализа кодов возврата.
****************************************************************
** Создан 10.10.2020 Семенов Д.С. Заявка №00003
****************************************************************
** Основные переменные:
** pointDateInputData : string - время запуска модуля имитации
** исходных данных;
** pointDateAnalyze : string - время запуска модуля анализа;
** processInputData : alias myProcess - процесс, отвечающий за
** запуск модуля имитации исходных данных;
** processAnalyze : alias myProcess - процесс, отвечающий за
** запуск модуля анализа.
****************************************************************/

import QtQuick 2.0
import myProcess 1.0

Item
{
    id: rootItemObserver

    property string currentDate: Date().toLocaleString()
    property string pointDateInputData: "Пн дек 7 15:57:20 2020 GMT+0300"
    property string pointDateAnalyze:   "Пн дек 7 15:59:55 2020 GMT+0300"

    signal equalTimesInputData(string pTime)
    signal equalTimesAnalyze(string pTime)
    signal resultExecute(string moduleName, int result)

    property alias processInputData: processInputData
    property alias processAnalyze: processAnalyze

    ItemCodeExec
    {
        id: execCode
    }


    Process
    {
               id: processInputData
               onFinished:
               {
                   //Обработка завершения процесса
                   var result = readAll()
                   console.log(result)
                   rootItemObserver.resultExecute("inputData", result)
               }
    }

    Process
    {
               id: processAnalyze
               onFinished:
               {
                   //Обработка завершения процесса
                   var result = readAll()
                   console.log(result)
                   rootItemObserver.resultExecute("analyze", result)
               }
    }

    Timer
    {
        interval: 1000
        running: true
        repeat: true
        onTriggered:
        {
            //Обработка событий таймера
            currentDate = new Date().toLocaleString()

            //Если время равно времени запуска модуля имитации
            if(currentDate === pointDateInputData)
            {
                console.log(currentDate)
                console.log(pointDateInputData)

                rootItemObserver.equalTimesInputData(pointDateInputData)

                processInputData.start("C:\\Users\\sds\\Documents\\build-inputData-Desktop_Qt_5_15_0_MinGW_64_bit-Release\\release\\inputData.exe",
                                       [applicationWindow.sTypeEquipment, applicationWindow.pathFilePlan ]);

                cObserver.sendToServer("Исходные данные запущены. Параметры( "+applicationWindow.sTypeEquipment+
                                       ", " + applicationWindow.pathFilePlan + " )")
            }
            //Если время равно времени запуска модуля анализа
            else if(currentDate === pointDateAnalyze)
            {
                console.log(currentDate)
                console.log(pointDateAnalyze)

                rootItemObserver.equalTimesAnalyze(pointDateAnalyze)

                processAnalyze.start("C:\\Users\\sds\\Documents\\build-AnalyzeResult-Desktop_Qt_5_15_0_MinGW_64_bit-Release\\release\\AnalyzeResult.exe",
                                       [applicationWindow.sTypeEquipment, applicationWindow.pathFilePlan,
                                        applicationWindow.pathFileAnalyze, applicationWindow.pathFileTMI ]);


                cObserver.sendToServer("Анализ запущен. Параметры( "+applicationWindow.sTypeEquipment+
                                       ", " + applicationWindow.pathFilePlan +
                                       ", " + applicationWindow.pathFileAnalyze +
                                       ", " + applicationWindow.pathFileTMI + " )")
            }

            delete currentDate;
        }
    }
}
