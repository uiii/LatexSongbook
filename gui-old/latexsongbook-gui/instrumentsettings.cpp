#include "instrumentsettings.h"
#include "ui_instrumentsettings.h"

#include <QDir>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QRegExp>
#include <QFont>
#include <QFileDialog>
#include <QMessageBox>
#include <QAbstractButton>

#include <iostream>
#include <stdexcept>

InstrumentSettings::InstrumentSettings(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstrumentSettings),
    noInstrument_(new Instrument),
    unsaved_(false)
{
    currentInstrument_ = noInstrument_;

    ui->setupUi(this);

    loadInstruments_();

    //instrumentModel_.setDataSource(&instruments_);

    //ui->instruments->setModel(&instrumentModel_);

    connect(ui->instruments, SIGNAL(currentIndexChanged(int)), this, SLOT(instrumentChanged_(int)));
    connect(ui->browseImage, SIGNAL(clicked()), this, SLOT(browseImage_()));

    connect(ui->controlButtons, SIGNAL(clicked(QAbstractButton*)), this, SLOT(controlButtonClicked_(QAbstractButton*)));
}

InstrumentSettings::~InstrumentSettings()
{
    delete ui;
}

void InstrumentSettings::showEvent(QShowEvent *)
{
    loadInstruments_();
    updateInstrumentComboBox_();
}

void InstrumentSettings::loadInstruments_()
{
    QString currentInstrumentName = currentInstrument_->name();

    QString path = QDir::homePath() + "/.latexSongbook/instruments";

    QDir instrumentDir(path);
    if(! instrumentDir.exists())
    {
        if(! instrumentDir.mkpath(path))
        {
            QString error = QString("Cannot create '") + path + QString("' directory");
            throw std::runtime_error(error.toAscii().data());
        }
    }

    for(auto it = instruments_.begin(); it != instruments_.end(); ++it)
    {
        delete *it;
    }
    instruments_.clear();

    QStringList fileList = instrumentDir.entryList();
    for(auto it = fileList.begin(); it != fileList.end(); ++it)
    {
        if(*it == "." || *it == "..")
        {
            continue;
        }

        QString filePath = path + "/" + *it;

        QFile instrumentFile(filePath);

        if(!instrumentFile.open(QIODevice::ReadOnly | QIODevice::Text))
            return; // TODO chybova hlaska

        QTextStream instrumentStream(&instrumentFile);

        QString instrumentContent = instrumentStream.readAll();

        QRegExp instrumentSyntax(
                    "name:[ \\t]*(\\w+)\\n"
                    "image:[ \\t]*(|\\S.*)\\n"
                    "stringsCount:[ \\t]*(\\d+)\\n"
                    "reportUnknownChords:[ \\t]*(true|false)\\n"
                    "chordsDef:(|\\n.*)"
        );

        if(! instrumentSyntax.exactMatch(instrumentContent))
        {
            QString error = filePath + ": Invalid instrument file " + QString::number(instrumentSyntax.matchedLength());
            throw std::runtime_error(error.toAscii().data());
        }

        QString name = instrumentSyntax.cap(1);
        QString imageFile = instrumentSyntax.cap(2);
        QString stringsCount = instrumentSyntax.cap(3);
        QString reportUnknownChords = instrumentSyntax.cap(4);
        QString chordsDef = instrumentSyntax.cap(5);

        QStringList chordList;
        QTextStream chordsDefStream(&chordsDef);
        while(! chordsDefStream.atEnd())
        {
            QString line = chordsDefStream.readLine();

            if(QRegExp("\\s*").exactMatch(line))
            {
                continue;
            }

            /*QRegExp chordReg(QString(
                    ".+:[ \t]*\\[(t|[1-9]+)\\]\\[(x,|n,|[1-9]+,){"
                    + QString::number(stringsCount.toInt() - 1)
                    + "}(x|n|[1-9]+)\\]")); //{") + stringsCount + QString("}\\]"));*/

            QRegExp chordReg(QString(".+:[ \t]*\\[(t|[1-9]+)\\]\\[(x,|n,|[1-9]+,)*(x|n|[1-9]+)\\]"));
            if(! chordReg.exactMatch(line))
            {
                QString error = filePath + ": Invalid chord definition(" + QString::number(chordReg.matchedLength()) + "): '" + line + "'";
                throw std::runtime_error(error.toAscii().data());
            }

            chordList.push_back(line);
        }

        Instrument* instrument = new Instrument(filePath, name, imageFile, stringsCount.toInt(), chordList.join("\n"), (reportUnknownChords == "true"));
        connect(instrument, SIGNAL(changed()), this, SLOT(setUnsaved_()));
        instruments_.push_back(instrument);

        instrumentFile.close();
    }

    setCurrentInstrument(currentInstrumentName);
}

void InstrumentSettings::updateInstrumentComboBox_()
{
    int index = instruments_.indexOf(currentInstrument_) + 1;

    ui->instruments->clear();
    ui->instruments->addItem(tr("-- No instrument selected --"));

    for(auto it = instruments_.begin(); it != instruments_.end(); ++it)
    {
        ui->instruments->addItem((*it)->name());
    }

    ui->instruments->setCurrentIndex(index);
}

void InstrumentSettings::chordsDefChanged_()
{
    currentInstrument_->setChordsDef(ui->chordsEdit->toPlainText());
}

