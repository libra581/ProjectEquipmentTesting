#include "AServerTCP.h"

AServerTCP::AServerTCP(QObject *parent) : QObject(parent),
    m_nNextBlockSize(0)
{

}

AServerTCP::~AServerTCP()
{

}

void AServerTCP::sentToClient(QTcpSocket *pSocket, const QString &str)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_9);
    out << quint16(0) << QTime::currentTime() << str;

    out.device()->seek(0);
    out << quint16(arrBlock.size() - sizeof(quint16) );

    pSocket->write(arrBlock);
}

void AServerTCP::slotNewConnection()
{
    QTcpSocket* pClientSocket = m_ptcpServer->nextPendingConnection();

    connect(pClientSocket, SIGNAL(disconnected()),
            pClientSocket, SLOT(deleteLater()));

    connect(pClientSocket, SIGNAL(readyRead()),
            this, SLOT(slotReadClient()));

    sentToClient(pClientSocket, "Server Response: Connected!");
}

