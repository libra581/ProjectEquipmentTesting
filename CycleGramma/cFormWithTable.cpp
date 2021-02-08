#include "cFormWithTable.h"
#include "ui_cformwithtable.h"

/*********************************************************************
 * cFormWithTable     - конструктор класса cFormWithTable.
 * *******************************************************************
 * Формальные параметры:
 * numMode    - номер режима по названию;
 * numTabMode - номер режима по расположению в QTabWidget;
 * parent     - указатель, хранящий объект родителя.
 * ********************************************************************/
cFormWithTable::cFormWithTable( int numMode, int numTabMode, QWidget *parent /* = 0 */) :
         QWidget    ( parent                ),
         ui         ( new Ui::cFormWithTable),
         numMode    ( numMode               ),
         numTabMode ( numTabMode            )
{
    ui->setupUi( this );

    rk_On.type       = "РК"      ;
    rk_On.app        = ""        ;
    rk_On.comWord    = "4"       ;

    ip.type          = "ИП"      ;
    ip.app           = "КПИ УХП" ;
    ip.comWord       = "10285"   ;

    mko.type         = "МКО"     ;
    mko.app          = "СТИ"     ;
    mko.comWord      = "0"       ;

    onceMode.type    = "1 режим" ;
    onceMode.app     = ""        ;
    onceMode.comWord = "1"       ;

    iok.type         = "ИОК"     ;
    iok.app          = "УХП"     ;
    iok.comWord      = "11299"   ;

    rk_Off.type      = "РК"        ;
    rk_Off.app       = "ОТКЛ. БАПИ";
    rk_Off.comWord   = "5"         ;

    tkpo.type        = "ТКПО"      ;
    tkpo.app         = "1"         ;
    tkpo.comWord     = "0"         ;

    usb.type         = "USB"       ;
    usb.app          = "1"         ;
    usb.comWord      = "0"         ;

    init.type        = "ИНИТ"      ;
    init.app         = "ТКПО 1"    ;
    init.comWord     = "0"         ;

    intl.type        = "Инициализация" ;
    intl.app         = "0"             ;
    intl.comWord     = "0"             ;

    flagPush = false;
}

/*********************************************************************
 * addItemsInTabPar  - вспомогательный метод, позволяющий добавить сразу
 * три поля в таблицу по полям структуры  relateItems.
 * *******************************************************************
 * Формальные параметры:
 * row     - номер строки в таблице;
 * type    - кодовое слово элемента режима;
 * app     - название элемента режима;
 * comWord - прибор элемента режима.
 * *******************************************************************
 * Локальные переменные:
 * num  - виджет таблицы, содержащий кодовое слово элемента режима;
 * inApp- виджет таблицы, содержащий название элемента режима;
 * com  - виджет таблицы, содержащий прибор элемента режима.
 **********************************************************************/
void cFormWithTable::addItemsInTabPar( int row, QString &type, QString &app, QString &comWord )
{
    ui->tableParameter_2->insertRow( row );

    QTableWidgetItem *num   = new QTableWidgetItem;
    QTableWidgetItem *inApp = new QTableWidgetItem;
    QTableWidgetItem *com   = new QTableWidgetItem;

    num->setText    ( type    );
    inApp->setText  ( app     );
    com->setText    ( comWord );

    ui->tableParameter_2->setItem( row, 2, num   );
    ui->tableParameter_2->setItem( row, 3, inApp );
    ui->tableParameter_2->setItem( row, 7, com   );
}

/*********************************************************************
 * addModeRecord     - метод, подготавливающий таблицу для режима ДР-ЗИ.
 * *******************************************************************
 * Формальные параметры:
 * row     - номер начальной строки в таблице;
 * column  - номер начального столбца в таблице.
 * *******************************************************************
 * Локальные переменные:
 * begTimeRK    - виджет таблицы, содержащий начальное время РК на включение;
 * endTimeRK    - виджет таблицы, содержащий конечное время РК на включение;
 * totalTimeRK  - виджет таблицы, содержащий длительность РК на включение.
 **********************************************************************/
