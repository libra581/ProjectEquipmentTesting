/*
* ***********************************************************
* cMainWindow - класс главного окна приложения.
* ***********************************************************
* Назначение класса: отображение интерфейса пользователя,
* реализация пользовательской механики взаимодействия пользователя
* и интерфейса, сброка всех модулей программы в единное целое.
* ***********************************************************
* Свойства класса:
* ui                - указатель, содержащий главное окно;
* pView             -  главное представление, на которой отображаются
* раличные сцены;
* pScene            - главная сцена циклограммы;
* tmr               - таймер, использующийся для реализации анимации на сцене;
* scl,sclExt,msec   - переменные, необходимые для задания величины,
* с помощью которой уменьшается или увеличивается масштаб сцены;
* listSceneOptions  - вспомогательная сцена, на которой находятся
* основные настройки циклограммы;
* countApplyModes   - переменная подсчета количества заполненных режимов
* пользователем;
* currentIndexTab   - переменная, содержащая текущий индекс TabMenu;
* flag              - флаг, использующийся для отображения выбранного элемента в
* listWidget;
* bar               - панель инструментов, находящихся на представлении.
* ***********************************************************
* Используемые методы:
* cMainWindow       - конструктор класса;
* createScenes      - метод создания сцен для каждого режима;
* setEnabledGroups  - метод, задающий доступ ко всем элементам
* после того, как пользователь заполнит все режимы;
* setDisabledGroups - метод, задающий доступ к определенному
* элементу, остальные же блокирует;
* setDateTimeEnd    - метод, задающий дату конца режима;
* valListForButton  - метод, разблокирующий кнопку "Далее" в
* случае ,если listRight заполнен;
* writeToInterfaceDate - метод, предназначенный для чтения из файла;
* ~cMainWindow      - деструктор класса.
* ***********************************************************
* Используемые слоты:
* on_action_exit_triggered       - слот нажатия на кнопку "Выход", расположенную
* на ToolBar;
* on_onTheRightButton_clicked    - слот нажатия на кпонку со стрелкой, смотрящей на право,
* реализующий перенос с левого листа "Доступный режим" на правый лист "Выбранные режимы";
* on_onTheLeftButton_clicked     - слот нажатия на кпонку с крестиком,
* реализующий удаления элемента из правого листа "Выбранные режимы";
* on_buttonNext_clicked          - слот нажатия на копку "Далее" , расположенную
* на ToolBar;
* expandMyView, exp              - слоты, содержащие алгоритм расширения сцены
* на правую кнопку мыши;
* on_listRight_itemChanged       - слот, реагирующий на изменения в listWidget;
* slotBackOnView                 - слот, устанавливающий сцену с режимами;
* on_pushData_clicked            - слот заполнения таблицы текущего режима;
* updateMainWidgetOfScrolls      - обновление главного окна при движении скроллов
* на сцене;
* on_action_save_triggered       - слот нажатия на кнопку "Сохранить" в
* панели инструментов;
* on_action_open_triggered       - слот нажатия на кнопку "Открыть" в
* панели инструментов;
* slotChangeOptions              - слот изменения четырех параметров со сцены;
* on_buttonTimeEdit_clicked      - слот нажатия на кнопку "Изменить";
* on_pushButComands_clicked      - слот нажатия на кнопку "Задать команды";
* on_pushButSetTime_clicked      - слот нажатия на кнопку "Задать время";
* on_listLeft_currentItemChanged - слот изменения текущей строки в listLeft;
* on_listRight_currentItemChanged - слот изменения текущей строки в listRight;
* on_tabModes_tabBarDoubleClicked - слот реагирующий на двойной щелчок мыши
* на вкладку в TabBar;
* on_tabModes_tabBarClicked      - слот реагирующий на один щелчок мыши
* на вкладку в TabBar;
* on_tabModes_tabCloseRequested  - слот удаления вкладки в TabBar;
* on_tabModes_currentChanged     - слот изменения текущей вкладки в
* TabBar;
* on_action_about_triggered      - слот отображения окна "О программе".
* ***********************************************************
* Используемые сигналы:
* signalValueChangeIOK     - сигнал, высылающий размер Тиок на сцене;
* signalValueChangeIP      - сигнал, высылающий размер Тип на сцене;
* signalValueChangeOneMode - сигнал, высылающий размер Т1-го режима на сцене;
* signalValueChangeUprezh  - сигнал, высылающий размер Тупрежд на сцене.
* ***********************************************************
*/

#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QListView>
#include <QTimer>
#include <QPixmap>
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>

#include "ccycleEllipse.h"
#include "cViewWithCycle.h"
#include "ccreatedialog.h"
#include "cSceneWithWidget.h"
#include "cscenewithoptions.h"
#include "cSceneWithMode.h"
#include "cChoicePathDelegate.h"
#include "cFormWithTable.h"
#include "cListDialog.h"

namespace Ui {
class cMainWindow;
}

class cMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit cMainWindow          ( QWidget* parent = nullptr    );

    void     valListForButton     ( QListWidget*, QPushButton*   );
    void     writeToInterfaceDate ( const QString &              );

    ~cMainWindow();

signals:
    signalValueChangeIOK    ( int );
    signalValueChangeIP     ( int );
    signalValueChangeOneMode( int );
    signalValueChangeUprezh ( int );

private slots:
    void on_action_exit_triggered        (                   );

    void on_onTheRightButton_clicked     (                   );

    void on_onTheLeftButton_clicked      (                   );

    void on_buttonNext_clicked           (                   );

    void expandMyView                    ( int, int          );

    void exp                             (                   );

    void on_listRight_itemChanged        ( QListWidgetItem * );

    void updateMainWidgetOfScrolls       (                   );

    void slotBackOnView                  (                   );

    void on_tabModes_tabBarClicked       ( int               );

    void on_pushData_clicked             (                   );

    void on_action_save_triggered        (                   );

    void on_action_open_triggered        (                   );

    void slotChangeOptions               (int, int, int, int );

    void on_buttonTimeEdit_clicked       (                   );

    void on_pushButComands_clicked       (                   );

    void on_pushButSetTime_clicked       (                   );

    void on_tabModes_tabBarDoubleClicked ( int               );

    void on_listLeft_currentItemChanged  ( QListWidgetItem *, QListWidgetItem * );

    void on_listRight_currentItemChanged ( QListWidgetItem *, QListWidgetItem * );

    void on_tabModes_tabCloseRequested   ( int                 );

    void on_tabModes_currentChanged      ( int                 );

    void on_action_about_triggered       (                     );

    void on_listLeft_doubleClicked       ( const QModelIndex & );

private:
    Ui::cMainWindow* ui     ;
    cSceneWithMode*  pScene ;
    QTimer*          tmr    ;
    double           scl   ,
                     sclExt,
                     msec   ;

    QList<cSceneWithOptions *> listSceneOptions;
    QVector<bool> vecApplyMode;

    int     countApplyModes ;
    int     currentIndexTab ;
    bool    flag            ;

    void createScenes       (           );
    void setEnabledGroups   (           );
    void setDisabledGroups  (           );
    void setDateTimeEnd     ( int index );


};

#endif // CMAINWINDOW_H
