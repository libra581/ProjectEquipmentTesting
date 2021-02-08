/*
* cCycleEllipse - класс отображения главного элемента на циклограмме
* (фигуры в виде эллипса).
* *********************************
* Назначение класса: класс cCycleEllipse нужен для отображения
* фигуры в виде эллипса, которую можно помещать на сцену,
* а также для отображения некоторых эффектов данной фигуры.
* *********************************
* Свойства класса:
* pMainEllipse      - эллипс, который рисуется на сцене;
* extra_width       - дополнительная величина для подсчета ширины эллипса;
* color             - цвет эллипса;
* text              - текст, отображаемый выше над элиппсом на сцене;
* labAboveEllipse   - метка, содержащая текст и длительность режима(эллипса) на сцене;
* gradient          - градиент, для закрашивания эллипса;
* myPenBorder       - инструмент для рисования границ эллипса;
* flag              - флаг, предназначенный для отображения анимации наведения
* на объект.
************************************
* Используемые методы:
* cCycleEllipse     - конструктор класса сCycleEllipse;
* setText           - метод, задающий текст метки эллипса;
* Text              - метод, возвращающий текст метки;
* Color             - метод, возвращающий текущий цвет объекта;
* createPCycleLabel - метод, создающий объект метки над эллипсом;
* setAutoUpdateLabel- метод, обновляющий объект метки;
* calculatInterval  - метод, высчитывающий длину отрезка от левой
* до правой границы эллипса;
* addText           - метод, задающий текст метки;
* validationCorrectWidth - метод, высчитывающий корректную ширину объекта;
* setColorPen       - метод, задающий цвет границы объекта;
* colorPen          - метод, возвращающий цвет границы объекта;
* infoFocus         - метод, возвращающий выбран ли пользователем элемент или нет;
* paintEvent        - виртуальный обработчик событий рисования объекта;
* mousePressEvent   - виртуальный обработчик событий нажатия кнопки мыши;
* ~cCycleEllipse    - деструктор класса cCycleEllipse.
************************************
* Используемые слоты:
* slotExpandWidthOnTheLeft  - слот, изменяющий ширину объекта слева;
* slotExpandWidthOnTheRight - слот, изменяющий ширину объекта справа.
************************************
*/
#ifndef CCYCLEITEM_H
#define CCYCLEITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPointF>
#include <QLine>
#include <QLabel>
#include <QApplication>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <QGraphicsProxyWidget>
#include <QRgb>
#include <QMessageBox>

#include "ccycleLabel.h"
#include "ccyclePolygon.h"
#include "qmath.h"

class cCycleEllipse: public QWidget
{
    Q_OBJECT

private:
    QRectF*         pMainEllipse = nullptr;
    int             extra_width;
    QColor          color;
    QString         text;
    cCycleLabel*    labAboveEllipse;
    QLinearGradient gradient;
    QColor*         myPenBorder;
    bool            flag;

public:
    explicit     cCycleEllipse( int, int, int, int, QString, const QColor&, QWidget *parent = 0 );

    void         setText                ( QString*  );
    QString      Text                   (   void    );
    QColor       Color                  (   void    );
    cCycleLabel* createPCycleLabel      (           );
    void         setAutoUpdateLabel     (           );
    int          calculatInterval       ( int , int );
    void         addText                ( int       );
    bool         validationCorrectWidth ( bool, int );
    void         setColorPen            ( QColor*   );
    QColor       colorPen               (   void    );
    bool         infoFocus              (   void    );

    virtual void paintEvent     (QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);

    ~cCycleEllipse (    );

public slots:
    void slotExpandWidthOnTheLeft   ( int value );
    void slotExpandWidthOnTheRight  ( int value );
};

#endif // CCYCLEITEM_H
