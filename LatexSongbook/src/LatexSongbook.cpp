#include "LatexSongbook.hpp"
#include "ui_LatexSongbook.h"

#include "SongEditor.hpp"
#include "SongbookEditor.hpp"

LatexSongbook::LatexSongbook(QWidget *parent) :
    QDialog(parent),
    ui_(new Ui::LatexSongbook)
{
    ui_->setupUi(this);

    connect(ui_->songEditorButton, SIGNAL(clicked()), this, SLOT(openSongEditor()));
    connect(ui_->songbookEditorButton, SIGNAL(clicked()), this, SLOT(openSongbookEditor()));
}

LatexSongbook::~LatexSongbook()
{
    delete ui_;
}

void LatexSongbook::openSongEditor()
{
    SongEditor* songEditor = new SongEditor(this);
    songEditor->show();

    hide();
}

void LatexSongbook::openSongbookEditor()
{
    SongbookEditor* songbookEditor = new SongbookEditor(this);
    songbookEditor->show();

    hide();
}
