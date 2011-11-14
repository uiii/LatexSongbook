#ifndef SONGEDITOR_HPP
#define SONGEDITOR_HPP

#include <QMainWindow>

namespace Ui {
    class SongEditor;
}

class SongEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit SongEditor(QWidget *parent = 0);
    ~SongEditor();

private:
    Ui::SongEditor *ui;
};

#endif // SONGEDITOR_HPP
