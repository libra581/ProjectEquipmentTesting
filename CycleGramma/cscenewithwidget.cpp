#include "cSceneWithWidget.h"

/*********************************************************************
 * cSceneWithWidget     - конструктор класса cSceneWithWidget.
 * *******************************************************************
 * Формальные параметры:
 * rect     - размер сцены;
 * parent   - указатель, хранящий объект родителя.
 * ********************************************************************/
cSceneWithWidget::cSceneWithWidget( QRectF rect, QObject *parent /* = 0 */):
    QGraphicsScene( rect, parent )
{
    this->setBackgroundBrush( QBrush( Qt::black ) );
}

/*********************************************************************
 * drawBackground      - метод, рисующий задний фон сцены.
 * *******************************************************************
 * Формальные параметры:
 * painter     - инструмент для рисования фона сцены;
 * rect        - область сцены для рисования.
 * ********************************************************************
 * Локальные переменные:
 * pen          - перо, задающее цвет и тип кисти для рисовния;
 * gridSize     - расстояние между линиями циклограммы;
 * left         - левая границы (точка прорисовки на сцене);
 * currentLine  - номер, от которого зависит тип текущей линии;
 * x            - переменная, являющаяся началом нового отрезка;
 * bottom       - нижняя границы необходимая для задания начала и конца линии
 * по оси Ох и Оу.
 * ********************************************************************/
void cSceneWithWidget::drawBackground( QPainter *painter, const QRectF &rect )
{

    QPen pen;
    pen.setColor( QColor("#413d51") );
    pen.setBrush( QColor("#413d51") );

    painter->setPen  ( pen  );
    painter->setBrush( QBrush( QColor("#413d51") ) );
    painter->drawRect( rect );

    pen.setColor(         Qt::white   );
    pen.setBrush( QBrush( Qt::white ) );

    painter->setPen  ( pen         );
    painter->setBrush( Qt::NoBrush );

    int gridSize    = 20    ;
    int left        = -800  ;
    int currentLine = 0     ;
    int bottom      = this->sceneRect().top() + 200;

    for ( qreal x = left; x < rect.right(); x += gridSize )
    {
        switch( currentLine )
        {
            case 0: { painter->drawLine( QPoint( x , bottom - 40 ) , QPointF( x, bottom ) ); break; }
            case 1: { painter->drawLine( QPoint( x , bottom - 10 ) , QPointF( x, bottom ) ); break; }
            case 2: { painter->drawLine( QPoint( x , bottom - 25 ) , QPointF( x, bottom ) ); break; }
            case 3: { painter->drawLine( QPoint( x , bottom - 10 ) , QPointF( x, bottom ) ); break; }
            case 4: { painter->drawLine( QPoint( x , bottom - 25 ) , QPointF( x, bottom ) ); break; }
            case 5: { painter->drawLine( QPoint( x , bottom - 10 ) , QPointF( x, bottom ) ); break; }
            case 6: { painter->drawLine( QPoint( x , bottom - 25 ) , QPointF( x, bottom ) ); break; }
            case 7: { painter->drawLine( QPoint( x , bottom - 10 ) , QPointF( x, bottom ) ); break; }
        }

        currentLine++;

        if( currentLine > 7 )
        {
            currentLine = 0;
        }

    }

    painter->drawLine( QPoint( rect.left() , bottom + 1 ) , QPointF( rect.right() , bottom + 1 ) );
}

/*********************************************************************
 * deleteCycleEllipse  - метод, удаляющий эллипсы (технологические процессы)
 * со сцены.
 * *******************************************************************
 * Формальный параметр:
 * index     - номер эллипса на удаление.
 * ********************************************************************
 * Локальная переменная:
 * delWidget  -  указатель на эллипс из списка, который позволит
 * освободить память от эллипса.
 * ********************************************************************/
