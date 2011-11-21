#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileInfo>
#include <QFileDialog>
#include <QTextStream>
#include <QCloseEvent>
#include <QMessageBox>

#include <iostream>
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    unsaved_(false),
    instrumentSettings_(new InstrumentSettings())
{
    ui->setupUi(this);

    songbook_.setInstrumentSettings(instrumentSettings_);

    connect(ui->actionNew, SIGNAL(activated()), this, SLOT(newSongbook()));
    connect(ui->actionOpen, SIGNAL(activated()), this, SLOT(loadSongbook()));
    connect(ui->actionAdd_song, SIGNAL(activated()), this, SLOT(addSong()));
    connect(ui->actionSave, SIGNAL(activated()), this, SLOT(saveSongbook()));
    connect(ui->actionSave_As, SIGNAL(activated()), this, SLOT(saveAsSongbook()));
    connect(ui->actionInstrument_settings, SIGNAL(activated()), instrumentSettings_, SLOT(show()));

    connect(instrumentSettings_, SIGNAL(saved()), &songbook_, SLOT(updateInstrument()));

    //SongbookSituation situation = songbook_.currentSituation();
    eventsModel_.setDataSource(&songbook_.events());
    newSongsModel_.setDataSource(&songbook_.unfiledSongs());
    allSongsModel_.setDataSource(&songbook_.songs());

    ui->eventsView->setModel(&eventsModel_);
    ui->newSongsView->setModel(&newSongsModel_);
    ui->allSongsView->setModel(&allSongsModel_);

    selectNow();

    connect(&songbook_, SIGNAL(eventsChanged()), &eventsModel_, SLOT(update()));
    connect(&songbook_, SIGNAL(eventsChanged()), this, SLOT(selectNow()));
    connect(&songbook_, SIGNAL(unfiledChanged()), &newSongsModel_, SLOT(update()));
    connect(&songbook_, SIGNAL(filedChanged()), &allSongsModel_, SLOT(update()));
    connect(&songbook_, SIGNAL(instrumentChanged(QString)), ui->instrumentLabel, SLOT(setText(QString)));
    connect(&songbook_, SIGNAL(instrumentChanged(QString)), this, SLOT(setAsUnsaved()));
    connect(&songbook_, SIGNAL(sizeChanged()), this, SLOT(setAsUnsaved()));

    connect(&songbook_, SIGNAL(filedChanged()), this, SLOT(setAsUnsaved()));

    paperSizes_ << "A4" << "A5" << "B5" << "Letter" << "Legal" << "Executive";
    fontSizes_ << "9pt" << "10pt" << "11pt" << "12pt" << "14pt";
    recommendedFontSizes_ << "12pt" << "11pt" << "11pt" << "12pt" << "12pt" << "12pt";

    ui->paperSize->addItems(paperSizes_);
    ui->fontSize->addItems(fontSizes_);

    setRecommendedFontSize_(ui->paperSize->currentIndex());

    connect(ui->paperSize, SIGNAL(currentIndexChanged(QString)), &songbook_, SLOT(setPaperSize(QString)));
    connect(ui->paperSize, SIGNAL(currentIndexChanged(int)), this, SLOT(setRecommendedFontSize_(int)));
    connect(ui->fontSize, SIGNAL(currentIndexChanged(QString)), &songbook_, SLOT(setFontSize(QString)));

    connect(ui->eventsView->selectionModel(), SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(changeTime(QItemSelection,QItemSelection)));

    connect(ui->fileUnfiledButton, SIGNAL(clicked()), this, SLOT(fileUnfiled()));

    updateTitle();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadSongbook()
{
    newSongbook();

    QString songbookFile = QFileDialog::getOpenFileName(this, "Open songbook", getenv("HOME"), tr("Songbook files *.lsb (*.lsb)"));

    if(! songbookFile.isNull())
    {
        if(songbook_.load(songbookFile))
        {
            songbookFile_ = songbookFile;
            setAsSaved();
        }
    }
}

void MainWindow::addSong()
{
    //QStringList fileList = QFileDialog::getOpenFileNames(this, "Add songs", getenv("HOME"), tr("Songs (*.*)"));
    QStringList fileList = QFileDialog::getOpenFileNames(this, "Add songs", "/mnt/uloziste/Pracoviste/Projekty/zpevnik", tr("Songs (*.*)"));

    songbook_.addSongs(fileList);

    eventsModel_.highlightNow(true);
    selectNow();
}

void MainWindow::selectNow()
{
    QModelIndex index = eventsModel_.index(eventsModel_.rowCount(QModelIndex()) - 1);
    ui->eventsView->setCurrentIndex(index);
}

void MainWindow::changeTime(const QItemSelection& selected, const QItemSelection&)
{
    QModelIndex index = selected.indexes().at(0);

    std::time_t time = eventsModel_.rawData(index);

    if(time)
    {
        newSongsModel_.setFilter(new SongPropertyFilter< SongProperty<std::time_t>, Equal<std::time_t> >(&Song::fileTime, time));
        newSongsModel_.setDataSource(&songbook_.songs());

        allSongsModel_.setFilter(new SongPropertyFilter< SongProperty<std::time_t>, LessThenOrEqual<std::time_t> >(&Song::fileTime, time));
        allSongsModel_.setDataSource(&songbook_.songs());

        ui->newSongsBox->setTitle(QString("New songs (") + eventsModel_.data(index, Qt::DisplayRole).toString() + QString(")"));
        ui->songbookBox->setTitle(QString("Songbook (") + eventsModel_.data(index, Qt::DisplayRole).toString() + QString(")"));
    }
    else
    {
        newSongsModel_.setFilter(new NoFilter());
        newSongsModel_.setDataSource(&songbook_.unfiledSongs());

        allSongsModel_.setFilter(new NoFilter());
        allSongsModel_.setDataSource(&songbook_.songs());

        ui->newSongsBox->setTitle(QString("New songs"));
        ui->songbookBox->setTitle(QString("Songbook"));
    }
}

void MainWindow::fileUnfiled()
{
    if(songbook_.fileUnfiled())
    {
        QModelIndex index = eventsModel_.index(eventsModel_.rowCount(QModelIndex()) - 2);
        ui->eventsView->setCurrentIndex(index);
    }

    eventsModel_.highlightNow(false);
}

void MainWindow::saveSongbook()
{
    if(songbookFile_ == "")
    {
        saveAsSongbook();
    }
    else
    {
        saveSongbook_(songbookFile_);
    }
}

void MainWindow::saveAsSongbook()
{
    QString songbookFile = QFileDialog::getSaveFileName(this, "Save songbook", getenv("HOME"), tr("Songbook files *.lsb (*.lsb)"));

    saveSongbook_(songbookFile);
}

void MainWindow::saveSongbook_(const QString& songbookFile)
{
    if(songbookFile != "")
    {
        if(songbook_.save(songbookFile))
        {
            songbookFile_ = songbookFile;
            setAsSaved();
        }
    }
}

void MainWindow::updateTitle()
{
    QString title;
    QTextStream titleStream(&title);

    QString fileName;
    QString fileDir;
    if(songbookFile_ != "")
    {
        QFileInfo info(songbookFile_);

        fileName = info.fileName();
        fileDir = info.absolutePath();
    }
    else
    {
        fileName = "[No name]";
        fileDir = "";
    }

    if(unsaved_)
    {
        titleStream << "* ";
    }

    titleStream << fileName;

    if(fileDir != "")
    {
        titleStream << " (" << fileDir << ")";
    }

    titleStream << " - Latex songbook";

    setWindowTitle(title);
}

void MainWindow::setAsUnsaved()
{
    unsaved_ = true;

    updateTitle();
}

void MainWindow::setAsSaved()
{
    unsaved_ = false;

    updateTitle();
}

void MainWindow::newSongbook()
{
    maybeSave_();
    songbook_.clear();
    songbookFile_ = "";
    setAsSaved();
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if(maybeSave_())
    {
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

bool MainWindow::maybeSave_()
{
    if(unsaved_)
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Songbook has changed!"));
        msgBox.setInformativeText(tr("Do you want to save the songbook?"));
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Discard);

        int ret = msgBox.exec();

        switch(ret)
        {
            case QMessageBox::Save:
                saveSongbook();
                return true;
            break;
            case QMessageBox::Discard:
                return true;
            break;
            case QMessageBox::Cancel:
                return false;
            break;
            default:
                return false;
            break;
        }
    }

    return true;
}

void MainWindow::setRecommendedFontSize_(int index)
{
    QString recommendedSize = recommendedFontSizes_.at(index);

    ui->fontSize->setCurrentIndex(fontSizes_.indexOf(recommendedSize));
    ui->recommendedSize->setText(recommendedSize);
}
