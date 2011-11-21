#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <QObject>
#include <QString>

#include <QFileSystemWatcher>
#include <QtSql/QSqlDatabase>

class Database : public QObject
{
    Q_OBJECT
public:
    explicit Database(QObject *parent = 0);

signals:
    
public slots:
    void addDirectory(const QString& path);
    void updateDirectory(const QString& path);

private:
    QFileSystemWatcher watcher_;
    QSqlDatabase database_;
};

#endif // DATABASE_HPP
