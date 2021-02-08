//Статус WidgetBlock (Цвет заднего фона - зеленый, красный, серый)
var ArrayOfStatus = {"NOT_INFORMATION": '#c4c4c4',
                     "CORRECT": '#3FF090',
                     "ERROR": '#FF9898'};

function getArrayStatus() {
    return ArrayOfStatus;
}

function getStatusNotInformation() {
    return "NOT_INFORMATION";
}

function getStatusCorrect() {
    return "CORRECT";
}

function getStatusError() {
    return "ERROR";
}


//Генерация создания WidgetBlock по входным параметрам объекта obj{}
var component;
var sprite;

//Создание элемента WidgetBlock внутри главного экрана
function createSpriteObjects(obj) {
    component = Qt.createComponent("WidgetBlock.qml");
    if (component.status == Component.Ready)
        finishCreation(obj);
    else
        component.statusChanged.connect(finishCreation);

    return sprite;
}

function finishCreation(obj) {
    if (component.status == Component.Ready)
    {
        sprite = component.createObject(itemRoot, {x: obj["x"],
                                                   y: obj["y"],
                                                   width: 285,
                                                   height: 306,
                                                   antialiasing: false,
                                                   z: -1,
                                                   text_title: obj["text_title"],
                                                   status: obj["status"] });
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


