#include "cSceneWithOptions.h"

/*********************************************************************
 * cSceneWithOptions     - конструктор класса cSceneWithOptions.
 * *******************************************************************
 * Формальные параметры:
 * rect     - размер сцены;
 * parent   - указатель, хранящий объект родителя.
 * ********************************************************************/
cSceneWithOptions::cSceneWithOptions(QRectF rect, QObject *parent):
    cSceneWithWidget(rect,parent)
{
    objectSelected = pObjectExtra = NULL;
    polygon_left = NULL;

    //Создание главных элементов циклограммы
    addCycleEllipse( 1, "T_0",         QColor("#7fc7ff"), 100 );
    addCycleEllipse( 2, "T_oт",        QColor("#7fc7ff"), 100 );
    addCycleEllipse( 3, "Т_рк",        QColor("#7fc7ff"), 100 );
    addCycleEllipse( 4, "Т подачи ИП", QColor("#7fc7ff"), 100 );
    addCycleEllipse( 5, "Т упрежд.",   QColor("#7fc7ff"), 450 );
    addCycleEllipse( 6, "Т иок",       QColor("#8FF111"), 295 );
    addCycleEllipse( 7, "Т 1-го реж.", QColor("#8FF111"), 100 );

    QPushButton *onCloseButton = new QPushButton();

    onCloseButton->setStyleSheet( "background:  rgba(0, 0, 0, 0);" );
    onCloseButton->setIcon      ( QCommonStyle().standardIcon( QStyle::SP_DialogOkButton ) );

    addWidget( onCloseButton );
    connect  ( onCloseButton, SIGNAL(clicked()), SLOT(slotBackOnView()) );

    updSceneDueItems();

    for( int i = 3; i < 7; i++ )
    {
        dinamicGroupWidget[i]->setAutoUpdateLabel();
    }

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
QGraphicsProxyWidget*  cSceneWithOptions::addCycleEllipse(int index          , QString info,
                                                          const QColor& color, int extrWidth)
{

          cCycleEllipse* pExtraParameter;
    const cCycleEllipse* pPreWidgetAdd  ;

    int rect_width  = extrWidth;
    int rect_height = 11       ;

    //Добавление элементов в динамический список
    if( dinamicGroupWidget.size() > 0 )
    {

            if( index != 0 && (index <= dinamicGroupWidget.size()))
            {
                pPreWidgetAdd =  dinamicGroupWidget[index-1];

                pExtraParameter = new cCycleEllipse(pPreWidgetAdd->x(),pPreWidgetAdd->y(),
                                                    rect_width,rect_height,info,color);

                int sizeDinamicGroup = dinamicGroupWidget.size();

                for(int i = index-1; i < sizeDinamicGroup ; i++)
                {
                    dinamicGroupWidget[i]->move(dinamicGroupWidget[i]->x()+150,
                                                dinamicGroupWidget[i]->y()-10);

                    dinamicGroupWidget[i]->setAutoUpdateLabel();
                }

                dinamicGroupWidget.insert(index-1, pExtraParameter);

            }
            else
            {
                pPreWidgetAdd =  dinamicGroupWidget[dinamicGroupWidget.size()-1];
                pExtraParameter = new cCycleEllipse(pPreWidgetAdd->x()+ pPreWidgetAdd->width()+50,pPreWidgetAdd->y(),
                                                    rect_width,rect_height,info,color);

                dinamicGroupWidget.append(pExtraParameter);
            }

    }
    else
    {
            pExtraParameter = new cCycleEllipse(15,100,rect_width,rect_height,info,color);

            dinamicGroupWidget.append(pExtraParameter);

    }

    if(info == "Т упрежд.")
    {
        pExtraParameter->setGeometry(pExtraParameter->x()-152,pExtraParameter->y()-50,
                                     pExtraParameter->width(),pExtraParameter->height());
    }
    else if (info == "Т иок")
    {
        pExtraParameter->setGeometry(pExtraParameter->x()-350,pExtraParameter->y()+50,
                                     pExtraParameter->width(),pExtraParameter->height());
    }


    pExtraParameter->installEventFilter(this);

    //Добавление элемента на сцену
    QGraphicsProxyWidget *pProxyPar = this->addWidget(pExtraParameter);

    //Добавление эффекта тени элементам
    QGraphicsDropShadowEffect *effectShadow=new QGraphicsDropShadowEffect();
    effectShadow->setBlurRadius(10);
    effectShadow->setOffset(2,2);
    effectShadow->setColor(color);
    pProxyPar->setGraphicsEffect(effectShadow);


    cCycleLabel *labelPrmt = pExtraParameter->createPCycleLabel();
    if(info == "T_0")
    {
        labelPrmt->setText(pExtraParameter->Text() + "\nt = 60 cек");
    }
    else if(info == "T_oт")
    {
        labelPrmt->setText(pExtraParameter->Text() + "\nt = 1 cек");
    }
    else if(info == "Т_рк")
    {
        labelPrmt->setText(pExtraParameter->Text() + "\nt = 5 cек");
    }
    else
    {
            labelPrmt->setText(pExtraParameter->Text() + "\nt = " +
                                                QString::number(
                                                qCeil((pExtraParameter->x()+pExtraParameter->width()-15)/3)-
                                                qCeil((pExtraParameter->x()-15)/3))
                                                +" cек");
    }

    labelPrmt->setAutoUpdateLabel();

    this->addWidget(labelPrmt);

    return pProxyPar;
}

/*********************************************************************
 * eventFilter        - фильтр событий, реализующий алгоритм взаимодествия
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
bool cSceneWithOptions::eventFilter(QObject *watched, QEvent *event)
{


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

        if(watched == dinamicGroupWidget[0] ||
           watched == dinamicGroupWidget[1] ||
           watched == dinamicGroupWidget[2] ||
           watched == dinamicGroupWidget[3] ||
           watched == dinamicGroupWidget[4])
        {
            return true;
        }

        //Нажата левая кнопка мыши
        if (eventMouse->button() == 1 && eventMouse!=NULL)
        {
            cCyclePolygon *objectSelected2 = dynamic_cast<cCyclePolygon *>(watched);



        //Определение объекта события
            if (objectSelected2 != NULL &&
               (objectSelected2 == polygon_left   ||
                objectSelected2 == polygon_right))
            {
                QApplication::setOverrideCursor(Qt::SizeHorCursor);
                return true;
            }


                if (objectSelected != NULL)
                {
                    pObjectExtra = objectSelected;
                }



                objectSelected = dynamic_cast<cCycleEllipse *>(watched);


                  if (polygon_left==NULL)
                  {
                      displaysSettingItems(objectSelected);
                  }
                  else if (objectSelected == pObjectExtra)
                  {
                      deleteSettingItems( );
                  }
                  else
                  {
                      pObjectExtra->mousePressEvent(eventMouse);
                      pObjectExtra->setAutoUpdateLabel();

                      deleteSettingItems( );
                      displaysSettingItems(objectSelected);
                  }

                  if(objectSelected != NULL)
                  {
                     objectSelected->mousePressEvent(eventMouse);
                     objectSelected->setAutoUpdateLabel();
                  }


        }
        else if(eventMouse->button() == Qt::RightButton && eventMouse!=NULL)
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

    //Передвижение зажатого курсора
    if (event->type() == QEvent::MouseMove)
    {
       // QMouseEvent *eventMouseMove = static_cast<QMouseEvent *>(event);
        cCyclePolygon *objectSelected2 = dynamic_cast<cCyclePolygon *>(watched);

        if(objectSelected2!=NULL)
        {
            //Сдвиг элементов настроек
            if (objectSelected2 == polygon_left)
            {
                if(objectSelected == dinamicGroupWidget[5])
                {
                    return true;
                }

                if( objectSelected->validationCorrectWidth(0, coord_Cursor.rx()+7) &&
                        coord_Cursor.rx() > 0 &&
                        ((dinamicGroupWidget[0]->x() - (objectSelected->x()-(coord_Cursor.rx()))) >= 0))
                {
                        collidingUpdate(objectSelected2, objectSelected, coord_Cursor.rx() );
                        shiftLeftSettingItems(objectSelected2);
                        objectSelected->calculatInterval(line_right->Value(),line_left->Value());
                }
            }
            else if (objectSelected2 == polygon_right)
            {
                if( objectSelected->validationCorrectWidth(1, coord_Cursor.rx()-7) && coord_Cursor.rx() > 0 )
                {
                        collidingUpdate(objectSelected2, objectSelected, coord_Cursor.rx() );
                        shiftRightSettingItems(objectSelected2);
                        objectSelected->calculatInterval(line_right->Value(),line_left->Value());
                }
            }

            if(objectSelected == dinamicGroupWidget[5])
            {
                emit signalchangeIOK    (qFloor(dinamicGroupWidget[5]->width()/3));
            }
            else if(objectSelected == dinamicGroupWidget[6])
            {
                emit signalchangeOneMode(qFloor(dinamicGroupWidget[6]->width()/3));
            }

        updSceneDueItems();

        }
        return true;
    }

    return false;
}

/*********************************************************************
 * slotBackOnView - слот, реализующий вызов сигнала signalBackOnView.
 * ********************************************************************/
void cSceneWithOptions::slotBackOnView()
{
    emit signalBackOnView();
}

/*********************************************************************
 * ~cSceneWithOptions   - деструктор класса cSceneWithOptions.
 * ********************************************************************/
cSceneWithOptions::~cSceneWithOptions()
{

}
