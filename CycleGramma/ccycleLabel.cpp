#include "ccycleLabel.h"

/*********************************************************************
 * cCycleLabel     - конструктор класса cCycleLabel.
 * *******************************************************************
 * Формальные параметры:
 * color    - цвет эллипса;
 * parent   - указатель, хранящий объект родителя.
 * *******************************************************************/
cCycleLabel::cCycleLabel( const QColor &color, QWidget *parent /* = 0 */):
    QLabel( parent )
{
    setStyleSheet( "background:  rgba(0, 0, 0, 0);" );

    this->color  = color ;
    this->parent = parent;
}

/*********************************************************************
 * setAutoUpdateLabel - метод, обновляющий текст.
 * *******************************************************************/
void cCycleLabel::setAutoUpdateLabel()
{
    this->setGeometry( parent->x(), parent->y() - 30, 100, 30 );

    this->repaint(   );
    this->update (   );
}

/*********************************************************************
 * paintEvent  - виртуальный обработчик событий рисования объекта.
 * *******************************************************************
 * Формальный параметр:
 * event - указатель на событие класса QPaintEvent.
 * ******************************************************************/
void cCycleLabel::paintEvent( QPaintEvent *event )
{
    QPainter painter;
    painter.begin( this );

    painter.setRenderHint( QPainter::Antialiasing, true   );
    painter.setBrush     ( QBrush ( color )               );
    painter.setPen       ( color                          );
    painter.drawText     ( 0, 0, 100, 30, 0, this->text() );

    painter.end();

    QWidget::paintEvent( event );
}

/*********************************************************************
 * ~cCycleLabel    - деструктор  класса cCycleLabel.
 * *******************************************************************/
cCycleLabel::~cCycleLabel()
{

}



