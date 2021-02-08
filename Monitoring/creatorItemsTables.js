var component;
var sprite;

//Создание элемента таблицы внутри выпадающего списка WidgetBlock
function createSpriteObjects(text_title) {
    component = Qt.createComponent("RectTableItem.ui.qml");
    if (component.status == Component.Ready)
        finishCreation(text_title);
    else
        component.statusChanged.connect(finishCreation);

    return sprite;
}

function finishCreation(text_title) {
    if (component.status == Component.Ready)
    {
        sprite = component.createObject(columnLayoutTables, {text_title: text_title});
        if (sprite == null)
        {
            console.log("Error creating object");
        }
    }
    else if (component.status == Component.Error)
    {
        console.log("Error loading component:", component.errorString());
    }
}
