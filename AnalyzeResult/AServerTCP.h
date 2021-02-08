#ifndef ASERVERTCP_H
#define ASERVERTCP_H

#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include <QHostInfo>
#include <QDataStream>
#include <QTime>
#include <QDebug>

class AServerTCP : public QObject
{
    Q_OBJECT

protected:
    QTcpServer *m_ptcpServer;
    quint16 m_nNextBlockSize;

public:
    explicit AServerTCP(QObject *parent = nullptr);
    ~AServerTCP();

    void sentToClient(QTcpSocket* pSocket, const QString &str);
    virtual void createServerTCP(int nPort) = 0;

signals:

public slots:
    virtual void slotNewConnection();
    virtual void slotReadClient () = 0;

};

#endif // ASERVERTCP_H
