#ifndef SONGIMPORT_HPP
#define SONGIMPORT_HPP

#include <QDialog>

namespace Ui {
    class SongImportDialog;
}

class SongImportDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SongImportDialog(QWidget *parent = 0);
    ~SongImportDialog();
    
private:
    Ui::SongImportDialog *ui;
};

#endif // SONGIMPORT_HPP