void cSceneWithWidget::deleteCycleEllipse( int index )
{
    cCycleEllipse *delWidget =  dinamicGroupWidget[ index ];

    for(int i = index + 1; i < dinamicGroupWidget.size(); i++)
    {
        dinamicGroupWidget[i] -> setGeometry( dinamicGroupWidget[i]->geometry().x() -
                                              delWidget->geometry().width() - 50,
                                              dinamicGroupWidget[i]->geometry().y(),
                                              dinamicGroupWidget[i]->geometry().width(),
                                              dinamicGroupWidget[i]->geometry().height());

        dinamicGroupWidget[i] -> setAutoUpdateLabel();

        dinamicGroupWidget[i-1] = dinamicGroupWidget[i];
    }

    delete delWidget;
    dinamicGroupWidget.removeAt( dinamicGroupWidget.size() - 1 );

    this->update();
}

/*********************************************************************
 * mouseMoveEvent  - обработчик событий, получающий события
 * перемещения мыши на сцене.
 * *******************************************************************
 * Формальный параметр:
 * event     - возникшее событие в программе.
 * ********************************************************************/
void cSceneWithWidget::mouseMoveEvent( QGraphicsSceneMouseEvent *event )
{
    if( polygon_left != NULL )
          coord_Cursor = event->scenePos();

     QGraphicsScene::mouseMoveEvent( event );
}

/*********************************************************************
 * displaysSettingItems   - реализует добавление и отображение
 * элементов настройки технологических отрезков на сцене циклограммы.
 * *******************************************************************
 * Формальный параметр:
 * objectSelected     - эллипс, с которым связанны элементы настройки.
 * ********************************************************************
 * Локальные переменные:
 * parent  -  указатель, созданный для удобства задания родителя элементам
 * настройки;
 * pointFirst     - переменная, хранящая расстояние от начала сцены до конца
 * эллипса на сцене;
 * coordOYPolygon - переменная, хранящая координату точки начала прямоугольника
 * на сцене по оси Оу;
 * coordOYLine    - переменная, хранящая координату точки начала линии на сцене
 * по оси Оу;
 * coordBoundLine - переменная, являющаяся высотой линии и координатой точки
 * окончания отрезка по оси Оу.
 * ********************************************************************/
void cSceneWithWidget::displaysSettingItems( cCycleEllipse* objectSelected )
{

    //Отображение элементов настроект засеченного эллипса

    QWidget *parent     = NULL;
    int  pointFirst     = objectSelected->x() + objectSelected->width();
    int  coordOYPolygon = objectSelected->y() + 2;

    polygon_left  = new cCyclePolygon(  objectSelected->x() - 12,
                                        coordOYPolygon,
                                        13, 12,
                                        QColor( "#ffb6c1" ), parent );

    polygon_right = new cCyclePolygon(  pointFirst + 2,
                                        coordOYPolygon,
                                        13, 12,
                                        QColor( "#ffb6c1" ), parent );

    proxyPolygonLeft  = this->addWidget( polygon_left  );
    proxyPolygonRight = this->addWidget( polygon_right );

    polygon_left ->installEventFilter( this );
    polygon_right->installEventFilter( this );

    int coordBoundLine = 190 - objectSelected->y();
    int coordOYLine    = objectSelected->y() + 12;

    line_left  = new cCycleLine( QPoint( objectSelected->x(),
                                         coordOYLine           ),
                                 25,     coordBoundLine, "",
                                 QColor( "#fdbdba" ), parent   );

    line_right = new cCycleLine( QPoint( pointFirst,
                                         coordOYLine  ),
                                 25,     coordBoundLine, "",
                                 QColor( "#fdbdba" ), parent   );



   this->addWidget( line_left  );
   this->addWidget( line_right );

    /*-------------------------------------------------------------*/
   // ////////////  Соединение сигналов и слотов    ///////////// //
  /*-------------------------------------------------------------*/
   connect( polygon_left,   SIGNAL( signalExpandWidthOnTheLeft(  int ) ),
            objectSelected, SLOT  ( slotExpandWidthOnTheLeft  (  int ) ) );

   connect( polygon_right,  SIGNAL( signalExpandWidthOnTheRight( int ) ),
            objectSelected, SLOT  ( slotExpandWidthOnTheRight  ( int ) ) );

}

