#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QObject>

#include <QString>

class Instrument : public QObject
{
    Q_OBJECT

public:
    Instrument(
        const QString& instrumentFile = "",
        const QString& name = "",
        const QString& imageFile = "",
        int stringsCount = 0,
        const QString& chordsDef = "",
        bool reportUnknownChords = true
    );

    //virtual ~Instrument(){}

    const QString& name() const;
    const QString& imageFile() const;
    int stringsCount() const;
    const QString& chordsDef() const;
    bool reportUnknownChords() const;

signals:
    void changed();

public slots:
    void setName(const QString& name);
    void setImageFile(const QString& file);
    void setStringsCount(int count);
    void setChordsDef(const QString& chordsDef);
    void setReportUnknownChords(bool);

    void save();

private:
    QString instrumentFile_;

    QString name_;
    QString imageFile_;

    int stringsCount_;
    QString chordsDef_;

    bool reportUnknownChords_;
};

#endif // INSTRUMENT_H
