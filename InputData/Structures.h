/***************************************************************
**
** Structures.h - содержит структуры используемые в программе.
****************************************************************
** Создан 20.09.2020 Семенов Д.С. Заявка №00001
****************************************************************
** Основные структуры:
** DataBASI - содержит поля исходных данных БАСИ;
** DataBAPPD - содержит поля исходных данных БАППД;
** masRK - содержит поля разовых команд для БАСИ и БАППД.
****************************************************************/

#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <QtGlobal>
#include <QDataStream>

namespace Struct
{

    struct DataBASI
    {
        quint16 usCodeMode;
        quint16 usNumSession;

        qint32 MemoryAddress;
        qint32 NumberProgram;
        qint32 AmountDataWords;
        qint32 State;
        QByteArray Reserve;
    };


    struct DataBAPPD
    {
        quint16 usNumMode;
        quint16 usCodeMode;
        quint16 usNumSession;

        qint8 TRejStart1[4];
        qint8 TRejEnd1[4];
        qint8 TRejStart2[4];
        qint8 TRejEnd2[4];

        qint32 MemoryAddress;
        qint32 NumberProgram;
        qint32 AmountDataWords;
        qint32 State;
        QByteArray Reserve;
    };

    struct masRK
    {
        bool Comp1;
        bool Comp2;
        bool EnableParachute;
        bool PS1;
        bool PS2;
        qint32 SpecInfo;
    };
};

#endif // STRUCTURES_H
