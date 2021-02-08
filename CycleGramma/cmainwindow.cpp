#include "cMainWindow.h"
#include "ui_cmainwindow.h"

/*********************************************************************
 * cMainWindow - конструктор класса cMainWindow.
 * ************************
 * Формальный параметр:
 * parent - содержит указатель на родительский объект типа QWidget.
 *********************************************************************/
cMainWindow::cMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::cMainWindow)
{
    ui->setupUi( this );

    flag = false;

   // ui->pView->setStyleSheet("background:  #413d51;");


    pScene = new cSceneWithMode( QRectF(0,0,200,200), ui->pView );

    ui->pView->setScene( pScene );
    ui->pView->setRenderHint( QPainter::Antialiasing, true );

    ui->onTheRightButton->setIcon( QCommonStyle().standardIcon(QStyle::SP_ArrowRight) );
    ui->onTheLeftButton ->setIcon( QCommonStyle().standardIcon(QStyle::SP_DialogCloseButton) );


    scl = sclExt = 1.0;
    msec = 12;

    connect( pScene , SIGNAL( expand( int, int ) ) , this , SLOT( expandMyView( int, int ) ) );

    countApplyModes = 0;
    currentIndexTab = 0;

}

/*********************************************************************
 * createScenes -  метод создания сцен для каждого режима.
 *********************************************************************
 * Локальные переменные:
 * i             - счетчик цикла по правому листу;
 * pSceneOptions - указатель на объект класса cSceneWithOptions, являющийся
 * новой сценой с параметрами для нового режима.
 *********************************************************************
*/
void cMainWindow::createScenes()
{
    //Создание сцен для каждого выбранного режима
    for( int i = 0; i <= ui->listRight->count() - 1; i++ )
    {
        cSceneWithOptions *pSceneOptions = new cSceneWithOptions( QRectF( 0, 0, 600, 250 ),
                                                                  ui->pView
                                                                 );

        connect( pSceneOptions,  &cSceneWithOptions::signalBackOnView,
                 this,           &cMainWindow::slotBackOnView         );

        listSceneOptions.append( pSceneOptions );
    }

    if( listSceneOptions.count() > 0 )
    {
      connect( ui->spinBoxIOK_1,      SIGNAL( valueChanged( int ) ), listSceneOptions[0], SLOT( changeIOK    ( int ) ));
      connect( ui->spinBoxOnceMode_2, SIGNAL( valueChanged( int ) ), listSceneOptions[0], SLOT( changeOneMode( int ) ));

      connect( listSceneOptions[0], SIGNAL( signalchangeIOK    ( int ) ), ui->spinBoxIOK_1,      SLOT( setValue( int ) ));
      connect( listSceneOptions[0], SIGNAL( signalchangeOneMode( int ) ), ui->spinBoxOnceMode_2, SLOT( setValue( int ) ));

      listSceneOptions[0]->sentAllSignalsChange();
    }

}

/*********************************************************************
 * setEnabledGroups  - метод, задающий доступ ко всем элементам
 * после того, как пользователь заполнит все режимы.
 * *******************************************************************/
void cMainWindow::setEnabledGroups()
{
    ui->groupComands    ->setEnabled( true  );
    ui->groupDateAndTime->setEnabled( true  );
    ui->groupDateAndTime->setVisible( false );
    ui->groupTimeSet    ->setEnabled( true  );
    ui->groupParameter  ->setEnabled( true  );
    ui->groupParameter  ->setVisible( true  );
}

/*********************************************************************
 * setDisabledGroups - метод, задающий доступ к определенному
 * элементу, остальные же блокирует.
 * *******************************************************************/
void cMainWindow::setDisabledGroups()
{
    ui->groupComands    ->setEnabled( false );
    ui->groupDateAndTime->setEnabled( true  );
    ui->groupDateAndTime->setVisible( true  );
    ui->groupTimeSet    ->setEnabled( false );
    ui->groupParameter  ->setEnabled( false );
    ui->groupParameter  ->setVisible( false );
    ui->tabModes        ->widget( ui->tabModes->count() - 2 )
                        ->setEnabled( false );
}

/*********************************************************************
 * setDateTimeEnd    - метод, задающий дату конца режима.
 * *******************************************************************
 * Формальный параметр:
 * index - индекс вкладки, для которой высчитывается время.
 * *******************************************************************
 * Локальные переменные:
 * extraTime - дополнительное время режима для вкладки по индексу для
 * подсчета конечног времени;
 * hh        - час начала режима;
 * dateTime  - время конца режима;
 * newhh     - час конца режима;
 * day       - номер дня конца режима;
 * numYear   - номер четырех столетия окончания режима.
 *********************************************************************/