void cFormWithTable::addModeRecord( int row)
{

    //Добавление РК в таблицу на включение УХП
    addItemsInTabPar( row, rk_On.type, rk_On.app, rk_On.comWord );

    //Добавление начальног времени
    QTableWidgetItem *begTimeRK   = new QTableWidgetItem;
    QTableWidgetItem *endTimeRK   = new QTableWidgetItem;
    QTableWidgetItem *totalTimeRK = new QTableWidgetItem;

    begTimeRK->setText  ("61");
    endTimeRK->setText  ("62");
    totalTimeRK->setText("1" );

    ui->tableParameter_2->setItem( row, 4, begTimeRK   );
    ui->tableParameter_2->setItem( row, 5, endTimeRK   );
    ui->tableParameter_2->setItem( row, 6, totalTimeRK );

    //Добавление ИП в таблицу
    addItemsInTabPar( row + 1, ip.type, ip.app, ip.comWord );

    //Добавление МКО в таблицу
    addItemsInTabPar( row + 2, mko.type, mko.app, mko.comWord );

    //Добавление первого режима в таблицу
    addItemsInTabPar( row + 3, onceMode.type, onceMode.app, onceMode.comWord );

    //Добавление ИОК в таблицу
    addItemsInTabPar( row + 4, iok.type, iok.app, iok.comWord );

    //Добавление РК в таблицу на отключение БАПИ
    addItemsInTabPar( row + 5, rk_Off.type, rk_Off.app, rk_Off.comWord );
}

/*********************************************************************
 * addModePlay - метод, подготавливающий таблицу для режима ДР-ВИ(КП).
 * *******************************************************************
 * Формальные параметры:
 * row     - номер начальной строки в таблице;
 * column  - номер начального столбца в таблице.
 * *******************************************************************
 * Локальные переменные:
 * begTimeRK    - виджет таблицы, содержащий начальное время РК на включение;
 * endTimeRK    - виджет таблицы, содержащий конечное время РК на включение;
 * totalTimeRK  - виджет таблицы, содержащий длительность РК на включение.
 **********************************************************************/
void cFormWithTable::addModePlay  (int row)
{
    addItemsInTabPar(row, intl.type, intl.app, intl.comWord);

    //Добавление ТКПО в таблицу
    addItemsInTabPar(row + 1, tkpo.type, tkpo.app, tkpo.comWord);
    addItemsInTabPar(row + 2, tkpo.type, tkpo.app, tkpo.comWord);

    //Добавление РК в таблицу на включение УХП
    addItemsInTabPar(row + 3, rk_On.type, rk_On.app, rk_On.comWord);

    //Добавление начальных значений в таблицу
    QTableWidgetItem *begTimeRK   = new QTableWidgetItem;
    QTableWidgetItem *endTimeRK   = new QTableWidgetItem;
    QTableWidgetItem *totalTimeRK = new QTableWidgetItem;

    begTimeRK->setText  ("61");
    endTimeRK->setText  ("62");
    totalTimeRK->setText("1" );

    ui->tableParameter_2->setItem( row + 3, 4, begTimeRK   );
    ui->tableParameter_2->setItem( row + 3, 5, endTimeRK   );
    ui->tableParameter_2->setItem( row + 3, 6, totalTimeRK );

    addItemsInTabPar( row + 4,  ip.type,        ip.app,         ip.comWord       );
    addItemsInTabPar( row + 5,  iok.type,       iok.app,        iok.comWord      );
    addItemsInTabPar( row + 6,  usb.type,       usb.app,        usb.comWord      );
    addItemsInTabPar( row + 7,  init.type,      init.app,       init.comWord     );
    addItemsInTabPar( row + 8,  onceMode.type,  onceMode.app,   onceMode.comWord );
    addItemsInTabPar( row + 9,  iok.type,       iok.app,        iok.comWord      );
    addItemsInTabPar( row + 10, rk_Off.type,    rk_Off.app,     rk_Off.comWord   );
}

