#-------------------------------------------------
#
# Project created by QtCreator 2017-02-18T12:55:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CycleGramma
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    ccycleEllipse.cpp \
    ccyclePolygon.cpp \
    ccycleLine.cpp \
    ccycleLabel.cpp \
    cMainWindow.cpp \
    cSceneWithWidget.cpp \
    cSceneWithOptions.cpp \
    cSceneWithMode.cpp \
    cFormWithTable.cpp \
    cListDialog.cpp \

HEADERS  += \
    ccycleEllipse.h \
    ccyclePolygon.h \
    ccycleLine.h \
    ccycleLabel.h \
    cMainWindow.h \
    cSceneWithWidget.h \
    cSceneWithOptions.h \
    cSceneWithMode.h \
    cFormWithTable.h \
    cListDialog.h \

FORMS    += cmainwindow.ui \
    cformwithtable.ui

RESOURCES +=  img/img.qrc \

RC_FILE = myapp.rc
