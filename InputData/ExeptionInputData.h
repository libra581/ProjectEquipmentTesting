/***************************************************************
**
** ExeptionInputData - класс наследует QException и
** реализует кастомный вариант создания исключений.
****************************************************************
** Назначение класса: используется как фабрика
** пользовательских исключений в программе.
****************************************************************
** Создан 20.09.2020 Семенов Д.С. Заявка №00001
****************************************************************
** Входные параметра конструктора:
** textExcept : QString - текст исключения.
****************************************************************
** Основные методы:
** whatIs : QString - возвращает текст исключения.
**
****************************************************************/

#ifndef EXEPTIONINPUTDATA_H
#define EXEPTIONINPUTDATA_H

#include <QException>
#include <QString>

class ExeptionInputData : public QException
{
private:
    QString textExcept = "None";

public:
    ExeptionInputData(const QString &textExcept);
    const QString & whatIs() const;

    void raise() const override;
    ExeptionInputData *clone() const override;
};

#endif // EXEPTIONINPUTDATA_H
