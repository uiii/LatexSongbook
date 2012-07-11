#include <QtGui/QApplication>

#include <QDebug>

#include "Config.hpp"

#include "DatabaseEditor.hpp"
#include "SongbookEditor.hpp"
#include "SongEditor.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Config config(argc, argv);

    Generator generator;

    DatabaseEditor databaseEditor(&config);
    SongEditor songEditor(&generator);
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
