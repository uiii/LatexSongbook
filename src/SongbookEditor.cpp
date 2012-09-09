#include "SongbookEditor.hpp"
#include "ui_SongbookEditor.hpp"

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QTextStream>
#include <QIcon>
#include <QList>
#include <QPair>
#include <QAction>
#include <QDebug>
#include <QTextDocument>
#include <QMessageBox>
#include <QCloseEvent>
#include <QTime>
#include <QPushButton>
#include <QToolButton>

#include "common.hpp"
#include "TarArchive.hpp"
#include "SongImportDialog.hpp"

SongbookEditor::SongbookEditor(Config* config, QWidget *parent):
    QMainWindow(parent),
    config_(config),
    database_(new LocalDatabaseModel),
    isModified_(false),
    //fileFilter_(tr("Songbook (*.lsb)")), // TODO
    lastAccessedDir_(QDir::homePath()),
    ui_(new Ui::SongbookEditor)
{
    ui_->setupUi(this);

    QList<QPair<QAction*, QString> > actionIcons;
    actionIcons
        << qMakePair(ui_->actionNew, QString("songbook"))
        << qMakePair(ui_->actionOpen, QString("document-open"))
        << qMakePair(ui_->actionSave, QString("document-save"))
        << qMakePair(ui_->actionSaveAs, QString("document-save-as"))

        //<< qMakePair(ui_->actionImportSongs, QString("song-add"))

        << qMakePair(ui_->actionUndo, QString("edit-undo"))
        << qMakePair(ui_->actionRedo, QString("edit-redo"))
        << qMakePair(ui_->actionCut, QString("edit-cut"))
        << qMakePair(ui_->actionCopy, QString("edit-copy"))
        << qMakePair(ui_->actionPaste, QString("edit-paste"))

        << qMakePair(ui_->actionExit, QString("application-exit"));

    for(auto& actionIcon: actionIcons)
    {
        actionIcon.first->setIcon(QIcon::fromTheme(actionIcon.second));
    }

    ui_->menuImportSongs->setIcon(QIcon::fromTheme("song-add"));

    QToolButton* importSongsButton = new QToolButton;
    importSongsButton->setMenu(ui_->menuImportSongs);
    importSongsButton->setPopupMode(QToolButton::MenuButtonPopup);
    importSongsButton->setIcon(QIcon::fromTheme("song-add"));
    ui_->toolBar->insertWidget(ui_->actionNew, importSongsButton);
    ui_->toolBar->insertSeparator(ui_->actionNew);

    ui_->songs->setModel(database_);

    ui_->songs->horizontalHeader()->setResizeMode(0, QHeaderView::Stretch);
    ui_->songs->horizontalHeader()->setResizeMode(1, QHeaderView::Stretch);
    ui_->songs->horizontalHeader()->setResizeMode(2, QHeaderView::Stretch);
    ui_->songs->horizontalHeader()->setResizeMode(3, QHeaderView::Stretch);

    connect(importSongsButton, SIGNAL(clicked()), this, SLOT(importFromDatabase_()));
    connect(ui_->actionImportFromFiles, SIGNAL(activated()), this, SLOT(importFromFiles_()));
    connect(ui_->actionImportFromDatabase, SIGNAL(activated()), this, SLOT(importFromDatabase_()));

    connect(ui_->actionNew, SIGNAL(activated()), this, SLOT(newSongbook()));
    connect(ui_->actionOpen, SIGNAL(activated()), this, SLOT(openSongbook()));
    connect(ui_->actionSave, SIGNAL(activated()), this, SLOT(saveSongbook()));
    connect(ui_->actionSaveAs, SIGNAL(activated()), this, SLOT(saveAsSongbook()));

    connect(ui_->actionRedo, SIGNAL(activated()), this, SLOT(saveTarTest())); // TODO - remove
    connect(ui_->actionUndo, SIGNAL(activated()), this, SLOT(extractTarTest())); // TODO - remove

    connect(ui_->title, SIGNAL(textChanged(QString)), this, SLOT(updateWindowTitle()));

    newSongbook();
}

SongbookEditor::~SongbookEditor()
{
    delete ui_;
}

void SongbookEditor::newSongbook()
{
    if(continueIfUnsaved())
    {
        songbookFileName_ = QString();
        removeTmpDir_();

        setAsSaved(true);
        updateEditorState();
    }
}

void SongbookEditor::openSongbook(QString fileName)
{
    if(fileName.isEmpty())
    {
        fileName = QFileDialog::getOpenFileName(this, tr("Open songbook"), lastAccessedDir_, fileFilter_);

        if(fileName.isEmpty())
        {
            return;
        }

        lastAccessedDir_ = QFileInfo(fileName).absolutePath();
    }

    TarArchive archive(fileName);

    if(continueIfUnsaved() && loadSongbookInfo_(archive))
    {
        songbookFileName_ = fileName;
        removeTmpDir_();

        archive.extract(songbookTmpDir_);

        setAsSaved(true);
        updateEditorState();
    }
}

