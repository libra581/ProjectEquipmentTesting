/*
* cSceneWithOptions - класс сцены cSceneWithWidget, в котором располагаются
* параметры, каждого выбранного режима.
* *********************************************************************
* Назначение класса: быть контейнером для технологических процессов, а также
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
* Используемый сигнал:
* signalBackOnView - сигнал, вызывающийся для возврата на сцену с
* выбранными режимами.
* *********************************************************************
* Используемый слот:
* slotBackOnView - слот, реализующий вызов сигнала signalBackOnView.
* *********************************************************************
*/

#ifndef CSCENEWITHOPTIONS_H
#define CSCENEWITHOPTIONS_H

#include <QStyle>
#include <QCommonStyle>
#include <QMessageBox>

#include "cSceneWithWidget.h"

class cSceneWithOptions : public cSceneWithWidget
{
    Q_OBJECT

public:
   explicit cSceneWithOptions ( QRectF, QObject *parent = nullptr );

   virtual bool          eventFilter       ( QObject *, QEvent *                   );
   QGraphicsProxyWidget* addCycleEllipse   ( int , QString  , const QColor & , int );

   ~cSceneWithOptions    (  );

signals:
    void signalBackOnView(  );

public slots:
    void slotBackOnView  (  );
};

#endif // CSCENEWITHOPTIONS_H
