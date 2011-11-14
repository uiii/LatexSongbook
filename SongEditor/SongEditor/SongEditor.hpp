#ifndef SONGEDITOR_HPP
#define SONGEDITOR_HPP

#include <QMainWindow>

namespace Ui {
    class SongEditorWindow;
}

class QFileDialog; // forward declaration

class SongEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit SongEditor(QWidget *parent = 0);
    ~SongEditor();

public slots:
    void newSong();
    void openSong(QString fileName = QString());
    void saveSong();
    void saveAsSong(QString fileName = QString());

    void updateWindowTitle();

private:
    QString songFileName_;

    bool isUnsaved_;

    QString fileFilter_;
    QString lastAccessedDir_;

    Ui::SongEditorWindow *ui_;
};

#endif // SONGEDITOR_HPP
