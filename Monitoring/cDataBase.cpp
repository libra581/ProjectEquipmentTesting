#include "cDataBase.h"

cDataBase::cDataBase(const QString & nameDataBase, const QString & hostName,
                     const QString & userName, const QString & password, QObject *parent)
    : IDataBase(parent),
      m_name_data_base(nameDataBase), m_host_name(hostName),
      m_user_name(userName), m_password(password)
{
    m_db = new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL"));
    m_db->setHostName(hostName);
    m_db->setDatabaseName(nameDataBase);
    m_db->setUserName(userName);
    m_db->setPassword(password);

    m_status_db = m_db->open();

    if (m_status_db)
    {
        m_error_db = m_db->lastError();
        m_db = nullptr;
        QSqlDatabase::removeDatabase("QPSQL");
    }
}

quint16 cDataBase::selectCurrval(const QString &str)
{
    if(this->m_status_db)
    {
        QSqlQuery query_select(QString("SELECT currval('%1')").arg(str));

        while (query_select.next())
        {
             qDebug() <<  query_select.value(0).toString();
             return query_select.value(0).toInt();
        }

        qDebug() <<  query_select.lastError().text();
    }

    return -1;
}

QVector<QVector<QString>> & cDataBase::select(const QString &str)
{
    if(this->m_status_db)
    {
        if(matrix_data.length() > 0)
        {
            for(int i = 0; i < matrix_data.length(); ++i)
                matrix_data[i].erase(matrix_data[i].begin(), matrix_data[i].end());

            matrix_data.erase(matrix_data.begin(), matrix_data.end());
        }

        QSqlQuery query_count_columns(QString("select count(*)"
        " from information_schema.columns"
        " where table_catalog = 'BD_MAIN'"
        " and table_name = '%1'").arg(str));

        query_count_columns.next();
        int count_columns = query_count_columns.value(0).toInt();

        QSqlQuery query_select(QString("SELECT * FROM %1;").arg(str));

        while (query_select.next())
        {
            QVector<QString> tmp_vector;
            tmp_vector.reserve(count_columns);

            for(int i = 0; i < count_columns; ++i)
            {
                 //qDebug() << query_select.value(i).toString();
                 tmp_vector << query_select.value(i).toString();
            }

            matrix_data.push_back(tmp_vector);
        }

        qDebug() <<  query_select.lastError().text();
    }

    return this->matrix_data;
}

void cDataBase::insert(const QString &table_name, const QList<QString> &columns, const QVariantList &var)
{
    if(this->m_status_db)
    {
        QString select("INSERT INTO " + table_name + "(");

        for(int i = 0; i < columns.length() - 1; ++i)
        {
            select += columns.at(i);
            select += ",";
        }

        select += columns.at(columns.length()- 1);

        select += ") VALUES (?";

        for(int i = 0; i < var.length() - 1; ++i)
        {
            select += ",?";
        }

        select += ");";

        QSqlQuery query_insert;
        query_insert.prepare(select);

        for(auto a : var)
        {
            query_insert.addBindValue(a);
        }

        query_insert.exec();

        qDebug() <<  query_insert.lastError().text();
    }
}

void cDataBase::update(const QString &table_name, const QString &change,  const QString &where)
{
    if(this->m_status_db)
    {
        QString select("UPDATE " + table_name + " SET " + change +
                       " WHERE " + where);

        QSqlQuery query_insert;
        query_insert.prepare(select);
        query_insert.exec();

        qDebug() <<  query_insert.lastError().text();
    }
}

bool cDataBase::getStatus()
{
    return this->m_status_db;
}

cDataBase::~cDataBase()
{
    if (m_db)
    {
        delete m_db;
        QSqlDatabase::removeDatabase("QPSQL");
    }

    m_db = nullptr;
}
