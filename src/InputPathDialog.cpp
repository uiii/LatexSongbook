#include "InputPathDialog.hpp"
#include "ui_InputPathDialog.hpp"

InputPathDialog::InputPathDialog(QWidget* parent):
    mode_(InputPathDialog::File),
    ui_(new Ui::InputPathDialog)
{
    ui_->setupUi(this);

    connect(ui_->browseButton, SIGNAL(clicked()), this, SLOT(browse()));
}

InputPathDialog::~InputPathDialog()
{
    delete ui_;
}

QString InputPathDialog::text() const
{
    return ui_->text->text();
}

QString InputPathDialog::path() const
{
    return ui_->path->text();
}

InputPathDialog::Mode InputPathDialog::mode() const
{
    return mode_;
}

QString InputPathDialog::filter() const
{
    return filter_;
}

void InputPathDialog::setText(const QString& text)
{
    ui_->text->setText(text);
}

void InputPathDialog::setPath(const QString& path)
{
    ui_->path->setText(path);
}

void InputPathDialog::setMode(InputPathDialog::Mode mode)
{
    mode_ = mode;
}

void InputPathDialog::setFilter(const QString& filter)
{
    filter_ = filter;
}

QString InputPathDialog::getFile(QWidget* parent, const QString& title, const QString& text, const QString& path, const QString& filter)
{
    InputPathDialog dialog(parent);
    dialog.setWindowTitle(title);
    dialog.setText(text);
    dialog.setPath(path);
    dialog.setMode(InputPathDialog::File);
    dialog.setFilter(filter);

    QString newPath;
    if(dialog.exec())
    {
        newPath = dialog.ui_->path->text();
    }

    return newPath;
}

QString InputPathDialog::getDirectory(QWidget* parent, const QString& title, const QString& text, const QString& path, const QString& filter)
{
    InputPathDialog dialog(parent);
    dialog.setWindowTitle(title);
    dialog.setText(text);
    dialog.setPath(path);
    dialog.setMode(InputPathDialog::Directory);
    dialog.setFilter(filter);

    QString newPath;
    if(dialog.exec())
    {
        newPath = dialog.ui_->path->text();
    }

    return newPath;
}

void InputPathDialog::browse()
{
    QString path;
    if(mode_ == InputPathDialog::File)
    {
        path = QFileDialog::getOpenFileName(this, "Browse file", ui_->path->text(), filter_);
    }
    else
    {
        path = QFileDialog::getExistingDirectory(this, "Browse file", ui_->path->text());
    }

    if(! path.isEmpty())
    {
        ui_->path->setText(path);
    }
}
