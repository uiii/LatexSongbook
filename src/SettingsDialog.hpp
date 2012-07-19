#ifndef SETTINGSDIALOG_HPP
#define SETTINGSDIALOG_HPP

#include <QDialog>
#include <QStandardItemModel>
#include <QTabWidget>

#include "Settings.hpp"

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();

    void addSettings(Settings* settings);
    
private:
    void updateWidth_();

    QStandardItemModel* settingsListModel_;

    Ui::SettingsDialog* ui_;
};

#endif // SETTINGSDIALOG_HPP
