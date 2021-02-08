var component;
var sprite;

function createSpriteObjects(obj) {
    component = Qt.createComponent("CustomTableWidget.qml");
    if (component.status == Component.Ready)
        finishCreation(obj);
    else
        component.statusChanged.connect(finishCreation);

    return sprite;
}

function finishCreation(obj) {
    if (component.status == Component.Ready)
    {
        sprite = component.createObject(rootItem, { x: obj["x"], y: obj["y"],
                                                    width: obj["width"], height: obj["height"],
                                        doubleArrayOfData: obj["doubleArrayOfData"], titleTable: obj["titleTable"],
                                        visible: obj["visible"]});
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
