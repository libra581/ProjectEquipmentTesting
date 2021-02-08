#include "CObserver.h"

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

QDataStream & operator>>(QDataStream &in, Struct::masRK &p){
    in >> p.Comp1 >> p.Comp2 >> p.EnableParachute
            >> p.PS1 >> p.PS2 >> p.SpecInfo;
    return in;
}

QDataStream &operator<<(QDataStream &out, const Struct::masRK &p){
    out << p.Comp1 << p.Comp2 << p.EnableParachute
            << p.PS1 << p.PS2 << p.SpecInfo;
    return out;
}

CObserver::CObserver(QObject *parent)
    : AClientTCP(parent),
      type(TypeEquipment::BASI), dateInputData("None"),
      file_plan(nullptr), dateAnalyze("None1"),
      result_formular("testingForm")
{

}

CObserver::~CObserver()
{
    if(file_plan != nullptr)
    {
        delete file_plan;
        file_plan = nullptr;
    }

    if(m_db)
        delete m_db;

    m_db = nullptr;

}

void CObserver::setTypeEquipment(int typeEquipment)
{
    this->typeEquipment = typeEquipment;
    this->type = static_cast<TypeEquipment>(this->typeEquipment);
}

int CObserver::getTypeEquipment() const
{
    return this->typeEquipment;
}

void CObserver::setMatrixSelect(QVector<QVector<QString>> &matrix)
{
    this->matrix_select = matrix;
}

QVector<QVector<QString>>& CObserver::getMatrixSelect()
{
    return this->matrix_select;
}

void CObserver::readFilePlan()
{
    this->file_plan = new QFile(this->pathFilePlan);

    if(!file_plan->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        emit errorFilePlan();
        return;
    }

    qDebug() << pathFilePlan;

    //QByteArray b_date = file_plan->readLine();
    QDataStream in(file_plan);
    in >> this->dateInputData;
    emit dateChangedInputData();

    if(this->type == TypeEquipment::BASI)
    {
        in >> this->basi_plan;
    }
    else if(this->type == TypeEquipment::BAPPD)
    {
        qDebug() << 123;
        in >> this->usQuantRej_plan;
        in >> this->bappd_plan;
    }

    in >> this->rk_plan;

    in >> this->fouryears;
    in >> this->currentdate;
    in >> this->moscow_time;


    file_plan->close();

    QDateTime date = QDateTime::fromString(this->dateInputData);
    this->dateAnalyze = date.addSecs(3600).toString();
    emit dateChangedAnalyze();

    qDebug() << this->dateInputData << this->dateAnalyze
             //<< this->basi_plan.NumberProgram << this->basi_plan.Reserve
             << this->usQuantRej_plan<< this->bappd_plan.NumberProgram << this->bappd_plan.Reserve
             << this->rk_plan.Comp1 << this->rk_plan.SpecInfo;

}

void CObserver::initDB()
{
    m_db = new cDataBase("BD_MAIN", "localhost", "postgres", "123", this);

    matrix_select = m_db->select("emode");
}

