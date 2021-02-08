#include "cObserver.h"

cObserver::cObserver(QObject *parent)
    : AServerTCP(parent),
      m_nPort(0)
{

}

cObserver::~cObserver()
{

}

void cObserver::initDB()
{
    m_db = new cDataBase("BD_MAIN", "localhost", "postgres", "123", this);
}

QVector<QVector<QString>>& cObserver::select(const QString &table)
{
    setMatrixSelect(m_db->select(table));

    return getMatrixSelect();
}

void cObserver::setCodeExec(int codeExec)
{
    this->codeExec = codeExec;
}

int cObserver::getCodeExec() const
{
    return this->codeExec;
}

void cObserver::setMatrixSelect(QVector<QVector<QString> > &matrix)
{
    this->matrix_select = matrix;
}

QVector<QVector<QString> > &cObserver::getMatrixSelect()
{
    return this->matrix_select;
}

void cObserver::createServerTCP(int nPort)
{
    m_ptcpServer = new QTcpServer();
    if (!m_ptcpServer->listen(QHostAddress::Any, nPort))
    {
        qDebug() << "Unable to start the зerver:" +
                    m_ptcpServer->errorString();
        m_ptcpServer->close();
        return;
    }

    connect(m_ptcpServer, SIGNAL(newConnection()),
            this, SLOT(slotNewConnection()));
}


void cObserver::slotReadClient()
{
    QTcpSocket* pClientSocket = (QTcpSocket*)sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_5_9);

    for (;;)
    {
        if (!m_nNextBlockSize)
        {
            if (pClientSocket->bytesAvailable() < (qint64)sizeof(quint16))
            {
                break;
            }
            in >> m_nNextBlockSize;
        }

        if (pClientSocket->bytesAvailable() < m_nNextBlockSize)
        {
            break;
        }

        //QTime time;
        QString name_computer;
        int typeEquipment;
        int msg;
        in >>  name_computer >> typeEquipment >> msg;

        m_hmClients[name_computer] = typeEquipment;

        QHashIterator<QString, int> i(m_hmClients);
        while (i.hasNext())
        {
            i.next();
            qDebug() << i.key() << ": " << i.value() << Qt::endl;
        }

        QString strMessage = "Client " + name_computer + " has sent - t = " + QString::number(typeEquipment)
                            + ", msg = " + QString::number(msg);

        qDebug() << strMessage;
        emit msgClient(typeEquipment, msg);

        m_nNextBlockSize = 0;

        sentToClient(pClientSocket,"Server Response: Received \"" + QString::number(msg) + "\"" );
    }
}
