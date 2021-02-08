/***************************************************************
**
** InputDataBASI - класс, который наследует интерфейс IInputData и
** реализует логику имитации входных данных БАСИ.
****************************************************************
** Назначение класса: используется для реализации алгоритма
** чтения и хранения данных плана для испытания БАСИ.
****************************************************************
** Основной алгоритм:
** Считывание из файла плана производится в следующем порядке:
** 1) исходное время;
** 2) исходные данные БАСИ;
** 3) РК БАСИ.
****************************************************************
** Создан 20.09.2020 Семенов Д.С. Заявка №00001
****************************************************************
** Основные методы:
** readCyclegrammaFile : CodeExec - чтение файла плана;
** getInputData : QByteArray - получение структуры исходных данных;
** getRK : QByteArray - получение структуры РК;
** getDateTime : QString - получение исходного времени;
** setData : void - задание данных плана
** writeToByteArray : void - преобразование структур данных в QByteArray
** для отправки по порту.
****************************************************************
** Дружественные функции:
** operator>> и operator<< - используются для инициализации
** структур данных представленных в файле "Structures.h".
**
****************************************************************/

#ifndef INPUTDATABASI_H
#define INPUTDATABASI_H

#include <QtGlobal>
#include <QDebug>
#include <QTextStream>
#include <QFile>
#include <QDataStream>

#include "iinputdata.h"
#include "Structures.h"
#include "ExeptionInputData.h"

class InputDataBASI : public IInputData
{
    Q_OBJECT
private:
    Struct::DataBASI obj_Data_BASI;
    Struct::masRK obj_RK_BASI;

    QString date_time;

    QByteArray btarr_Data_BASI;
    QByteArray btarr_RK_BASI;

public:
    InputDataBASI(QObject *parent = nullptr);

    virtual CodeExec readCyclegrammaFile(const QString & filename) override;

    virtual const QByteArray &getInputData() override;
    virtual const QByteArray &getRK() override;
    virtual const QString & getDateTime() override;
    virtual void setData(const QString &filename) override;

    friend QDataStream & operator>>(QDataStream &in, Struct::DataBASI &p);
    friend QDataStream & operator<<(QDataStream &out, const Struct::DataBASI &p);

    friend QDataStream & operator>>(QDataStream &in, Struct::masRK &p);
    friend QDataStream & operator<<(QDataStream &out, const Struct::masRK &p);

private:
    void writeToByteArray();
    void unitTestFileRead();
    bool equalStructres(const Struct::DataBASI &data_1, const Struct::masRK &rk_1,
                        const Struct::DataBASI &data_2, const Struct::masRK &rk_2);
};

#endif // INPUTDATABASI_H
