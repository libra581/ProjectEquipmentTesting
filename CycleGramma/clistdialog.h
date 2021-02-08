/*
* cListDialog - класс клиентского диалогового окна для добавления режима
* во вкладки.
* *********************************************************************
* Назначение класса: диалоговое окно для выбора режима пользователем.
* *********************************************************************
* Свойства класса:
* list   - объект, хранящий список режимов для добавления в закладки.
* *********************************************************************
* Используемые методы:
* cListDialog     - конструктор класса cListDialog;
* currentItemList - метод, возвращающий текущий режим, выбранный
* пользователем.
* *********************************************************************
*/

#ifndef CLISTDIALOG_H
#define CLISTDIALOG_H

#include <QDialog>
#include <QListWidget>
#include <QGridLayout>
#include <QPushButton>

class cListDialog : public QDialog
{
    Q_OBJECT

private:
    QListWidget list;

public:
    cListDialog            ( QWidget* parent = nullptr )      ;
    QString currentItemList(                           ) const;
};

#endif // CLISTDIALOG_H
