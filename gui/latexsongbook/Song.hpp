#ifndef SONG_HPP
#define SONG_HPP

#include <QObject>
#include <QDateTime>

class Song : public QObject
{
    Q_OBJECT
public:
    Song(QObject* parent, const QString& data, QDateTime fileTime = QDateTime());

    const QString& title() const;
    const QString& author() const;

    QDateTime fileTime() const;
    bool isFiled() const;

    const QString& data() const;

    void file(QDateTime fileTime);

private:
    QString title_;
    QString author_;

    QDateTime fileTime_;

    QString data_;
};

#endif // SONG_HPP
