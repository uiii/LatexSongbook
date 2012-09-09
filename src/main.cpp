#include <QtGui/QApplication>

#include <QDebug>

#include "Config.hpp"

#include "DatabaseEditor.hpp"
#include "SongbookEditor.hpp"
#include "SongEditor.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QIcon::setThemeName("FreshFarm");

    Config config(argc, argv);

    DatabaseEditor databaseEditor(&config);
    SongEditor songEditor(&config);
    SongbookEditor songbookEditor(&config);

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
            songEditor.openSong(QString::fromLocal8Bit(argv[2]));
        }
    }
    else if(arg == "--songbook-editor")
    {
        songbookEditor.show();

        if(argc > 2)
        {
            songbookEditor.openSongbook(QString::fromLocal8Bit(argv[2]));
        }
    }
    else
    {
        databaseEditor.show();
    }

    qDebug() << "tu";
    return app.exec();
}
