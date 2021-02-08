import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    id: root
    visible: true
    width: 1024
    height: 768
    title: qsTr("Ruslo Pro")


    minimumWidth: 930
    minimumHeight: 300

    SettingsMainForm
    {
        id: itemSettings
    }

    RusloMain
    {
        id: mainItem
        anchors.fill: parent
    }
}