void cMainWindow::setDateTimeEnd( int index )
{
    int extraTime = 0;

    if( ui->tabModes->tabText( index ) == "ДР - ЗИ" )
    {
        extraTime += ui->spinBoxOnceMode_2->text().toInt() + ui->spinBoxIP_3->text().toInt() + 17;
    }
    else if( ui->tabModes->tabText( index ) == "ДР - ВИ (КП)" )
    {
        extraTime = 854;
    }

    int hh      = ui->timeEditData->time().hour();

    QString dateTime( ui->timeEditData->time().addSecs( extraTime ).toString() );

    int newhh   = ui->timeEditData->time().addSecs( extraTime ).hour();
    int day     = ui->spinBoxDay_3->text().toInt();
    int numYear = ui->spinBoxNum_3->text().toInt();

    if(hh == 23 && hh > newhh)
    {
        day += 1;
        if(day > 1460)
        {
            day = 0;
            numYear += 1;
        }

    }

    ui->dateTimeEnd->setText(""  + QString::number( numYear ) +
                             "." + QString::number( day     ) +
                             "." + dateTime);

    pScene->setLabelEllipse( index, extraTime);
    ui->pView->update();
}

/*********************************************************************
 * valListForButton  - метод, разблокирующий кнопку "Далее" в
 * случае, если list заполнен.
 * *******************************************************************
 * Формальные параметры:
 * list   - лист, который проверяется на наличие в нем элементов;
 * button - кнопка, к которой дает доступ.
 * *******************************************************************/
void cMainWindow::valListForButton( QListWidget *list, QPushButton *button )
{
    if( list->count() > 0 )
        button->setEnabled( true  );
    else
        button->setEnabled( false );
}

/*********************************************************************
 * writeToInterfaceDate - метод, предназначенный для чтения из файла.
 * *******************************************************************
 * Формальный параметр:
 * array - содержит указатель на родительский объект типа QWidget.
 * *******************************************************************
 * Локальные переменные:
 * dataToString, extraString - строки, содержащие копии текста из файла;
 * dec - переменная, предназначенная для превращения из строки в число;
 * hh,mm,ss - переменные, содержащие часы, минуты и секунды соответственно.
 *********************************************************************/
void cMainWindow::writeToInterfaceDate( const QString &array )
{
    /* Чтение файла данных в программный интерфейс*/

    //Чтение даты и времени
    QString dataToString( array );
    QString extraString("");


    for(int i = 47; i < dataToString.indexOf("."); i++ )
    {
        extraString += dataToString[i];

    }

    ui->spinBoxNum_3->setValue( extraString.toInt() );
    extraString = "";

    for(int i = dataToString.indexOf(".")+1; i < dataToString.indexOf(".",dataToString.indexOf(".")+1); i++ )
    {
        extraString += dataToString[i];
    }


    ui->spinBoxDay_3->setValue(extraString.toInt());
    extraString = "";

    for(int i = dataToString.indexOf(".",dataToString.indexOf(".")+1)+1; i < dataToString.lastIndexOf("."); i++ )
    {
        extraString += dataToString[i];

    }

    int dec = 1;
    int hh,mm,ss;

    hh = mm = ss = 0;

    for(int i = extraString.indexOf(":")-1; i >= 0; i-- )
    {
        hh += QString(extraString[i]).toInt()*dec;
        dec *=10;
    }

    dec = 1;

    for(int i = extraString.indexOf(":",extraString.indexOf(":")+1)-1; i > extraString.indexOf(":") ; i-- )
    {
        mm += QString(extraString[i]).toInt()*dec;
        dec *=10;
    }



    ui->timeEditData->setTime( QTime( hh, mm, extraString.remove(0,extraString.indexOf(":",extraString.indexOf(":")+1)+1).toInt() ) );

    //Чтение релейных команд
    for(int i = 0; i < dataToString.length(); i++)
    {

        if(dataToString[i] == "О" && dataToString[i+1] == "Т" && dataToString[i+2] == "К")
        {

            if (dataToString[i+11] == "1")
            {
                ui->chBoxDisabBAPI->setChecked(true);
            }
            else
            {
                ui->chBoxDisabBAPI->setChecked(false);
            }
        }
        else if (dataToString[i] == "В" && dataToString[i+1] == "К" && dataToString[i+9] == "1")
        {
            if (dataToString[i+11] == "1")
            {
                ui->radBoxUHPOn_1->setChecked(true);
                ui->radBoxUHPOn_2->setChecked(false);
            }
            else
            {
                ui->radBoxUHPOn_1->setChecked(false);
                ui->radBoxUHPOn_2->setChecked(true);
            }
        }
        else if (dataToString[i] == "Т" && dataToString[i+1] == "и" && dataToString[i+2] == "о")
        {
             QString str("");

             i += 5;

             while(dataToString[i] != "\r")
             {
                 str += dataToString[i];
                 i++;
             }

             i -= 1;

             ui->spinBoxIOK_1->setValue(str.toInt());
        }
        else if (dataToString[i] == "Т" && dataToString[i+1] == "п" && dataToString[i+2] == "е")
        {
             QString str("");

             i += 8;

             while(dataToString[i] != "\r")
             {
                 str += dataToString[i];
                 i++;
             }

             i -= 1;

             ui->spinBoxOnceMode_2->setValue(str.toInt());
        }
        else if (dataToString[i] == "Т" && dataToString[i+1] == "и" && dataToString[i+2] == "п")
        {
             QString str("");

             i += 4;

             while(dataToString[i] != "\r")
             {
                 str += dataToString[i];
                 i++;
             }

             i -= 1;

             ui->spinBoxIP_3->setValue(str.toInt());
        }
        else if (dataToString[i] == "Т" && dataToString[i+1] == "у" && dataToString[i+2] == "п")
        {
             QString str("");

             i += 8;
             while(dataToString[i] != "\r")
             {
                 str += dataToString[i];
                 i++;
             }

             ui->spinBoxUprezh_4->setValue(str.toInt());
        }
    }

}

