/***************************************************************
** CObserver - класс, который наследует абстрактный класс AClientTCP и
** реализует логику объекта-наблюдателя на стороне С++ кода.
****************************************************************
** Создан 10.10.2020 Семенов Д.С. Заявка №00004
****************************************************************
** Назначение класса:
** Управляет взаимодействиями объектов в системе менеджера, реализует
** манипулирования данными и запись структур в БД, реализует
** пользовательскиую интеграцию объекта типа CObserver в QML.
****************************************************************
** Основные совйства класса:
** Переменные с тегом "_plan" относятся к плану испытаний,
** который сформирован циклограммой.
****************************************************************
** Описание основных методов приведено в "AClientTCP.h"
** readFilePlan - чтение файла плана;
** initDB - инициализация БД PostgreSQL;
** insertInputData - вставка исходных данных в БД;
** insertAnalyze - вставка данных анализа в БД.
****************************************************************/

#ifndef COBSERVER_H
#define COBSERVER_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QIODevice>
#include <QDebug>
#include <QDataStream>
#include <QDateTime>
#include <QTcpSocket>
#include <QHostInfo>

#include "cDataBase.h"
#include "Structures.h"
#include "EnumClasses.h"
#include "AClientTCP.h"

class CObserver : public AClientTCP
{
    Q_OBJECT
    /*Свойства для интеграциив QML*/
    Q_PROPERTY(QString pathFilePlan READ getPath WRITE setPath NOTIFY pathChanged)
    Q_PROPERTY(QString dateInputData READ getDateInputData NOTIFY dateChangedInputData)
    Q_PROPERTY(QString dateAnalyze READ getDateAnalyze NOTIFY dateChangedAnalyze)
    Q_PROPERTY(int typeEquipment WRITE setTypeEquipment READ getTypeEquipment NOTIFY typeEquipmentChanged)
    Q_PROPERTY(QVector<QVector<QString>> matrix_select WRITE setMatrixSelect READ getMatrixSelect NOTIFY matrixSelectChanged)

private:
    int typeEquipment;
    TypeEquipment type;

    /*Свойства плана*/
    QString dateInputData;
    Struct::DataBASI basi_plan;
    quint16 usQuantRej_plan = 1;
    Struct::DataBAPPD bappd_plan;
    Struct::masRK rk_plan;

    Struct::TMI tmi_analyze;

    QFile *file_plan;
    QString pathFilePlan;
    QString dateAnalyze;

    cDataBase *m_db = nullptr;

    bool testing_type = false;
    quint8 fouryears = 0;
    quint16 currentdate = 0;
    QTime moscow_time;

    quint16 currval_request = 0;
    QString currval_session = "";

    CodeExec result_analyze = CodeExec::Waiting;
    QByteArray result_formular;

public:
    /*Таблица результата выполнения запроса*/
    QVector<QVector<QString>> matrix_select;

public:
    explicit CObserver(QObject *parent = nullptr);
    ~CObserver();

    Q_INVOKABLE void readFilePlan();
    Q_INVOKABLE void initDB();
    Q_INVOKABLE void insertInputData();
    Q_INVOKABLE void insertAnalyze();

    /* START Геттеры и сеттеры класса*/
    const QString & getDateInputData() const;
    const QString & getDateAnalyze() const;

    void setTypeEquipment(int typeEquipment);
    int getTypeEquipment() const;

    void setMatrixSelect(QVector<QVector<QString>> & matrix);
    QVector<QVector<QString>> &getMatrixSelect();

    void setPath(const QString &);
    const QString &getPath() const;
    /* END Геттеры и сеттеры класса*/

    /*TCP Client*/
    Q_INVOKABLE virtual void setClientProperty(const QString& strHost, int nPort) override;
    Q_INVOKABLE virtual void sendToServer(int) override;
    virtual void sendToServer(QString) override {};
    virtual void sendToServer(QByteArray) override {};

    friend QDataStream & operator>>(QDataStream &in, Struct::DataBAPPD &p);
    friend QDataStream &operator<<(QDataStream &out, const Struct::DataBAPPD &p);

    friend QDataStream & operator>>(QDataStream &in, Struct::DataBASI &p);
    friend QDataStream & operator<<(QDataStream &out, const Struct::DataBASI &p);

    friend QDataStream & operator>>(QDataStream &in, Struct::masRK &p);
    friend QDataStream & operator<<(QDataStream &out, const Struct::masRK &p);

signals:
    void dateChangedInputData();
    void dateChangedAnalyze();
    void pathChanged();
    void typeEquipmentChanged();
    void matrixSelectChanged();
    void errorFilePlan();
};

#endif // COBSERVER_H
