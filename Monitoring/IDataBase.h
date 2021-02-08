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

    virtual bool getStatus() = 0;

    virtual ~IDataBase() {}
};

#endif // IDATABASE_H
