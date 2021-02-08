/***************************************************************
** typeEquipments - объект, содержащий типы аппаратуры.
****************************************************************
** Создан 10.10.2020 Семенов Д.С. Заявка №00004
****************************************************************/

import QtQuick 2.0

QtObject
{
    id: typeEquipments

    readonly property int tBASI: 0
    readonly property int tBAPPD: 1

    readonly property string sBASI: "BASI"
    readonly property string sBAPPD: "BAPPD"
}
