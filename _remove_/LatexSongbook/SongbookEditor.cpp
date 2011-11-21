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

SongbookEditor::SongbookEditor(QWidget *parent) :
    QMainWindow(parent),
    isSaved_(true),
    fileFilter_(tr("Song (*)")),
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
        // TODO
        songbookFileName_ = QString();

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

    /*QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return; // TODO error
    }

    QString data = file.readAll();

    file.close();

    if(continueIfUnsaved())
    {
        ui_->songEdit->setPlainText(data);
        songbookFileName_ = fileName;

        setAsSaved(true);
        updateWindowTitle();
    }*/
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

    if(songbookFileName_.isEmpty())
    {
        stream << tr("[No name]");
    }
    else
    {
        stream << QFileInfo(songbookFileName_).fileName();
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
        event->accept();
    }
    else
    {
        event->ignore();
    }
}