/*********************************************************************
 * pushData - метод, заполняющий таблицу пользовательскими значениями
 * в зависимости от названия режима.
 * *******************************************************************
 * Формальные параметры:
 * iOK        - значение Тиок;
 * onceMode   - значение Т1-го режима;
 * iP         - значение Тип;
 * uprezh     - значение Тупрежд;
 * radioButOn - значение включенного устройства.
 * *******************************************************************
 * Локальная переменная:
 * countRowTable  - общее количество строк в таблице.
 **********************************************************************/
void cFormWithTable::pushData(int iOK, int onceMode, int iP, int uprezh, qint8 radioButOn)
{
    int countRowTable = ui->tableParameter_2->rowCount();

    for( int i = 0; i < countRowTable; i++ )
    {
        ui->tableParameter_2->removeRow( 0 );
    }

    switch ( numMode )
    {
        case 1:
            this->addModeRecord ( 0 );
            pushDataModeRec     ( iOK, onceMode, radioButOn );
            flagPush = true;
            break;

        case 2:
            this->addModePlay   ( 0 );
            pushDataModePlay    ( iOK, radioButOn );
            flagPush = true;
            break;

        default:
            QMessageBox::critical( 0,
                                   "Ошибка!",
                                   "Режим не найден! \n"
                                   "Этап: добавление данных в таблицу") ;
            flagPush = false;
            break;
    }

    if(flagPush)
    {
        this->pushMode     ( numTabMode );
        this->setExtraTable( numMode    );
    }
    Q_UNUSED(iP)
    Q_UNUSED(uprezh)
}

/*********************************************************************
 * pushDataModeRec   - метод, заполняющий таблицу вычислениями, если
 * выбран режим ДР-ЗИ.
 * *******************************************************************
 * Формальные параметры:
 * iOK        - значение Тиок;
 * onceMode   - значение Т1-го режима;
 * iP         - значение Тип;
 * uprezh     - значение Тупрежд;
 * radioButOn - значение включенного устройства.
 * *******************************************************************
 * Локальная переменная:
 * extra_onceMode   - переменная, необходимая для подсчета повторов ИОК;
 * numUHP           - объект для таблицы с текстом о включенном приборе;
 * itemBegin,beginOfCommand - объект, содержащий начало элемента таблицы режима;
 * itemFinish       - объект, содержащий конец элемента таблицы режима;
 * itemLength       - объект, содержащий длительность элемента таблицы режима;
 * i - счетчик цикла по строкам;
 * j - счетчик цикла по стобцам.
 **********************************************************************/