void CObserver::insertInputData()
{
    /******************/
    Struct::masRK  rk_plan{1,0,1,1,0,509};
    Struct::DataBASI  basi_plan{1,2,3,4,5,5,"123"};
    Struct::DataBAPPD  bappd_plan{0,0,0,{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},0,0,0,0,""};

    fouryears = 1;
    moscow_time.setHMS(1,2,3);
    currentdate = 1;
    /******************/

    QList<QString> col_moscow_time,
                   col_request,
                   col_rk, col_testingdata,
                   col_session;

    QVariantList lst_moscow_time,
                 lst_request,
                 lst_rk, lst_testingdata,
                 lst_session;


    col_moscow_time << "FourYeares" << "Time" << "CurrentDay";
    lst_moscow_time << fouryears << moscow_time << currentdate;

    m_db->insert("moscowtime", col_moscow_time, lst_moscow_time);
    quint16 currval_moscowtime = m_db->selectCurrval("moscowtime_id_seq");

    col_rk << "Comp1" << "Comp2" << "EnableParachute"
           << "PS1" << "PS2" << "SpecInfo";
    lst_rk << rk_plan.Comp1 << rk_plan.Comp2 << rk_plan.EnableParachute
           << rk_plan.PS1 << rk_plan.PS2 << rk_plan.SpecInfo;

    m_db->insert("onetimecommands",col_rk, lst_rk);
    quint16 currval_rk = m_db->selectCurrval("onetimecommands_code_seq");


    quint16 currval_testingdata = 1;

    if(this->type == TypeEquipment::BASI)
    {
        col_testingdata << "AddressData" << "NumberProgram"
                        << "AmountDataWords" << "State";
        lst_testingdata << basi_plan.MemoryAddress << basi_plan.NumberProgram
                        << basi_plan.AmountDataWords << basi_plan.State;

        m_db->insert("testingdata", col_testingdata, lst_testingdata);
        currval_testingdata = m_db->selectCurrval("testingdata_Code_seq");

        col_request << "Date" << "Time" << "IdEquip"
                    << "CodeMode" << "IdTesting"  << "IdMT";
        lst_request << QDate::currentDate().toString("dd.MM.yyyy")
                    << QTime::currentTime().toString("hh:mm:ss")
                    << 2 << 1
                    << static_cast<int>(testing_type)
                    << currval_moscowtime;

       m_db->insert("request", col_request, lst_request);
       this->currval_request = m_db->selectCurrval("request_id_seq");

       this->currval_session = "SP" + QString::number(basi_plan.usNumSession);
       col_session << "Id" << "MassiveModes"
                   << "CodeCommands" << "CodeTestData";
       lst_session << this->currval_session << this->usQuantRej_plan
                   << currval_rk << currval_testingdata;
        m_db->insert("session", col_session, lst_session);
    }
    else if(this->type == TypeEquipment::BAPPD)
    {
        col_testingdata << "AddressData" << "NumberProgram"
                        << "AmountDataWords" << "State";
        lst_testingdata << bappd_plan.MemoryAddress << bappd_plan.NumberProgram
                        << bappd_plan.AmountDataWords << bappd_plan.State;

        m_db->insert("testingdata", col_testingdata, lst_testingdata);
        currval_testingdata = m_db->selectCurrval("onetimecommands_Code_seq");

        col_request << "Date" << "Time" << "IdEquip"
                    << "CodeMode" << "IdTesting"  << "IdMT";
        lst_request << QDate::currentDate().toString("dd.MM.yyyy")
                    << QTime::currentTime().toString("hh:mm:ss")
                    << 3 << 2
                    << static_cast<int>(testing_type)
                    << currval_moscowtime;

        m_db->insert("request", col_request, lst_request);
        this->currval_request = m_db->selectCurrval("request_id_seq");

        this->currval_session = "SP" + QString::number(bappd_plan.usNumSession);
        col_session << "Id" << "MassiveModes"
                    << "CodeCommands" << "CodeTestData";
        lst_session << this->currval_session << this->usQuantRej_plan
                    << currval_rk << currval_testingdata;
         m_db->insert("session", col_session, lst_session);
    }

}

void CObserver::insertAnalyze()
{
    /******************/
    Struct::TMI tmi_analyze{1,2,3,4};
    currval_session = "SP2";
    currval_request = 5;
    /******************/

    QList<QString> col_TMI,
                   col_fanalyze;

    QVariantList lst_TMI,
                 lst_fanalyze;

    col_TMI << "ContentMemoryCells" << "StateEquipment" << "LoadCurrents" << "SpecInfo";
    lst_TMI << tmi_analyze.ContentMemoryCells << tmi_analyze.StateEquipment
            << tmi_analyze.LoadCurrents << tmi_analyze.SpecInfo;

    m_db->insert("TMI", col_TMI, lst_TMI);
    quint16 currval_TMI = m_db->selectCurrval("TMI_id_seq");

    m_db->update("session", "idtmi = " + QString::number(currval_TMI), "id = \'" + currval_session + "\'");

    col_fanalyze << "IdRequest" << "IdSession" << "CodeExecute" << "FileDeviations";
    lst_fanalyze << currval_request << currval_session
            << static_cast<int>(result_analyze) << result_formular;
    m_db->insert("fanalyze", col_fanalyze, lst_fanalyze);
}

const QString & CObserver::getDateInputData() const
{
    return this->dateInputData;
}

const QString &CObserver::getDateAnalyze() const
{
    return this->dateAnalyze;
}

void CObserver::setPath(const QString &path)
{
    this->pathFilePlan = path;
}

const QString &CObserver::getPath() const
{
    return this->pathFilePlan;
}


/*TCP Client*/
void CObserver::setClientProperty(const QString &strHost, int nPort)
{
    AClientTCP::setClientProperty(strHost, nPort);
}


void CObserver::sendToServer(int msg)
{
    if(m_pTcpSocket != nullptr)
    {
        QByteArray arrBlock;
        QDataStream out(&arrBlock, QIODevice::WriteOnly);

        out.setVersion(QDataStream::Qt_5_9);
        qDebug() << msg;
       // QHostInfo info;
        //QHostAddress address = info.addresses().first();
        qDebug() << "IP adress" << m_pTcpSocket->localAddress();
        qDebug() << "IP adress" << m_pTcpSocket->localPort();
        out << quint16(0) << m_pTcpSocket->localAddress().toString()
                           + " " +  QHostInfo::localHostName() << this->typeEquipment << msg;

        out.device()->seek(0);
        out << quint16(arrBlock.size() - sizeof(quint16) );

        m_pTcpSocket->write(arrBlock);
    }
}

