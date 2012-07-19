#include "SettingsDialog.hpp"
#include "ui_SettingsDialog.hpp"

#include <QScrollBar>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    settingsListModel_(new QStandardItemModel),
    ui_(new Ui::SettingsDialog)
{
    ui_->setupUi(this);

    ui_->settingsList->setModel(settingsListModel_);
}

SettingsDialog::~SettingsDialog()
{
    delete ui_;
}

void SettingsDialog::addSettings(Settings* settings)
{
    settingsListModel_->appendRow(new QStandardItem(settings->name()));

    QTabWidget* tabs = new QTabWidget();

    for(Page* page : settings->pages())
    {
        tabs->addTab(page, page->name());
    }

    ui_->settingsPages->addWidget(tabs);

    updateWidth_();

    ui_->settingsList->setCurrentIndex(settingsListModel_->index(0, 0));
}

void SettingsDialog::updateWidth_()
{
    int width = ui_->settingsList->sizeHintForColumn(0)
        + ui_->settingsList->frameWidth() * 2
        + 10;

    if(ui_->settingsList->verticalScrollBar()->isVisible())
    {
        width += ui_->settingsList->verticalScrollBar()->width();
    }

    ui_->settingsList->setFixedWidth(qMax(width, 120));
}
