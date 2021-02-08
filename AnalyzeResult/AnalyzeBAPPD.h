#ifndef ANALYZEBAPPD_H
#define ANALYZEBAPPD_H

#include <QDebug>
#include <QDataStream>
#include <QDateTime>

#include "Structures.h"
#include "ianalyze.h"

class AnalyzeBAPPD : public IAnalyze
{
    Q_OBJECT
private:
    quint16 usQuantRej = 0;    
    Struct::DataBAPPD obj_Data_BAPPD;
    Struct::masRK obj_RK_BAPPD;
    QDateTime date_time;

    quint16 usQuantRej_plan;
    Struct::DataBAPPD obj_Data_BAPPD_plan;
    Struct::masRK obj_RK_BAPPD_plan;
    QDateTime date_time_plan;

public:
    AnalyzeBAPPD(QObject *parent = nullptr);

    virtual CodeExec setPlan(const QString &) override;
    virtual CodeExec setOutputData(const QByteArray &) override;
    virtual quint8 analyze() override;

    virtual ~AnalyzeBAPPD() {};

    friend QDataStream & operator>>(QDataStream &in, Struct::DataBAPPD &p);
    friend QDataStream & operator<<(QDataStream &out, const Struct::DataBAPPD &p);

    friend QDataStream & operator>>(QDataStream &in, Struct::masRK &p);
    friend QDataStream & operator<<(QDataStream &out, const Struct::masRK &p);

private:
    virtual quint8 countErrorStructres(const Struct::DataBAPPD &data_1, const Struct::masRK &rk_1,
                                     const Struct::DataBAPPD &data_2, const Struct::masRK &rk_2) override;

};

#endif // ANALYZEBAPPD_H
