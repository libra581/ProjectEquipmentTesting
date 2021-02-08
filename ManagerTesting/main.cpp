/**********************************************************************
**
** Модуль "Manager Testing". Управление испытаниями БАСИ и БАППД.
**
** Создан 23.09.2020 Семенов Д.С. Заявка №00003
**
** Версия: 1.3
** Среда разработки: Qt Creater
** Язык программирования: C++ / Qt 5.15.2
**
** Задача:
** Запуск циклограммы, имитации исходных данных и анализа в
** определенный планом времени.
** Предоставление GUI для управления графическим интерфейсом пользователя.
**
** Основные переменные функции main:
** app : QGuiApplication - объект класса, контролирующий главный поток и основные
** настройки приложения;
** engine : QQmlApplicationEngine - объект класса, который предоставляет центральную
** функциональность приложения на QML;
** context : QQmlContext -
** myObserver : CObserver - объект-наблюдатель, реализующий алгоритм взаимодействия
** программных модулей.
**********************************************************************/


#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include <QQmlContext>

#include "myprocess.h"
#include "CObserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/img/icons8-networking-manager-96.png"));

    qmlRegisterType<myProcess>("myProcess", 1, 0, "Process");
    qmlRegisterType<CObserver>("CObserver", 1, 0, "CObserver");

    QQmlApplicationEngine engine;

    QQmlContext *context = engine.rootContext();
    CObserver myObserver(&app);

    context->setContextProperty("CObserver", &myObserver);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);


    engine.load(url);

    return app.exec();
}
