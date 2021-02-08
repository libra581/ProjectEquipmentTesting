QT -= gui
QT += serialport
CONFIG += c++14 console
CONFIG -= app_bundle

SOURCES += \
        ExeptionInputData.cpp \
        IInputData.cpp \
        ImitLogic.cpp \
        InputDataBAPPD.cpp \
        InputDataBASI.cpp \
        cQCoreApplication.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    EnumClasses.h \
    ExeptionInputData.h \
    IInputData.h \
    ImitLogic.h \
    InputDataBAPPD.h \
    InputDataBASI.h \
    Structures.h \
    cQCoreApplication.h
