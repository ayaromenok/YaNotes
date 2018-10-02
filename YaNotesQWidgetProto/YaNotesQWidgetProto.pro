# Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
# MIT License - https://github.com/ayaromenok/YaNotes/blob/master/LICENSE

QT      += core gui widgets

TARGET = YaNotesQWidgetProto
TEMPLATE = app

CONFIG += c++11

include(../share/share.pri)

SOURCES += \
        main.cpp \        
        ynwidget.cpp

HEADERS += \        
        ynwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
