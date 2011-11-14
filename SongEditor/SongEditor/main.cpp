#include <QtGui/QApplication>
#include "SongEditor.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SongEditor w;
    w.show();

    return a.exec();
}
