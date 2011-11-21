/********************************************************************************
** Form generated from reading UI file 'SongEditor.ui'
**
** Created: Sun Nov 20 16:29:15 2011
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

class Ui_SongEditor
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

    void setupUi(QMainWindow *SongEditor)
    {
        if (SongEditor->objectName().isEmpty())
            SongEditor->setObjectName(QString::fromUtf8("SongEditor"));
        SongEditor->resize(493, 465);
        SongEditor->setAcceptDrops(false);
        actionSaveAs = new QAction(SongEditor);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionSaveAs->setVisible(true);
        actionSaveAs->setIconVisibleInMenu(true);
        actionUndo = new QAction(SongEditor);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(SongEditor);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionShow_preview = new QAction(SongEditor);
        actionShow_preview->setObjectName(QString::fromUtf8("actionShow_preview"));
        actionShow_preview->setCheckable(true);
        actionShow_preview->setChecked(true);
        actionShow_preview->setEnabled(true);
        actionSave = new QAction(SongEditor);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(SongEditor);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit->setMenuRole(QAction::TextHeuristicRole);
        actionOpen = new QAction(SongEditor);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionNew = new QAction(SongEditor);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionCut = new QAction(SongEditor);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        actionPaste = new QAction(SongEditor);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        actionCopy = new QAction(SongEditor);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        centralwidget = new QWidget(SongEditor);
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

        SongEditor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SongEditor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 493, 19));
        menuSong = new QMenu(menubar);
        menuSong->setObjectName(QString::fromUtf8("menuSong"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        SongEditor->setMenuBar(menubar);
        toolBar = new QToolBar(SongEditor);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(16, 16));
        toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        SongEditor->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(SongEditor);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SongEditor->setStatusBar(statusBar);

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

        retranslateUi(SongEditor);
        QObject::connect(actionExit, SIGNAL(activated()), SongEditor, SLOT(close()));
        QObject::connect(actionUndo, SIGNAL(activated()), songEdit, SLOT(undo()));
        QObject::connect(actionRedo, SIGNAL(activated()), songEdit, SLOT(redo()));
        QObject::connect(actionShow_preview, SIGNAL(triggered(bool)), previewBox, SLOT(setVisible(bool)));
        QObject::connect(actionCut, SIGNAL(activated()), songEdit, SLOT(cut()));
        QObject::connect(actionCopy, SIGNAL(activated()), songEdit, SLOT(copy()));
        QObject::connect(actionPaste, SIGNAL(activated()), songEdit, SLOT(paste()));

        QMetaObject::connectSlotsByName(SongEditor);
    } // setupUi

    void retranslateUi(QMainWindow *SongEditor)
    {
        SongEditor->setWindowTitle(QApplication::translate("SongEditor", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setText(QApplication::translate("SongEditor", "Save as ...", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setIconText(QApplication::translate("SongEditor", "Save to a file ...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSaveAs->setToolTip(QApplication::translate("SongEditor", "Save song as another file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSaveAs->setStatusTip(QApplication::translate("SongEditor", "Save song as another file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionUndo->setText(QApplication::translate("SongEditor", "Undo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionUndo->setToolTip(QApplication::translate("SongEditor", "Undo last action", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionUndo->setStatusTip(QApplication::translate("SongEditor", "Undo last action", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionUndo->setShortcut(QApplication::translate("SongEditor", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionRedo->setText(QApplication::translate("SongEditor", "Redo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRedo->setToolTip(QApplication::translate("SongEditor", "Redo last undid action", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionRedo->setStatusTip(QApplication::translate("SongEditor", "Redo last undid action", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionRedo->setShortcut(QApplication::translate("SongEditor", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionShow_preview->setText(QApplication::translate("SongEditor", "Show preview", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionShow_preview->setToolTip(QApplication::translate("SongEditor", "Show preview of generated output", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionShow_preview->setStatusTip(QApplication::translate("SongEditor", "Show preview of generated output", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionSave->setText(QApplication::translate("SongEditor", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("SongEditor", "Save changes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionSave->setStatusTip(QApplication::translate("SongEditor", "Save changes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionSave->setShortcut(QApplication::translate("SongEditor", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("SongEditor", "Exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("SongEditor", "Exit editing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionExit->setStatusTip(QApplication::translate("SongEditor", "Exit editing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionExit->setShortcut(QApplication::translate("SongEditor", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("SongEditor", "Open ...", 0, QApplication::UnicodeUTF8));
        actionOpen->setIconText(QApplication::translate("SongEditor", "Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("SongEditor", "Open song", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionOpen->setStatusTip(QApplication::translate("SongEditor", "Open song", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionOpen->setShortcut(QApplication::translate("SongEditor", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("SongEditor", "New", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("SongEditor", "Create new song", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionNew->setStatusTip(QApplication::translate("SongEditor", "Create new song", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionNew->setShortcut(QApplication::translate("SongEditor", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("SongEditor", "Cut", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCut->setToolTip(QApplication::translate("SongEditor", "Cut to clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionCut->setStatusTip(QApplication::translate("SongEditor", "Cut to clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionCut->setShortcut(QApplication::translate("SongEditor", "Ctrl+X", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("SongEditor", "Paste", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionPaste->setToolTip(QApplication::translate("SongEditor", "Paste from clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionPaste->setStatusTip(QApplication::translate("SongEditor", "Paste from clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionPaste->setShortcut(QApplication::translate("SongEditor", "Ctrl+V", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("SongEditor", "Copy", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionCopy->setToolTip(QApplication::translate("SongEditor", "Copy to clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionCopy->setStatusTip(QApplication::translate("SongEditor", "Copy to clipboard", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        actionCopy->setShortcut(QApplication::translate("SongEditor", "Ctrl+C", 0, QApplication::UnicodeUTF8));
        songEdit->setHtml(QApplication::translate("SongEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Monospace'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        previewBox->setTitle(QApplication::translate("SongEditor", "Preview", 0, QApplication::UnicodeUTF8));
        menuSong->setTitle(QApplication::translate("SongEditor", "Song", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("SongEditor", "Edit", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("SongEditor", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SongEditor: public Ui_SongEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGEDITOR_H
