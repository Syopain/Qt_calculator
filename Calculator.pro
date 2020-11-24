QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    calculator.h \
    core.h

SOURCES += \
    calculator.cpp \
    core.cpp \
    main.cpp

FORMS += \
    calculator.ui

RESOURCES += \
    calculator.qrc

RC_FILE += \
    Calculator.rc

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

