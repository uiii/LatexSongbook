#include "songmanager.h"
#include "ui_songmanager.h"

SongManager::SongManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SongManager)
{
    ui->setupUi(this);
}

SongManager::~SongManager()
{
    delete ui;
}
