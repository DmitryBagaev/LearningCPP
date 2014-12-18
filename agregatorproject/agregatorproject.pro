#-------------------------------------------------
#
# Project created by QtCreator 2014-12-05T14:42:52
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT       += network
QT       += xml

TARGET = agregatorproject
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app

SOURCES += main.cpp \
            file.cpp \
            twitter.cpp \
            json.cpp
HEADERS += file.h \
            twitter.h \
            json.h




win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libtwitcurl/release/ -ltwitcurl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libtwitcurl/debug/ -ltwitcurl
else:unix: LIBS += -L$$PWD/libtwitcurl/ -ltwitcurl

INCLUDEPATH += $$PWD/libtwitcurl
DEPENDPATH += $$PWD/libtwitcurl
