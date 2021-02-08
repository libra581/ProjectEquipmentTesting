#include "AnalyzeBASI.h"

QDataStream & operator>>(QDataStream &in, Struct::DataBASI &p){
    in >> p.usCodeMode >> p.usNumSession >> p.MemoryAddress
            >> p.NumberProgram >> p.AmountDataWords >> p.State >> p.Reserve;
    return in;
}


QDataStream &operator<<(QDataStream &out, const Struct::DataBASI &p){
    out << p.usCodeMode << p.usNumSession << p.MemoryAddress
            << p.NumberProgram << p.AmountDataWords << p.State << p.Reserve;
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

AnalyzeBASI::AnalyzeBASI(QObject *parent)
    : IAnalyze(parent)
{

}

CodeExec AnalyzeBASI::setPlan(const QString &filename)
{
    QFile fileData(filename);

    if (!fileData.open(QIODevice::ReadOnly))
    {
        return CodeExec::ErrorFile;
    }

    QDataStream in(&fileData);
    in >> date_time_plan;
    in >> obj_Data_BASI_plan;
    in >> obj_RK_BASI_plan;

    fileData.close();

    return CodeExec::Success;
}

CodeExec AnalyzeBASI::setOutputData(const QByteArray &output_data)
{
    QDataStream out(output_data);
    out >> date_time;
    out >> obj_Data_BASI;
    out >> obj_RK_BASI;

    qDebug() << "obj_Data_BASI " << obj_Data_BASI.usNumSession;

    return CodeExec::Success;
}

quint8 AnalyzeBASI::analyze()
{
    quint8 result = this->countErrorStructres(obj_Data_BASI, obj_RK_BASI, obj_Data_BASI_plan, obj_RK_BASI_plan);
    return result;
}

quint8 AnalyzeBASI::countErrorStructres(const Struct::DataBASI &data_1, const Struct::masRK &rk_1,
                                 const Struct::DataBASI &data_2, const Struct::masRK &rk_2)
{
    quint8 count_errors{0};

    if(data_1.usCodeMode != data_2.usCodeMode)
    {
        count_errors += 1;
    }

    if(data_1.usNumSession != data_2.usNumSession)
    {
        count_errors += 1;
    }

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



void AnalyzeBASI::unitTestAnalyze()
{
    //Совпадающие данные
    Struct::DataBASI basi_1{0,1,0,1,0,0,""};
    Struct::DataBASI basi_2{0,0,1,0,1,0,"2"};

    Struct::masRK rk_1{0,0,1,0,1,0};
    Struct::masRK rk_2{0,0,0,1,0,0};

    QByteArray output_data_test;
    QFile path_plan_test("path_plan_test");

    QDataStream out_b(&output_data_test, QIODevice::WriteOnly);
    out_b << QString("DateTime 1:2:3");
    out_b << basi_1;
    out_b << rk_1;

    path_plan_test.open(QIODevice::WriteOnly);

    QDataStream out_f(&path_plan_test);
    out_f << QString("DateTime 1:2:3");
    out_f << basi_2;
    out_f << rk_2;

    path_plan_test.close();

    this->setOutputData(output_data_test);
    this->setPlan("path_plan_test");
    quint8 count_errors = this->analyze();

    qDebug() << "Errors: " << count_errors;

    //Q_ASSERT_X(count_errors == 0,"unitTestAnalyze", "errors > 0");
    Q_ASSERT_X(count_errors == 8,"unitTestAnalyze", "errors != 8");

    qDebug() << "Well done! " << Qt::endl;
}







