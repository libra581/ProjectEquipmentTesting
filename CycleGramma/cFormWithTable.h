/*
* cFormWithTable - класс, содержащий виджет с таблицами для любого режима.
* *********************************************************************
* Назначение класса: описывает правила взаимодействия и логику
* работы пользователя и программиста с таблицами и дополнительными
* выпадающими списками.
* *********************************************************************
* Свойства класса:
* ui        - указатель, содержащий главное окно;
* flagPush  - флаг, показывающий внесены ли данные в таблицу;
* numMode   - номер режима по названию;
* numTabMode- номер режима по расположению в QTabWidget;
* relateItems - структура, содержащая поля c названием, типом и прибором;
* comWord   - поле "Кодовое слово"   структуры relateItems;
* type      - поле "Название"        структуры relateItems;
* app       - поле "Прибор"     структуры relateItems;
* rk_On     - структурa, содержащая описание разовой команды на включение;
* ip        - структурa, содержащая описание ИП;
* mko       - структурa, содержащая описание МКО;
* onceMode  - структурa, содержащая описание первого режима;
* twiceMode - структурa, содержащая описание второго режима;
* iok       - структурa, содержащая описание ИОК;
* rk_Off    - структурa, содержащая описание разовой команды на выключение;
* tkpo      - структурa, содержащая описание ТКПО;
* usb       - структурa, содержащая описание USB;
* init      - структурa, содержащая описание ИНИТ;
* intl      - структурa, содержащая описание инициализации.
* *********************************************************************
* Используемые методы:
* cFormWithTable    - конструктор класса cFormWithTable;
* addItemsInTabPar  - вспомогательный метод, позволяющий добавить сразу три поля
* в таблицу по полям структуры  relateItems;
* addModeRecord     - метод, подготавливающий таблицу для режима ДР-ЗИ;
* addModePlay       - метод, подготавливающий таблицу для режима ДР-ВИ(КП);
* pushData          - метод, заполняющий таблицу пользовательскими значениями
* в зависимости от названия режима;
* pushDataModeRec   - метод, заполняющий таблицу вычислениями, если
* выбран режим ДР-ЗИ;
* pushDataModePlay  - метод, заполняющий таблицу вычислениями, если
* выбран режим ДР-ВИ(КП);
* pushMode          - метод, заполняющий таблицу в столбце "Номер режима";
* setExtraTable     - метод, предоставляющий доступ к различным элементам класса
* cFormWithTable в зависимости от режима;
* flagPushData      - метод, возвращающий значение флага flagPush;
* dataComBoxForFile - метод, переносящий данные из группы "Первый режим" в файл;
* ~cFormWithTable   - деструктор  класса cFormWithTable.
* *********************************************************************
* Используемый слот:
* on_tableParameter_2_itemChanged - слот, вычисляющий длительность каждого
* параметра режима в таблице.
* *********************************************************************
*/

#ifndef CFORMWITHTABLE_H
#define CFORMWITHTABLE_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QTextStream>
#include <QString>

namespace Ui {
    class cFormWithTable;
}

class cFormWithTable : public QWidget
{
    Q_OBJECT

public:
    explicit cFormWithTable ( int, int, QWidget *parent = nullptr );

    void pushData        (  int, int, int, int, qint8   );
    void pushMode        (  int                         );
    void pushDataModeRec (  int, int, qint8             );
    void pushDataModePlay(  int, qint8                  );

    bool flagPushData     (                    );
    void dataComBoxForFile( int, QTextStream & );

    ~cFormWithTable();

protected:
    void        addModeRecord   (int                                   );
    void        addModePlay     (int                                   );
    inline void addItemsInTabPar( int, QString &, QString &, QString & );

private:
    void setExtraTable( int );

private slots:
    void on_tableParameter_2_itemChanged( QTableWidgetItem * );

private:
    Ui::cFormWithTable *ui;

    bool flagPush   ;
    int  numMode    ;
    int  numTabMode ;

    struct relateItems
    {
       QString comWord;
       QString type   ;
       QString app    ;

    } rk_On, ip    , mko , onceMode, twiceMode,
      iok  , rk_Off, tkpo, usb     , init     , intl;
};

#endif // CFORMWITHTABLE_H
