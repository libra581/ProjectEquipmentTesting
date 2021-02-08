#include "AnalyzeLogic.h"

AnalyzeLogic::AnalyzeLogic(TypeEquipment type, const QString &file_name_analyze
                           , const QString &filename_form_TMI, const QString &path_plan, QObject *parent)
    : QObject(parent), type_equipment(type), cerr(stderr), result_execute(CodeExec::Waiting),
      filename_form_analyze(file_name_analyze), filename_form_TMI(filename_form_TMI),
      path_plan(path_plan)
{
    qDebug() << static_cast<int>(type);

    if(type == TypeEquipment::BASI)
    {
        objAnalyze = new AnalyzeBASI(this);
        server = new cServerTCP(this);
        server->createServerTCP(2324);
    }
    else
    {
        objAnalyze = new AnalyzeBAPPD(this);
        client = new cClientTCP(this);
        client->setClientProperty("localhost", 2324);
    }

    serial_port = new QSerialPort(this);
    serial_port->setPortName("COM4");
    serial_port->setBaudRate(QSerialPort::Baud9600);
    serial_port->setDataBits(QSerialPort::Data8);
    serial_port->setParity(QSerialPort::NoParity);
    serial_port->setStopBits(QSerialPort::OneStop);
    serial_port->setFlowControl(QSerialPort::NoFlowControl);
    serial_port->open(QIODevice::ReadOnly);

    qDebug() << this->filename_form_analyze << this->filename_form_TMI;

    //unitTestAnalyze();

    //Ожидание выдачи ТМИ 1 сек
    startTimer(1000);

    //Ожидание успешного приема выходнйо ТМИ (31 секунда общая)
    startTimer(30000);
}

CodeExec AnalyzeLogic::analyzeResult(const QByteArray &output_data, const QString &path_plan)
{
    objAnalyze->setOutputData(output_data);
    objAnalyze->setPlan(path_plan);
    quint8 count_errors = objAnalyze->analyze();

    if(this->type_equipment == TypeEquipment::BAPPD)
    {
        client->sendToServer(count_errors);
    }

    qDebug() << "Errors: " << count_errors;

    if(count_errors > MAX_ERRORS)
        return CodeExec::AnalyzeError;

    return CodeExec::Success;
}

CodeExec AnalyzeLogic::getOutputData()
{
    CodeExec res = CodeExec::Success;

    /*прием данных с COM*/
    this->output_data = serial_port->readAll();

    qDebug() << output_data;

    if(output_data.isEmpty())
        return res = CodeExec::PortEmpty;

    res = this->analyzeResult(output_data, path_plan);

    emit exit(static_cast<int>(res));

    return res;
}

AnalyzeLogic::~AnalyzeLogic()
{
    serial_port->close();
}

void AnalyzeLogic::timerEvent(QTimerEvent *event)
{
    qDebug() << "Timer ID:" << event->timerId();

    if(event->timerId() == 1)
    {
        killTimer(1);
        QObject::connect(serial_port, &QSerialPort::readyRead, this, &AnalyzeLogic::getOutputData);
        if(this->result == CodeExec::Waiting)
            this->result = CodeExec::Success;
    }
    else if(event->timerId() == 2)
    {
        killTimer(2);
        this->result = CodeExec::Error;
        emit exit(static_cast<int>(this->result));
    }
}



/*
void AnalyzeLogic::unitTestCountErrorsSame()
{
    //Совпадающие данные
    Struct::DataBASI basi_1{0,0,0,0,0,0,""};
    Struct::DataBASI basi_2{0,0,0,0,0,0,""};

    qint8 TR_1[4] = {0,0,0,0};
    qint8 TR_2[4] = {0,0,0,0};

    int length_1 = sizeof(TR_1)/sizeof(*TR_1);
    int length_2 = sizeof(TR_2)/sizeof(*TR_2);

    Struct::DataBAPPD bappd_1{0,0,0,{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},0,0,0,0,""};
    Struct::DataBAPPD bappd_2{0,0,0,{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},0,0,0,0,""};

    Struct::masRK rk_1{0,0,0,0,0,0};
    Struct::masRK rk_2{0,0,0,0,0,0};

    Q_ASSERT_X(countErrorMasInt8(TR_1, length_1, TR_2, length_2) == 0, "same", "countErrorMasInt8");
    Q_ASSERT_X(countErrorRK(rk_1, rk_2) == 0, "same", "countErrorRK");
    Q_ASSERT_X(countErrorStructres(basi_1, rk_1, basi_2, rk_2) == 0, "same", "countErrorStructresBASI");
    Q_ASSERT_X(countErrorStructres(bappd_1, rk_1, bappd_1, rk_2) == 0, "same", "countErrorStructresBAPPD");


    qDebug() << "Well done!" << Qt::endl;
}

void AnalyzeLogic::unitTestCountErrorsDifferent()
{
    //Несовпадающие данные
    Struct::DataBASI basi_1{0,0,0,0,0,0,"0"};
    Struct::DataBASI basi_2{1,1,1,1,1,1,"1"};

    qint8 TR_1[4] = {0,0,0,0};
    qint8 TR_2[4] = {1,1,1,1};

    int length_1 = sizeof(TR_1)/sizeof(*TR_1);
    int length_2 = sizeof(TR_2)/sizeof(*TR_2);

    Struct::DataBAPPD bappd_1{0,0,0,{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},0,0,0,0,"0"};
    Struct::DataBAPPD bappd_2{1,1,1,{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1},1,1,1,1,"1"};

    Struct::masRK rk_1{0,0,0,0,0,0};
    Struct::masRK rk_2{1,1,1,1,1,1};

    Q_ASSERT_X(countErrorMasInt8(TR_1, length_1, TR_2, length_2) == 4, "same", "countErrorMasInt8");
    Q_ASSERT_X(countErrorRK(rk_1, rk_2) == 6, "same", "countErrorRK");
    Q_ASSERT_X(countErrorStructres(basi_1, rk_1, basi_2, rk_2) == 18, "same", "countErrorStructresBASI");
    Q_ASSERT_X(countErrorStructres(bappd_1, rk_1, bappd_1, rk_2) == 13, "same", "countErrorStructresBAPPD");


    qDebug() << "Well done!" << Qt::endl;
}
*/
