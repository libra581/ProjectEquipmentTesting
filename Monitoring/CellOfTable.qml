import QtQuick 2.4
import QtQuick.Layouts 1.3

CellOfTableForm {
    anchors.verticalCenter: parent.verticalCenter
    Layout.preferredWidth: parent.width / arrayOfData.length
    Layout.minimumHeight: 40
}
