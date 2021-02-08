#ifndef ACLIENTTCP_H
#define ACLIENTTCP_H

#include <QObject>
#include <QTcpSocket>
#include <QHostInfo>
#include <QDataStream>
#include <QTime>
#include <QDebug>

class AClientTCP :  public QObject
{
    Q_OBJECT

protected:
    QTcpSocket* m_pTcpSocket;
    quint16 m_nNextBlockSize;

public:
    explicit AClientTCP(QObject *parent = nullptr);
    ~AClientTCP();

    virtual void setClientProperty(const QString& strHost, int nPort);

    virtual void sendToServer(int) = 0;
    virtual void sendToServer(QString) = 0;
    virtual void sendToServer(QByteArray) = 0;

signals:

private slots:
    void slotReadyRead();
    void slotError(QAbstractSocket::SocketError);
    void slotConnected();
};

#endif // ACLIENTTCP_H
