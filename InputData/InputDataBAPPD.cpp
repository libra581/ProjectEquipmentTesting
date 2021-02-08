#include "InputDataBAPPD.h"

//Функция инициализации структуры Struct::DataBAPPD
//из потока QDataStream
QDataStream & operator>>(QDataStream &in, Struct::DataBAPPD &p){
    in >> p.usNumMode >> p.usCodeMode >> p.usNumSession
    >> p.TRejStart1[0] >> p.TRejStart1[1] >> p.TRejStart1[2] >> p.TRejStart1[3]
    >> p.TRejEnd1[0] >> p.TRejEnd1[1] >> p.TRejEnd1[2] >> p.TRejEnd1[3]
    >> p.TRejStart2[0]  >> p.TRejStart2[1] >> p.TRejStart2[2] >> p.TRejStart2[3]
    >> p.TRejEnd2[0] >> p.TRejEnd2[1] >> p.TRejEnd2[2]>> p.TRejEnd2[3]
    >> p.MemoryAddress >> p.NumberProgram >> p.AmountDataWords >> p.State >> p.Reserve;
    return in;
}

//Функция записи структуры Struct::DataBAPPD
//в поток QDataStream
QDataStream &operator<<(QDataStream &out, const Struct::DataBAPPD &p){
    out << p.usNumMode << p.usCodeMode << p.usNumSession
    << p.TRejStart1[0] << p.TRejStart1[1] << p.TRejStart1[2] << p.TRejStart1[3]
    << p.TRejEnd1[0] << p.TRejEnd1[1] << p.TRejEnd1[2] << p.TRejEnd1[3]
    << p.TRejStart2[0]  << p.TRejStart2[1] << p.TRejStart2[2] << p.TRejStart2[3]
    << p.TRejEnd2[0] << p.TRejEnd2[1] << p.TRejEnd2[2]<< p.TRejEnd2[3]
    << p.MemoryAddress << p.NumberProgram << p.AmountDataWords << p.State << p.Reserve;
    return out;
}

//Функция инициализации структуры Struct::masRK
//из потока QDataStream
inline QDataStream & operator>>(QDataStream &in, Struct::masRK &p){
    in >> p.Comp1 >> p.Comp2 >> p.EnableParachute
            >> p.PS1 >> p.PS2 >> p.SpecInfo;
    return in;
}

//Функция записи структуры Struct::masRK
//в поток QDataStream
inline QDataStream &operator<<(QDataStream &out, const Struct::masRK &p){
    out << p.Comp1 << p.Comp2 << p.EnableParachute
            << p.PS1 << p.PS2 << p.SpecInfo;
    return out;
}



InputDataBAPPD::InputDataBAPPD(QObject *parent) :
    IInputData(parent)
{

}

CodeExec InputDataBAPPD::readCyclegrammaFile(const QString & filename)
{
    QFile fileData(filename);

    if (!fileData.exists() || !fileData.open(QIODevice::ReadOnly))
    {
        throw ExeptionInputData("objBAPPD -> readCyclegrammaFile: file "
                                + filename +" doesnt open!");
        return CodeExec::Error;
    }

/*
 * Имитация файла от циклограммы

    obj_RK_BAPPD.Comp1 = 1;
    obj_RK_BAPPD.Comp2 = 0;
    obj_RK_BAPPD.EnableParachute = 1;
    obj_RK_BAPPD.PS1 = 1;
    obj_RK_BAPPD.PS2 = 0;
    obj_RK_BAPPD.SpecInfo = 500;

    usQuantRej = 33;

    obj_Data_BAPPD.usNumMode = 0;
    obj_Data_BAPPD.usCodeMode = 1;
    obj_Data_BAPPD.usNumSession = 2;
    obj_Data_BAPPD.MemoryAddress = 3;
    obj_Data_BAPPD.NumberProgram = 4;
    obj_Data_BAPPD.AmountDataWords = 5;
    obj_Data_BAPPD.State = 5;
    obj_Data_BAPPD.Reserve = "666";

    QDateTime time(QDate(2020, 12, 6),QTime(8, 30, 0));

    QDataStream out(&fileData);
    out << time;
    out << usQuantRej;
    out << obj_Data_BAPPD;
    out << obj_RK_BAPPD;


    fileData.close();
    fileData.open(QIODevice::ReadWrite);
*/
    //Чтение файла плана и инициализация структур входных данных
    QDataStream in(&fileData);
    in >> date_time;
    in >> usQuantRej;
    in >> obj_Data_BAPPD;
    in >> obj_RK_BAPPD;

  //  qDebug() << date_time << obj_Data_BAPPD.Reserve << usQuantRej
  //           << obj_RK_BAPPD.SpecInfo << obj_RK_BAPPD.Comp2;

    fileData.close();

    //Преобразование структур данных в QByteArray
    //для отправки по порту
    this->writeToByteArray();

    return CodeExec::Success;
}


const QByteArray & InputDataBAPPD::getInputData()
{
    return this->btarr_Data_BAPPD;
}

const QByteArray & InputDataBAPPD::getRK()
{
    return this->btarr_RK_BAPPD;
}

const QString &InputDataBAPPD::getDateTime()
{
    return this->date_time;
}

void InputDataBAPPD::setData(const QString & filename)
{
    QTextStream cerr(stderr);

    try
    {
        this->readCyclegrammaFile(filename);
    }
    catch(ExeptionInputData &exp)
    {
        cerr << "Step call: ImitLogic -> WORKING of "  << exp.whatIs() << Qt::endl;
    }
}


void InputDataBAPPD::writeToByteArray()
{
    QDataStream out_data(&this->btarr_Data_BAPPD, QIODevice::WriteOnly);
    out_data << usQuantRej
             << obj_Data_BAPPD.usNumMode
             << obj_Data_BAPPD.usCodeMode
             << obj_Data_BAPPD.usNumSession

             << obj_Data_BAPPD.TRejStart1[0]
             << obj_Data_BAPPD.TRejStart1[1]
             << obj_Data_BAPPD.TRejStart1[2]
             << obj_Data_BAPPD.TRejStart1[3]

             << obj_Data_BAPPD.TRejEnd1[0]
             << obj_Data_BAPPD.TRejEnd1[1]
             << obj_Data_BAPPD.TRejEnd1[2]
             << obj_Data_BAPPD.TRejEnd1[3]

             << obj_Data_BAPPD.TRejStart2[0]
             << obj_Data_BAPPD.TRejStart2[1]
             << obj_Data_BAPPD.TRejStart2[2]
             << obj_Data_BAPPD.TRejStart2[3]

             << obj_Data_BAPPD.TRejEnd2[0]
             << obj_Data_BAPPD.TRejEnd2[1]
             << obj_Data_BAPPD.TRejEnd2[2]
             << obj_Data_BAPPD.TRejEnd2[3]

             << obj_Data_BAPPD.MemoryAddress
             << obj_Data_BAPPD.NumberProgram
             << obj_Data_BAPPD.AmountDataWords
             << obj_Data_BAPPD.State
             << obj_Data_BAPPD.Reserve;

    QDataStream out_rk(&this->btarr_RK_BAPPD, QIODevice::WriteOnly);
    out_rk  << obj_RK_BAPPD.Comp1
            << obj_RK_BAPPD.Comp2
            << obj_RK_BAPPD.EnableParachute
            << obj_RK_BAPPD.PS1
            << obj_RK_BAPPD.PS2
            << obj_RK_BAPPD.SpecInfo;
}

