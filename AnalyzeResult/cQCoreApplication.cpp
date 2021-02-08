#include "cQCoreApplication.h"

cQCoreApplication::cQCoreApplication(int &argc, char **argv)
    :QCoreApplication(argc, argv)
{

}

void cQCoreApplication::exitCode(int code)
{
    qDebug () << code;
    this->exit(code);
}
