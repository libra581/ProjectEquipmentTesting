//Генерация создания RowOfTable по входным параметрам объекта obj{}
var component;
var sprite;

//Создание элемента RowOfTable внутри главного экрана
function createSpriteObjects(obj) {
    component = Qt.createComponent("RowOfTable.qml");
    if (component.status == Component.Ready)
        finishCreation(obj);
    else
        component.statusChanged.connect(finishCreation);

    return sprite;
}

function finishCreation(obj) {
    if (component.status == Component.Ready)
    {
        sprite = component.createObject(rectBackground, { y: obj["y"] + rectBackground.height*0.3, colorBackGrnd: obj["color"], opacityBackGrnd: obj["opacity"],
                                           arrayOfData: obj["arrayOfData"], idRow: obj["idRow"], typeMode: obj["typeMode"]});
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
