/*
* cSceneWithMode - класс сцены, в котором располагаются выбранные режимы.
* *********************************************************************
* Назначение класса: быть контейнером для выбранных режимов, а также
* определять механику взаимодействия сцены и пользователя.
* *********************************************************************
* Используемые методы:
* cSceneWithMode     - конструктор класса cSceneWithMode;
* addCycleEllipse    - метод добавления новых элементов циклограммы
* на сцену;
* eventFilter        - фильтр событий, реализующий алгоритм взаимодействия
* сцены и пользователя;
* ~cSceneWithMode    - деструктор класса cSceneWithMode.
* *********************************************************************
*/

#ifndef CSCENEWITHMODE_H
#define CSCENEWITHMODE_H

#include <QMessageBox>

#include "cSceneWithWidget.h"

class cSceneWithMode : public cSceneWithWidget
{
    Q_OBJECT

public:
   explicit     cSceneWithMode  ( QRectF  , QObject *parent = nullptr);

   virtual bool          eventFilter     ( QObject*, QEvent  *                   );
   QGraphicsProxyWidget* addCycleEllipse ( int , QString  , const QColor & , int );

   ~cSceneWithMode();
};

#endif // CSCENEWITHMODE_H
