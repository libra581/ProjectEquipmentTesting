#ifndef CCLIENTTCP_H
#define CCLIENTTCP_H

#include "AClientTCP.h"

class cClientTCP : public AClientTCP
{
    Q_OBJECT
public:
    cClientTCP(QObject *parent = nullptr);

    virtual void setClientProperty(const QString& strHost, int nPort) override;
    virtual void sendToServer(int) override;
    virtual void sendToServer(QString) override {};
    virtual void sendToServer(QByteArray) override {};
};

#endif // CCLIENTTCP_H
