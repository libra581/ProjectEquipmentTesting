#ifndef COBSERVER_H
#define COBSERVER_H

#include <QDebug>
#include <QDataStream>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTime>
#include <QHash>
#include <QVector>

#include "EnumClasses.h"
#include "AServerTCP.h"
#include "cDataBase.h"

class cObserver : public AServerTCP
{
    Q_OBJECT

    Q_PROPERTY(int codeExec READ getCodeExec WRITE setCodeExec NOTIFY codeExecChanged)
    Q_PROPERTY(QVector<QVector<QString>> matrix_select WRITE setMatrixSelect READ getMatrixSelect NOTIFY matrixSelectChanged)

private:
    QHash<QString,int> m_hmClients;
    int m_nPort;
    int codeExec;

    cDataBase *m_db = nullptr;
    QVector<QVector<QString>> matrix_select;

public:
    explicit cObserver(QObject *parent = nullptr);
    ~cObserver();

    void setCodeExec(int codeExec);
    int getCodeExec() const;

    void setMatrixSelect(QVector<QVector<QString>> & matrix);
    QVector<QVector<QString> > &getMatrixSelect();

    Q_INVOKABLE void initDB();
    Q_INVOKABLE QVector<QVector<QString> > &select(const QString &table);

    Q_INVOKABLE virtual void createServerTCP(int nPort) override;

signals:
    void codeExecChanged();
    void matrixSelectChanged();
    Q_INVOKABLE void msgClient(int typeEquipment, int codeExec);

public slots:
       virtual void slotReadClient () override;

};

#endif // COBSERVER_H
