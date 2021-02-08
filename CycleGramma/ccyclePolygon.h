/*
* cCyclePolygon - класс отображения ромба, слевой и справой стороны эллипса.
* *********************************************************************
* Назначение класса: рисовать прямоугольники, с помощью которых
* пользователь настраивает ширину эллипса.
* *********************************************************************
* Свойства класса:
* pRhombus          - указатель, хранящий ромб типа QPolygon;
* color             - цвет линий.
* *********************************************************************
* Используемые методы:
* cCyclePolygon     - конструктор класса cCyclePolygon;
* paintEvent        - виртуальный обработчик событий рисования объекта;
* ~cCyclePolygon    - деструктор  класса cCyclePolygon.
* *********************************************************************
* Используемые сигналы:
* signalExpandWidthOnTheLeft  - сигнал, высылающий насколько эллипс
* расширился влевую сторону при изменении курсора;
* signalExpandWidthOnTheRight - сигнал, высылающий насколько эллипс
* расширился вправо сторону при изменении курсора.
* *********************************************************************
*/

#ifndef CCYCLEPOLYGON_H
#define CCYCLEPOLYGON_H

#include <QWidget>
#include <QPolygon>
#include <QPainter>
#include <QEvent>
#include <QApplication>

class cCyclePolygon : public QWidget
{
    Q_OBJECT

private:
    QPolygon* pRhombus;
    QColor    color;

public:
    cCyclePolygon (qreal, qreal, qreal, qreal,
                    const QColor &, QWidget *parent = nullptr );

    virtual void paintEvent ( QPaintEvent *event             );

    ~cCyclePolygon( );

signals:
    void signalExpandWidthOnTheLeft  ( int value );
    void signalExpandWidthOnTheRight ( int value );

};

#endif // CCYCLEPOLYGON_H
