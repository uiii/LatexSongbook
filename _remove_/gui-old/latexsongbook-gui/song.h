#ifndef SONG_H
#define SONG_H

#include <QString>
#include <ctime>

class Song
{
public:
    //Song(const QString& title, const QString& author);
    Song(const QString& data, std::time_t fileTime = 0);
    //Song(const QString& title, const QString& author, std::time_t time, const QString& data);

    const QString& title() const;
    const QString& author() const;

    std::time_t fileTime() const;
    bool isFiled() const;

    const QString& data() const;

    void file(std::time_t fileTime);

private:
    QString title_;
    QString author_;

    std::time_t fileTime_;

    QString data_;
};

#endif // SONG_H
