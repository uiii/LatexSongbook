#include <QtGui/QApplication>
#include "songmanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SongManager w;
    w.show();

    return a.exec();
}
