import QtQuick 2.4

ItemTypeAndStateRowForm {
    id: rootItem

    state: "correct"

    //Состояние строки таблицы Резерва или Основы
    //Включает в себя 2 состояния ItemTypeAndStateRowForm: норма(зелен.) и ошибка(красн.).
    states: [
        State {
            name: "correct"
            PropertyChanges {
                id: itemCorrectState
                target: rootItem.rectBackGrnd
                color: "green"
            }
        },

        State {
            name: "error"
            PropertyChanges {
                id: itemErrorState
                target: rootItem.rectBackGrnd
                color: "red"
            }
        }
    ]

}
