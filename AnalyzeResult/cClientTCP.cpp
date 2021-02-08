#include "cClientTCP.h"

cClientTCP::cClientTCP(QObject *parent):
    AClientTCP(parent)
{

}

void cClientTCP::setClientProperty(const QString &strHost, int nPort)
{
    AClientTCP::setClientProperty(strHost, nPort);
}


void cClientTCP::sendToServer(int msg)
{
    if(m_pTcpSocket != nullptr)
    {
        QByteArray arrBlock;
        QDataStream out(&arrBlock, QIODevice::WriteOnly);

        out.setVersion(QDataStream::Qt_5_9);
        qDebug() << msg;
        out << quint16(0) << QHostInfo::localHostName() << 1 << msg; //int typeEquipment

        out.device()->seek(0);
        out << quint16(arrBlock.size() - sizeof(quint16) );

        m_pTcpSocket->write(arrBlock);
    }
}