void InstrumentSettings::browseImage_()
{
    QString imageFile = QFileDialog::getOpenFileName(this, "Browse image", getenv("HOME"), tr("Images *.jpg, *.png (*.jpg; *.png)"));

    if(imageFile != "")
    {
        ui->image->setPixmap(QPixmap(imageFile));

        emit imageLoaded(imageFile);
    }
}

void InstrumentSettings::instrumentChanged_(int index)
{
    ui->nameEdit->disconnect();
    disconnect(currentInstrument_);
    ui->stringsCount->disconnect();
    ui->chordsEdit->disconnect();
    ui->reportUnknowChords->disconnect();

    clearAll_();

    if(index < 0)
    {
        return;
    }
    else if(index == 0)
    {
        currentInstrument_ = noInstrument_;

        disableAll_();
    }
    else
    {
        std::cout << index - 1 << std::endl;
        currentInstrument_ = instruments_.at(index - 1);

        enableAll_();

        ui->nameEdit->setText(currentInstrument_->name());
        std::cout << "image: " << currentInstrument_->imageFile().toAscii().data() << std::endl;
        ui->image->setPixmap(QPixmap(currentInstrument_->imageFile()));
        ui->stringsCount->setValue(currentInstrument_->stringsCount());
        ui->chordsEdit->setPlainText(currentInstrument_->chordsDef());
        ui->reportUnknowChords->setChecked(currentInstrument_->reportUnknownChords());

        connect(ui->nameEdit, SIGNAL(textChanged(QString)), currentInstrument_, SLOT(setName(QString)));
        connect(this, SIGNAL(imageLoaded(QString)), currentInstrument_, SLOT(setImageFile(QString)));
        connect(ui->stringsCount, SIGNAL(valueChanged(int)), currentInstrument_, SLOT(setStringsCount(int)));
        connect(ui->chordsEdit, SIGNAL(textChanged()), this, SLOT(chordsDefChanged_()));
        connect(ui->reportUnknowChords, SIGNAL(toggled(bool)), currentInstrument_, SLOT(setReportUnknownChords(bool)));
    }
}

void InstrumentSettings::clearAll_()
{
    ui->nameEdit->clear();
    ui->image->clear();
    ui->chordsEdit->clear();
    ui->stringsCount->setValue(0);
    ui->reportUnknowChords->setChecked(true);
}

void InstrumentSettings::enableAll_()
{
    ui->deleteInstrument->setEnabled(true);
    ui->nameEdit->setEnabled(true);
    ui->image->setEnabled(true);
    ui->browseImage->setEnabled(true);
    ui->removeImage->setEnabled(true);
    ui->stringsCount->setEnabled(true);
    ui->chordsEdit->setEnabled(true);
    ui->reportUnknowChords->setEnabled(true);
}

void InstrumentSettings::disableAll_()
{
    ui->deleteInstrument->setEnabled(false);
    ui->nameEdit->setEnabled(false);
    ui->image->setEnabled(false);
    ui->browseImage->setEnabled(false);
    ui->removeImage->setEnabled(false);
    ui->stringsCount->setEnabled(false);
    ui->chordsEdit->setEnabled(false);
    ui->reportUnknowChords->setEnabled(false);
}

void InstrumentSettings::controlButtonClicked_(QAbstractButton* button)
{
    QDialogButtonBox::ButtonRole role = ui->controlButtons->buttonRole(button);

    switch(role)
    {
        case QDialogButtonBox::AcceptRole:
            save_();
            hide();
        break;
        case QDialogButtonBox::ApplyRole:
            save_();
        break;
        case QDialogButtonBox::RejectRole:
            if(maybeSave_())
            {
                hide();
            }
        break;
        default:
        break;
    }
}

void InstrumentSettings::save_()
{
    for(auto it = instruments_.begin(); it != instruments_.end(); ++it)
    {
        try
        {
            (*it)->save();
        }
        catch(const std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    unsaved_ = false;

    updateInstrumentComboBox_();

    emit saved();
}

bool InstrumentSettings::maybeSave_()
{
    if(unsaved_)
    {
        QMessageBox msgBox;
        msgBox.setText(tr("Instrument settings have changed!"));
        msgBox.setInformativeText(tr("Do you want to save these changes?"));
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Discard);

        int ret = msgBox.exec();

        switch(ret)
        {
            case QMessageBox::Save:
                save_();
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

void InstrumentSettings::setUnsaved_()
{
    unsaved_ = true;
}

Instrument * InstrumentSettings::currentInstrument()
{
    if(currentInstrument_ == noInstrument_)
    {
        return 0;
    }
    else
    {
        return currentInstrument_;
    }
}

bool InstrumentSettings::setCurrentInstrument(const QString& instrumentName)
{
    if(instrumentName == "")
    {
        currentInstrument_ = noInstrument_;
        return true;
    }

    bool set = false;
    for(auto it = instruments_.begin(); (it != instruments_.end()) && (set == false); ++it)
    {
        if(instrumentName == (*it)->name())
        {
            currentInstrument_ = *it;
            set = true;
        }
    }

    if(set == false)
    {
        currentInstrument_ == noInstrument_;
        return false;
    }
    else
    {
        return true;
    }
}
