#ifndef DATABASEEDITOR_HPP
#define DATABASEEDITOR_HPP

#include <QMainWindow>
#include <QSortFilterProxyModel>

#include "Config.hpp"
#include "LocalDatabaseModel.hpp"
#include "SettingsDialog.hpp"

namespace Ui {
    class DatabaseEditor;
}

class DatabaseEditor : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit DatabaseEditor(Config* config, QWidget* parent = 0);
    ~DatabaseEditor();

signals:
    void showed();

protected:
    void showEvent(QShowEvent *event);

private slots:
    void setDatabaseDirectory_();
    void updateSorting_();

    void newSong_();
    void editSong_();
    void deleteSongs_();

    void newSongbook_();

    void openSong_(const QModelIndex& index);

    void selectionChanged_();

private:
    Ui::DatabaseEditor* ui_;

    Config* config_;
    SettingsDialog* settingsDialog_;

    LocalDatabaseModel* model_;
    QSortFilterProxyModel* sortModel_;
};

#endif // DATABASEEDITOR_HPP
