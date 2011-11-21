/********************************************************************************
** Form generated from reading UI file 'SongManager.ui'
**
** Created: Wed Nov 16 21:45:55 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGMANAGER_H
#define UI_SONGMANAGER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SongManager
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *SongManager)
    {
        if (SongManager->objectName().isEmpty())
            SongManager->setObjectName(QString::fromUtf8("SongManager"));
        SongManager->resize(492, 486);
        centralWidget = new QWidget(SongManager);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());

        verticalLayout->addWidget(tabWidget);

        SongManager->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SongManager);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 492, 21));
        SongManager->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SongManager);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SongManager->addToolBar(Qt::TopToolBarArea, mainToolBar);
        SongManager->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(SongManager);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SongManager->setStatusBar(statusBar);
        toolBar = new QToolBar(SongManager);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        SongManager->addToolBar(Qt::TopToolBarArea, toolBar);
        SongManager->insertToolBarBreak(toolBar);

        retranslateUi(SongManager);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SongManager);
    } // setupUi

    void retranslateUi(QMainWindow *SongManager)
    {
        SongManager->setWindowTitle(QApplication::translate("SongManager", "SongManager", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SongManager", "Tab 1", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("SongManager", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SongManager: public Ui_SongManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGMANAGER_H