/*********************************************************************
 * deleteSettingItems     - реализует удаление элементов
 * настройки технологических отрезков на сцене циклограммы.
 * *******************************************************************/
void cSceneWithWidget::deleteSettingItems()
{
    /*-------------------------------------------------------------*/
   // //////////// Разъединение сигналов и слотов   ///////////// //
  /*-------------------------------------------------------------*/

   //Удаление элементов настроек
    if( polygon_left != NULL )
    {
         disconnect( polygon_left,  SIGNAL( signalExpandWidthOnTheLeft ( int ) ) );
         delete polygon_left;
    }

    if( polygon_right != NULL )
    {
         disconnect( polygon_right, SIGNAL( signalExpandWidthOnTheRight( int ) ) );
         delete polygon_right;
    }

    if( line_left  != NULL )
         delete line_left;

    if( line_right != NULL )
         delete line_right;

    polygon_left  = NULL;
    polygon_right = NULL;
    line_left     = NULL;
    line_right    = NULL;
}

/*********************************************************************
 * shiftLeftSettingItems  - реализует сдвиг элементов настройки
 * эллипса в левую сторону.
 * *******************************************************************
 * Формальный параметр:
 * objectSelectedSide     - элемент управления ширины эллипса (квадрат).
 * ********************************************************************
 * Локальная переменная:
 * coordMoveLineX  -  переменная, хранящая значение, на которое следует сдвинуть
 * левую линию.
 * ********************************************************************/
void cSceneWithWidget::shiftLeftSettingItems( cCyclePolygon* objectSelectedSide )
{
    int coordMoveLineX = coord_Cursor.rx() + 7;

    objectSelectedSide ->move( coord_Cursor.rx() - 5,
                               objectSelectedSide->y() );

    line_left          ->move( coordMoveLineX,
                               line_left->y()          );

    emit objectSelectedSide -> signalExpandWidthOnTheLeft( coordMoveLineX );

    objectSelected->setAutoUpdateLabel( );
}

/*********************************************************************
 * shiftRightSettingItems - реализует сдвиг элементов настройки
 * эллипса в правую сторону.
 * *******************************************************************
 * Формальный параметр:
 * objectSelectedSide     - элемент управления ширины эллипса (квадрат).
 * ********************************************************************
 * Локальная переменная:
 * coordMoveLineX  -  переменная, хранящая значение, на которое следует сдвинуть
 * правую линию.
 * ********************************************************************/
void cSceneWithWidget::shiftRightSettingItems( cCyclePolygon* objectSelectedSide )
{
    int coordMoveLineX = coord_Cursor.rx() - 7;

    objectSelectedSide->move( coord_Cursor.rx() - 5,
                              objectSelectedSide->y() );

    line_right        ->move( coordMoveLineX,
                              line_right->y()         );

    emit objectSelectedSide->signalExpandWidthOnTheRight( coordMoveLineX );

    objectSelected->setAutoUpdateLabel( );
}

/*********************************************************************
 * collidingUpdate     - метод, реализующий перемещение элементов
 * на сцене при их "столкновении".
 * *******************************************************************
 * Формальные параметры:
 * selectedPolygon  - элемент управления шириной эллипса (квадрат);
 * selectedObject   - засеченный эллипс (выбранный пользователем);
 * value            - значение, на которое эллипс изменил свою ширину.
 * ********************************************************************
 * Локальные переменные:
 * extra_value - дополнительная величина, которая определяет на сколько
 * необходимо сдвинуть элементы в списке;
 * it          - итератор, ходящий по списку эллипсов сцены.
 * ********************************************************************/
