#-------------------------------------------------
#
# Project created by QtCreator 2011-08-18T17:36:46
#
#-------------------------------------------------

QT       += core gui

TARGET = latexsongbook-gui
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        mainwindow.cpp \
    songbook.cpp \
    song.cpp \
    songmodel.cpp \
    songbooksituation.cpp \
    eventmodel.cpp \
    instrumentsettings.cpp \
    instrument.cpp \
    instrumentmodel.cpp \
    songbookgenerator.cpp

HEADERS  += mainwindow.h \
    songbook.h \
    song.h \
    songmodel.h \
    songcomparator.h \
    songbooksituation.h \
    songfilter.h \
    songproperty.h \
    relation.h \
    eventmodel.h \
    common.h \
    instrumentsettings.h \
    instrument.h \
    instrumentmodel.h \
    songbookgenerator.h

FORMS    += mainwindow.ui \
    instrumentsettings.ui




