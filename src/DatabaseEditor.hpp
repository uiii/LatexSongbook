#ifndef DATABASEEDITOR_HPP
#define DATABASEEDITOR_HPP

#include <QMainWindow>

#include "LocalDatabaseModel.hpp"

namespace Ui {
    class DatabaseEditor;
}

class DatabaseEditor : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit DatabaseEditor(QString selfApp, QWidget *parent = 0);
    ~DatabaseEditor();

private slots:
    void newSong_();
    void editSong_();
    void deleteSongs_();

    void openSong_(const QModelIndex& index);

    void selectionChanged_();

private:
    Ui::DatabaseEditor *ui_;

    LocalDatabaseModel* model_;

    QString selfApp_;
};

#endif // DATABASEEDITOR_HPP
