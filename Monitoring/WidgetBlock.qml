import QtQuick 2.4

WidgetBlockForm {
    id: rootForm


    MouseArea
    {
        id: mainMouseArea
        anchors.fill: parent

        drag
        {
            target: rootForm
            axis: Drag.XandYAxis
            minimumX: 0
            minimumY: rootForm.height*0.1
            maximumX: rootRusloMainForm.width - rootForm.width
            maximumY: rootRusloMainForm.height - rootForm.height*0.4
        }

        z:-1
  }
}
