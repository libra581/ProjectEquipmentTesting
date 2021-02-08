/***************************************************************
** IDataBase - интерфейс, наследующий класс QObject
** и содержащий чисто виртуальные функции для реализации
** алгоритмов манипулирования данными с БД PostgreSQL.
****************************************************************
** Создан 20.09.2020 Семенов Д.С. Заявка №00004
****************************************************************
** Основные чисто виртуальные функции:
** select : QVector<QVector<QString>> & - выборка из таблицы БД;
** insert : void - вставка в талицу БД;
** update : void - обновление записей в талице БД.
****************************************************************/

#ifndef IDATABASE_H
#define IDATABASE_H

#include <QObject>
#include <QString>
#include <QVector>

class IDataBase : public QObject
{
    Q_OBJECT
public:
    IDataBase(QObject *parent = nullptr);

    virtual QVector<QVector<QString>> & select(const QString &str) = 0;
    virtual void insert(const QString &str, const QList<QString> &columns, const QVariantList &var) = 0;
    virtual void update(const QString &table_name, const QString &change,  const QString &where) = 0;
    virtual QVector<QVector<QString>> & selectAll(const QString &equipment, const QString &mode) = 0;
    virtual bool getStatus() = 0;

    virtual ~IDataBase() {}
};

#endif // IDATABASE_H
