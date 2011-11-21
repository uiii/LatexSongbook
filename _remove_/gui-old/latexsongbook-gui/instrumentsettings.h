#ifndef INSTRUMENTSETTINGS_H
#define INSTRUMENTSETTINGS_H

#include <QWidget>
#include <QList>
#include <QAbstractButton>

#include "common.h"
#include "instrument.h"
#include "instrumentmodel.h"

namespace Ui {
    class InstrumentSettings;
}

class InstrumentSettings : public QWidget
{
    Q_OBJECT

public:
    explicit InstrumentSettings(QWidget *parent = 0);
    ~InstrumentSettings();

    Instrument* currentInstrument();

    bool setCurrentInstrument(const QString& instrumentName);

protected:
    void showEvent(QShowEvent *);

signals:
    void imageLoaded(QString);
    void saved();

private slots:
    void instrumentChanged_(int);
    void browseImage_();
    void chordsDefChanged_();
    void clearAll_();
    void enableAll_();
    void disableAll_();

    void controlButtonClicked_(QAbstractButton*);

    void setUnsaved_();
    void save_();
    bool maybeSave_();

private:
    void loadInstruments_();
    void updateInstrumentComboBox_();

    Ui::InstrumentSettings *ui;

    Instrument* currentInstrument_;

    Instrument* noInstrument_;

    InstrumentList instruments_;
    InstrumentModel instrumentModel_;

    bool unsaved_;
};

#endif // INSTRUMENTSETTINGS_H
