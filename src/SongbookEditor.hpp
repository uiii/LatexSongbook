#ifndef SONGBOOKEDITOR_HPP
#define SONGBOOKEDITOR_HPP

#include <QMainWindow>

#include "Config.hpp"
#include "LocalDatabaseModel.hpp"

namespace Ui {
    class SongbookEditor;
}

class QFileDialog; // forward declaration
class QTextDocument; // forward declaration
class TarArchive; // forward declaration

class SongbookEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit SongbookEditor(Config* config, QWidget *parent = 0);
    ~SongbookEditor();

    bool continueIfUnsaved();

    void closeEvent(QCloseEvent *event);

public slots:
    void newSongbook();
    void openSongbook(QString fileName = QString());
    bool saveSongbook();
    bool saveAsSongbook(QString fileName = QString());

    void setAsSaved(bool flag);

    void updateEditorState();

    void updateWindowTitle();

    void saveTarTest(); // TODO - remove
    void extractTarTest(); // TODO - remove

private slots:
    void importFromFiles_();
    void importFromDatabase_();

private:
    bool loadSongbookInfo_(const TarArchive& archive);

    Config* config_;
    LocalDatabaseModel* database_;

    void makeTmpDir_();
    void removeTmpDir_();

    QString songbookFileName_;
    QString songbookTmpDir_;

    bool isModified_;

    QString fileFilter_;
    QString lastAccessedDir_;

    Ui::SongbookEditor *ui_;
};

#endif // SONGBOOKEDITOR_HPP