void cFormWithTable::pushDataModeRec( int iOK, int onceMode,
                                      qint8 radioButOn )
{
    //Подсчет количества повторов ИОК
    int extra_onceMode = 11 + onceMode;
    int numRepIOK      = 0       ;

    while( extra_onceMode > 0 )
    {
        extra_onceMode -= iOK;
        numRepIOK++;
    }


    if( radioButOn >= 1 && radioButOn <= 2 )
    {
         /* Заполнение первой строки в таблице РК (ВКЛ. УХП - ?) */
         QTableWidgetItem *numUHP = new QTableWidgetItem;

         numUHP->setText( "ВКЛ. УХП - " + QString::number( radioButOn ) );

         ui->tableParameter_2->setItem( 0, 3, numUHP );
    }

    on_tableParameter_2_itemChanged( ui->tableParameter_2->item( 0 ,5 ) );

    for( int i = 0, row = 0; i < 5; i++, row++ )
    {
        QTableWidgetItem *itemBegin  = new QTableWidgetItem;
        QTableWidgetItem *itemFinish = new QTableWidgetItem;

        switch(i)
        {
         case 0:
         {
            /* Заполнение строки в таблице ИП (КПИ УХП) */
            int beginOfCommand = ui->tableParameter_2->item( row, 4 )->text().toInt() + 5;

            itemBegin ->setText( QString::number( beginOfCommand     ) );
            itemFinish->setText( QString::number( beginOfCommand + 1 ) );

            ui->tableParameter_2->setItem( row + 1, 4, itemBegin  );
            ui->tableParameter_2->setItem( row + 1, 5, itemFinish );

            break;
         }

         case 1:
         {
            /* Заполнение строки в таблице МКО (СТИ) */
            int beginOfCommand = ui->tableParameter_2->item( row, 4 )->text().toInt() + 1;

            itemBegin ->setText( QString::number( beginOfCommand           ) );
            itemFinish->setText( QString::number( beginOfCommand + onceMode) );

            ui->tableParameter_2->setItem( row + 1, 4, itemBegin  );
            ui->tableParameter_2->setItem( row + 1, 5, itemFinish );

            break;
         }

         case 2:
         {
            /* Заполнение строки в таблице 1 режим (дублирует предыдущую строку ИП)*/
            itemBegin ->setText( ui->tableParameter_2->item( row, 4 )->text() );
            itemFinish->setText( ui->tableParameter_2->item( row, 5 )->text() );

            ui->tableParameter_2->setItem( row + 1, 4, itemBegin  );
            ui->tableParameter_2->setItem( row + 1, 5, itemFinish );

            break;
         }

         case 3:
         {
            /* Заполнение строки в таблице ИОК (УХП) */
            int beginOfCommand = ui->tableParameter_2->item( row, 4 )->text().toInt() + 1;

            itemBegin ->setText( QString::number( beginOfCommand       ));
            itemFinish->setText( QString::number( beginOfCommand + iOK ));

            ui->tableParameter_2->setItem( row + 1, 4, itemBegin  );
            ui->tableParameter_2->setItem( row + 1, 5, itemFinish );

            row++;


            for( int j = 0; j < numRepIOK-1; j++, row++ )
            {
                addItemsInTabPar( row + 1, iok.type, iok.app, iok.comWord );

                QTableWidgetItem *itemBeginExtr  = new QTableWidgetItem;
                QTableWidgetItem *itemFinishExtr = new QTableWidgetItem;

               int beginOfCommand = ui->tableParameter_2->item( row, 5 )->text().toInt();

                itemBeginExtr ->setText( QString::number( beginOfCommand       ));
                itemFinishExtr->setText( QString::number( beginOfCommand + iOK ));

                ui->tableParameter_2->setItem( row + 1, 4, itemBeginExtr  );
                ui->tableParameter_2->setItem( row + 1, 5, itemFinishExtr );
            }

            row--;

            break;
         }

         case 4:
         {
            /* Заполнение строки в таблице РК (ОТКЛ. БАПИ) */
            int beginOfCommand = onceMode + 12 +  ui->tableParameter_2->item( 3, 4 )->text().toInt();

            QTableWidgetItem *itemLength = new QTableWidgetItem;

            itemLength->setText( "3" );
            itemBegin ->setText( QString::number( beginOfCommand     ));
            itemFinish->setText( QString::number( beginOfCommand + 3 ));

            ui->tableParameter_2->setItem( row + 1, 4, itemBegin  );
            ui->tableParameter_2->setItem( row + 1, 5, itemFinish );
            ui->tableParameter_2->setItem( row + 1, 6, itemLength );

            break;
         }
       }
    }
}

