#include <QCoreApplication>
#include <QTextStream>

#include "cQCoreApplication.h"
#include "EnumClasses.h"
#include "AnalyzeLogic.h"

int main(int argc, char *argv[])
{
    cQCoreApplication a(argc, argv);

    QTextStream cout(stdout);

    if(argc > 4)
    {

        AnalyzeLogic *objLogic = nullptr;

        if(strcmp(argv[1],"BASI") == 0)
        {
            objLogic = new AnalyzeLogic(TypeEquipment::BASI, argv[2], argv[3], argv[4], &a);
        }
        else if (strcmp(argv[1],"BAPPD") == 0)
        {
            objLogic = new AnalyzeLogic(TypeEquipment::BAPPD, argv[2], argv[3], argv[4], &a);
        }
        else
        {
            cout << "Error! Bad argument!" << Qt::endl;
            return -4;
        }

        QObject::connect(objLogic, SIGNAL(exit(int)), &a, SLOT(exitCode(int)));

        Q_UNUSED(objLogic);

    }
    else
    {
        cout << "Error! Need 4 arguments: mode and filename!" << Qt::endl;
        return -5;
    }


    return a.exec();
}
