#include "DatabaseEditor.hpp"
#include "ui_DatabaseEditor.hpp"

#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QString>
#include <QProcess>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include <QInputDialog>

DatabaseEditor::DatabaseEditor(Config* config, QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::DatabaseEditor),
    config_(config)
{
    ui_->setupUi(this);

    if(! QFileInfo(QDir::homePath() + "/.latexsongbook").exists())
    {
        if(! QDir::home().mkdir(".latexsongbook"))
        {
            throw; // TODO
        }
    }

    //QString databaseDir = "/mnt/uloziste/Pracoviste/Projekty/LatexSongbook/tmp/database";
    QString databaseDir = config_->value<QString>("DatabaseEditor/DatabaseDir");
    bool ok = true;
    while(ok && ! QFileInfo(databaseDir).isDir())
    {
        databaseDir = QInputDialog::getText(this,
            "Set database directory",
            "Database directory is not set, or is not valid. Please type in the correct one.",
            QLineEdit::Normal,
            databaseDir,
            &ok);
    }

    if(ok)
    {
        config_->setValue("DatabaseEditor/DatabaseDir", databaseDir);
    }
    else
    {
        int result = QMessageBox::question(this,
            "Temporary database directory",
            "Do you want to set the database directory as temporary directory?"
                "(Warning: This directory may be removed after reboot.)",
            QMessageBox::Yes | QMessageBox::No);

        if(result == QMessageBox::Yes)
        {
            QDir::temp().mkdir("LatexSongbookDatabase");
            databaseDir = QDir::temp().absoluteFilePath("LatexSongbookDatabase");
        }
        else
        {
            qApp->quit();
        }
    }

    model_ = new LocalDatabaseModel(databaseDir);

    QSortFilterProxyModel* sortProxyModel = new QSortFilterProxyModel();
    sortProxyModel->setSortLocaleAware(true);
    sortProxyModel->setSortRole(Qt::UserRole + 1);
    sortProxyModel->setSourceModel(model_);

    ui_->songs->setModel(sortProxyModel);

    ui_->songs->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
    ui_->songs->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
    ui_->songs->horizontalHeader()->setResizeMode(2, QHeaderView::Stretch);
    ui_->songs->horizontalHeader()->setResizeMode(3, QHeaderView::Stretch);

    connect(ui_->actionNewSong, SIGNAL(triggered()), this, SLOT(newSong_()));
    connect(ui_->actionEditSong, SIGNAL(triggered()), this, SLOT(editSong_()));
    connect(ui_->actionDeleteSongs, SIGNAL(triggered()), this, SLOT(deleteSongs_()));

    connect(ui_->songs, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(openSong_(QModelIndex)));
    connect(ui_->songs->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(selectionChanged_()));

    connect(ui_->actionReload, SIGNAL(triggered()), model_, SLOT(reloadSongs()));
}

DatabaseEditor::~DatabaseEditor()
{
    delete ui_;
}

void DatabaseEditor::newSong_()
{
    QProcess::startDetached(config_->selfAppPath(), QStringList() << "--song-editor");
}

void DatabaseEditor::editSong_()
{
    QModelIndexList indexes = ui_->songs->selectionModel()->selectedRows();

    if(! indexes.isEmpty())
    {
        openSong_(indexes.front());
    }
}

void DatabaseEditor::deleteSongs_()
{
    QModelIndexList indexes = ui_->songs->selectionModel()->selectedRows();

    int result = QMessageBox::question(this, "Delete song(s)", "Do you really want to delete %1 song(s)?", QMessageBox::Ok | QMessageBox::Cancel);
    if(result == QMessageBox::Ok)
    {
        for(QModelIndex index : indexes)
        {

        }
    }
}

void DatabaseEditor::openSong_(const QModelIndex& index)
{
    SongInfo info = model_->songInfo(index);

    QProcess::startDetached(config_->selfAppPath(), QStringList() << "--song-editor" << info.file.absoluteFilePath());
}

void DatabaseEditor::selectionChanged_()
{
    QModelIndexList indexes = ui_->songs->selectionModel()->selectedRows();

    ui_->actionEditSong->setEnabled(indexes.count() == 1);
    ui_->actionDeleteSongs->setEnabled(indexes.count() > 0);
}
