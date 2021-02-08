#include "cSceneWithMode.h"

/*********************************************************************
 * cSceneWithMode     - конструктор класса cSceneWithMode.
 * *******************************************************************
 * Формальные параметры:
 * rect     - размер сцены;
 * parent   - указатель, хранящий объект родителя.
 * ********************************************************************/
cSceneWithMode::cSceneWithMode( QRectF rect, QObject *parent ):
    cSceneWithWidget( rect, parent )
{
    objectSelected = pObjectExtra = NULL;
    polygon_left = NULL;

    updSceneDueItems();
}


/*********************************************************************
 * addCycleEllipse    - метод добавления новых элементов циклограммы
 * на сцену.
 * *******************************************************************
 * Формальные параметры:
 * index     - индекс (позиция), на который встанет виджет;
 * info      - информация о новом параметре циклограммы;
 * color     - цвет параметра циклограммы;
 * extrWidth - желательная ширина параметра.
 * *******************************************************************
 * Локальные переменные:
 * pExtraParameter - параметр, который добавляется на сцену и в список параметров;
 * pPreWidgetAdd   - параметр, который стоит на позиции index - 1;
 * rect_width      - желательная ширина нового параметра циклограммы;
 * rect_height     - желательная высота нового параметра циклограммы;
 * pProxyPar       - прокси виджет на объект сцены, для добавлении эффекта;
 * effectShadow    - эффект тени для прокси виджета.
 * labelPrmt       - метка параметра.
 *********************************************************************/
QGraphicsProxyWidget*  cSceneWithMode::addCycleEllipse(int index          , QString info,
                                                       const QColor& color, int extrWidth)
{

          cCycleEllipse* pExtraParameter;
    const cCycleEllipse* pPreWidgetAdd  ;

    int rect_width  = extrWidth;
    int rect_height = 11       ;

    //Добавление элементов в динамический список
    if( dinamicGroupWidget.size() > 0 )
    {

            if( index != 0 && ( index <= dinamicGroupWidget.size() ) )
            {
                pPreWidgetAdd =  dinamicGroupWidget[ index - 1 ];

                pExtraParameter = new cCycleEllipse( pPreWidgetAdd->x(), pPreWidgetAdd->y(),
                                                     rect_width, rect_height, info, color );

                int sizeDinamicGroup = dinamicGroupWidget.size();

                for(int i = index - 1; i < sizeDinamicGroup ; i++)
                {
                    dinamicGroupWidget[i]->move( dinamicGroupWidget[i]->x() + 150,
                                                 dinamicGroupWidget[i]->y() - 10 );

                    dinamicGroupWidget[i]->setAutoUpdateLabel();
                }

                dinamicGroupWidget.insert( index - 1, pExtraParameter );

            }
            else
            {
                pPreWidgetAdd   = dinamicGroupWidget[ dinamicGroupWidget.size() - 1 ];
                pExtraParameter = new cCycleEllipse( pPreWidgetAdd->x() + pPreWidgetAdd->width() + 50,
                                                     pPreWidgetAdd->y(),
                                                     rect_width, rect_height, info, color );

                dinamicGroupWidget.append( pExtraParameter );
            }

    }
    else
    {
            pExtraParameter = new cCycleEllipse( 15, 100, rect_width, rect_height, info, color );

            dinamicGroupWidget.append( pExtraParameter );

    }

    pExtraParameter->installEventFilter( this );

    //Добавление элемента на сцену
    QGraphicsProxyWidget *pProxyPar = this->addWidget( pExtraParameter );

    //Добавление эффекта тени элементам
    QGraphicsDropShadowEffect *effectShadow = new QGraphicsDropShadowEffect();
    effectShadow->setBlurRadius  ( 10            );
    effectShadow->setOffset      ( 2, 2          );
    effectShadow->setColor       ( color         );
    pProxyPar->setGraphicsEffect ( effectShadow  );


    cCycleLabel *labelPrmt = pExtraParameter->createPCycleLabel();
    if( pExtraParameter->Text() == tr("ДР - ЗИ") )
    {
        labelPrmt->setText( pExtraParameter->Text() + "\nt = 214 cек" );
    }
    else if( pExtraParameter->Text() == tr("ДР - ВИ (КП)") )
    {
        labelPrmt->setText( pExtraParameter->Text() + "\nt = 814 cек" );
    }

    labelPrmt->setAutoUpdateLabel();

    this->addWidget( labelPrmt );

    return pProxyPar;
}


/*********************************************************************
 * eventFilter        - фильтр событий, реализующий алгоритм взаимодействия
 * сцены и пользователя.
 * *******************************************************************
 * Формальные параметры:
 * watched    - объект, который был помещен в фильтр;
 * event      - событие класса QEvent.
 * *******************************************************************
 * Локальные переменные:
 * objectSelected2 - объект класса cCycleEllipse, с которым
 * взаимодействует пользователь;
 * eventMouse      - событие, возникшее из внейшней среды.
 *********************************************************************
*/
bool cSceneWithMode::eventFilter(QObject *watched, QEvent *event)
{
    //Наведение курсора
    if(event->type() == QEvent::Enter)
    {
        cCycleEllipse *objectSelected2 = dynamic_cast<cCycleEllipse *>(watched);

        if(objectSelected2!=NULL && !objectSelected2->infoFocus())
        {
            objectSelected2->setColorPen(new QColor(255,255,255,255));
            this->update();
        }
        return true;
    }

    //Исчезновение курсора
    if(event->type() == QEvent::Leave)
    {
        cCycleEllipse *objectSelected2 = dynamic_cast<cCycleEllipse *>(watched);

        if(objectSelected2!=NULL && !objectSelected2->infoFocus())
        {
            objectSelected2->setColorPen(new QColor(0,0,0,0));
            this->update();
        }
        return true;
    }

    //Нажата любая кнопка мыши
    if (event->type() == QEvent::MouseButtonPress || event->type() == QEvent::MouseButtonDblClick)
    {
        QMouseEvent *eventMouse = dynamic_cast<QMouseEvent *>(event);


            if(eventMouse->button() == Qt::RightButton && eventMouse!=NULL)
            {
                objectSelected = dynamic_cast<cCycleEllipse *>(watched);

                if(objectSelected != NULL)
                        expandScene(objectSelected);                
            }
            return true;
    }

    //Кнопка мыши отпущена
    if (event->type() == QEvent::MouseButtonRelease)
    {
        QApplication::restoreOverrideCursor();
        return true;
    }

    return false;
}

/*********************************************************************
 * ~cSceneWithMode   - деструктор класса cSceneWithMode.
 * ********************************************************************/
cSceneWithMode::~cSceneWithMode()
{

}
