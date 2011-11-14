#include "SongEditor.hpp"
#include "ui_SongEditor.h"

SongEditor::SongEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SongEditor)
{
    ui->setupUi(this);
}

SongEditor::~SongEditor()
{
    delete ui;
}
