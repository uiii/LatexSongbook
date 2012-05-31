#ifndef SONGEDITOR_HPP
#define SONGEDITOR_HPP

#include <QMainWindow>

namespace Ui {
    class SongEditor;
}

class QFileDialog; // forward declaration
class QTextDocument; // forward declaration

class SongEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit SongEditor(QWidget *parent = 0);
    ~SongEditor();

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

    Ui::SongEditor *ui_;
};

#endif // SONGEDITOR_HPP
