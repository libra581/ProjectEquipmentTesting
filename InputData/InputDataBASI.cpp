#include "InputDataBASI.h"

//Функция инициализации структуры Struct::DataBASI
//из потока QDataStream
QDataStream & operator>>(QDataStream &in, Struct::DataBASI &p){
    in >> p.usCodeMode >> p.usNumSession >> p.MemoryAddress
            >> p.NumberProgram >> p.AmountDataWords >> p.State >> p.Reserve;
    return in;
}

//Функция записи структуры Struct::DataBASI
//в поток QDataStream
QDataStream &operator<<(QDataStream &out, const Struct::DataBASI &p){
    out << p.usCodeMode << p.usNumSession << p.MemoryAddress
            << p.NumberProgram << p.AmountDataWords << p.State << p.Reserve;
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

InputDataBASI::InputDataBASI(QObject *parent) :
    IInputData(parent)
{
this->unitTestFileRead();
}

CodeExec InputDataBASI::readCyclegrammaFile(const QString & filename)
{

    QFile fileData(filename);

    if (!fileData.exists() || !fileData.open(QIODevice::ReadOnly))
    {
        throw ExeptionInputData("objBASI -> readCyclegrammaFile: file "
                                + filename +" doesnt open!");
    }

/*
 * Имитация файла от циклограммы
 *
    obj_RK_BASI.Comp1 = 1;
    obj_RK_BASI.Comp2 = 0;
    obj_RK_BASI.EnableParachute = 1;
    obj_RK_BASI.PS1 = 1;
    obj_RK_BASI.PS2 = 0;
    obj_RK_BASI.SpecInfo = 500;

    obj_Data_BASI.usCodeMode = 1;
    obj_Data_BASI.usNumSession = 2;
    obj_Data_BASI.MemoryAddress = 3;
    obj_Data_BASI.NumberProgram = 4;
    obj_Data_BASI.AmountDataWords = 5;
    obj_Data_BASI.State = 5;
    obj_Data_BASI.Reserve = "123";

    QDateTime time(QDate(2020, 12, 6),QTime(8, 30, 0));

    QDataStream out(&fileData);
    out << time;
    out << obj_Data_BASI;
    out << obj_RK_BASI;

    fileData.close();
    fileData.open(QIODevice::ReadWrite);
*/

    //Чтение файла плана и инициализация структур входных данных
    QDataStream in(&fileData);
    in >> date_time;
    in >> obj_Data_BASI;
    in >> obj_RK_BASI;

    //qDebug() << date_time << obj_Data_BASI.Reserve << obj_Data_BASI.usNumSession
    //         << obj_RK_BASI.SpecInfo << obj_RK_BASI.Comp2;

    fileData.close();

    //Преобразование структур данных в QByteArray
    //для отправки по порту
    this->writeToByteArray();

    return CodeExec::Success;
}

const QByteArray& InputDataBASI::getInputData()
{
    return this->btarr_Data_BASI;
}

const QByteArray& InputDataBASI::getRK()
{
    return this->btarr_RK_BASI;
}

const QString &InputDataBASI::getDateTime()
{
    return this->date_time;
}

void InputDataBASI::setData(const QString & filename)
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

void InputDataBASI::writeToByteArray()
{
    QDataStream out_data(&this->btarr_Data_BASI, QIODevice::WriteOnly);

    out_data << obj_Data_BASI.usCodeMode
             << obj_Data_BASI.usNumSession
             << obj_Data_BASI.MemoryAddress
             << obj_Data_BASI.NumberProgram
             << obj_Data_BASI.AmountDataWords
             << obj_Data_BASI.State
             << obj_Data_BASI.Reserve;

    QDataStream out_rk(&this->btarr_RK_BASI, QIODevice::WriteOnly);

    out_rk  << obj_RK_BASI.Comp1
            << obj_RK_BASI.Comp2
            << obj_RK_BASI.EnableParachute
            << obj_RK_BASI.PS1
            << obj_RK_BASI.PS2
            << obj_RK_BASI.SpecInfo;
}

//Юнит-тест проверки работы считывания данных из файла плана
//Проверка алгоритма метода setData(QString);
//Создан 21.09.2020 Семенов Д.С. Заявка №00001
void InputDataBASI::unitTestFileRead()
{
    /*Имитация файла от циклограммы*/

    QFile fileData("C:\\Users\\sds\\Documents\\Plan");

    if (!fileData.exists() || !fileData.open(QIODevice::WriteOnly))
    {
        throw ExeptionInputData("objBASI -> readCyclegrammaFile: file "
                                "C:\\Users\\sds\\Documents\\Plan  doesnt open!");
    }

    //Структуры, имитирующие данные в плане испытаний
    Struct::DataBASI obj_Data_BASI_test;
    Struct::masRK obj_RK_BASI_test;

    obj_RK_BASI_test.Comp1 = 1;
    obj_RK_BASI_test.Comp2 = 0;
    obj_RK_BASI_test.EnableParachute = 1;
    obj_RK_BASI_test.PS1 = 1;
    obj_RK_BASI_test.PS2 = 0;
    obj_RK_BASI_test.SpecInfo = 500;

    obj_Data_BASI_test.usCodeMode = 1;
    obj_Data_BASI_test.usNumSession = 2;
    obj_Data_BASI_test.MemoryAddress = 3;
    obj_Data_BASI_test.NumberProgram = 4;
    obj_Data_BASI_test.AmountDataWords = 5;
    obj_Data_BASI_test.State = 5;
    obj_Data_BASI_test.Reserve = "123";

    QString time = QTime::currentTime().toString();

    QDataStream out(&fileData);
    out << time;
    out << obj_Data_BASI_test;
    out << obj_RK_BASI_test;

    fileData.close();

    //Вызов инициализации структур данными из плана испытаний
    this->setData("C:\\Users\\sds\\Documents\\Plan");

    Q_ASSERT_X(equalStructres(obj_Data_BASI_test, obj_RK_BASI_test,
                              obj_Data_BASI, obj_RK_BASI), "unitTestFileRead", "not equal");


    qDebug() << "Well done!" << Qt::endl;
}

//Метод проверки идентичности полей структур данных BASI и RK
//Возвращает false - если поля структур различаются,
//true - если поля структур совпадают
bool InputDataBASI::equalStructres(const Struct::DataBASI &data_1, const Struct::masRK &rk_1,
                                 const Struct::DataBASI &data_2, const Struct::masRK &rk_2)
{
    if(data_1.usCodeMode != data_2.usCodeMode)
    {
        return false;
    }

    if(data_1.usNumSession != data_2.usNumSession)
    {
        return false;
    }

    if(data_1.MemoryAddress != data_2.MemoryAddress)
    {
        return false;
    }

    if(data_1.NumberProgram != data_2.NumberProgram)
    {
        return false;
    }

    if(data_1.AmountDataWords != data_2.AmountDataWords)
    {
        return false;
    }

    if(data_1.State != data_2.State)
    {
        return false;
    }

    if(data_1.Reserve.compare(data_2.Reserve) != 0)
    {
        return false;
    }


    if(rk_1.Comp1 != rk_2.Comp1)
    {
        return false;
    }

    if(rk_1.Comp2 != rk_2.Comp2)
    {
        return false;
    }

    if(rk_1.EnableParachute != rk_2.EnableParachute)
    {
        return false;
    }


    if(rk_1.PS1 != rk_2.PS1)
    {
        return false;
    }



    if(rk_1.PS2 != rk_2.PS2)
    {
        return false;
    }

    if(rk_1.SpecInfo != rk_2.SpecInfo)
    {
        return false;
    }

    return true;
}
