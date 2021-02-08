#include "ccycleEllipse.h"

#include <QDebug>


/*********************************************************************
 * cCycleEllipse     - конструктор класса сCycleEllipse.
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
cCycleEllipse::cCycleEllipse(int x, int y, int width, int height,
                             QString information, const QColor& pColorItem,
                             QWidget* parent ):
    QWidget(parent)
{
    this->myPenBorder = new QColor( Qt::white );
    this->myPenBorder ->setAlpha  (     0     );

    flag = false;

    this->text  = information;
    this->color = pColorItem ;

    this->setStyleSheet("background:  rgba(0, 0, 0, 0);");
    this->setGeometry  ( x,  y,  width + 4,  height + 4 );

    gradient.setStart     ( 0,  0            );
    gradient.setFinalStop ( 0,  height * 0.7 );
    gradient.setColorAt   ( 0,  Qt::white    );
    gradient.setColorAt   ( 1,  color        );
}

/*********************************************************************
 * setText - метод, задающий текст метки эллипса.
 * *******************************************************************
 * Формальный параметр:
 * text        - текст для инициализации метки над эллипсом.
 * ********************************************************************/
void cCycleEllipse::setText( QString *text )
{
    this->text      = *text;
    labAboveEllipse -> setText( *text );
}

/*********************************************************************
 * Text - метод, возвращающий текст метки.
 * ********************************************************************/
QString cCycleEllipse::Text( void )
{
    return this->text;
}

/*********************************************************************
 * Color   - метод, возвращающий текущий цвет объекта.
 * ********************************************************************/
QColor cCycleEllipse::Color()
{
    return color;
}

/*********************************************************************
 *  createPCycleLabel - метод, создающий объект метки над эллипсом.
 * ********************************************************************/
cCycleLabel* cCycleEllipse::createPCycleLabel()
{
    labAboveEllipse = new cCycleLabel( this->color, this);
    return labAboveEllipse;
}

/*********************************************************************
 * setAutoUpdateLabel- метод, обновляющий объект метки.
 * ********************************************************************/
void cCycleEllipse::setAutoUpdateLabel()
{
    labAboveEllipse->setAutoUpdateLabel();
}

/*********************************************************************
 * calculatInterval  - метод, высчитывающий длину отрезка от левой
 * до правой границы эллипса.
 * *******************************************************************
 * Формальные параметры:
 * begin_value  - начало отрезка;
 * end_value    - конец отрезка.
 * *******************************************************************
 * Локальная переменная:
 * value - расстрояние между началом и концом отрезка.
 **********************************************************************/
int cCycleEllipse::calculatInterval( int begin_value, int end_value )
{
    int    value = qAbs( begin_value - end_value );
    this->addText( value );
    return value;
}

/*********************************************************************
 * addText  - метод, задающий текст метки.
 * *******************************************************************
 * Формальный параметр:
 * length  - длина отрезка.
 * ********************************************************************/
void cCycleEllipse::addText( int length )
{
    labAboveEllipse->setText( this->text +
                              "\nt = "   +
                              QString::number(length) +
                              " cек" );
}

/*********************************************************************
 * validationCorrectWidth - метод, высчитывающий корректную ширину объекта.
 * *******************************************************************
 * Формальные параметры:
 * rightSide - параметр, хранящий true, если сторона правая, иначе
 * false, если сторона левая;
 * value - значение, которо показывает на сколько изменилась ширина.
 * ********************************************************************/
bool cCycleEllipse::validationCorrectWidth( bool rightSide, int value )
{
    qDebug() << "validationCorrectWidth";
    if ( rightSide )
    {
         //Правая сторона
         extra_width = value - x();
    }
    else
    {
         //Левая сторона
         extra_width = width() + x() - value;
    }

    if ( extra_width < 2 )
    {
        QApplication::restoreOverrideCursor();
        QMessageBox::information(0,
                                 "Ошибка размера",
                                 "Меньше размер установить нельзя");
        return false;
    }
    else if(text == "Т иок" && extra_width > 600 )
    {
        QApplication::restoreOverrideCursor();
        QMessageBox::information(0,
                                 "Ошибка размера",
                                 "Больше размер установить нельзя");
        return false;
    }
    else if(text == "Т 1-го реж." && extra_width > 2500 )
    {
        QApplication::restoreOverrideCursor();
        QMessageBox::information(0,
                                 "Ошибка размера",
                                 "Больше размер установить нельзя");
        return false;
    }


    return true;
}

/*********************************************************************
 * setColorPen - метод, задающий цвет границы объекта.
 * *******************************************************************
 * Формальные параметры:
 * color - цвет границы объекта.
 * *******************************************************************/
