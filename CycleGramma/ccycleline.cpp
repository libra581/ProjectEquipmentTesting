#include "ccycleLine.h"

#include <qDebug>

/*********************************************************************
 * cCycleLine     - конструктор класса cCycleLine.
 * *******************************************************************
 * Формальные параметры:
 * p1        - координата точки начала отрезка;
 * p2        - координата точки конца  отрезка;
 * width     - ширины отрезка;
 * height    - высота отрезка;
 * information - текстовая информация об отрезке;
 * pColorItem  - цвет отрезка;
 * parent   - указатель, хранящий объект родителя.
 * ********************************************************************/
cCycleLine::cCycleLine(   QPoint p1          ,
                          qreal width        , qreal height            ,
                          QString information, const QColor& pColorItem,
                          QWidget *parent /* = 0 */)
    :QWidget( parent )
{

    this->color = pColorItem;

    pLine = new QLine ( 1, 0, 1, height );
    pText = new QLabel( this            );

    pText->setText( information );

    setStyleSheet( "background:  rgba(0, 0, 0, 0);" );

    setGeometry  ( QRect( p1.rx(), p1.ry(), width, height ) );

    value = 0;
}

/*********************************************************************
 * paintEvent     - виртуальный обработчик событий рисования объекта.
 * *******************************************************************
 * Формальный параметр:
 * event - указатель на событие класса QPaintEvent.
 * ********************************************************************/
void cCycleLine::paintEvent( QPaintEvent *event )
{
    value = qCeil( ( x() - 15 ) / 3 ) - 117;

    QPainter painter;
    painter.begin( this );

    painter.setPen   ( Qt::yellow   );
    painter.setBrush ( Qt::NoBrush  );
    painter.drawLine ( *pLine       );
    painter.setPen   ( color        );
    painter.drawText ( QRect( 5, this->height() * 0.5, 25, 20 ),
                       QString::number( value ).append("")    );

    painter.end();

    QWidget::paintEvent( event );
}

/*********************************************************************
 * Value  - метод, возвращающий значение на циклограмме линии.
 * ******************************************************************/
int cCycleLine::Value()
{
    return value;
}

/*********************************************************************
 * ~cCycleLine  - деструктор  класса cCycleLine.
 * *******************************************************************/
cCycleLine::~cCycleLine()
{
    if( pLine )
        delete pLine;

    if( pText )
        delete pText;
}

