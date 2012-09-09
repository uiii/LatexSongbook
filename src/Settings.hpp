#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QWidget>
#include <QString>
#include <QIcon>

class Page : public QWidget
{
    Q_OBJECT

public:
    Page(const QString& name);

    QString name() const;

private:
    QString name_;
};

class Settings
{
public:
    typedef QList<Page*> Pages;

    Settings(const QString& name, const QIcon& icon = QIcon());

    const QString& name() const;
    const QIcon& icon() const;

    const Pages& pages() const;

protected:
    void addPage_(Page* page);

private:
    QString name_;
    QIcon icon_;

    Pages pages_;
};

#endif // SETTINGS_HPP
