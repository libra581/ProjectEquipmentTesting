#ifndef ANALYZELOGIC_H
#define ANALYZELOGIC_H

#include <QTimerEvent>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QtGlobal>

#include "ianalyze.h"
#include "AnalyzeBAPPD.h"
#include "AnalyzeBASI.h"
#include "cClientTCP.h"
#include "cServerTCP.h"

class AnalyzeLogic : public QObject
{
    Q_OBJECT
private:
    TypeEquipment type_equipment;
    IAnalyze *objAnalyze = nullptr;
    QTextStream cerr;
    CodeExec result_execute = CodeExec::Waiting;
    QString filename_form_analyze = "None";
    QString filename_form_TMI = "None1";
    QString path_plan = "None2";
    QSerialPort *serial_port;

    QByteArray output_data;

    CodeExec result = CodeExec::Waiting;

    /*Объекты для связи при АИ и КИ*/
    cClientTCP *client = nullptr;
    cServerTCP *server = nullptr;

public:
    const int MAX_ERRORS{3};

public:
    AnalyzeLogic(TypeEquipment type = TypeEquipment::BASI, const QString &file_name_analyze = "None"
            , const QString &filename_form_TMI = "None1"
            , const QString &filename_plan = "None2", QObject *parent = nullptr);

    CodeExec analyzeResult(const QByteArray &, const QString &path_plan);

    ~AnalyzeLogic();

protected:
    virtual void timerEvent(QTimerEvent *event) override;

private:
   // void unitTestAnalyze();


signals:
    void exit(int code);

public slots:
        CodeExec getOutputData();
};

#endif // ANALYZELOGIC_H
