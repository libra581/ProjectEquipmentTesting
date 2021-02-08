QT -= gui
QT += serialport network
CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        AClientTCP.cpp \
        AServerTCP.cpp \
        AnalyzeBAPPD.cpp \
        AnalyzeBASI.cpp \
        AnalyzeLogic.cpp \
        IAnalyze.cpp \
        cClientTCP.cpp \
        cQCoreApplication.cpp \
        cServerTCP.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    AClientTCP.h \
    AServerTCP.h \
    AnalyzeBAPPD.h \
    AnalyzeBASI.h \
    AnalyzeLogic.h \
    EnumClasses.h \
    IAnalyze.h \
    Structures.h \
    cClientTCP.h \
    cQCoreApplication.h \
    cServerTCP.h
