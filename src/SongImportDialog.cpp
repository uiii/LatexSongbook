#include "SongImportDialog.hpp"
#include "ui_SongImportDialog.hpp"

#include <QFileDialog>

SongImportDialog::SongImportDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SongImportDialog)
{
    ui->setupUi(this);
}

SongImportDialog::~SongImportDialog()
{
    delete ui;
}
