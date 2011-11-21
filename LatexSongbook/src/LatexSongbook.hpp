#ifndef LATEXSONGBOOK_HPP
#define LATEXSONGBOOK_HPP

#include <QDialog>

namespace Ui {
    class LatexSongbook;
}

class LatexSongbook : public QDialog
{
    Q_OBJECT

public:
    explicit LatexSongbook(QWidget *parent = 0);
    ~LatexSongbook();

public slots:
    void openSongEditor();
    void openSongbookEditor();

private:
    Ui::LatexSongbook *ui_;
};

#endif // LATEXSONGBOOK_HPP