void cSceneWithWidget::collidingUpdate(  cCyclePolygon* selectedPolygon,
                                         cCycleEllipse* selectedObject,
                                         int value    )
{
    int extra_value = value-selectedObject->x() + 7;

    QList< cCycleEllipse* >::iterator it = dinamicGroupWidget.begin();

    if(  selectedPolygon == polygon_right )
    {
        extra_value =  value-selectedObject->x() - selectedObject->width() - 7;
        while( *it != selectedObject )
        {
            ++it;
        }

        ++it;


        if( selectedObject == dinamicGroupWidget[3] )
        {
            (*it)->setGeometry( (*it)->x(), (*it)->y(),
                                (*it)->width() + extra_value,
                                (*it)->height() );

            (*it)->setAutoUpdateLabel();

            ++it;
        }
        else if( selectedObject == dinamicGroupWidget[5] )
             {
                 it -= 2;

                 (*it)->setGeometry((*it)->x(), (*it)->y(),
                                    (*it)->width() + extra_value,
                                    (*it)->height());

                 (*it)->setAutoUpdateLabel();

                 it += 2;
             }
    }

    if( ( selectedPolygon == polygon_left ) && ( selectedObject == dinamicGroupWidget[3] ) )
    {
        dinamicGroupWidget[4]->move       ( dinamicGroupWidget[4]->x() + extra_value,
                                            dinamicGroupWidget[4]->y()      );

        dinamicGroupWidget[4]->setGeometry( dinamicGroupWidget[4]->x(),
                                            dinamicGroupWidget[4]->y(),
                                            dinamicGroupWidget[4]->width() - extra_value,
                                            dinamicGroupWidget[4]->height() );

        dinamicGroupWidget[4]->setAutoUpdateLabel();
    }

    while( ( it != dinamicGroupWidget.end() ) && ( *it != selectedObject ) )
    {
        if ( ( (*it) != dinamicGroupWidget[4] ) || ( selectedObject == dinamicGroupWidget[6] ) )
        {
            (*it)->move( (*it)->x() + extra_value,
                         (*it)->y() );
        }
        else if( selectedObject == dinamicGroupWidget[5] )
        {
            (*it)->move       ( (*it)->x() + extra_value,(*it)->y() );
            (*it)->setGeometry( (*it)->x(),              (*it)->y(),
                                (*it)->width() - extra_value,
                                (*it)->height());
        }

        (*it)->setAutoUpdateLabel();

        ++it;
    }

    this->update();
}

/*********************************************************************
 * countWidgetOnScene  - метод, возвращающий количество эллипсов на сцене.
 * *******************************************************************/
int cSceneWithWidget::countWidgetOnScene()
{
    return dinamicGroupWidget.length();
}

/*********************************************************************
 * setLabelEllipse - метод, устанавливающий в тексте новую длительность
 * над эллипсом.
 * *******************************************************************
 * Формальные параметры:
 * index  - номер эллипса в списке;
 * sec    - новое время в тексте над эллипсом.
 * ********************************************************************/
void cSceneWithWidget::setLabelEllipse( int index , int sec)
{
    if( ( index < dinamicGroupWidget.length() ) && ( index >= 0 ) )
    {
       dinamicGroupWidget[index]->addText( sec );
       dinamicGroupWidget[index]->setAutoUpdateLabel( );

       this->update();
    }
    else
    {
        QMessageBox::critical(0,
                              "Ошибка",
                              "Неправильный индекс");
    }
}

/*********************************************************************
 * changeIOK     - слот, изменяющий размер эллипса "Тиок".
 * ********************************************************************
 * Формальный параметр:
 * value - величина, на которую изменяется технологический процесс.
 * ********************************************************************
 * Локальная переменная:
 * numProcess - номер технологического процесса в списке.
 *********************************************************************/
void cSceneWithWidget::changeIOK( int value )
{
    int numProcess = 5;
    objectSelected = dinamicGroupWidget[ numProcess ];
    this->publicChangeEllipse( numProcess, value, dinamicGroupWidget[ numProcess ]->x() + 7 );
    setLabelEllipse          ( numProcess, value );
}

/*********************************************************************
 * changeOneMode - слот, изменяющий размер эллипса "Т1-ый режим".
 * ********************************************************************
 * Формальный параметр:
 * value - величина, на которую изменяется технологический процесс.
 * ********************************************************************
 * Локальная переменная:
 * numProcess - номер технологического процесса в списке.
 *********************************************************************/
