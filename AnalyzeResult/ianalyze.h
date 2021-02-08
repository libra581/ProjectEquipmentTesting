#ifndef IANALYZE_H
#define IANALYZE_H

#include <QObject>
#include <QFile>
#include <QDataStream>

#include "EnumClasses.h"
#include "Structures.h"

class IAnalyze : public QObject
{
    Q_OBJECT

public:
    IAnalyze(QObject *parent = nullptr);

    virtual CodeExec setPlan(const QString &) = 0;
    virtual CodeExec setOutputData(const QByteArray &) = 0;
    static CodeExec createTMI(const QString &, const QByteArray &);
    virtual quint8 analyze() = 0;

    virtual ~IAnalyze() {};

protected:
    virtual quint8 countErrorStructres(const Struct::DataBAPPD &, const Struct::masRK & ,
                        const Struct::DataBAPPD &, const Struct::masRK &);

    virtual quint8 countErrorStructres(const Struct::DataBASI &, const Struct::masRK & ,
                        const Struct::DataBASI &, const Struct::masRK &);

    virtual quint8 countErrorRK(const Struct::masRK & , const Struct::masRK &);
    virtual quint8 countErrorMasInt8(const qint8 *, qint8, const qint8 *, qint8);
    ;

};

#endif // IANALYZE_H
