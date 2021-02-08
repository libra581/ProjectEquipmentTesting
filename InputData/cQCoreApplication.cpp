#include "cQCoreApplication.h"

cQCoreApplication::cQCoreApplication(int &argc, char **argv)
    :QCoreApplication(argc, argv)
{

}

void cQCoreApplication::exitCode(int code)
{
    this->exit(code);
}
