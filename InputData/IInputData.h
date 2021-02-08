/***************************************************************
**
** IInputData - интерфейс, наследующий класс QObject
** и содержащий чисто виртуальные функции для реализации
** алгоритмов манипулирования данными взависимости
** от типа оборудования.
****************************************************************
** Создан 20.09.2020 Семенов Д.С. Заявка №00001
****************************************************************
** Основные чисто виртуальные функции:
** readCyclegrammaFile : CodeExec - чтение файла плана;
** getInputData : QByteArray - получение структуры исходных данных;
** getRK : QByteArray - получение структуры РК;
** getDateTime : QString - получение исходного времени;
** setData : void - задание данных плана.
****************************************************************/

#ifndef IINPUTDATA_H
#define IINPUTDATA_H

#include <QDataStream>
#include <QDateTime>
#include <QTimerEvent>

#include "EnumClasses.h"
#include "Structures.h"

class IInputData : public QObject
{
    Q_OBJECT
public:
    IInputData(QObject *parent = nullptr):
        QObject(parent)
    {};

    virtual CodeExec readCyclegrammaFile(const QString &) = 0;

    virtual const QByteArray & getInputData() = 0;
    virtual const QByteArray & getRK() = 0;
    virtual const QString & getDateTime() = 0;
    virtual void setData(const QString &) = 0;

    virtual ~IInputData() {};
};

#endif // IINPUTDATA_H