/*********************************************************************
 * pushDataModePlay  - метод, заполняющий таблицу вычислениями, если
 * выбран режим ДР-ВИ(КП).
 * *******************************************************************
 * Формальные параметры:
 * iOK        - значение Тиок;
 * onceMode   - значение Т1-го режима;
 * iP         - значение Тип;
 * uprezh     - значение Тупрежд;
 * radioButOn - значение включенного устройства.
 * *******************************************************************
 * Локальная переменная:
 * onceIokPush, countOnceIokLoop - переменные, необходимая для подсчета
 * повторов ИОК;
 * numUHP           - объект для таблицы с текстом о включенном приборе;
 * itemBegin,beginOfCommand - объект, содержащий начало элемента таблицы режима;
 * itemFinish       - объект, содержащий конец элемента таблицы режима;
 * itemLength       - объект, содержащий длительность элемента таблицы режима;
 * i, row           - счетчики цикла по строкам;
 * j                - счетчик цикла по стобцам.
 **********************************************************************/
void cFormWithTable::pushDataModePlay( int iOK,
                                       qint8 radioButOn  )
{
    int onceIokPush      = 180;
    int countOnceIokLoop = 0  ;

    //Подсчет количества повторов первых ИОК-ов
    while( onceIokPush > 0 )
    {
        onceIokPush -= iOK;
        countOnceIokLoop++;
    }

    if( radioButOn >= 1 && radioButOn <=2 )
    {
         /* Заполнение первой строки в таблице РК (ВКЛ. УХП - ?) */
         QTableWidgetItem *numUHP = new QTableWidgetItem;

         numUHP->setText( "ВКЛ. УХП - " + QString::number( radioButOn ) );

         ui->tableParameter_2->setItem( 3, 3, numUHP );
    }

   // on_tableParameter_2_itemChanged(ui->tableParameter_2->item(0,5));

    for( int i= 0, row = 0; i < 11; i++, row++ )
    {
        QTableWidgetItem *itemBegin  = new QTableWidgetItem;
        QTableWidgetItem *itemFinish = new QTableWidgetItem;

        switch(i)
        {
         case 0:
         {
            /* Заполнение строки в таблице Инициализация */
            itemBegin ->setText( QString::number( 0 ) );
            itemFinish->setText( QString::number( 1 ) );

            ui->tableParameter_2->setItem( row, 4, itemBegin  );
            ui->tableParameter_2->setItem( row, 5, itemFinish );

            break;
         }

         case 1:
         {
            /* Заполнение строки в таблице ТКПО(1) */
            int beginOfCommand = ui->tableParameter_2->item( row - 1, 5 )->text().toInt();

            itemBegin ->setText( QString::number( beginOfCommand      ) );
            itemFinish->setText( QString::number( beginOfCommand + 60 ) );

            ui->tableParameter_2->setItem( row, 4, itemBegin  );
            ui->tableParameter_2->setItem( row, 5, itemFinish );

            break;
         }

         case 2:
         {
            /* Заполнение строки в таблице ТКПО(2)*/
            int beginOfCommand = ui->tableParameter_2->item( row - 2, 5 )->text().toInt();

            itemBegin ->setText( QString::number( beginOfCommand       ) );
            itemFinish->setText( QString::number( beginOfCommand + 853 ) );

            ui->tableParameter_2->setItem( row, 4, itemBegin  );
            ui->tableParameter_2->setItem( row, 5, itemFinish );

            break;
         }

         case 3:
         {
            row++;

            /* Заполнение строки в таблице ИП */
            int beginOfCommand = ui->tableParameter_2->item( row - 1, 5 )->text().toInt() + 4;

            itemBegin ->setText( QString::number( beginOfCommand     ) );
            itemFinish->setText( QString::number( beginOfCommand + 1 ) );

            ui->tableParameter_2->setItem( row, 4, itemBegin  );
            ui->tableParameter_2->setItem( row, 5, itemFinish );

            break;
         }

         case 4:
         {
            /* Заполнение строки в таблице ИОК(1) */
            int beginOfCommand = ui->tableParameter_2->item( row - 1, 5 )->text().toInt() + 1;

            itemBegin ->setText( QString::number( beginOfCommand       ) );
            itemFinish->setText( QString::number( beginOfCommand + iOK ) );

            ui->tableParameter_2->setItem( row, 4, itemBegin  );
            ui->tableParameter_2->setItem( row, 5, itemFinish );

            row++;

            for( int j = 0; j < countOnceIokLoop - 1; j++, row++ )
            {
                addItemsInTabPar( row, iok.type, iok.app, iok.comWord );

                QTableWidgetItem *itemBeginExtr  = new QTableWidgetItem;
                QTableWidgetItem *itemFinishExtr = new QTableWidgetItem;

               int beginOfCommand = ui->tableParameter_2->item( row - 1, 5 )->text().toInt();

                itemBeginExtr ->setText( QString::number( beginOfCommand       ) );
                itemFinishExtr->setText( QString::number( beginOfCommand + iOK ) );

                ui->tableParameter_2->setItem( row, 4, itemBeginExtr  );
                ui->tableParameter_2->setItem( row, 5, itemFinishExtr );

            }

            row--;

            break;
         }

         case 5:
         {
            /* Заполнение строки в таблице USB */
            itemBegin ->setText( QString::number( 239 ) );
            itemFinish->setText( QString::number( 843 ) );

            ui->tableParameter_2->setItem( row, 4, itemBegin  );
            ui->tableParameter_2->setItem( row, 5, itemFinish );

            break;
         }

        case 6:
        {
           /* Заполнение строки в таблице ИНИТ*/
           itemBegin ->setText( QString::number( 239 ) );
           itemFinish->setText( QString::number( 240 ) );

           ui->tableParameter_2->setItem( row, 4, itemBegin  );
           ui->tableParameter_2->setItem( row, 5, itemFinish );

           break;
        }

        case 7:
        {
           /* Заполнение строки в таблице 1 режима*/
           itemBegin ->setText( QString::number( 242 ) );
           itemFinish->setText( QString::number( 842 ) );

           ui->tableParameter_2->setItem( row, 4, itemBegin  );
           ui->tableParameter_2->setItem( row, 5, itemFinish );

           break;
        }

        case 8:
        {
            //Подсчет количества повторов вторых ИОК-ов
            int extra_onceMode = 600;
            int numRepIOK = 0;

            while( extra_onceMode > 0 )
            {
                extra_onceMode -= iOK;
                numRepIOK++;
            }

            /* Заполнение строки в таблице ИОК(2) */
            int beginOfCommand = ui->tableParameter_2->item( row - 4, 5 )->text().toInt();

            itemBegin ->setText( QString::number( beginOfCommand       ) );
            itemFinish->setText( QString::number( beginOfCommand + iOK ) );

            ui->tableParameter_2->setItem( row, 4, itemBegin  );
            ui->tableParameter_2->setItem( row, 5, itemFinish );

            row++;

            for( int j = 0; j < numRepIOK - 1; j++, row++ )
            {
                addItemsInTabPar( row, iok.type, iok.app, iok.comWord );

                QTableWidgetItem *itemBeginExtr  = new QTableWidgetItem;
                QTableWidgetItem *itemFinishExtr = new QTableWidgetItem;

                int beginOfCommand = ui->tableParameter_2->item( row - 1, 5 )->text().toInt();

                itemBeginExtr ->setText( QString::number( beginOfCommand       ) );
                itemFinishExtr->setText( QString::number( beginOfCommand + iOK ) );

                ui->tableParameter_2->setItem( row, 4, itemBeginExtr  );
                ui->tableParameter_2->setItem( row, 5, itemFinishExtr );
            }

            row--;

           break;
        }
        case 9:
        {
           /* Заполнение строки в таблице РК (ОТКЛ. БАПИ) */
           int beginOfCommand = 854;

           QTableWidgetItem *itemLength = new QTableWidgetItem;

           itemLength->setText( "3" );
           itemBegin ->setText( QString::number( beginOfCommand     ) );
           itemFinish->setText( QString::number( beginOfCommand + 3 ) );

           ui->tableParameter_2->setItem( row, 4, itemBegin  );
           ui->tableParameter_2->setItem( row, 5, itemFinish );
           ui->tableParameter_2->setItem( row, 6, itemLength );

           break;
        }
      }
    }
}

