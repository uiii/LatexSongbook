#include "SongEditor.hpp"
#include "ui_SongEditorWindow.h"

#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QTextStream>
#include <QIcon>
#include <QList>
#include <QPair>
#include <QAction>
#include <QDebug>

SongEditor::SongEditor(QWidget *parent) :
    QMainWindow(parent),
    isUnsaved_(false),
    fileFilter_(tr("Song (*)")),
    ui_(new Ui::SongEditorWindow)
{
    ui_->setupUi(this);

    //ui_->actionShow_preview->trigger(); // TODO docasne
    //ui_->actionShow_preview->setEnabled(false); // TODO docasne

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

    newSong();
}

SongEditor::~SongEditor()
{
    delete ui_;
}

void SongEditor::newSong()
{
    songFileName_ = QString();
    ui_->songEdit->clear();

    updateWindowTitle();

    isUnsaved_ = false;
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

    ui_->songEdit->setPlainText(data);

    songFileName_ = fileName;

    updateWindowTitle();

    isUnsaved_ = false;
}

void SongEditor::saveSong()
{
    saveAsSong(songFileName_);
}

void SongEditor::saveAsSong(QString fileName)
{
    if(fileName.isEmpty())
    {
        fileName = QFileDialog::getSaveFileName(this, tr("Save song as ..."), lastAccessedDir_, fileFilter_);

        if(fileName.isEmpty())
        {
            return;
        }

        lastAccessedDir_ = QFileInfo(fileName).absolutePath();
    }

    QFile file(fileName);

    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return; // TODO error
    }

    QTextStream stream(&file);
    stream << ui_->songEdit->toPlainText();

    file.close();

    songFileName_ = fileName;

    updateWindowTitle();

    isUnsaved_ = false;
}

void SongEditor::updateWindowTitle()
{
    QString title;
    QTextStream stream(&title);

    if(isUnsaved_)
    {
        stream << "* ";
    }

    if(songFileName_.isEmpty())
    {
        stream << "[No name]";
    }
    else
    {
        stream << QFileInfo(songFileName_).fileName();
    }

    stream << " - Song Editor | LatexSongbook";

    setWindowTitle(title);
}
