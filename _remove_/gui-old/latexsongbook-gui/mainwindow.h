#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "songbook.h"
#include "eventmodel.h"

#include "instrumentsettings.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void closeEvent(QCloseEvent *);

public slots:
    void newSongbook();
    void loadSongbook();
    void saveSongbook();
    void saveAsSongbook();
    void addSong();
    void fileUnfiled();

    void changeTime(const QItemSelection& selected, const QItemSelection&);

    void selectNow();

    void setAsUnsaved();
    void setAsSaved();

    void updateTitle();

private slots:
    bool maybeSave_();
    void setRecommendedFontSize_(int);

private:
    void saveSongbook_(const QString& file);

    Ui::MainWindow *ui;

    Songbook songbook_;

    EventModel eventsModel_;
    SongModel newSongsModel_;
    SongModel allSongsModel_;

    QString songbookFile_;
    bool unsaved_;

    InstrumentSettings* instrumentSettings_;

    QStringList paperSizes_;
    QStringList fontSizes_;
    QStringList recommendedFontSizes_;
};

#endif // MAINWINDOW_H
