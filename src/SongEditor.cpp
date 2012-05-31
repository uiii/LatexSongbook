#include "SongEditor.hpp"
#include "ui_SongEditor.h"

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

SongEditor::SongEditor(QWidget *parent) :
    QMainWindow(parent),
    isSaved_(true),
    fileFilter_(tr("Song (*)")),
    lastAccessedDir_(QDir::homePath()),
    ui_(new Ui::SongEditor)
{
    ui_->setupUi(this);

    document_ = ui_->songEdit->document();

    ui_->actionShow_preview->trigger(); // TODO docasne
    ui_->actionShow_preview->setEnabled(false); // TODO docasne

    QList<QPair<QAction*, QString> > actionIcons;
    actionIcons
        << qMakePair(ui_->actionNew, QString("document-new"))
        << qMakePair(ui_->actionOpen, QString("document-open"))
        << qMakePair(ui_->actionSave, QString("document-save"))
        << qMakePair(ui_->actionSaveAs, QString("document-save-as"))
        << qMakePair(ui_->actionShow_preview, QString("document-print-preview"))

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

    connect(ui_->actionNew, SIGNAL(activated()), this, SLOT(newSong()));
    connect(ui_->actionOpen, SIGNAL(activated()), this, SLOT(openSong()));
    connect(ui_->actionSave, SIGNAL(activated()), this, SLOT(saveSong()));
    connect(ui_->actionSaveAs, SIGNAL(activated()), this, SLOT(saveAsSong()));

    connect(document_, SIGNAL(contentsChanged()), this, SLOT(updateSongState()));
    //connect(document_, SIGNAL(modificationChanged(bool)), this, SLOT(updateSongState()));

    newSong();
}

SongEditor::~SongEditor()
{
    delete ui_;
}

void SongEditor::newSong()
{
    if(continueIfUnsaved())
    {
        ui_->songEdit->clear();
        songFileName_ = QString();

        setAsSaved(true);
        updateWindowTitle();
    }
}

void SongEditor::openSong(QString fileName)
{
    if(fileName.isEmpty())
    {
        fileName = QFileDialog::getOpenFileName(this, tr("Open song"), lastAccessedDir_, fileFilter_);

        if(fileName.isEmpty())
        {
            return;
        }

        lastAccessedDir_ = QFileInfo(fileName).absolutePath();
    }

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return; // TODO error
    }

    QString data = file.readAll();

    file.close();

    if(continueIfUnsaved())
    {
        ui_->songEdit->setPlainText(data);
        songFileName_ = fileName;

        setAsSaved(true);
        updateWindowTitle();
    }
}

bool SongEditor::saveSong()
{
    return saveAsSong(songFileName_);
}

bool SongEditor::saveAsSong(QString fileName)
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

    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return false; // TODO error
    }

    QTextStream stream(&file);
    stream << ui_->songEdit->toPlainText();

    file.close();

    songFileName_ = fileName;

    setAsSaved(true);
    updateWindowTitle();

    return true;
}

void SongEditor::setAsSaved(bool isSaved)
{
    document_->setModified(! isSaved);
    isSaved_ = isSaved;
}

void SongEditor::updateSongState()
{
    isSaved_ = ! document_->isModified();

    ui_->actionUndo->setEnabled(document_->isUndoAvailable());
    ui_->actionRedo->setEnabled(document_->isRedoAvailable());

    updateWindowTitle();
}

void SongEditor::updateWindowTitle()
{
    QString title;
    QTextStream stream(&title);

    if(! isSaved_)
    {
        stream << "* ";
    }

    if(songFileName_.isEmpty())
    {
        stream << tr("[No name]");
    }
    else
    {
        stream << QFileInfo(songFileName_).fileName();
    }

    stream << " - Song Editor | LatexSongbook";

    setWindowTitle(title);
}

bool SongEditor::continueIfUnsaved()
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
            return saveSong();
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

void SongEditor::closeEvent(QCloseEvent *event)
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