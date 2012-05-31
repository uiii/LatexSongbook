#include "SongbookEditor.hpp"
#include "ui_SongbookEditor.h"

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

#include "common.hpp"
#include "TarArchive.hpp"

SongbookEditor::SongbookEditor(QWidget *parent) :
    QMainWindow(parent),
    isSaved_(true),
    fileFilter_(tr("Songbook (*.lsb)")),
    lastAccessedDir_(QDir::homePath()),
    ui_(new Ui::SongbookEditor)
{
    ui_->setupUi(this);

    QList<QPair<QAction*, QString> > actionIcons;
    actionIcons
        << qMakePair(ui_->actionNew, QString("document-new"))
        << qMakePair(ui_->actionOpen, QString("document-open"))
        << qMakePair(ui_->actionSave, QString("document-save"))
        << qMakePair(ui_->actionSaveAs, QString("document-save-as"))

        << qMakePair(ui_->actionUndo, QString("edit-undo"))
        << qMakePair(ui_->actionRedo, QString("edit-redo"))
        << qMakePair(ui_->actionCut, QString("edit-cut"))
        << qMakePair(ui_->actionCopy, QString("edit-copy"))
        << qMakePair(ui_->actionPaste, QString("edit-paste"))

        << qMakePair(ui_->actionExit, QString("application-exit"));

    for(auto& actionIcon: actionIcons)
    {
        if(! QIcon::hasThemeIcon(actionIcon.second))
        {
            QIcon::setThemeName("FreshFarm");
            break;
        }
    }

    for(auto& actionIcon: actionIcons)
    {
        actionIcon.first->setIcon(QIcon::fromTheme(actionIcon.second));
    }

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

        makeTmpDir_();

        setAsSaved(true);
        updateWindowTitle();
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
        songbookTmpDir_ = makeTmpDir_();

        archive.extract(songbookTmpDir_);

        setAsSaved(true);
        updateWindowTitle();
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
    isSaved_ = isSaved;
}

void SongbookEditor::updateSongbookState()
{
    /*isSaved_ = ! document_->isModified();

    ui_->actionUndo->setEnabled(document_->isUndoAvailable());
    ui_->actionRedo->setEnabled(document_->isRedoAvailable());*/

    updateWindowTitle();
}

void SongbookEditor::updateWindowTitle()
{
    QString title;
    QTextStream stream(&title);

    if(! isSaved_)
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
    if(isSaved_)
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
        removeTmpDir_();

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

QString SongbookEditor::makeTmpDir_()
{
    removeTmpDir_();

    std::size_t suffix = 0;
    QDir tmpDir(QDir::temp().filePath("LatexSongbook"));
    if(tmpDir.exists())
    {
        QStringList entryList = tmpDir.entryList(QStringList("songbook*"), QDir::NoFilter, QDir::Name | QDir::Reversed);
        if(! entryList.isEmpty())
        {
            suffix = entryList.first().replace("songbook", "").toInt();
            ++suffix;
        }
    }

    QString songbookTmpDir = QDir::temp().filePath(
        QString("LatexSongbook/songbook").append(QString::number(suffix)));

    QDir().mkpath(songbookTmpDir);

    return songbookTmpDir;
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