/*********************************************************************
 * ~cMainWindow - деструктор класса cMainWindow.
 * *******************************************************************
 * Локальные переменные:
 * removePScene, removeWidget - объекты сцен и закладок для выспобождения
 * памяти.
 *********************************************************************/
cMainWindow::~cMainWindow()
{
    int lengthList = listSceneOptions.length();

    for(int i = 0; i < lengthList; i++)
    {
        cSceneWithOptions * removePScene = listSceneOptions.takeAt( 0 );
        delete removePScene;
    }

    int lengthTabModes = ui->tabModes->count();

    for(int i = 0; i < lengthTabModes; i++)
    {
        QWidget *removeWidget = ui->tabModes->widget( 0 );
        delete removeWidget;
    }

    delete ui;
}



/*********************************************************************
 * on_action_save_triggered - слот сохранения параметров пользователя.
 * *******************************************************************
 * Локальные переменные:
 * FILE_NAME - имя файла для записи;
 * file      - объект файла для записи;
 * stream    - поток, который записывается в файл;
 * wdgTable  - указатель на текущую таблицу из cFormWithTable;
 * time      - объект времени, позволяющий получать часы, минуты и секнду отдельно.
 *********************************************************************
*/
void cMainWindow::on_action_save_triggered()
{
    if(vecApplyMode[ui->tabModes->currentIndex()] == true)
    {
       QString FILE_NAME =
               QFileDialog::getSaveFileName(this,
                                            QString::fromUtf8("Сохранить файл"),
                                            QDir::currentPath(),
                                            "*.dat");

       QFile file( FILE_NAME );

       if ( !file.open( QIODevice::WriteOnly ) )
       {
           QMessageBox::critical(this,
                                 "Ошибка",
                                 "Ошибка сохранения файла");
       }
       else
       {
           /* Запись данных в файл */

           QTextStream  stream( &file );

           //Запись названия режима
           stream << QObject::tr( "Название режима: " );
           stream << ui->tabModes->tabText(ui->tabModes->currentIndex()) << "\r\n";

           //Запись Даты и Времени
           stream << QObject::tr( "Время нач/кон режима: " );
           stream << ui->spinBoxNum_3->value() ;
           stream << ".";
           stream << ui->spinBoxDay_3->value() ;
           stream << ".";
           QTime time(ui->timeEditData->time());
           stream << time.hour();
           stream << ":";
           stream << time.minute();
           stream << ":";
           stream << time.second();
           stream << "." << " - " << ui->dateTimeEnd->text() << "\r\n";

           //Запись релейных команд
           stream << QObject::tr( "ОТКЛ. БАПИ " );
           stream << ui->chBoxDisabBAPI->isChecked() << "\r\n";
           stream << QObject::tr( "ВКЛ. УХП-1 " );
           stream << ui->radBoxUHPOn_1->isChecked()  << "\r\n";
           stream << QObject::tr( "ВКЛ. УХП-2 " );
           stream << ui->radBoxUHPOn_2->isChecked()  << "\r\n";

           //Запись размера элементов циклограммы
           stream << QObject::tr( "Тиок " );
           stream << ui->spinBoxIOK_1->value()      << "\r\n";
           stream << QObject::tr( "Тперреж " );
           stream << ui->spinBoxOnceMode_2->value() << "\r\n";
           stream << QObject::tr( "Тип " );
           stream << ui->spinBoxIP_3->value()       << "\r\n";
           stream << QObject::tr( "Тупрежд " );
           stream << ui->spinBoxUprezh_4->value()   << "\r\n";


           cFormWithTable *wdgTable = dynamic_cast<cFormWithTable *> (ui->tabModes->currentWidget());

           if(wdgTable != NULL)
           {
              int numMode = 0;

              if(ui->tabModes->tabText(ui->tabModes->currentIndex()) == "ДР - ЗИ")
              {
                   numMode = 1;
              }
              else if(ui->tabModes->tabText(ui->tabModes->currentIndex()) == "ДР - ВИ (КП)")
              {
                          numMode = 2;
              }

              wdgTable->dataComBoxForFile( numMode, stream );

           }
           else
           {
               QMessageBox::information(0,
                                        "Ошибка приведения",
                                        "Имя объекта: wdgTable");
           }
       }

       file.close();
    }
    else
    {
        QMessageBox::information(0,
                                 "Ошибка сохранения",
                                 "Сначала двойным щелчком по вкладке активируйте режим");
    }
}

