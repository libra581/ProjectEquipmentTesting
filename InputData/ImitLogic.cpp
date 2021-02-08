#include "ImitLogic.h"

ImitLogic::ImitLogic(TypeEquipment type, const QString &filename, QObject *parent):
    QObject(parent), cerr(stderr), filename(filename)
{
    qDebug() << static_cast<int>(type);

    //Определение типа реализации интерфейса по типу оборудования
    if(type == TypeEquipment::BASI)
        this->objInpData = new InputDataBASI();
    else
        this->objInpData = new InputDataBAPPD();

    //Настройка последовательного порта
    serial_port = new QSerialPort(this);
    serial_port->setPortName("COM4");
    serial_port->setBaudRate(QSerialPort::Baud9600);
    serial_port->setDataBits(QSerialPort::Data8);
    serial_port->setParity(QSerialPort::NoParity);
    serial_port->setStopBits(QSerialPort::OneStop);
    serial_port->setFlowControl(QSerialPort::NoFlowControl);

    //Считывание плана по поданному в программу пути
    this->working();

    //Ожидание выдачи РК 1 сек
    startTimer(1000);
    //Ожидание выдачи данных 2 сек после РК (3 сек общая)
    startTimer(2000);
    //Ожидание успешного выполнения (6 сек общая)
    startTimer(3000);
}

CodeExec ImitLogic::sendInputData()
{
    QByteArray ba = objInpData->getInputData();

    /*Отправка исходных данных на COM*/
    if (!serial_port->open(QIODevice::WriteOnly))
        return CodeExec::ErrorPort;

    serial_port->flush();
    serial_port->write(ba);
    serial_port->flush();

    serial_port->close();

    return CodeExec::Success;
}

CodeExec ImitLogic::sendRK()
{
    QByteArray ba = objInpData->getRK();

    /*Отправка РК на COM*/
    if (!serial_port->open(QIODevice::WriteOnly))
        return CodeExec::ErrorPort;

    serial_port->flush();
    serial_port->write(ba);
    serial_port->flush();

    serial_port->close();

    return CodeExec::Success;
}


ImitLogic::~ImitLogic()
{
    if(objInpData)
        delete objInpData;

    if(serial_port)
        delete serial_port;
}

void ImitLogic::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == 1)
    {
        //Обработка таймера подачи РК
        killTimer(1);
        CodeExec code_rk = sendRK();
        if(code_rk != CodeExec::Success)
            emit exit(static_cast<int>(code_rk));
    }
    else if(event->timerId() == 2)
    {
        //Обработка таймера подачи исходных данных
        killTimer(2);
        CodeExec code_inData = sendInputData();
        if(code_inData != CodeExec::Success)
            emit exit(static_cast<int>(code_inData));

        if(this->result == CodeExec::Waiting)
            this->result = CodeExec::Success;
    }
    else if(event->timerId() == 3)
    {
        //Обработка таймера завершения программы
        killTimer(3);
        emit exit(static_cast<int>(this->result));
    }
}

CodeExec ImitLogic::working()
{
    try
    {
       this->result = this->objInpData->readCyclegrammaFile(this->filename);
    }
    catch(ExeptionInputData &exp)
    {
        cerr << "Step call: ImitLogic -> WORKING of "  << exp.whatIs() << Qt::endl;
        this->result = CodeExec::ErrorFile;
    }

    return this->result;
}

