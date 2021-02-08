/*
* cCycleLabel - класс отображения текста в виде QLabel над эллипсом.
* *********************************************************************
* Назначение класса: класс cCycleLabel явялется обычной меткой, которая
* необходима для отображения текста над эллипсом.
* *********************************************************************
* Свойства класса:
* color             - цвет текста;
* parent            - родитель-объект.
* *********************************************************************
* Используемые методы:
* cCycleLabel     - конструктор класса cCycleLabel;
* setAutoUpdateLabel - метод, обновляющий текст;
* paintEvent      - виртуальный обработчик событий рисования объекта;
* ~cCycleLabel    - деструктор  класса cCycleLabel.
* *********************************************************************
*/

#ifndef CCYCLELABEL_H
#define CCYCLELABEL_H

#include <QLabel>
#include <QPainter>
#include <qDebug>

class cCycleLabel : public QLabel
{
private:
    QColor color;
    QWidget *parent;

public:
    cCycleLabel            ( const QColor &color,
                            QWidget *parent = nullptr );

    void setAutoUpdateLabel(                          );
    void paintEvent        ( QPaintEvent *event       );

    ~cCycleLabel           (                          );

};

#endif // CCYCLELABEL_H