/*********************************************************************
 * on_action_open_triggered - слот открытия файла с сохраннеными
 * параметрами пользователя.
 * *******************************************************************
 * Локальные переменные:
 * dataOfFile - строка, содержащая все данные из файла;
 * file       - объект файла для чтения;
 * stream     - поток, который читает файл.
 *********************************************************************
*/
void cMainWindow::on_action_open_triggered()
{
    QString FILE_NAME =  QFileDialog::getOpenFileName(this,
                                                      QString::fromUtf8("Открыть файл"),
                                                      QDir::currentPath(),
                                                      "*.dat;;All files (*.*)");

    QFile file( FILE_NAME );

    if (FILE_NAME !=  NULL)
    {
        if ( !file.open( QIODevice::ReadOnly ) )
        {
            QMessageBox::critical(this,
                                  "Ошибка",
                                  "Ошибка чтения файла");
        }
        else
        {
            QTextStream stream( &file            );
            QString dataOfFile( stream.readAll() );


            int numMode = 0;
            QString nameMode;

            if( dataOfFile.contains( "ДР - ЗИ" ) )
            {
                numMode = 1;
                nameMode = "ДР - ЗИ";
            }
            else if( dataOfFile.contains( "ДР - ВИ (КП)" ) )
            {
                     numMode = 2;
                     nameMode = "ДР - ВИ (КП)";
            }

            cFormWithTable *form = new cFormWithTable( numMode, ui->tabModes->count() - 1 , ui->tabModes );

            ui->tabModes->insertTab( ui->tabModes->count() - 1, form , nameMode );

            pScene->addCycleEllipse( ui->tabModes->count() - 1, nameMode, QColor("#e9967a"), 100 );
            pScene->updSceneDueItems();

            cSceneWithOptions *pSceneOptions = new cSceneWithOptions( QRectF( 0, 0, 600, 250),
                                                                      ui->pView
                                                                     );

            connect( pSceneOptions,  &cSceneWithOptions::signalBackOnView,
                     this,           &cMainWindow::slotBackOnView         );

            listSceneOptions.append( pSceneOptions );

            vecApplyMode.append(false);

            slotBackOnView();

            setDisabledGroups();

            ui->tabModes->setCurrentIndex( ui->tabModes->count() - 1 );

            //Cчитываем все данные с файла в объект data
            writeToInterfaceDate( dataOfFile );


            ui->pushButSetTime->clicked( true );
            ui->pushButComands->clicked( true );
            ui->pushData      ->clicked( true );
        }
    }

    file.close();
}

/*********************************************************************
 * expandMyView - слот, содержащий инициализацию всех переменных при
 * нажатии на правую кнопку мыши.
 *********************************************************************
 * Формальные параметры:
 * x, y - координаты, где произошел щелчок мыши.
 *********************************************************************
*/
void cMainWindow::expandMyView(int x, int y)
{
    scl = sclExt = 1.0;
    msec *= 5;
    tmr = new QTimer( this );
    tmr->setInterval( msec );
    connect( tmr , SIGNAL( timeout() ) , this , SLOT( exp() ));
    tmr->start();

    Q_UNUSED(x)
    Q_UNUSED(y)
}


/*********************************************************************
 * exp - слот, содержащий алгоритм расширения сцены
 * на правую кнопку мыши.
 *********************************************************************
*/
void cMainWindow::exp()
{
    if( scl < 1.1 )
    {
        scl+=0.005;
        ui->pView->scale( scl , scl );

        (scl >= 1.1)? sclExt = 1.1 + 0.01 : sclExt = 0;

        if( scl > 1.1 )
        {
            ui->pView->setScene( listSceneOptions[currentIndexTab] );
        }
    }
    else if(sclExt > 1.0025)
    {
        sclExt-=0.005;
        ui->pView->scale( 1/sclExt , 1/sclExt );

    }
    else if(sclExt < 1.0)
    {
        tmr->stop();
        tmr->disconnect( tmr , SIGNAL( timeout() ) , this , SLOT( exp() ));
        delete tmr;
    }
}

/*********************************************************************
 * on_action_exit_triggered - слот нажатия на кнопку "Выход", расположенную
 * на ToolBar.
 *********************************************************************
*/
void cMainWindow::on_action_exit_triggered()
{
    this->close();
}

/*********************************************************************
 * on_onTheRightButton_clicked - слот нажатия на кпонку со стрелкой, смотрящей на право,
 * реализующий перенос с левого листа "Доступный режим" на правый лист "Выбранные режимы".
 *********************************************************************
*/
void cMainWindow::on_onTheRightButton_clicked()
{
    if( ui->listLeft->currentItem() )
    {
        ui->listRight->addItem( ui->listLeft->currentItem()->text() );
    }

    valListForButton( ui->listRight, ui->buttonNext );

    ui->listRight->itemChanged( ui->listRight->item( ui->listRight->count()-1 ) );
}


