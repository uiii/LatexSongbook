#include <QtGui/QApplication>
#include "SongEditor.hpp"

#include <QFileInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SongEditor w;

    if(argc > 1)
    {
        w.openSong(argv[1]);
    }

    w.show();

    return a.exec();
}
