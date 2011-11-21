#-------------------------------------------------
#
# Project created by QtCreator 2011-11-18T12:23:04
#
#-------------------------------------------------

QT       += core gui

TARGET = LatexSongbook
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp\
        LatexSongbook.cpp \
    SongEditor.cpp \
    SongbookEditor.cpp

HEADERS  += LatexSongbook.hpp \
    SongEditor.hpp \
    SongbookEditor.hpp

FORMS    += LatexSongbook.ui \
    SongEditor.ui \
    SongbookEditor.ui

RESOURCES += \
    FreshFarm.qrc





















