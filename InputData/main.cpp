/***************************************************************************
**
** Модуль "InputData". Имитация исходных данных БАСИ и БАППД.
**
** Создан 20.09.2020 Семенов Д.С. Заявка №00001
** Модификация 31.12.2020 Семенов Д.С. Заявка №0010
** Корректировка перечислений: добавление дополнительных
** полей в перечисление "CodeExec"
**
** Версия: 1.5
** Среда разработки: Qt Creater
** Язык программирования: C++ / Qt 5.15.2
**
** Задача:
** Формирование исходных данных и разовых команд на основе плана испытаний.
** Подача команд в определенное время по COM-порту (COM4 -> ).
**
** Входные данные функции main:
** Программа принимает параметры командной строки в следующем порядке -
** 1.Тип оборудования : указатель на C-Style строку (Пример содержимого: "BASI", "BAPPD");
** 2.Путь к файлу плана : указатель на C-Style строку  (Пример содержимого: "C:\\Users\\sds\\Documents\\Plan").
**
** Основные переменные функции main:
** app : cQCoreApplication - объект класса, контролирующий главный поток и основные
** настройки приложения (является кастомным, реализуя сигнало-слотовое соединения);
** objLogic : ImitLogic - указатель на объект, отвечающий за логику имитации данных.
****************************************************************************/

#include <QCoreApplication>
#include <QTextStream>
#include <QObject>

#include "cQCoreApplication.h"
#include "EnumClasses.h"
#include "ImitLogic.h"

int main(int argc, char *argv[])
{
    cQCoreApplication app(argc, argv);

    QTextStream cout(stdout);

    if(argc > 2)
    {

        ImitLogic *objLogic = nullptr;

        if(strcmp(argv[1],"BASI") == 0)
        {
            objLogic = new ImitLogic(TypeEquipment::BASI, argv[2], &app);
        }
        else if (strcmp(argv[1],"BAPPD") == 0)
        {
            objLogic = new ImitLogic(TypeEquipment::BAPPD, argv[2], &app);
        }
        else
        {
            cout << "Ошибка! Некорректные аргументы!" << Qt::endl;
            return -4;
        }

        QObject::connect(objLogic, SIGNAL(exit(int)), &app, SLOT(exitCode(int)));

        Q_UNUSED(objLogic);

    }
    else
    {
        cout << "Ошибка! Ожидалось 2 аргумента: Вид режима, Путь к файлу плана!" << Qt::endl;
        return -5;
    }

    return app.exec();
}
