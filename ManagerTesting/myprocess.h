/***************************************************************
** myProcess - класс, который наследует возможности QProcess и
** реализует пользовательскую интеграцию в QML.
****************************************************************
** Назначение класса: используется для интеграции класса QProcess
** в QML для создания пользовательского типа Process.
****************************************************************
** Создан 10.10.2020 Семенов Д.С. Заявка №00001
****************************************************************
** Основные методы:
** start : void - реализует запуск процесса;
** readAll : qint32 - считывает код возврата процесса.
****************************************************************/

#ifndef MYPROCESS_H
#define MYPROCESS_H

#include <QProcess>
#include <QVariant>
#include <QDebug>

class myProcess : public QProcess
{
    Q_OBJECT
public:
    myProcess(QObject *parent = 0) : QProcess(parent) { }
    Q_INVOKABLE void start(const QString &program, const QVariantList &arguments);
    Q_INVOKABLE qint32 readAll();
    ~myProcess() {};
};

#endif // MYPROCESS_H
