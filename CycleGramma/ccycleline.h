/*
* cCycleLine - класс отображения линий, измеряющих начало и конец
* параметра режима на циклограмме.
* *********************************************************************
* Свойства класса:
* value             - значение начала или конца параметра, в зависимости
* от расположения линии;
* color             - цвет линий;
* pLine             - указатель, хранящий линию типа QLine,
* pText             - указатель, хранящий текст, отображающийся справа от линии
* типа pText.
* *********************************************************************
* Используемые методы:
* cCycleLine     - конструктор класса cCycleLine;
* Value          - метод, возвращающий значение на циклограмме линии;
* paintEvent     - виртуальный обработчик событий рисования объекта;
* ~cCycleLine    - деструктор  класса cCycleLine.
* *********************************************************************
*/

#ifndef CCYCLELINE_H
#define CCYCLELINE_H

#include <QWidget>
#include <QPolygon>
#include <QPainter>
#include <QEvent>
#include <QLabel>

#include "qmath.h"

class cCycleLine : public QWidget
{
    Q_OBJECT

private:
    int     value;
    QColor  color;
    QLine * pLine;
    QLabel* pText;

public:
    cCycleLine(QPoint, qreal, qreal, QString,
                const QColor &, QWidget *parent = nullptr );

    int          Value      (                              );
    virtual void paintEvent ( QPaintEvent *event           );

    ~cCycleLine             (                              );
};


#endif // CCYCLELINE_H
