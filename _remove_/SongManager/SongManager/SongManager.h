#ifndef SONGMANAGER_H
#define SONGMANAGER_H

#include <QMainWindow>

namespace Ui {
    class SongManager;
}

class SongManager : public QMainWindow
{
    Q_OBJECT

public:
    explicit SongManager(QWidget *parent = 0);
    ~SongManager();

private:
    Ui::SongManager *ui;
};

#endif // SONGMANAGER_H
