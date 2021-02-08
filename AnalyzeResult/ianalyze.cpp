#include "ianalyze.h"

IAnalyze::IAnalyze(QObject *parent)
    : QObject(parent)
{

}

quint8 IAnalyze::countErrorStructres(const Struct::DataBAPPD &, const Struct::masRK &, const Struct::DataBAPPD &, const Struct::masRK &)
{
    return 0;
}

quint8 IAnalyze::countErrorStructres(const Struct::DataBASI &, const Struct::masRK &, const Struct::DataBASI &, const Struct::masRK &)
{
    return 0;
}

quint8 IAnalyze::countErrorRK(const Struct::masRK &rk_1, const Struct::masRK &rk_2)
{
    quint8 count_errors{0};

    if(rk_1.Comp1 != rk_2.Comp2)
    {
        count_errors += 1;
    }

    if(rk_1.Comp2 != rk_2.Comp2)
    {
        count_errors += 1;
    }

    if(rk_1.EnableParachute != rk_2.EnableParachute)
    {
        count_errors += 1;
    }


    if(rk_1.PS1 != rk_2.PS1)
    {
        count_errors += 1;
    }


    if(rk_1.PS2 != rk_2.PS2)
    {
        count_errors += 1;
    }

    if(rk_1.SpecInfo != rk_2.SpecInfo)
    {
        count_errors += 1;
    }

    return count_errors;
}

quint8 IAnalyze::countErrorMasInt8(const qint8 tr_1[], qint8 length_1, const qint8 tr_2[], qint8 length_2)
{
    quint8 count_errors{0};

    if(length_1 == length_2)
    {
        for(int i = 0; i < length_1; ++i)
        {
            if(tr_1[i] != tr_2[i])
                count_errors += 1;
        }
    }

    return count_errors;
}

CodeExec createTMI(const QString &filename, const QByteArray &data)
{
    QFile fileData(filename);

    if (!fileData.open(QIODevice::WriteOnly))
    {
        return CodeExec::Error;
    }

    QDataStream out(&fileData);
    out << data;

    fileData.close();

    return CodeExec::Success;
}
