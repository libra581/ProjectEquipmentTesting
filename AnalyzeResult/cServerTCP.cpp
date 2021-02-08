#include "cServerTCP.h"

cServerTCP::cServerTCP(QObject *parent)
    :AServerTCP(parent)
{

}

void cServerTCP::createServerTCP(int nPort)
{
    m_ptcpServer = new QTcpServer();
    if (!m_ptcpServer->listen(QHostAddress::Any, nPort))
    {
        qDebug() << "Unable to start the зerver:" +
                    m_ptcpServer->errorString();
        m_ptcpServer->close();
        return;
    }

    QObject::connect(m_ptcpServer, SIGNAL(newConnection()),
            this, SLOT(slotNewConnection()));
}

void cServerTCP::slotReadClient()
{
    QTcpSocket* pClientSocket = (QTcpSocket*)AServerTCP::sender();
    QDataStream in(pClientSocket);
    in.setVersion(QDataStream::Qt_5_9);


qDebug() << "qweqweqwe";

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

        QString strMessage = "Client " + name_computer + " has sent - t = " + QString::number(typeEquipment)
                            + ", msg = " + QString::number(msg);

        qDebug() << strMessage;

        m_nNextBlockSize = 0;

        sentToClient(pClientSocket,"Server Response: Received \"" + QString::number(msg) + "\"" );
    }
}
