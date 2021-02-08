/***************************************************************
**
** ImitLogic - класс, который наследует возможности QObject и
** реализует логику имитации входных данных
** испытуемого оборудования.
****************************************************************
** Назначение класса: используется для имитации
** исходных данных и подачи разовых команд по COM4-порту в
** определенное время, указанное в плане.
****************************************************************
** Основной алгоритм:
** Перед подачей РК идет секундная готовность.
** Первыми подаются разовые команды.
** После чего следует секунда ожидания и
** подаются исходные данные. После еще одной секунды завершается
** программа.
****************************************************************
** Создан 20.09.2020 Семенов Д.С. Заявка №00001
****************************************************************
** Входные параметры конструктора:
** type : TypeEquipment - тип оборудования;
** filename : QString - путь к файлу плана.
****************************************************************
** Основные методы:
** sendInputData : CodeExec - подает исходных данные по COM-порту;
** sendRK : CodeExec - подает РК по COM-порту;
** exit : void - отправляет код возврата;
** timerEvent : void - обработчик событий таймера.
****************************************************************/

#ifndef IMITLOGIC_H
#define IMITLOGIC_H

#include <QDebug>
#include <QTextStream>
#include <QtSerialPort/QSerialPort>
#include <QSerialPortInfo>

#include "EnumClasses.h"
#include "iinputdata.h"
#include "InputDataBASI.h"
#include "InputDataBAPPD.h"
#include "ExeptionInputData.h"

class ImitLogic : public QObject
{
    Q_OBJECT
private:
    IInputData *objInpData = nullptr;
    QTextStream cerr;
    QString filename = "None";
    CodeExec result = CodeExec::Waiting;
    QSerialPort *serial_port;

public:
    ImitLogic(TypeEquipment type = TypeEquipment::BASI,
              const QString &filename = "None", QObject *parent = nullptr);

    CodeExec sendInputData();
    CodeExec sendRK();

    ~ImitLogic();

protected:
    virtual void timerEvent(QTimerEvent *event) override;

signals:
    void exit(int code);

private:
    CodeExec working();
};

#endif // IMITLOGIC_H
