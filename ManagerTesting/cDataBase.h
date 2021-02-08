/***************************************************************
** cDataBase - класс, который наследует интерфейс IDataBase и
** реализует логику рабоыт с БД PostgreSQL.
****************************************************************
** Создан 20.09.2020 Семенов Д.С. Заявка №00004
****************************************************************
** Основные совйства класса:
** matrix_data : QVector<QVector<QString>> - объект матрицы, поля
** которой состоят из полей таблицы последнего запроса SELECT.
****************************************************************
** Описание основных методов приведено в "IDataBase.h".
** selectCurrval : quint16 - возвращает значение первичного ключа
** текущей вставленной записи в таблицу.
****************************************************************/
#ifndef CDATABASE_H
#define CDATABASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

#include "IDataBase.h"

class cDataBase : public IDataBase
{
    Q_OBJECT
private:
    QString m_name_data_base;
    QString m_host_name;
    QString m_user_name;
    QString m_password;
    QSqlDatabase *m_db = nullptr;
    bool m_status_db = false;
    QSqlError m_error_db;

public:
    QVector<QVector<QString>> matrix_data;

public:
    cDataBase(const QString & nameDataBase, const QString &hostName,
              const QString &userName, const QString &password, QObject *parent = nullptr);

    virtual quint16 selectCurrval(const QString &str);
    virtual QVector<QVector<QString>> & select(const QString &str) override;
    virtual QVector<QVector<QString>> & selectAll(const QString &equipment, const QString &mode) override;
    virtual void insert(const QString &table_name, const QList<QString> &columns, const QVariantList &var) override;
    virtual void update(const QString &table_name, const QString &change,  const QString &where) override;
    virtual bool getStatus() override;

    ~cDataBase();
};

#endif // CDATABASE_H
