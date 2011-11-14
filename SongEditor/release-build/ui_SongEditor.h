/********************************************************************************
** Form generated from reading UI file 'SongEditor.ui'
**
** Created: Sun Nov 13 02:55:53 2011
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
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_songEditor
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
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *songEdit;
    QGroupBox *previewBox;
    QMenuBar *menubar;
    QMenu *menuSong;
    QMenu *menuEdit;
    QToolBar *toolBar;

    void setupUi(QMainWindow *songEditor)
    {
        if (songEditor->objectName().isEmpty())
            songEditor->setObjectName(QString::fromUtf8("songEditor"));
        songEditor->resize(800, 600);
        actionSaveAs = new QAction(songEditor);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionSaveAs->setVisible(true);
        actionSaveAs->setIconVisibleInMenu(true);
        actionUndo = new QAction(songEditor);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        actionRedo = new QAction(songEditor);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        actionShow_preview = new QAction(songEditor);
        actionShow_preview->setObjectName(QString::fromUtf8("actionShow_preview"));
        actionShow_preview->setCheckable(true);
        actionShow_preview->setChecked(true);
        actionShow_preview->setEnabled(true);
        actionSave = new QAction(songEditor);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionExit = new QAction(songEditor);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionExit->setMenuRole(QAction::TextHeuristicRole);
        actionOpen = new QAction(songEditor);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionNew = new QAction(songEditor);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        centralwidget = new QWidget(songEditor);
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

        songEditor->setCentralWidget(centralwidget);
        menubar = new QMenuBar(songEditor);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        menuSong = new QMenu(menubar);
        menuSong->setObjectName(QString::fromUtf8("menuSong"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        songEditor->setMenuBar(menubar);
        toolBar = new QToolBar(songEditor);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        songEditor->addToolBar(Qt::TopToolBarArea, toolBar);

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
        toolBar->addAction(actionNew);
        toolBar->addSeparator();
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addSeparator();
        toolBar->addAction(actionUndo);
        toolBar->addAction(actionRedo);
        toolBar->addSeparator();
        toolBar->addAction(actionShow_preview);

        retranslateUi(songEditor);
        QObject::connect(actionExit, SIGNAL(activated()), songEditor, SLOT(close()));
        QObject::connect(actionUndo, SIGNAL(activated()), songEdit, SLOT(undo()));
        QObject::connect(actionRedo, SIGNAL(activated()), songEdit, SLOT(redo()));
        QObject::connect(actionShow_preview, SIGNAL(triggered(bool)), previewBox, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(songEditor);
    } // setupUi

    void retranslateUi(QMainWindow *songEditor)
    {
        songEditor->setWindowTitle(QApplication::translate("songEditor", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setText(QApplication::translate("songEditor", "Save as ...", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setIconText(QApplication::translate("songEditor", "Save to a file ...", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSaveAs->setToolTip(QApplication::translate("songEditor", "Save as another file", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionUndo->setText(QApplication::translate("songEditor", "Undo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionUndo->setToolTip(QApplication::translate("songEditor", "Undo last action", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionUndo->setShortcut(QApplication::translate("songEditor", "Ctrl+Z", 0, QApplication::UnicodeUTF8));
        actionRedo->setText(QApplication::translate("songEditor", "Redo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionRedo->setToolTip(QApplication::translate("songEditor", "Redo last action", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        actionRedo->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        actionRedo->setShortcut(QApplication::translate("songEditor", "Ctrl+Y", 0, QApplication::UnicodeUTF8));
        actionShow_preview->setText(QApplication::translate("songEditor", "Show preview", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionShow_preview->setToolTip(QApplication::translate("songEditor", "Show preview of generated output", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setText(QApplication::translate("songEditor", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("songEditor", "Save song's changes", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("songEditor", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("songEditor", "Exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("songEditor", "Quit editing", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionExit->setShortcut(QApplication::translate("songEditor", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("songEditor", "Open ...", 0, QApplication::UnicodeUTF8));
        actionOpen->setIconText(QApplication::translate("songEditor", "Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("songEditor", "Open song", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("songEditor", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("songEditor", "New", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("songEditor", "Create new song", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNew->setShortcut(QApplication::translate("songEditor", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        songEdit->setHtml(QApplication::translate("songEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Monospace'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        previewBox->setTitle(QApplication::translate("songEditor", "Preview", 0, QApplication::UnicodeUTF8));
        menuSong->setTitle(QApplication::translate("songEditor", "Song", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("songEditor", "Edit", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("songEditor", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class songEditor: public Ui_songEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SONGEDITOR_H
