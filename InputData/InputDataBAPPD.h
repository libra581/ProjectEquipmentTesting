/***************************************************************
**
** InputDataBAPPD - класс, который наследует интерфейс IInputData и
** реализует логику имитации входных данных БАППД.
****************************************************************
** Назначение класса: используется для реализации алгоритма
** чтения и хранения данных плана для испытания БАППД.
****************************************************************
** Основной алгоритм:
** Считывание из файла плана производится в следующем порядке:
** 1) исходное время;
** 2) количество режимов;
** 3) исходные данные БАППД;
** 4) РК БАППД.
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

#ifndef INPUTDATABAPPD_H
#define INPUTDATABAPPD_H

#include <QTextStream>
#include <QFile>
#include <QDataStream>

#include "iinputdata.h"
#include "Structures.h"
#include "ExeptionInputData.h"

class InputDataBAPPD : public IInputData
{
    Q_OBJECT
private:
    quint16 usQuantRej = 0;
    Struct::DataBAPPD obj_Data_BAPPD;
    Struct::masRK obj_RK_BAPPD;

    QString date_time;

    QByteArray btarr_Data_BAPPD;
    QByteArray btarr_RK_BAPPD;

public:
    InputDataBAPPD(QObject *parent = nullptr);

    virtual CodeExec readCyclegrammaFile(const QString & filename) override;

    virtual const QByteArray & getInputData() override;
    virtual const QByteArray & getRK() override;
    virtual const QString &getDateTime() override;
    virtual void setData(const QString &filename) override;

    friend QDataStream & operator>>(QDataStream &in, Struct::DataBAPPD &p);
    friend QDataStream &operator<<(QDataStream &out, const Struct::DataBAPPD &p);

    friend QDataStream & operator>>(QDataStream &in, Struct::masRK &p);
    friend QDataStream & operator<<(QDataStream &out, const Struct::masRK &p);

private:
    void writeToByteArray();
};

#endif // INPUTDATABAPPD_H
