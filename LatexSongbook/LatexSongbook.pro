#-------------------------------------------------
#
# Project created by QtCreator 2011-11-18T12:23:04
#
#-------------------------------------------------

QT       += core gui

TARGET = LatexSongbook
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++0x

SOURCES += src/main.cpp\
    src/LatexSongbook.cpp \
    src/SongEditor.cpp \
    src/SongbookEditor.cpp \
    src/TarFile.cpp \
    src/TarArchive.cpp

HEADERS  += src/LatexSongbook.hpp \
    src/SongEditor.hpp \
    src/SongbookEditor.hpp \
    src/TarFile.hpp \
    src/TarArchive.hpp

FORMS    += ui/LatexSongbook.ui \
    ui/SongEditor.ui \
    ui/SongbookEditor.ui

RESOURCES += \
    res/FreshFarm.qrc

























