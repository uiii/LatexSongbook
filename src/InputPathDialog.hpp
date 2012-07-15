#ifndef INPUTPATHDIALOG_HPP
#define INPUTPATHDIALOG_HPP

#include <QDialog>
#include <QFileDialog>

namespace Ui {
    class InputPathDialog;
}

class InputPathDialog : public QDialog
{
    Q_OBJECT
    
public:
    enum Mode {
        File,
        Directory
    };

    explicit InputPathDialog(
        QWidget *parent
    );

    ~InputPathDialog();

    QString text() const;
    QString path() const;

    InputPathDialog::Mode mode() const;
    QString filter() const;

    void setText(const QString& text);
    void setPath(const QString& path);

    void setMode(InputPathDialog::Mode mode);
    void setFilter(const QString& filter);

public /* static */ :
    static QString getFile(
        QWidget* parent,
        const QString& title,
        const QString& text,
        const QString& path,
        const QString& filter = QString()
    );

    static QString getDirectory(
        QWidget* parent,
        const QString& title,
        const QString& text,
        const QString& path,
        const QString& filter = QString()
    );

private slots:
    void browse();

private:
    InputPathDialog::Mode mode_;
    QString filter_;

    Ui::InputPathDialog *ui_;
};

#endif // INPUTPATHDIALOG_HPP
