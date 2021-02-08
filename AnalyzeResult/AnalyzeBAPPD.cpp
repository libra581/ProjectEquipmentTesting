#include "AnalyzeBAPPD.h"

QDataStream & operator>>(QDataStream &in, Struct::DataBAPPD &p){
    in >> p.usNumMode >> p.usCodeMode >> p.usNumSession
    >> p.TRejStart1[0] >> p.TRejStart1[1] >> p.TRejStart1[2] >> p.TRejStart1[3]
    >> p.TRejEnd1[0] >> p.TRejEnd1[1] >> p.TRejEnd1[2] >> p.TRejEnd1[3]
    >> p.TRejStart2[0]  >> p.TRejStart2[1] >> p.TRejStart2[2] >> p.TRejStart2[3]
    >> p.TRejEnd2[0] >> p.TRejEnd2[1] >> p.TRejEnd2[2]>> p.TRejEnd2[3]
    >> p.MemoryAddress >> p.NumberProgram >> p.AmountDataWords >> p.State >> p.Reserve;
    return in;
}


QDataStream &operator<<(QDataStream &out, const Struct::DataBAPPD &p){
    out << p.usNumMode << p.usCodeMode << p.usNumSession
    << p.TRejStart1[0] << p.TRejStart1[1] << p.TRejStart1[2] << p.TRejStart1[3]
    << p.TRejEnd1[0] << p.TRejEnd1[1] << p.TRejEnd1[2] << p.TRejEnd1[3]
    << p.TRejStart2[0]  << p.TRejStart2[1] << p.TRejStart2[2] << p.TRejStart2[3]
    << p.TRejEnd2[0] << p.TRejEnd2[1] << p.TRejEnd2[2]<< p.TRejEnd2[3]
    << p.MemoryAddress << p.NumberProgram << p.AmountDataWords << p.State << p.Reserve;
    return out;
}


inline QDataStream & operator>>(QDataStream &in, Struct::masRK &p){
    in >> p.Comp1 >> p.Comp2 >> p.EnableParachute
            >> p.PS1 >> p.PS2 >> p.SpecInfo;
    return in;
}

inline QDataStream &operator<<(QDataStream &out, const Struct::masRK &p){
    out << p.Comp1 << p.Comp2 << p.EnableParachute
            << p.PS1 << p.PS2 << p.SpecInfo;
    return out;
}

AnalyzeBAPPD::AnalyzeBAPPD(QObject *parent)
    : IAnalyze(parent)
{

}

CodeExec AnalyzeBAPPD::setPlan(const QString &filename)
{
    QFile fileData(filename);

    if (!fileData.open(QIODevice::ReadOnly))
    {
        return CodeExec::ErrorFile;
    }

    QDataStream in(&fileData);
    in >> date_time_plan;
    in >> usQuantRej_plan;
    in >> obj_Data_BAPPD_plan;
    in >> obj_RK_BAPPD_plan;

    fileData.close();

    return CodeExec::Success;
}

CodeExec AnalyzeBAPPD::setOutputData(const QByteArray &output_data)
{
    QDataStream out(output_data);
    out >> date_time;
    out >> usQuantRej;
    out >> obj_Data_BAPPD;
    out >> obj_RK_BAPPD;

    return CodeExec::Success;
}

quint8 AnalyzeBAPPD::analyze()
{
    quint8 result = this->countErrorStructres(obj_Data_BAPPD, obj_RK_BAPPD, obj_Data_BAPPD_plan, obj_RK_BAPPD_plan);
    return result;
}

quint8 AnalyzeBAPPD::countErrorStructres(const Struct::DataBAPPD &data_1, const Struct::masRK &rk_1,
                                 const Struct::DataBAPPD &data_2, const Struct::masRK &rk_2)
{
    quint8 count_errors{0};


    if(data_1.usNumMode != data_2.usNumMode)
    {
        count_errors += 1;
    }

    if(data_1.usCodeMode != data_2.usCodeMode)
    {
        count_errors += 1;
    }

    if(data_1.usNumSession != data_2.usNumSession)
    {
        count_errors += 1;
    }

    count_errors += countErrorMasInt8(data_1.TRejStart1, 4, data_2.TRejStart1, 4);
    count_errors += countErrorMasInt8(data_1.TRejStart2, 4, data_2.TRejStart2, 4);
    count_errors += countErrorMasInt8(data_1.TRejEnd1, 4, data_2.TRejEnd1, 4);
    count_errors += countErrorMasInt8(data_1.TRejEnd2, 4, data_2.TRejEnd2, 4);

    if(data_1.MemoryAddress != data_2.MemoryAddress)
    {
        count_errors += 1;
    }

    if(data_1.NumberProgram != data_2.NumberProgram)
    {
        count_errors += 1;
    }

    if(data_1.AmountDataWords != data_2.AmountDataWords)
    {
        count_errors += 1;
    }

    if(data_1.State != data_2.State)
    {
        count_errors += 1;
    }

    if(data_1.Reserve.compare(data_2.Reserve) != 0)
    {
        count_errors += 1;
    }

    count_errors += this->countErrorRK(rk_1, rk_2);

    return count_errors;
}

