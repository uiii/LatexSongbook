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
#include <QFileDialog>

#include "InputPathDialog.hpp"
#include "GeneratorSettings.hpp" // TODO remove

DatabaseEditor::DatabaseEditor(Config* config, QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::DatabaseEditor),
    config_(config)
{
    ui_->setupUi(this);

    QList<QPair<QAction*, QString> > actionIcons;
    actionIcons
        << qMakePair(ui_->actionNewSong, QString("song-new"))
        << qMakePair(ui_->actionNewSongbook, QString("songbook"))
        << qMakePair(ui_->actionReload, QString("database-reload"))
        << qMakePair(ui_->actionExit, QString("application-exit"));

    for(auto& actionIcon: actionIcons)
    {
        actionIcon.first->setIcon(QIcon::fromTheme(actionIcon.second));
    }

    settingsDialog_ = new SettingsDialog(this);
    settingsDialog_->addSettings(new GeneratorSettings()); // TODO remove

    model_ = new LocalDatabaseModel();

    sortModel_ = new QSortFilterProxyModel();
    sortModel_->setSortLocaleAware(true);
    sortModel_->setSortRole(Qt::UserRole + 1);
    sortModel_->setSourceModel(model_);

    ui_->songs->setModel(sortModel_);

    ui_->songs->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
    ui_->songs->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
    ui_->songs->horizontalHeader()->setResizeMode(2, QHeaderView::Stretch);
    ui_->songs->horizontalHeader()->setResizeMode(3, QHeaderView::Stretch);

    connect(model_, SIGNAL(invalidDirectory()), this, SLOT(setDatabaseDirectory_()), Qt::QueuedConnection);
    connect(model_, SIGNAL(songsReloaded()), this, SLOT(updateSorting_()));
    connect(this, SIGNAL(showed()), this, SLOT(setDatabaseDirectory_()), Qt::QueuedConnection);

    connect(ui_->songs, SIGNAL(activated(QModelIndex)), this, SLOT(openSong_(QModelIndex)));
    connect(ui_->songs->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(selectionChanged_()));

    connect(ui_->actionSettings, SIGNAL(triggered()), settingsDialog_, SLOT(exec()));

    connect(ui_->actionNewSong, SIGNAL(triggered()), this, SLOT(newSong_()));
    connect(ui_->actionEditSong, SIGNAL(triggered()), this, SLOT(editSong_()));
    connect(ui_->actionDeleteSongs, SIGNAL(triggered()), this, SLOT(deleteSongs_()));

    connect(ui_->actionNewSongbook, SIGNAL(triggered()), this, SLOT(newSongbook_()));

    connect(ui_->actionReload, SIGNAL(triggered()), model_, SLOT(reloadSongs()));

    ui_->splitter->setStretchFactor(0, 3);
    ui_->splitter->setStretchFactor(1, 1);
}

DatabaseEditor::~DatabaseEditor()
{
    delete ui_;
}

void DatabaseEditor::showEvent(QShowEvent* event)
{
    QMainWindow::showEvent(event);

    emit showed();
}

void DatabaseEditor::setDatabaseDirectory_()
{
    QString databaseDirectory = config_->value<QString>("DatabaseEditor/DatabaseDirectory");
    while(! QFileInfo(databaseDirectory).isDir())
    {
        databaseDirectory = InputPathDialog::getDirectory(this,
            "Set database directory",
            "Database directory is not set, or is not valid. Please type in the correct one.",
            databaseDirectory
        );

        if(databaseDirectory.isNull())
        {
            break;
        }
    }

    if(databaseDirectory.isNull())
    {
        int result = QMessageBox::question(this,
            "Temporary database directory",
            "Do you want to set the database directory as temporary directory? "
                "\n(Warning: This directory may be removed after reboot.)\nPress 'No' to quit application.",
            QMessageBox::Yes | QMessageBox::No);

        if(result == QMessageBox::Yes)
        {
            QDir::temp().mkdir("LatexSongbookDatabase");
            databaseDirectory = QDir::temp().absoluteFilePath("LatexSongbookDatabase");
        }
        else
        {
            close();
            return;
        }
    }
    else
    {
        config_->setValue("DatabaseEditor/DatabaseDirectory", databaseDirectory);
    }

    model_->setDirectory(databaseDirectory);
}

void DatabaseEditor::updateSorting_()
{
    int sortColumn = sortModel_->sortColumn();
    if(sortColumn < 0)
    {
        sortColumn = 0;
    }

    ui_->songs->sortByColumn(sortColumn, Qt::AscendingOrder);
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

void DatabaseEditor::newSongbook_()
{
    QProcess::startDetached(config_->selfAppPath(), QStringList() << "--songbook-editor");
}

void DatabaseEditor::openSong_(const QModelIndex& index)
{
    SongInfo info = model_->songInfo(sortModel_->mapToSource(index));

    QProcess::startDetached(config_->selfAppPath(), QStringList() << "--song-editor" << QString("%1").arg(info.file.absoluteFilePath()));
}

void DatabaseEditor::selectionChanged_()
{
    QModelIndexList indexes = ui_->songs->selectionModel()->selectedRows();

    ui_->actionEditSong->setEnabled(indexes.count() == 1);
    ui_->actionDeleteSongs->setEnabled(indexes.count() > 0);
}
