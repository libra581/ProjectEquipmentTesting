#ifndef ANALYZEBASI_H
#define ANALYZEBASI_H

#include <QDebug>
#include <QDataStream>
#include <QDateTime>

#include "Structures.h"
#include "ianalyze.h"

class AnalyzeBASI :  public IAnalyze
{
    Q_OBJECT
private:
    Struct::DataBASI obj_Data_BASI;
    Struct::masRK obj_RK_BASI;
    QString date_time;

    Struct::DataBASI obj_Data_BASI_plan;
    Struct::masRK obj_RK_BASI_plan;
    QString date_time_plan;

public:
    AnalyzeBASI(QObject *parent = nullptr);

    virtual CodeExec setPlan(const QString &) override;
    virtual CodeExec setOutputData(const QByteArray &) override;
    virtual quint8 analyze() override;

    virtual ~AnalyzeBASI() {};


    friend QDataStream & operator>>(QDataStream &in, Struct::DataBASI &p);
    friend QDataStream & operator<<(QDataStream &out, const Struct::DataBASI &p);

    friend QDataStream & operator>>(QDataStream &in, Struct::masRK &p);
    friend QDataStream & operator<<(QDataStream &out, const Struct::masRK &p);

private:
    quint8 countErrorStructres(const Struct::DataBASI &, const Struct::masRK & ,
                        const Struct::DataBASI &, const Struct::masRK &) override;

    void unitTestAnalyze();

};

#endif // ANALYZEBASI_H
