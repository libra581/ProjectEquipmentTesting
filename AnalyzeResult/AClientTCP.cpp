#include "AClientTCP.h"

AClientTCP::AClientTCP(QObject *parent)
    : QObject(parent),
      m_nNextBlockSize(0)
{

}

AClientTCP::~AClientTCP()
{

}

void AClientTCP::setClientProperty(const QString &strHost, int nPort)
{
    m_nNextBlockSize = 0;

    m_pTcpSocket = new QTcpSocket(this);
    m_pTcpSocket->connectToHost(strHost, nPort);

    connect(m_pTcpSocket, SIGNAL(connected()), SLOT(slotConnected()));
    connect(m_pTcpSocket, SIGNAL(readyRead() ), SLOT(slotReadyRead()));

    connect(m_pTcpSocket, &QTcpSocket::errorOccurred,
    this, &AClientTCP::slotError);
}

void AClientTCP::slotReadyRead()
{
    QDataStream in(m_pTcpSocket);
    in.setVersion(QDataStream::Qt_5_9);

    for (;;)
    {
        if (!m_nNextBlockSize)
        {
            if (m_pTcpSocket->bytesAvailable() < (qint64)sizeof(quint16))
            {
                break;
            }
            in >> m_nNextBlockSize;
        }

        if (m_pTcpSocket->bytesAvailable() < m_nNextBlockSize)
        {
            break;
        }

        QTime time;
        QString str;
        in >> time >> str;

        qDebug() << time.toString() << str;
        m_nNextBlockSize = 0;
    }
}

void AClientTCP::slotError(QAbstractSocket::SocketError err)
{
    QString strError =
        "Error: "+ (err == QAbstractSocket::HostNotFoundError ?
        "The host was not found." :
        err == QAbstractSocket::RemoteHostClosedError ?
        "The remote host is closed." :
        err == QAbstractSocket::ConnectionRefusedError?
        "The connection was refused." :
        QString(m_pTcpSocket->errorString()));

    qDebug() << strError;
}

void AClientTCP::slotConnected()
{
    qDebug() << "Received the connected() signal";
}
