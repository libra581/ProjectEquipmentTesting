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
