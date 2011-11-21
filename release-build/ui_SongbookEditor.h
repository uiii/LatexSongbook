/********************************************************************************
** Form generated from reading UI file 'SongbookEditor.ui'
**
** Created: Sun Nov 20 23:16:33 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGBOOKEDITOR_H
#define UI_SONGBOOKEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SongbookEditor
{
public:
    QAction *actionSaveAs;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionCut;
    QAction *actionPaste;
    QAction *actionCopy;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *title;
    QLabel *label_2;
    QLineEdit *description;
    QTableView *songTable;
    QMenuBar *menubar;
    QMenu *menuSong;
    QMenu *menuEdit;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *SongbookEditor)
    {
        if (SongbookEditor->objectName().isEmpty())
            SongbookEditor->setObjectName(QString::fromUtf8("SongbookEditor"));
        SongbookEditor->resize(493, 465);
        SongbookEditor->setAcceptDrops(false);
        actionSaveAs = new QAction(SongbookEditor);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionSaveAs->setVisible(true);
        actionSaveAs->setIconVisibleInMenu(true);
        actionUndo = new QAction(SongbookEditor);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(SongbookEditor);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionSave = new QAction(SongbookEditor);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(SongbookEditor);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit->setMenuRole(QAction::TextHeuristicRole);
        actionOpen = new QAction(SongbookEditor);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionNew = new QAction(SongbookEditor);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionCut = new QAction(SongbookEditor);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionPaste = new QAction(SongbookEditor);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionCopy = new QAction(SongbookEditor);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        centralwidget = new QWidget(SongbookEditor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        title = new QLineEdit(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));

        gridLayout->addWidget(title, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        description = new QLineEdit(centralwidget);
        description->setObjectName(QString::fromUtf8("description"));

        gridLayout->addWidget(description, 1, 1, 1, 1);

        songTable = new QTableView(centralwidget);
        songTable->setObjectName(QString::fromUtf8("songTable"));

        gridLayout->addWidget(songTable, 2, 0, 1, 2);

        SongbookEditor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SongbookEditor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 493, 19));
        menuSong = new QMenu(menubar);
        menuSong->setObjectName(QString::fromUtf8("menuSong"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        SongbookEditor->setMenuBar(menubar);
        statusBar = new QStatusBar(SongbookEditor);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SongbookEditor->setStatusBar(statusBar);
        toolBar = new QToolBar(SongbookEditor);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(16, 16));
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        SongbookEditor->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuSong->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menuSong->addAction(actionNew);
        menuSong->addSeparator();
        menuSong->addAction(actionOpen);
        menuSong->addAction(actionSave);
        menuSong->addAction(actionSaveAs);
        menuSong->addSeparator();
        menuSong->addAction(actionExit);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        toolBar->addAction(actionNew);
        toolBar->addSeparator();
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);

        retranslateUi(SongbookEditor);
        QObject::connect(actionExit, SIGNAL(activated()), SongbookEditor, SLOT(close()));

        QMetaObject::connectSlotsByName(SongbookEditor);
    } // setupUi

    void retranslateUi(QMainWindow *SongbookEditor)
    {
        SongbookEditor->setWindowTitle(QApplication::translate("SongbookEditor", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setText(QApplication::translate("SongbookEditor", "Save as ...", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setIconText(QApplication::translate("SongbookEditor", "Save to a file ...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSaveAs->setToolTip(QApplication::translate("SongbookEditor", "Save song as another file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSaveAs->setStatusTip(QApplication::translate("SongbookEditor", "Save song as another file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionUndo->setText(QApplication::translate("SongbookEditor", "Undo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionUndo->setToolTip(QApplication::translate("SongbookEditor", "Undo last action", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionUndo->setStatusTip(QApplication::translate("SongbookEditor", "Undo last action", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionUndo->setShortcut(QApplication::translate("SongbookEditor", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionRedo->setText(QApplication::translate("SongbookEditor", "Redo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRedo->setToolTip(QApplication::translate("SongbookEditor", "Redo last undid action", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionRedo->setStatusTip(QApplication::translate("SongbookEditor", "Redo last undid action", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionRedo->setShortcut(QApplication::translate("SongbookEditor", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("SongbookEditor", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("SongbookEditor", "Save changes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSave->setStatusTip(QApplication::translate("SongbookEditor", "Save changes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionSave->setShortcut(QApplication::translate("SongbookEditor", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("SongbookEditor", "Exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("SongbookEditor", "Exit editing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionExit->setStatusTip(QApplication::translate("SongbookEditor", "Exit editing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionExit->setShortcut(QApplication::translate("SongbookEditor", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("SongbookEditor", "Open ...", 0, QApplication::UnicodeUTF8));
        actionOpen->setIconText(QApplication::translate("SongbookEditor", "Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("SongbookEditor", "Open song", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionOpen->setStatusTip(QApplication::translate("SongbookEditor", "Open song", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionOpen->setShortcut(QApplication::translate("SongbookEditor", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("SongbookEditor", "New", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("SongbookEditor", "Create new song", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionNew->setStatusTip(QApplication::translate("SongbookEditor", "Create new song", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionNew->setShortcut(QApplication::translate("SongbookEditor", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("SongbookEditor", "Cut", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCut->setToolTip(QApplication::translate("SongbookEditor", "Cut to clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionCut->setStatusTip(QApplication::translate("SongbookEditor", "Cut to clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionCut->setShortcut(QApplication::translate("SongbookEditor", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("SongbookEditor", "Paste", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPaste->setToolTip(QApplication::translate("SongbookEditor", "Paste from clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPaste->setStatusTip(QApplication::translate("SongbookEditor", "Paste from clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionPaste->setShortcut(QApplication::translate("SongbookEditor", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("SongbookEditor", "Copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCopy->setToolTip(QApplication::translate("SongbookEditor", "Copy to clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionCopy->setStatusTip(QApplication::translate("SongbookEditor", "Copy to clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionCopy->setShortcut(QApplication::translate("SongbookEditor", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SongbookEditor", "Title:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SongbookEditor", "Description:", 0, QApplication::UnicodeUTF8));
        menuSong->setTitle(QApplication::translate("SongbookEditor", "Songbook", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("SongbookEditor", "Edit", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("SongbookEditor", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SongbookEditor: public Ui_SongbookEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGBOOKEDITOR_H
