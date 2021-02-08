#include "myprocess.h"

void myProcess::start(const QString &program, const QVariantList &arguments)
{
    QStringList args;

    for (int i = 0; i < arguments.length(); i++)
        args << arguments[i].toString();

    QProcess::start(program, args);
}

qint32 myProcess::readAll()
{
    qDebug() << "cpp " << QProcess::exitCode();
    return QProcess::exitCode();
}
