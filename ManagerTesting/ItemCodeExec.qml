/***************************************************************
**
** ItemCodeExec - объект, содержащий коды возвратов.
****************************************************************
** Назначение класса: используется для анализа кодов возврата
** выполнения программных модулей.
****************************************************************
** Создан 10.10.2020 Семенов Д.С. Заявка №00004
****************************************************************
** Основные объекты:
** codeExec - коды возвратов программных модулей;
** serverCodeExec - коды возвратов серверной обработки.
****************************************************************/

import QtQuick 2.0

Item
{
    id: codeExec

    readonly property int iErrorPort: -3
    readonly property int iErrorFile: -2
    readonly property int iError: -1
    readonly property int iSuccess: 0
    readonly property int iWaiting: 1
    readonly property int iPortEmpty: 2
    readonly property int iAnalyzeError: 3

    property alias serverCodeExec: serverCodeExec

    QtObject
    {
        id: serverCodeExec

        readonly property int iEFAnalyze: -3
        readonly property int iEFInputData: -2
        readonly property int iEFCyclegramma: -1
        readonly property int iManager: 0
        readonly property int iFCyclegramma: 1
        readonly property int iFInputData: 2
        readonly property int iFAnalyze: 3
        readonly property int iSCyclegramma: 4
        readonly property int iSInputData: 5
        readonly property int iSAnalyze: 6
    }
}
