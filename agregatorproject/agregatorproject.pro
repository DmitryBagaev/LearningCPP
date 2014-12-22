#-------------------------------------------------
#
# Project created by QtCreator 2014-12-05T14:42:52
#
#-------------------------------------------------

QT       += core

QT  += gui widgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = agregatorproject

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app

SOURCES += main.cpp \
            file.cpp \
            twitter.cpp \
            mainwindow.cpp

HEADERS += file.h \
            twitter.h \
        mainwindow.h

FORMS    += mainwindow.ui


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/libtwitcurl/release/ -ltwitcurl
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/libtwitcurl/debug/ -ltwitcurl
else:unix: LIBS += -L$$PWD/libtwitcurl/ -ltwitcurl

INCLUDEPATH += $$PWD/libtwitcurl
DEPENDPATH += $$PWD/libtwitcurl
