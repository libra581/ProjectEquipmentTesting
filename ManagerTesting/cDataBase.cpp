#include "cDataBase.h"

cDataBase::cDataBase(const QString & nameDataBase, const QString & hostName,
                     const QString & userName, const QString & password, QObject *parent)
    : IDataBase(parent),
      m_name_data_base(nameDataBase), m_host_name(hostName),
      m_user_name(userName), m_password(password)
{
    //Настройка соединения с базой
    m_db = new QSqlDatabase(QSqlDatabase::addDatabase("QPSQL"));
    m_db->setHostName(hostName);
    m_db->setDatabaseName(nameDataBase);
    m_db->setUserName(userName);
    m_db->setPassword(password);

    m_status_db = m_db->open();

    //Если произошла ошибка соединения с БД
    if (!m_status_db)
    {
        m_error_db = m_db->lastError();
        m_db = nullptr;
        QSqlDatabase::removeDatabase("QPSQL");
    }
}

quint16 cDataBase::selectCurrval(const QString &str)
{
    //Если соединение с БД открыто успешно
    if(this->m_status_db)
    {
        QSqlQuery query_select(QString("SELECT currval('%1')").arg(str));

        //Просмотр результата выполнения запроса
        while (query_select.next())
        {
             return query_select.value(0).toInt();
        }

        //Если запрос не может быть выполнен
        qDebug() <<  query_select.lastError().text();
    }

    return -1;
}

QVector<QVector<QString>> & cDataBase::select(const QString &str)
{
    //Если соединение с БД открыто успешно
    if(this->m_status_db)
    {
        //Запрос определения количества столбцов в таблице
        QSqlQuery query_count_columns(QString("select count(*)"
        " from information_schema.columns"
        " where table_catalog = 'BD_MAIN'"
        " and table_name = '%1'").arg(str));

        query_count_columns.next();
        int count_columns = query_count_columns.value(0).toInt();

        QSqlQuery query_select(QString("SELECT * FROM %1;").arg(str));

        while (query_select.next())
        {
            //Временная переменная, хранящая текущую строку запроса
            QVector<QString> tmp_vector;
            tmp_vector.reserve(count_columns);

            for(int i = 0; i < count_columns; ++i)
            {
                 //Сохранение текущей строки запроса
                 tmp_vector << query_select.value(i).toString();
            }

            //Добавление строки в матрицу строк (сохранение в таблицу)
            matrix_data.push_back(tmp_vector);
        }

        qDebug() <<  query_select.lastError().text();
    }

    return this->matrix_data;
}

QVector<QVector<QString>> & cDataBase::selectAll(const QString &equipment, const QString &mode)
{
    if(this->m_status_db)
    {
        if(matrix_data.length() > 0)
        {
            for(int i = 0; i < matrix_data.length(); ++i)
                matrix_data[i].erase(matrix_data[i].begin(), matrix_data[i].end());

            matrix_data.erase(matrix_data.begin(), matrix_data.end());
        }

        const int count_columns = 5;

        QSqlQuery query_select(
     QString("SELECT f.idrequest, f.idsession, f.codeexecute, f.filedeviations, s.massivemodes"
            " FROM fanalyze f"
            " JOIN request r ON r.id = f.idrequest"
            " JOIN session s ON s.id = f.idsession"
            " JOIN emode e ON e.code = r.codemode"
            " JOIN equipment eq ON eq.idchild = r.idequip"
            " WHERE eq.\"name\" = '%1' and e.\"name\" = '%2';").arg(equipment).arg(mode));

        while (query_select.next())
        {
            //Временная переменная, хранящая текущую строку запроса
            QVector<QString> tmp_vector;
            tmp_vector.reserve(count_columns);

            for(int i = 0; i < count_columns; ++i)
            {
                 //Сохранение текущей строки запроса
                 tmp_vector << query_select.value(i).toString();
            }

            //Добавление строки в матрицу строк (сохранение в таблицу)
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

        //Добавление в запрос имен столбцов таблицы
        for(int i = 0; i < columns.length() - 1; ++i)
        {
            select += columns.at(i);
            select += ",";
        }

        select += columns.at(columns.length()- 1);

        select += ") VALUES (?";

        //Добавление в запрос меток для значений полей таблицы
        for(int i = 0; i < var.length() - 1; ++i)
        {
            select += ",?";
        }

        select += ");";

        QSqlQuery query_insert;
        query_insert.prepare(select);

        //Добавление в запрос значений полей таблицы
        for(const auto &a : var)
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

        //Выполнение запроса
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
