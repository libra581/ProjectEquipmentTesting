#ifndef CSERVERTCP_H
#define CSERVERTCP_H

#include <QObject>

#include "AServerTCP.h"

class cServerTCP : public AServerTCP
{
    Q_OBJECT
public:
    cServerTCP(QObject *parent = nullptr);

    virtual void createServerTCP(int nPort) override;

public slots:
       virtual void slotReadClient () override;

};

#endif // CSERVERTCP_H