/*********************************************************************
 * pushMode - метод, заполняющий таблицу в столбце "Номер режима".
 * *******************************************************************
 * Формальный параметр:
 * num     - номер режима.
 * *******************************************************************
 * Локальная переменная:
 * itemNum  - объект таблицы, содержащий номер режима.
 **********************************************************************/
void cFormWithTable::pushMode( int num )
{
    for( int i = 0; i < ui->tableParameter_2->rowCount(); i++ )
    {
        QTableWidgetItem *itemNum = new QTableWidgetItem;

        itemNum->setText( QString::number( num ) );

        ui->tableParameter_2->setItem( i, 1, itemNum );
    }
}

/*********************************************************************
 * setExtraTable - метод, предоставляющий доступ к различным элементам класса
 * cFormWithTable в зависимости от режима;.
 * *******************************************************************
 * Формальный параметр:
 * num     - номер режима.
 * *******************************************************************/
void cFormWithTable::setExtraTable( int num )
{
    switch (num)
    {
         case 1:
         {
             ui->comTZI_1         ->setEnabled( false );
             ui->comDKI_2         ->setEnabled( false );
             ui->comVI_3          ->setEnabled( false );
             ui->comNFI_4         ->setEnabled( true  );
             ui->comZKI_5         ->setEnabled( false );
             ui->comGL_BL_6       ->setEnabled( false );
             ui->comFSCH_7        ->setEnabled( false );
             ui->comPPK_MC_8      ->setEnabled( false );
             ui->comPKR_GMM_9     ->setEnabled( false );
             ui->comPNA_M_10      ->setEnabled( false );
             ui->comDZU_11        ->setEnabled( true  );
             ui->comChange_12     ->setEnabled( false );
             ui->comRange_13      ->setEnabled( false );
             ui->comFCH_14        ->setEnabled( false );
             ui->comCompisition_15->setEnabled( false );

             break;
         }

         case 2:
         {
             ui->comTZI_1         ->setEnabled( true  );
             ui->comDKI_2         ->setEnabled( false );
             ui->comVI_3          ->setEnabled( true  );
             ui->comNFI_4         ->setEnabled( true  );
             ui->comZKI_5         ->setEnabled( true  );
             ui->comGL_BL_6       ->setEnabled( true  );
             ui->comFSCH_7        ->setEnabled( false );
             ui->comPPK_MC_8      ->setEnabled( true  );
             ui->comPKR_GMM_9     ->setEnabled( false );
             ui->comPNA_M_10      ->setEnabled( false );
             ui->comDZU_11        ->setEnabled( false );
             ui->comChange_12     ->setEnabled( true  );
             ui->comRange_13      ->setEnabled( false );
             ui->comFCH_14        ->setEnabled( false );
             ui->comCompisition_15->setEnabled( true  );

             break;
         }
         default:
             QMessageBox::critical( 0,
                                    "Ошибка!",
                                    "Режим не найден! \n"
                                    "Этап: доступ к элементам") ;
             break;
    }
}

