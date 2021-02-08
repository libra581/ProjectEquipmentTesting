/***************************************************************
**
** cQCoreApplication - класс, который
** реализует возможности кастомного сигнало-слотового соединения
** и консольного приложения QCoreApplication.
****************************************************************
** Назначение класса: используется для получения
** кода возврата из класса ImitLogic и немедленного
** завершения выполнения модуля "InputData".
****************************************************************
** Создан 20.09.2020 Семенов Д.С. Заявка №00001
****************************************************************
** Входные данные конструктора:
** Параметры командной строки (int &argc, char **argv).
****************************************************************
** Основной слот соединения:
** public exitCode : void - используется вкачестве слота для
** содинения с сигналами ImitLogic. Принимает целочисленный
** параметр - код возврата. При вызове консольное приложение
** завершается немедленно возвращая int code.
**
****************************************************************/


#ifndef CQCOREAPPLICATION_H
#define CQCOREAPPLICATION_H

#include <QCoreApplication>

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
