#include "SongbookEditor.hpp"
#include "ui_SongbookEditor.h"

SongbookEditor::SongbookEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SongbookEditor)
{
    ui->setupUi(this);
}

SongbookEditor::~SongbookEditor()
{
    delete ui;
}