/*********************************************************************
 * flagPushData - метод, возвращающий значение флага flagPush.
 * *******************************************************************/
bool cFormWithTable::flagPushData()
{
    return flagPush;
}

/*********************************************************************
 * dataComBoxForFile - метод, переносящий данные из группы "Первый режим" в файл.
 * *******************************************************************
 * Формальные параметры:
 * numMode     - номер режима;
 * stream      - поток записи в файл.
 * *******************************************************************/
void cFormWithTable::dataComBoxForFile( int numMode, QTextStream  &stream)
{
    switch (numMode) {
    case 1:
        //Запись ДР-ЗИ 1 режим
        stream << ui->label_NFI_4->text();
        stream << ui->comNFI_4 ->currentText().mid( 0, ui->comNFI_4 ->currentText().indexOf(" -") )      << "\r\n";

        stream << ui->label_DZU_11->text();
        stream << ui->comDZU_11->currentText().mid( 0, ui->comDZU_11->currentText().indexOf(" -") )      << "\r\n";
        break;
    case 2:
        //Запись ДР-ВИ 1 режим
        stream << ui->label_TZI_1   ->text();
        stream << ui->comTZI_1         ->currentText().mid(0,ui->comTZI_1         ->currentText().indexOf(" -"))      << "\r\n";

        stream << ui->label_VI_3    ->text();
        stream << ui->comVI_3          ->currentText().mid(0,ui->comVI_3          ->currentText().indexOf(" -"))      << "\r\n";

        stream << ui->label_NFI_4   ->text();
        stream << ui->comNFI_4         ->currentText().mid(0,ui->comNFI_4         ->currentText().indexOf(" -"))      << "\r\n";

        stream << ui->label_ZKI_5   ->text();
        stream << ui->comZKI_5         ->currentText().mid(0,ui->comZKI_5         ->currentText().indexOf(" -"))      << "\r\n";

        stream << ui->label_GL_BL_6 ->text();
        stream << ui->comGL_BL_6       ->currentText().mid(0,ui->comGL_BL_6       ->currentText().indexOf(" -"))      << "\r\n";

        stream << ui->label_PPK_MC_8->text();
        stream << ui->comPPK_MC_8      ->currentText().mid(0,ui->comPPK_MC_8      ->currentText().indexOf(" -"))      << "\r\n";

        stream << ui->label_Change_12->text();
        stream << ui->comChange_12     ->currentText().mid(0,ui->comChange_12     ->currentText().indexOf(" -"))      << "\r\n";

        stream << ui->label_Compisition_15->text();
        stream << ui->comCompisition_15->currentText().mid(0,ui->comCompisition_15->currentText().indexOf(" -"))      << "\r\n";
        break;
    default:
        QMessageBox::critical(0,
                              "Ошибка",
                              "Режим не найден");
        break;
    }


}