/*********************************************************************
 * on_onTheLeftButton_clicked - слот нажатия на кпонку с крестиком,
 * реализующий удаления элемента из правого листа "Выбранные режимы".
 *********************************************************************
*/
void cMainWindow::on_onTheLeftButton_clicked()
{
    if( ui->listRight->currentItem() != NULL)
    {
       flag = true;
       pScene->deleteCycleEllipse( ui->listRight->currentRow() );

       ui->pView->update();
       pScene->updSceneDueItems();


       delete ui->listRight->takeItem( ui->listRight->currentRow() );


       valListForButton( ui->listRight, ui->buttonNext );

       flag = false;
    }
    else
    {
        QMessageBox::critical(this,
                              "Ошибка",
                              "Не выбран элемент на удаление");
    }

}

void cMainWindow::on_listLeft_doubleClicked( const QModelIndex & index)
{
    on_onTheRightButton_clicked();
    Q_UNUSED(index)
}

/*********************************************************************
 * on_buttonNext_clicked - слот нажатия на кпонку "Далее", расположенную
 * на ToolBar.
 *********************************************************************
 * Локальные переменные:
 * i       - счетчик цикла по правому листу;
 * numMode - номер режима;
 * form    - уазатель на объект класса cFormWithTable.
 *********************************************************************
*/
void cMainWindow::on_buttonNext_clicked()
{

   ui->groupParameter   ->setVisible( false );
   ui->groupDateAndTime ->setVisible( true  );
   ui->groupTimeSet     ->setEnabled( false );

   this->updateMainWidgetOfScrolls( );

   if(ui->tabModes->count() > 0)
   {
      ui->tabModes->clear();
   }

   for( int i = 0, numMode = 0; i < ui->listRight->count(); i++ )
   {
       if( ui->listRight->item(i)->text() == "ДР - ЗИ" )
       {
           numMode = 1;
       }
       else if( ui->listRight->item(i)->text() == "ДР - ВИ (КП)" )
       {
                numMode = 2;
       }

       cFormWithTable *form = new cFormWithTable( numMode, i + 1, ui->tabModes );

       ui->tabModes->addTab( form ,ui->listRight->item(i)->text() );
       vecApplyMode.append(false);
   }

   if(ui->tabModes->tabText(0)  == "ДР - ЗИ" )
   {
       ui->spinBoxOnceMode_2->setEnabled( true );
       ui->spinBoxOnceMode_2->setMinimum(  1   );
       ui->spinBoxOnceMode_2->setMaximum( 300  );
   }
   else if( ui->tabModes->tabText(0) == "ДР - ВИ (КП)" )
   {
            ui->spinBoxOnceMode_2->setEnabled(false);
            ui->spinBoxOnceMode_2->setMinimum( 600 );
            ui->spinBoxOnceMode_2->setMaximum( 600 );
   }

   ui->tabModes->addTab( new QPushButton( ui->tabModes ),
                         QCommonStyle().standardIcon( QStyle::SP_FileDialogDetailedView ) ,
                         QString("")
                        );

   ui->stackedMenu->setCurrentIndex( 1 );

   this->updateMainWidgetOfScrolls( );

   ui->pushData       ->setEnabled( true );
   ui->buttonTimeEdit ->setEnabled( true );

   this->createScenes();

   setDisabledGroups();
}

/*********************************************************************
 * slotChangeOptions - слот реагирующий на изменения на сцене элементов.
 *********************************************************************
 * Формальные параметры:
 * IOK -     размер Тиок на сцене в целочисленном типе;
 * oneMode - размер Т 1-го режима на сцене в целочисленном типе;
 * IP -      размер Тип на сцене в целочисленном типе;
 * Uprezh -  размер Тупрежд. на сцене в целочисленном типе.
 * *******************************************************************/
void cMainWindow::slotChangeOptions(int IOK, int oneMode, int IP, int Uprezh )
{
    ui->spinBoxIOK_1     ->setValue( IOK     );
    ui->spinBoxOnceMode_2->setValue( oneMode );
    ui->spinBoxIP_3      ->setValue( IP      );
    ui->spinBoxUprezh_4  ->setValue( Uprezh  );
}



/*********************************************************************
 * slotBackOnView -  слот, устанавливающий сцену со списком режимов.
 *********************************************************************/
void cMainWindow::slotBackOnView()
{
    //Слот, меняющий сцену настроек команд на главную сцену
    //настроек режимов в представлении
    ui->pView->setScene(pScene);

}

/*********************************************************************
 * on_pushData_clicked - слот заполнения таблицы текущего режима.
 ********************************************************************/
