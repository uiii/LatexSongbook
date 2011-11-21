#include "SongManager.h"
#include "ui_SongManager.h"

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
