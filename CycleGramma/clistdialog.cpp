#include "cListDialog.h"

/*********************************************************************
 * cListDialog   - конструктор класса cListDialog.
 * *******************************************************************
 * Формальный параметр:
 * parent -  указатель на объект родителя.
 * *******************************************************************
 * Локальные переменные:
 * strLst     - лист строк, содержащий список режимов;
 * pItem      - виджет, содержащий строку из strLst и располагающийся в list;
 * str        - строка, ходящая по strLst;
 * pcmdOk     - кнопка добавления;
 * pcmdCancel - кнопка отмены;
 * ptopLayout - макет, на котором располагаются элементы.
 *********************************************************************
*/
cListDialog::cListDialog( QWidget *parent )
    : QDialog( parent, Qt::WindowTitleHint | Qt::WindowSystemMenuHint )
{
    this->setWindowTitle("Выбор режима");

    QStringList      strLst;
    QListWidgetItem* pItem;

    strLst << tr( "ДР - ЗИ" ) << tr( "ДР - ВИ (КП)" );

    foreach( QString str, strLst )
    {
        pItem = new QListWidgetItem( str, &list );
    }

    QPushButton* pcmdOk     = new QPushButton("&Добавить");
    QPushButton* pcmdCancel = new QPushButton("&Отмена"  );

    connect(pcmdOk,     SIGNAL(clicked()),                  SLOT(accept()) );
    connect(pcmdCancel, SIGNAL(clicked()),                  SLOT(reject()) );
    connect(&list,      SIGNAL(doubleClicked(QModelIndex)), SLOT(accept()) );


    QGridLayout* ptopLayout = new QGridLayout;
    ptopLayout->addWidget( &list,         0, 0, 1, 2    );
    ptopLayout->addWidget(  pcmdOk,       1, 0          );
    ptopLayout->addWidget(  pcmdCancel,   1, 1          );

    this->setLayout( ptopLayout );
}

/*********************************************************************
 * currentItemList - метод, возвращающий текущий режим, выбранный
* пользователем.
 * ******************************************************************/
QString cListDialog::currentItemList() const
{
    return list.currentItem()->text();
}
