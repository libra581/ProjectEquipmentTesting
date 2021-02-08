import QtQuick 2.0

Item {
    id: itemSettings

    readonly property string webFontName: webFont.name
    readonly property string webFontLightName: webFontLight.name

    FontLoader
    {
        id: webFont
        source: "./fonts/OpenSans-Bold.ttf"
    }

    FontLoader
    {
        id: webFontLight
        source: "./fonts/OpenSans-Light.ttf"
    }


}
