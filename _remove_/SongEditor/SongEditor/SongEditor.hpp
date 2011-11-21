#ifndef SONGEDITOR_HPP
#define SONGEDITOR_HPP

#include <QMainWindow>

namespace Ui {
    class SongEditorWindow;
}

class QFileDialog; // forward declaration
class QTextDocument; // forward declaration

class SongbookEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit SongbookEditor(QWidget *parent = 0);
    ~SongbookEditor();

    bool continueIfUnsaved();

    void closeEvent(QCloseEvent *event);

public slots:
    void newSong();
    void openSong(QString fileName = QString());
    bool saveSong();
    bool saveAsSong(QString fileName = QString());

    void setAsSaved(bool flag);

    void updateSongState();

    void updateWindowTitle();

private:
    QString songFileName_;

    QTextDocument* document_;

    bool isSaved_;

    QString fileFilter_;
    QString lastAccessedDir_;

    Ui::SongEditorWindow *ui_;
};

#endif // SONGEDITOR_HPP
