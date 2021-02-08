#include "ccyclePolygon.h"

#include <qDebug>

/*********************************************************************
 * cCyclePolygon     - конструктор класса cCyclePolygon.
 * *******************************************************************
 * Формальные параметры:
 * x        - координаты вершины объекта класса по оси Ox;
 * y        - координаты вершины объекта класса по оси Oy;
 * width    - ширины объекта;
 * height   - высота объекта;
 * information - текстовая информация об объекте;
 * pColorItem  - цвет эллипса;
 * parent   - указатель, хранящий объект родителя.
 * ********************************************************************/
cCyclePolygon::cCyclePolygon(qreal x, qreal y,
                             qreal width, qreal height
                            ,const QColor& pColorItem, QWidget *parent):
    QWidget(parent)
{

    pRhombus  = new QPolygon();

    *pRhombus  << QPoint( 1,  5 ) << QPoint( 6, 10 )
               << QPoint( 11, 5 ) << QPoint( 6, 0  );

    this->color = pColorItem;

    this->installEventFilter( this );

    setStyleSheet( "background:  rgba(0, 0, 0, 0);" );
    setGeometry  ( QRect( x, y, width, height )     );
}

/*********************************************************************
 * paintEvent     - виртуальный обработчик событий рисования объекта.
 * *******************************************************************
 * Формальный параметр:
 * event - указатель на событие класса QPaintEvent.
 * ********************************************************************/
void cCyclePolygon::paintEvent( QPaintEvent *event )
{
    QPainter painter;
    painter.begin( this );

    painter.setPen      ( Qt::white       );
    painter.setBrush    ( QBrush( color ) );
    painter.drawPolygon ( *pRhombus       );

    painter.end();

    QWidget::paintEvent( event );
}

/*********************************************************************
 * ~cCyclePolygon  - деструктор  класса cCyclePolygon.
 * *******************************************************************/
cCyclePolygon::~cCyclePolygon()
{
    if( pRhombus )
        delete pRhombus;
}
