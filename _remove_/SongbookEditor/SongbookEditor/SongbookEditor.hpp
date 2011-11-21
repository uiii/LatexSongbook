#ifndef SONGBOOKEDITOR_HPP
#define SONGBOOKEDITOR_HPP

#include <QMainWindow>

namespace Ui {
    class SongbookEditor;
}

class SongbookEditor : public QMainWindow
{
    Q_OBJECT

public:
    explicit SongbookEditor(QWidget *parent = 0);
    ~SongbookEditor();

private:
    Ui::SongbookEditor *ui;
};

#endif // SONGBOOKEDITOR_HPP
