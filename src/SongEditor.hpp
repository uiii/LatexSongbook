#ifndef SONGEDITOR_HPP
#define SONGEDITOR_HPP

#include <QMainWindow>

#include "Config.hpp"
#include "Generator.hpp"

namespace Ui {
    class SongEditor;
}

class QFileDialog; // forward declaration
class QTextDocument; // forward declaration

class SongEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit SongEditor(Config* config, QWidget *parent = 0);
    ~SongEditor();

    bool continueIfUnsaved();

    void closeEvent(QCloseEvent *event);

public slots:
    void newSong();
    void openSong(QString fileName = QString());
    bool saveSong();
    bool saveAsSong(QString fileName = QString());

    void setAsSaved(bool flag);

    void updateEditorState();

    void updateWindowTitle();

    void generateSong();

private slots:
    void parseText_();

private:
    Config* config_;

    QString songFileName_;

    QTextDocument* document_;

    QString fileFilter_;
    QString lastAccessedDir_;

    SongParser parser_;
    Generator* generator_;

    Ui::SongEditor *ui_;
};

#endif // SONGEDITOR_HPP