void cCycleEllipse::setColorPen(QColor* color)
{
    this->myPenBorder->setRgba( color->rgba() );
    this->repaint();
}

/*********************************************************************
 * colorPen - метод, возвращающий цвет границы объекта.
 * *******************************************************************/
QColor cCycleEllipse::colorPen()
{
    return *( this->myPenBorder );
}

/*********************************************************************
 * infoFocus - метод, возвращающий выбран ли пользователем элемент или нет.
 * ********************************************************************/
bool cCycleEllipse::infoFocus()
{
    return flag;
}

/*********************************************************************
 * paintEvent - виртуальный обработчик событий рисования объекта.
 * *******************************************************************
 * Формальный параметр:
 * event - указатель на событие класса QPaintEvent.
 * *******************************************************************/
void cCycleEllipse::paintEvent( QPaintEvent *event )
{
    QPainter painter;

    painter.begin( this );

    painter.setRenderHint   ( QPainter::Antialiasing, true           );
    painter.setBrush        ( gradient                               );
    painter.setPen          ( QPen ( *myPenBorder, 2 )               );
    painter.drawRoundedRect ( 2, 2, width() - 4, height() - 4, 6, 30 );

    this->render( &painter, QPoint( 0, 0 ) );

    painter.end( );

    QWidget::paintEvent( event );

}

/*********************************************************************
 * mousePressEvent   - виртуальный обработчик событий нажатия кнопки мыши.
 * *******************************************************************
 * Формальный параметр:
 * event -  указатель на событие класса QMouseEvent.
 * *******************************************************************
 * Локальные переменные:
 * pProxyPar     - прокси виджет на объект сцены, для добавлении эффекта;
 * effectShadow  - эффект тени для прокси виджета.
 *********************************************************************/
void cCycleEllipse::mousePressEvent( QMouseEvent *event )
{
    if ( !flag )
    {
        gradient.setStart    ( 0, 0         );
        gradient.setFinalStop( 0, height()  );
        gradient.setColorAt  ( 1, Qt::white );
        gradient.setColorAt  ( 0, color     );

        QGraphicsProxyWidget *pProxyPar = this->graphicsProxyWidget();
        QGraphicsDropShadowEffect *effectShadow=new QGraphicsDropShadowEffect();
        effectShadow->setBlurRadius(10);
        effectShadow->setOffset(0,1);
        effectShadow->setColor(color);
        pProxyPar->setGraphicsEffect(effectShadow);

        this->myPenBorder->setAlpha(0);

        this->move(this->x()+1,this->y()+1);
    }
    else
    {
        gradient.setStart(0,0);
        gradient.setFinalStop(0,height()*0.7);
        gradient.setColorAt(0, Qt::white);
        gradient.setColorAt(1, color);

        QGraphicsProxyWidget *pProxyPar = this->graphicsProxyWidget();
        QGraphicsDropShadowEffect *effectShadow=new QGraphicsDropShadowEffect();
        effectShadow->setBlurRadius(10);
        effectShadow->setOffset(2,2);
        effectShadow->setColor(color);
        pProxyPar->setGraphicsEffect(effectShadow);

        this->move(this->x()-1,this->y()-1);
    }

    flag = !flag;

    this->update();

    QWidget::mousePressEvent(event);
}

/*********************************************************************
 * ~cCycleEllipse    - деструктор класса cCycleEllipse.
 * *******************************************************************/
cCycleEllipse::~cCycleEllipse()
{
    if( pMainEllipse )
         delete pMainEllipse;

    if( labAboveEllipse )
         delete labAboveEllipse;

    if( myPenBorder )
        delete myPenBorder;
}

  /*----------------------------------------------------*/
 // ////////////     Cсигналы и слоты    ///////////// //
/*----------------------------------------------------*/

/*********************************************************************
 * slotExpandWidthOnTheLeft  - слот, изменяющий ширину объекта слева.
 * *******************************************************************
 * Формальный параметр:
 * value - значение, которое показывает насколько меняется ширина объекта.
 * *******************************************************************/
void cCycleEllipse::slotExpandWidthOnTheLeft( int value )
{
    if( validationCorrectWidth ( false, value ) )
    {
        setGeometry( value, y(), extra_width, height() );
    }
}

/*********************************************************************
 * slotExpandWidthOnTheRight - слот, изменяющий ширину объекта справа.
 * *******************************************************************
 * Формальный параметр:
 * value - значение, которое показывает насколько меняется ширина объекта.
 * *******************************************************************/
void cCycleEllipse::slotExpandWidthOnTheRight( int value )
{
    if(validationCorrectWidth( true, value ) )
    {
        setGeometry( x(), y(), extra_width, height() );
    }
}