bool SongbookEditor::saveSongbook()
{
    return saveAsSongbook(songbookFileName_);
}

bool SongbookEditor::saveAsSongbook(QString fileName)
{
    if(fileName.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(this, tr("Save song as ..."), lastAccessedDir_, fileFilter_);

        if(fileName.isEmpty())
        {
            return false;
        }

        lastAccessedDir_ = QFileInfo(fileName).absolutePath();
    }

    /*QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return false; // TODO error
    }

    QTextStream stream(&file);
    stream << ui_->songEdit->toPlainText();

    file.close();

    songbookFileName_ = fileName;

    setAsSaved(true);
    updateWindowTitle();*/

    return true;
}

void SongbookEditor::setAsSaved(bool isSaved)
{
    isModified_ = ! isSaved;
}

void SongbookEditor::updateEditorState()
{
    //isSaved_ = ! document_->isModified();

    ui_->actionSave->setEnabled(isModified_);
    //ui_->actionUndo->setEnabled(document_->isUndoAvailable());
    //ui_->actionRedo->setEnabled(document_->isRedoAvailable());

    updateWindowTitle();
}

void SongbookEditor::updateWindowTitle()
{
    QString title;
    QTextStream stream(&title);

    if(isModified_)
    {
        stream << "* ";
    }

    if(ui_->title->text().isEmpty())
    {
        stream << tr("[No name]");
    }
    else
    {
        stream << ui_->title->text();
    }

    if(! songbookFileName_.isEmpty())
    {
        stream << " (" <<  QFileInfo(songbookFileName_).fileName() << ")";
    }

    stream << " - Songbook Editor | LatexSongbook";

    setWindowTitle(title);
}

bool SongbookEditor::continueIfUnsaved()
{
    if(! isModified_)
    {
        return true;
    }

    QMessageBox saveQuestion;
    saveQuestion.setText(tr("The song has been modified."));
    saveQuestion.setInformativeText("Do you want to save changes?");
    saveQuestion.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    saveQuestion.setDefaultButton(QMessageBox::Save);

    switch(saveQuestion.exec())
    {
        case QMessageBox::Save:
            return saveSongbook();
        break;
        case QMessageBox::Discard:
            return true;
        break;
        case QMessageBox::Cancel:
        default:
            return false;
        break;
    }
}

void SongbookEditor::closeEvent(QCloseEvent *event)
{
    if(continueIfUnsaved())
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

void SongbookEditor::saveTarTest()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save TAR as ..."), lastAccessedDir_, fileFilter_);

    TarArchive archive(fileName);
    archive.addFile(TarFile("a", "ahoj"));
    archive.addFile(TarFile("b", "nazdar"));
    archive.addFile(TarFile("c", "cus"));
    archive.pack();
}

void SongbookEditor::extractTarTest()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save TAR as ..."), lastAccessedDir_, fileFilter_);

    TarArchive archive(fileName);
    archive.extract(QFileInfo(fileName).path());
}

void SongbookEditor::importFromFiles_()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this, "Import songs", "."); // TODO

    if(! fileNames.isEmpty())
    {
        makeTmpDir_();

        for(QString fileName : fileNames)
        {
            QFile file(fileName);
            bool res = file.copy(QDir(songbookTmpDir_).filePath(QFileInfo(file).fileName()));
            qDebug() << QDir(songbookTmpDir_).filePath(QFileInfo(file).fileName());
            qDebug() << res;
        }
    }
}

void SongbookEditor::importFromDatabase_()
{
    SongImportDialog* dialog = new SongImportDialog();
    dialog->exec();
}

void SongbookEditor::makeTmpDir_()
{
    if(songbookTmpDir_.isEmpty())
    {
        qsrand(QTime::currentTime().msec());

        do
        {
            songbookTmpDir_ = QDir::temp().absoluteFilePath(QString("songbook").append(QString::number(qrand() % 1000)));
        } while(QFileInfo(songbookTmpDir_).exists());
    }

    if(! QFileInfo(songbookTmpDir_).exists())
    {
        QDir().mkpath(songbookTmpDir_);
    }

    database_->setDirectory(songbookTmpDir_);
}

void SongbookEditor::removeTmpDir_()
{
    if(! songbookTmpDir_.isEmpty())
    {
        removeDir(QDir(songbookTmpDir_));
        songbookTmpDir_ = QString();
    }
}

bool SongbookEditor::loadSongbookInfo_(const TarArchive& archive)
{
    TarFile infoTarFile;

    const TarArchive::Files& files = archive.files();
    auto it = files.find(".songbookinfo");
    if(it != files.end())
    {
        infoTarFile = *it;
    }

    if(! infoTarFile.isValid())
    {
        // TODO error - bud poskozen nebo invalidni
        return false;
    }

    QTextStream(infoTarFile.content());



    return true;
}
