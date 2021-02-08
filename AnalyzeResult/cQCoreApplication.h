#ifndef CQCOREAPPLICATION_H
#define CQCOREAPPLICATION_H

#include <QCoreApplication>
#include <QDebug>

class cQCoreApplication : public QCoreApplication
{
    Q_OBJECT
public:
    cQCoreApplication(int &argc, char **argv);

    virtual bool notify(QObject *receiver, QEvent *event)
    {
        return QCoreApplication::notify(receiver, event);
    }

    ~cQCoreApplication() {}

public slots:
    void exitCode(int code);
};

#endif // CQCOREAPPLICATION_H
