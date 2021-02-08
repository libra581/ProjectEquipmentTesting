//Генерация создания CellOfTable по входным параметрам объекта obj{}
var component;
var sprite;

//Создание элемента CellOfTable внутри главного экрана
function createSpriteObjects(obj) {
    component = Qt.createComponent("CellOfTable.qml");
    if (component.status == Component.Ready)
        finishCreation(obj);
    else
        component.statusChanged.connect(finishCreation);
}

function finishCreation(obj) {
    if (component.status == Component.Ready)
    {
        sprite = component.createObject(rowLayout, {textLabel: obj["text"], disabledToolTip: obj["disabledToolTip"]});

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