void cMainWindow::on_pushData_clicked()
{
    cFormWithTable *form = dynamic_cast<cFormWithTable*>( ui->tabModes->widget( ui->tabModes->currentIndex() ) );

    if (form != NULL)
    {
        qint8 radioButOn = 0;

        if(ui->radBoxUHPOn_1->isChecked())
        {
            radioButOn = 1;
        }
        else if(ui->radBoxUHPOn_2->isChecked())
        {
                radioButOn = 2;
        }

        form->pushData( ui->spinBoxIOK_1      ->text().toInt()    ,
                        ui->spinBoxOnceMode_2 ->text().toInt()    ,
                        ui->spinBoxIP_3       ->text().toInt() + 5,
                        ui->spinBoxUprezh_4   ->text().toInt() + 5,
                        radioButOn );

        if( countApplyModes < (ui->tabModes->count()-1)  && form->flagPushData())
        {
            ui->groupComands    ->setEnabled( false );
            ui->groupDateAndTime->setEnabled( false );
            ui->groupParameter  ->setEnabled( false );
            ui->groupTimeSet    ->setEnabled( false );
            ui->tabModes        ->setEnabled( true  );
            ui->tabModes->widget(ui->tabModes->currentIndex())->setEnabled(true);
        }

    }
    else
    {
        QMessageBox::critical(0,
                              "Ошибка приведения",
                              "Имя объекта: form \n"
                              "Тип: cFormWithTable");
    }
}


/*********************************************************************
 * on_listRight_itemChanged - слот, реагирующий на изменения в listWidget.
 ********************************************************************
 * Формальный параметр:
 * item - элемент в списке, с которым произошли изменения.
 ********************************************************************
 * Локальная переменная:
 * maxLenList - максимальное число элементов, которое можно добавить в
 * список.
 ********************************************************************/
void cMainWindow::on_listRight_itemChanged(QListWidgetItem *item)
{
    ui->listRight->blockSignals(true);

    if(item != NULL && !flag)
    {
        item->setFont(QFont("Times New Roman",14));
        item->setTextColor(Qt::black);
    }

    int maxLenList = 2;

    if(!flag )
    {
        flag = true;
        if(ui->listRight->count() > maxLenList )
        {
            delete ui->listRight->takeItem(ui->listRight->row(item));

            QMessageBox::warning(0,
                                 "Предупреждение",
                                 "Можно добавить максимум "+
                                 QString::number(maxLenList) +
                                 " режима"
                                 );
        }
        else if(ui->listRight->count() > pScene->countWidgetOnScene())
        {

            pScene->addCycleEllipse(ui->listRight->row(item)+1,item->text(),QColor("#e9967a"), 100);
            pScene->updSceneDueItems();

         }


        valListForButton(ui->listRight, ui->buttonNext);

        flag = false;
    }

    ui->listRight->blockSignals(false);
}

/*********************************************************************
 * on_tabModes_tabBarClicked      - слот реагирующий на один щелчок мыши
 * на вкладку в TabBar.
 ********************************************************************
 * Формальный параметр:
 * index - индекс вкладки, на которую нажал пользователь.
 ********************************************************************
 * Локальная переменная:
 * listDialog    - кастомный диалог с листом для добавления режимов;
 * numMode       - номер режима;
 * form          - объект с таблицами режимов;
 * pSceneOptions - объект сцены с параметрами циклограммы.
 ********************************************************************/