/*********************************************************************
 * ~cFormWithTable   - деструктор  класса cFormWithTable.
 * *******************************************************************/
cFormWithTable::~cFormWithTable()
{
    delete ui;
}

/*********************************************************************
 * on_tableParameter_2_itemChanged - слот, вычисляющий длительность каждого
 * параметра режима в таблице.
 * *******************************************************************
 * Формальный параметр:
 * item     - объект таблицы, в котором произошли пользовательские изменения.
 * *******************************************************************
 * Локальные переменные:
 * pBegin  - время начала элемента режима;
 * pEnd    - время конца  элемента режима.
 **********************************************************************/
void cFormWithTable::on_tableParameter_2_itemChanged( QTableWidgetItem *item )
{
       if (( item->column() == 5 ) &&
           ( item->row()    >= 0   &&
             item->row()    < ui->tableParameter_2->rowCount()) &&
           ( !ui->tableParameter_2->item(item->row(),
                                                item->column()-1)->text().isEmpty()))
        {
            QTableWidgetItem *pBegin = new QTableWidgetItem(
                        ui->tableParameter_2->item(item->row(),
                                                   item->column())->text());

            QTableWidgetItem *pEnd = new QTableWidgetItem(
                        ui->tableParameter_2->item(item->row(),
                                                   item->column()-1)->text());

            ui->tableParameter_2->setItem(item->row(), 6,
                        new QTableWidgetItem(QString::number(
                                                 QString(pBegin->text()).toInt()-
                                                 QString(pEnd  ->text()).toInt())));
        }
}
