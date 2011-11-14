/********************************************************************************
** Form generated from reading UI file 'SongEditorWindow.ui'
**
** Created: Sun Nov 13 20:16:25 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SONGEDITORWINDOW_H
#define UI_SONGEDITORWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SongEditorWindow
{
public:
    QAction *actionSaveAs;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionShow_preview;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionCut;
    QAction *actionPaste;
    QAction *actionCopy;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *songEdit;
    QGroupBox *previewBox;
    QMenuBar *menubar;
    QMenu *menuSong;
    QMenu *menuEdit;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SongEditorWindow)
    {
        if (SongEditorWindow->objectName().isEmpty())
            SongEditorWindow->setObjectName(QString::fromUtf8("SongEditorWindow"));
        SongEditorWindow->resize(800, 600);
        SongEditorWindow->setAcceptDrops(false);
        actionSaveAs = new QAction(SongEditorWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionSaveAs->setVisible(true);
        actionSaveAs->setIconVisibleInMenu(true);
        actionUndo = new QAction(SongEditorWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(SongEditorWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionShow_preview = new QAction(SongEditorWindow);
        actionShow_preview->setObjectName(QString::fromUtf8("actionShow_preview"));
        actionShow_preview->setCheckable(true);
        actionShow_preview->setChecked(true);
        actionShow_preview->setEnabled(true);
        actionSave = new QAction(SongEditorWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(SongEditorWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit->setMenuRole(QAction::TextHeuristicRole);
        actionOpen = new QAction(SongEditorWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionNew = new QAction(SongEditorWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionCut = new QAction(SongEditorWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionPaste = new QAction(SongEditorWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionCopy = new QAction(SongEditorWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        centralwidget = new QWidget(SongEditorWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        songEdit = new QTextEdit(centralwidget);
        songEdit->setObjectName(QString::fromUtf8("songEdit"));
        QFont font;
        font.setFamily(QString::fromUtf8("Monospace"));
        songEdit->setFont(font);

        horizontalLayout->addWidget(songEdit);

        previewBox = new QGroupBox(centralwidget);
        previewBox->setObjectName(QString::fromUtf8("previewBox"));

        horizontalLayout->addWidget(previewBox);

        SongEditorWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SongEditorWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuSong = new QMenu(menubar);
        menuSong->setObjectName(QString::fromUtf8("menuSong"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        SongEditorWindow->setMenuBar(menubar);
        toolBar = new QToolBar(SongEditorWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(16, 16));
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        SongEditorWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(SongEditorWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SongEditorWindow->setStatusBar(statusBar);

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
        toolBar->addSeparator();
        toolBar->addAction(actionCut);
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);
        toolBar->addSeparator();
        toolBar->addAction(actionShow_preview);

        retranslateUi(SongEditorWindow);
        QObject::connect(actionExit, SIGNAL(activated()), SongEditorWindow, SLOT(close()));
        QObject::connect(actionUndo, SIGNAL(activated()), songEdit, SLOT(undo()));
        QObject::connect(actionRedo, SIGNAL(activated()), songEdit, SLOT(redo()));
        QObject::connect(actionShow_preview, SIGNAL(triggered(bool)), previewBox, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(SongEditorWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SongEditorWindow)
    {
        SongEditorWindow->setWindowTitle(QApplication::translate("SongEditorWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setText(QApplication::translate("SongEditorWindow", "Save as ...", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setIconText(QApplication::translate("SongEditorWindow", "Save to a file ...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSaveAs->setToolTip(QApplication::translate("SongEditorWindow", "Save as another file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionUndo->setText(QApplication::translate("SongEditorWindow", "Undo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionUndo->setToolTip(QApplication::translate("SongEditorWindow", "Undo last action", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionUndo->setShortcut(QApplication::translate("SongEditorWindow", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionRedo->setText(QApplication::translate("SongEditorWindow", "Redo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRedo->setToolTip(QApplication::translate("SongEditorWindow", "Redo last action", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionRedo->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        actionRedo->setShortcut(QApplication::translate("SongEditorWindow", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionShow_preview->setText(QApplication::translate("SongEditorWindow", "Show preview", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionShow_preview->setToolTip(QApplication::translate("SongEditorWindow", "Show preview of generated output", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("SongEditorWindow", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("SongEditorWindow", "Save song's changes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("SongEditorWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("SongEditorWindow", "Exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("SongEditorWindow", "Quit editing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionExit->setShortcut(QApplication::translate("SongEditorWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("SongEditorWindow", "Open ...", 0, QApplication::UnicodeUTF8));
        actionOpen->setIconText(QApplication::translate("SongEditorWindow", "Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("SongEditorWindow", "Open song", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("SongEditorWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("SongEditorWindow", "New", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("SongEditorWindow", "Create new song", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNew->setShortcut(QApplication::translate("SongEditorWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("SongEditorWindow", "Cut", 0, QApplication::UnicodeUTF8));
        actionCut->setShortcut(QApplication::translate("SongEditorWindow", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("SongEditorWindow", "Paste", 0, QApplication::UnicodeUTF8));
        actionPaste->setShortcut(QApplication::translate("SongEditorWindow", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("SongEditorWindow", "Copy", 0, QApplication::UnicodeUTF8));
        actionCopy->setShortcut(QApplication::translate("SongEditorWindow", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        songEdit->setHtml(QApplication::translate("SongEditorWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Monospace'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        previewBox->setTitle(QApplication::translate("SongEditorWindow", "Preview", 0, QApplication::UnicodeUTF8));
        menuSong->setTitle(QApplication::translate("SongEditorWindow", "Song", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("SongEditorWindow", "Edit", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("SongEditorWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SongEditorWindow: public Ui_SongEditorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGEDITORWINDOW_H