void cMainWindow::on_tabModes_tabBarClicked(int index)
{
    if (index != ui->tabModes->count()-1)
    {
        if(currentIndexTab < 0 )
        {
           disconnect(ui->spinBoxIOK_1,       SIGNAL(valueChanged(int)),      listSceneOptions[currentIndexTab],SLOT(changeIOK(int)));
           disconnect(ui->spinBoxOnceMode_2,  SIGNAL(valueChanged(int)),      listSceneOptions[currentIndexTab],SLOT(changeOneMode(int)));

           disconnect(listSceneOptions[currentIndexTab],  SIGNAL(signalchangeIOK(int)),     ui->spinBoxIOK_1,     SLOT(setValue(int)));
           disconnect(listSceneOptions[currentIndexTab],  SIGNAL(signalchangeOneMode(int)), ui->spinBoxOnceMode_2,SLOT(setValue(int)));
        }

        listSceneOptions[currentIndexTab]->deleteSettingItems();

        ui->pView->setScene(listSceneOptions[index]);

        connect(ui->spinBoxIOK_1,       SIGNAL(valueChanged(int)),      listSceneOptions[index],SLOT(changeIOK(int)));
        connect(ui->spinBoxOnceMode_2,  SIGNAL(valueChanged(int)),      listSceneOptions[index],SLOT(changeOneMode(int)));

        connect(listSceneOptions[index],  SIGNAL(signalchangeIOK(int)),     ui->spinBoxIOK_1,     SLOT(setValue(int)));
        connect(listSceneOptions[index],  SIGNAL(signalchangeOneMode(int)), ui->spinBoxOnceMode_2,SLOT(setValue(int)));

        listSceneOptions[index]->sentAllSignalsChange();

        if(ui->tabModes->tabText(index)  == "ДР - ЗИ" )
        {
            ui->spinBoxOnceMode_2->setEnabled( true );
            ui->spinBoxOnceMode_2->setMinimum(  1   );
            ui->spinBoxOnceMode_2->setMaximum( 300  );
        }
        else if( ui->tabModes->tabText(index) == "ДР - ВИ (КП)" )
        {
                 ui->spinBoxOnceMode_2->setEnabled(false);
                 ui->spinBoxOnceMode_2->setMinimum( 600 );
                 ui->spinBoxOnceMode_2->setMaximum( 600 );
        }

        if( countApplyModes < (ui->tabModes->count()-1) && ui->tabModes->tabIcon(index).isNull())
        {
            ui->groupComands->setEnabled(false);
            ui->groupDateAndTime->setEnabled(true);
            ui->groupDateAndTime->setVisible(true);
            ui->groupTimeSet->setEnabled(false);
            ui->groupParameter->setEnabled(false);
            ui->groupParameter->setVisible(false);
        }
        else if (!ui->tabModes->tabIcon(index).isNull())
        {
            ui->tabModes->widget(index)->setEnabled(true);
        }

        setDateTimeEnd(index);

        currentIndexTab = index;



    }
    else if(ui->tabModes->count() < 3)
    {
        cListDialog *listDialog = new cListDialog(this);

        if(listDialog->exec() == QDialog::Accepted)
        {
            QMessageBox::information(0,
                                     "Выбранный режим",
                                     "Вы выбрали режим "+
                                     listDialog->currentItemList());

            int numMode = 0;

            if( listDialog->currentItemList() == "ДР - ЗИ" )
            {
                numMode = 1;
            }
            else if( listDialog->currentItemList() == "ДР - ВИ (КП)" )
            {
                     numMode = 2;
            }

            cFormWithTable *form = new cFormWithTable( numMode, ui->tabModes->count()-1 , ui->tabModes );

            ui->tabModes->insertTab(ui->tabModes->count()-1, form ,listDialog->currentItemList() );

            pScene->addCycleEllipse(ui->tabModes->count()-1,listDialog->currentItemList(),QColor("#e9967a"), 100);
            pScene->updSceneDueItems();

            cSceneWithOptions *pSceneOptions = new cSceneWithOptions( QRectF( 0, 0, 600, 250),
                                                                      ui->pView
                                                                     );

            connect( pSceneOptions,  &cSceneWithOptions::signalBackOnView,
                     this,           &cMainWindow::slotBackOnView         );

            listSceneOptions.append( pSceneOptions );

            vecApplyMode.append(false);

            slotBackOnView();

            setDisabledGroups();

        }

        delete listDialog;

    }
    else
    {
        QMessageBox::information(0,
                                 "Ошибка",
                                 "Больше режимов добавить нельзя ");

    }
}

/*********************************************************************
 * on_tabModes_currentChanged     - слот изменения текущей вкладки в
 * TabBar.
 ********************************************************************
 * Формальный параметр:
 * index - индекс текущей вкладки.
 ********************************************************************/
void cMainWindow::on_tabModes_currentChanged( int index )
{
    if ( index == ui->tabModes->count() - 1 )
    {
       ui->tabModes->setCurrentIndex( ui->tabModes->count() - 2 );       
    }
}

/*********************************************************************
 * on_tabModes_tabCloseRequested  - слот удаления вкладки в
 * TabBar.
 ********************************************************************
 * Формальный параметр:
 * index - индекс текущей вкладки.
 ********************************************************************
 * Локальная переменная:
 * removePScene - сцена, которая была привязана к вкладке.
 ********************************************************************/
void cMainWindow::on_tabModes_tabCloseRequested(int index)
{
    if( index != ui->tabModes->count() - 1 )
    {
        ui->tabModes->removeTab( index );

        cSceneWithOptions * removePScene = listSceneOptions.takeAt( index );
        delete removePScene;

        pScene->deleteCycleEllipse( index );

        delete ui->listRight->takeItem( index );

        if(ui->tabModes->count() == 1)
        {
            ui->stackedMenu->setCurrentIndex( 0 );
        }

        slotBackOnView();
        countApplyModes -= 1;


        vecApplyMode.remove( index );

        currentIndexTab = index - 1;

        if( currentIndexTab < 0 )
        {
            currentIndexTab = 0;
            countApplyModes = 0;
            valListForButton(ui->listRight, ui->buttonNext);
            ui->pView->setInteractive( false );
        }
    }
    else
    {
        QMessageBox::information( 0,
                                 "Ошибка!",
                                 "Выбранную вкладку удалить нельзя!" );
    }
}

/*********************************************************************
 * on_tabModes_tabBarDoubleClicked - слот реагирующий на двойной щелчок мыши
 * на вкладку в TabBar.
 ********************************************************************
 * Формальный параметр:
 * index - индекс текущей вкладки.
 ********************************************************************
 * Локальная переменная:
 * wdgTable - таблица текущего режима.
 ********************************************************************/