void cSceneWithWidget::changeOneMode( int value )
{
    int numProcess = 6;
    objectSelected = dinamicGroupWidget[ numProcess ];
    this->publicChangeEllipse( numProcess, value, dinamicGroupWidget[ numProcess ]->x() + 7 );
    setLabelEllipse          ( numProcess, value );
}

/*********************************************************************
 * publicChangeEllipse - метод, реализующий общий механизм
 * сдвига элементов настройки эллипса.
 * ********************************************************************
 * Формальный параметр:
 * index - номер элемента в листе эллипсов;
 * value - величина, на которую сдвигается технологический процесс;
 * extraInt - дополнительная величина для сдвига в процессе коллизии.
 * ********************************************************************
 * Локальная переменная:
 * tripleValue - тройная величина сдвига.
 *********************************************************************/
inline void cSceneWithWidget::publicChangeEllipse( int index, int value, int extraInt )
{
    int tripleValue = value + value + value;

    collidingUpdate(polygon_right, dinamicGroupWidget[ index ], tripleValue + extraInt );


    dinamicGroupWidget[ index ]->setGeometry( dinamicGroupWidget[ index ]->x(),
                                              dinamicGroupWidget[ index ]->y(),
                                              tripleValue,
                                              dinamicGroupWidget[ index ]->height());


    if( line_left )
    {
        line_left   ->setGeometry(  dinamicGroupWidget[ index ]->x() - 1,
                                    line_left->y(),
                                    line_left->width(),
                                    line_left->height()    );

        polygon_left->setGeometry(  line_left->x() - 12,
                                    polygon_left->y(),
                                    polygon_left->width(),
                                    polygon_left->height() );
    }

    if( line_right )
    {
        line_right   ->setGeometry( dinamicGroupWidget[ index ]->x() +
                                    dinamicGroupWidget[ index ]->width() - 1,
                                    line_right->y(),
                                    line_right->width(),
                                    line_right->height()    );

        polygon_right->setGeometry( line_right->x() + 2,
                                    polygon_right->y(),
                                    polygon_right->width(),
                                    polygon_right->height() );
    }

    dinamicGroupWidget[index]->setAutoUpdateLabel();

    this->updSceneDueItems();
}

/*********************************************************************
 * expandScene   - слот, отправляющий координаты эллипса сцены в
 * сигнале expand.
 * ********************************************************************
 * Формальный параметр:
 * watch - элемент сцены, являющийся эллипсом, координаты которого отправляются
 * в сигнале.
 * ********************************************************************/
void cSceneWithWidget::expandScene( cCycleEllipse* watch )
{
    emit expand( watch->frameGeometry().x(), watch->frameGeometry().y() );
}

/*********************************************************************
 * updSceneDueItems    - метод, расширяющий сцену в зависимости от размера
 * элементов на ней.
 * ********************************************************************/
void cSceneWithWidget::updSceneDueItems()
{
    setSceneRect( this->sceneRect().x(), this->sceneRect().y(),
                  this->itemsBoundingRect().width() + 50,
                  this->sceneRect().height() );
}

/*********************************************************************
 * sentAllSignalsChange - метод, высылающий сигналы сигналы со значениями
 * Тиок, Т1-ый режим.
 * ********************************************************************/
void cSceneWithWidget::sentAllSignalsChange()
{
        emit signalchangeIOK    ( dinamicGroupWidget[5]->width() / 3 );
        emit signalchangeOneMode( dinamicGroupWidget[6]->width() / 3 );
}

/*********************************************************************
 * ~cSceneWithWidget   - деструктор класса cSceneWithWidget.
 * ********************************************************************
 * Локальная переменная:
 * i    - счетчик циклапо листу эллипсов.
 * ********************************************************************/
cSceneWithWidget::~cSceneWithWidget()
{
    if ( polygon_left != NULL )
          this->deleteSettingItems();

    if ( dinamicGroupWidget.size() != 0 )
    {
        for( int i = 0; i < dinamicGroupWidget.size(); i++ )
        {
                if (dinamicGroupWidget[i] != NULL)
                {
                    delete dinamicGroupWidget[i];
                }
                else
                {
                    continue;
                }
        }
    }
}

