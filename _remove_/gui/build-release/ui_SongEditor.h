/********************************************************************************
** Form generated from reading UI file 'SongEditor.ui'
**
** Created: Sat Nov 12 23:06:18 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGEDITOR_H
#define UI_SONGEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SongEditor
{
public:
    QAction *actionSave_to_a_file;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *SongEditor)
    {
        if (SongEditor->objectName().isEmpty())
            SongEditor->setObjectName(QString::fromUtf8("SongEditor"));
        SongEditor->resize(800, 600);
        actionSave_to_a_file = new QAction(SongEditor);
        actionSave_to_a_file->setObjectName(QString::fromUtf8("actionSave_to_a_file"));
        centralwidget = new QWidget(SongEditor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        SongEditor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SongEditor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        SongEditor->setMenuBar(menubar);
        statusbar = new QStatusBar(SongEditor);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        SongEditor->setStatusBar(statusbar);
        toolBar = new QToolBar(SongEditor);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        SongEditor->addToolBar(Qt::TopToolBarArea, toolBar);
        SongEditor->insertToolBarBreak(toolBar);

        toolBar->addAction(actionSave_to_a_file);
        toolBar->addSeparator();

        retranslateUi(SongEditor);

        QMetaObject::connectSlotsByName(SongEditor);
    } // setupUi

    void retranslateUi(QMainWindow *SongEditor)
    {
        SongEditor->setWindowTitle(QApplication::translate("SongEditor", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSave_to_a_file->setText(QApplication::translate("SongEditor", "Save to a file ...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave_to_a_file->setToolTip(QApplication::translate("SongEditor", "Save this song to an external file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("SongEditor", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SongEditor: public Ui_SongEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGEDITOR_H
