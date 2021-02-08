/*
********************************************************
cSceneWithWidget - основной класс, определяющий механику
всех сцен (является родительским классом всех сцен, содержащих
технологические процессы).
********************************************************
Свойства класса:
pOneParameter  - виджет, отображающий на сцене
технологически процессы циклограммы;

objectSelected - дополнительный указатель, хранящий адрес
пойманного виджета фильтром событий при возникновении
какого-либо события;

pObjectExtra - дополнительный указатель, необходимый для
механики выбора элемента циклограммы, хранящий адрес
предыдущего виджета, фильтром событий при возникновении
какого-либо события;

polygon_left, polygon_right   - виджет, отображающий на сцене
элементы настроек отрезков времени;

line_left, line_right         - виджет, отображающий на сцене
элементы определения длительности отрезков времени;

proxyPolygonLeft, proxyPolygonRight   - прокси виджет,
хранящий элементы настроек отрезков времени;

coord_Cursor - координаты курсора по отношению к левому верхнему
углу текущей сцены на представлении;

dinamicGroupWidget - динамический лист добавленных и
отображаемых виджетов.
**********************************************************
Используемые методы:

cSceneWithWidget    - конструктор класса сSceneWithWidget;

displaysSettingItems   - реализует добавление и отображение
элементов настройки технологических отрезков на сцене циклограммы;

deleteSettingItems     - реализует удаление элементов
настройки технологических отрезков на сцене циклограммы;

shiftLeftSettingItems  - реализует сдвиг элементов настройки
эллипса в левую сторону;

shiftRightSettingItems - реализует сдвиг элементов настройки
эллипса в правую сторону;

publicChangeEllipse - метод, реализующий общий механизм
сдвига элементов настройки эллипса;

mouseMoveEvent      - обработчик событий, получающий события
перемещения мыши на сцене;

collidingUpdate     - метод, реализующий перемещение элементов
на сцене при их "столкновении";

deleteCycleEllipse  - метод, удаляющий эллипсы (технологические процессы)
со сцены;

drawBackground      - метод, рисующий задний фон сцены;

updSceneDueItems    - метод, расширяющий сцену в зависимости от размера
элементов на ней;

countWidgetOnScene  - метод, возвращающий количество эллипсов на сцене;

sentAllSignalsChange - метод, высылающий сигналы со значениями Тиок, Т1-ый режим;

setLabelEllipse      - метод, устанавливающий в тексте новую длительность
над эллипсом;

~cSceneWithWidget    - деструктор класса cSceneWithWidget.
*************************************************************
Используемые сигналы:
expand              - сигнал, высылающий координаты по осям Ox и Оу
эллипса слоту;
signalchangeIOK     - сигнал, высылающий длительность Тиок при
изменении эллипса;
signalchangeOneMode - сигнал, высылающий новую длительность Т1-ый режим
при изменении эллипса.
*************************************************************
Используемые слоты:
changeIOK     - слот, изменяющий размер эллипса "Тиок";
changeOneMode - слот, изменяющий размер эллипса "Т1-ый режим";
expandScene   - слот, отправляющий координаты эллипса сцены в
сигнале expand.
*************************************************************
*/

#ifndef CSCENEWITHWIDGET_H
#define CSCENEWITHWIDGET_H

#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QList>
#include <QPushButton>
#include <QStyle>
#include <QCommonStyle>
#include <QMessageBox>

#include "ccycleEllipse.h"
#include "ccyclePolygon.h"
#include "ccycleLine.h"

class cSceneWithWidget : public QGraphicsScene
{
    Q_OBJECT

protected:
    cCycleEllipse   * pOneParameter,
                    * objectSelected,
                    * pObjectExtra;

    cCyclePolygon   * polygon_left  = NULL,
                    * polygon_right = NULL;

    cCycleLine      * line_left     = NULL,
                    * line_right    = NULL;


    QGraphicsProxyWidget    * proxyPolygonLeft,
                            * proxyPolygonRight;

    QList <cCycleEllipse* > dinamicGroupWidget;

    QPointF coord_Cursor;


    void displaysSettingItems       ( cCycleEllipse*        );
    void shiftLeftSettingItems      ( cCyclePolygon*        );
    void shiftRightSettingItems     ( cCyclePolygon*        );
    inline void publicChangeEllipse ( int, int, int         );


public:
    explicit cSceneWithWidget   ( QRectF rect, QObject *parent = nullptr );

    virtual void mouseMoveEvent ( QGraphicsSceneMouseEvent *             );

    void collidingUpdate        (  cCyclePolygon* ,  cCycleEllipse*, int );
    void deleteCycleEllipse     ( int                                    );
    void drawBackground         (QPainter *painter, const QRectF &rect   );
    void updSceneDueItems       (                                        );
    int  countWidgetOnScene     (                                        );
    void sentAllSignalsChange   (                                        );
    void setLabelEllipse        (int, int                                );
    void deleteSettingItems     (                                        );

    ~cSceneWithWidget   (       );

signals:
    void expand               (int x,    int y       );
    void signalchangeIOK      (int                   );
    void signalchangeOneMode  (int                   );

public slots:
    void changeIOK            ( int                  );
    void changeOneMode        ( int                  );
    void expandScene          ( cCycleEllipse *watch );

};


#endif // CSCENEWITHWIDGET_H