void cMainWindow::on_tabModes_tabBarDoubleClicked(int index)
{
    cFormWithTable *wdgTable = dynamic_cast<cFormWithTable *> (ui->tabModes->widget(index));

    if(wdgTable != NULL)
    {
        if(ui->tabModes->tabIcon(index).isNull())
        {
            if(wdgTable->flagPushData())
            {
                ui->tabModes->setTabIcon(index,QCommonStyle().standardIcon(QStyle::SP_DialogApplyButton));
                countApplyModes += 1;
                vecApplyMode[index] = true;
            }
            else
            {
                QMessageBox::information(0,
                                         "Ошибка готовности!",
                                         "Задайте все параметры для "+
                                         QString::number(index+1)+
                                         " режима "+
                                         ui->tabModes->tabText(index));
            }
        }

        if(countApplyModes == ui->tabModes->count()-1)
        {
            this->setEnabledGroups();
        }
    }
    else
    {
        QMessageBox::information(0,
                                 "Ошибка!",
                                 "Не возможно привести объект "+
                                 ui->tabModes->widget(index)->objectName()+
                                 " к cFormWithTable");
    }

}

/*********************************************************************
 * on_buttonTimeEdit_clicked - слот нажатия на кнопку "Изменить".
 ********************************************************************/
void cMainWindow::on_buttonTimeEdit_clicked()
{
     ui->groupDateAndTime->setVisible( true  );
     ui->groupParameter  ->setVisible( false );
}

/*********************************************************************
 * on_pushButSetTime_clicked      - слот нажатия на кнопку "Задать время".
 ********************************************************************/
void cMainWindow::on_pushButSetTime_clicked()
{
    ui->groupComands->setEnabled( true );

    if( countApplyModes < ui->tabModes->count() - 1 )
    {
        ui->groupDateAndTime->setEnabled( false );
    }

    if( countApplyModes >= ui->tabModes->count() - 1 )
    {
        ui->groupDateAndTime->setVisible( false );
        ui->groupParameter  ->setVisible( true  );
    }

    ui->dateTimeBegin->setText(""  + ui->spinBoxNum_3->text()+
                               "." + ui->spinBoxDay_3->text()+
                               "." + ui->timeEditData->time().toString());

    setDateTimeEnd(ui->tabModes->currentIndex());
}

/*********************************************************************
 * on_pushButComands_clicked      - слот нажатия на кнопку "Задать команды".
 ********************************************************************/
void cMainWindow::on_pushButComands_clicked()
{
    if( countApplyModes < ui->tabModes->count()-1 )
    {
        ui->groupDateAndTime->setVisible( false );
        ui->groupParameter  ->setVisible( true  );
        ui->groupParameter  ->setEnabled( true  );
        ui->groupComands    ->setEnabled( false );

        ui->pView->setInteractive( true );
        ui->pView->setScene( listSceneOptions[ currentIndexTab ] );
    }

}

/*********************************************************************
 */
void cMainWindow::updateMainWidgetOfScrolls()
{
    this->update();
    this->repaint();
}

/*********************************************************************
 * on_action_about_triggered      - слот отображения окна "О программе".
 ********************************************************************/
void cMainWindow::on_action_about_triggered()
{
    QMessageBox::information(0,
                             "О программе",
                             "Данный продукт является дипломным проектом."
                             "Разработан на предприятии АО «ЦНИРТИ им. Академика А.И. Берга»"
                             "и является необходимой частью при проведениях испытаний БАПИ с использование "
                             "АКИА на предприятии изготовителя ОАО ""Машиностроительный завод ""Арсенал"", "
                             "АО «ОКБ МЭИ».\n"
                             "Разработал: Семенов Д.С.\n"
                             "Группа:ТМП81-13\n"
                             "Год: 2017");
}

/*********************************************************************
 * on_listLeft_currentItemChanged - слот изменения текущей строки в listLeft.
 ********************************************************************
 * Формальные параметры:
 * current  - текущий элемент в списке;
 * previous - предыдущий элемент в списке.
 ********************************************************************/
void cMainWindow::on_listLeft_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(previous != NULL)
    {
        previous->setFont     ( QFont("Times New Roman", 14) );
        previous->setTextColor( Qt::black                    );
    }

    if( current != NULL )
    {
        current->setFont     ( QFont("Times New Roman", 16) );
        current->setTextColor( QColor("#123524")            );
    }
}

/*********************************************************************
 * on_listRight_currentItemChange - слот изменения текущей строки в listRight.
 ********************************************************************
 * Формальные параметры:
 * current  - текущий элемент в списке;
 * previous - предыдущий элемент в списке..
 ********************************************************************/
void cMainWindow::on_listRight_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    flag = true;

    if(previous != NULL)
    {
        previous->setFont       ( QFont("Times New Roman", 14) );
        previous->setTextColor  ( Qt::black                    );
    }

    if( current != NULL )
    {
        current->setFont        ( QFont("Times New Roman", 16) );
        current->setTextColor   ( QColor("#123524")            );
    }

    flag = false;
}
