#include <QtGui/QApplication>

#include <QDebug>

#include "DatabaseEditor.hpp"
#include "SongbookEditor.hpp"
#include "SongEditor.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DatabaseEditor databaseEditor(argv[0]);
    SongEditor songEditor;
    SongbookEditor songbookEditor;

    QString arg;
    if(argc > 1)
    {
        arg = argv[1];
    }

    if(arg == "--song-editor")
    {
        songEditor.show();

        if(argc > 2)
        {
            songEditor.openSong(argv[2]);
        }
    }
    else if(arg == "--songbook-editor")
    {
        songbookEditor.show();

        if(argc > 2)
        {
            songbookEditor.openSongbook(argv[2]);
        }
    }
    else
    {
        databaseEditor.show();
    }

    return app.exec();
}
