#include <QtGui/QApplication>
#include "LatexSongbook.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LatexSongbook w;

    QString arg;
    if(argc > 1)
    {
        arg = argv[1];
    }

    if(arg == "--song-editor")
    {
        w.openSongEditor();
    }
    else if(arg == "--songbook-editor")
    {
        w.openSongbookEditor();
    }
    else if(arg == "--song-database")
    {
        // TODO
    }
    else
    {
        w.show();
    }

    return a.exec();
}
