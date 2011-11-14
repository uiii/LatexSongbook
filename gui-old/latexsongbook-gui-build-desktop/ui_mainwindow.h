/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Aug 31 21:11:57 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolBar>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionSave;
    QAction *actionAdd_song;
    QAction *actionGenerate_songbook;
    QAction *actionGenerate_songbook_from;
    QAction *actionSave_As;
    QAction *actionQuit;
    QAction *actionInstrument_settings;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QComboBox *paperSize;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_6;
    QFrame *frame_3;
    QLabel *label_3;
    QComboBox *fontSize;
    QLabel *label_4;
    QLabel *recommendedSize;
    QSpacerItem *horizontalSpacer_2;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLabel *instrumentLabel;
    QPushButton *instrumentSettingsButton;
    QSpacerItem *horizontalSpacer;
    QFrame *frame_2;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *historyBox;
    QVBoxLayout *verticalLayout;
    QListView *eventsView;
    QGroupBox *newSongsBox;
    QVBoxLayout *verticalLayout_4;
    QTreeView *newSongsView;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *fileUnfiledButton;
    QPushButton *pushButton;
    QFrame *frame;
    QPushButton *pushButton_2;
    QGroupBox *songbookBox;
    QVBoxLayout *verticalLayout_3;
    QTreeView *allSongsView;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;
    QMenuBar *menuBar;
    QMenu *menuSoubor;
    QMenu *menuSongbook;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(872, 644);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionAdd_song = new QAction(MainWindow);
        actionAdd_song->setObjectName(QString::fromUtf8("actionAdd_song"));
        actionGenerate_songbook = new QAction(MainWindow);
        actionGenerate_songbook->setObjectName(QString::fromUtf8("actionGenerate_songbook"));
        actionGenerate_songbook_from = new QAction(MainWindow);
        actionGenerate_songbook_from->setObjectName(QString::fromUtf8("actionGenerate_songbook_from"));
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionInstrument_settings = new QAction(MainWindow);
        actionInstrument_settings->setObjectName(QString::fromUtf8("actionInstrument_settings"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_5 = new QVBoxLayout(groupBox);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, -1, 0);
        widget_5 = new QWidget(groupBox);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        horizontalLayout_5->addWidget(label_2);

        paperSize = new QComboBox(widget_5);
        paperSize->setObjectName(QString::fromUtf8("paperSize"));

        horizontalLayout_5->addWidget(paperSize);

        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        horizontalLayout_6 = new QHBoxLayout(widget_6);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        frame_3 = new QFrame(widget_6);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::VLine);
        frame_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_6->addWidget(frame_3);

        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_6->addWidget(label_3);

        fontSize = new QComboBox(widget_6);
        fontSize->setObjectName(QString::fromUtf8("fontSize"));

        horizontalLayout_6->addWidget(fontSize);

        label_4 = new QLabel(widget_6);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QPalette palette;
        QBrush brush(QColor(255, 170, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(165, 166, 166, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_4->setPalette(palette);
        QFont font1;
        font1.setPointSize(9);
        font1.setItalic(true);
        label_4->setFont(font1);

        horizontalLayout_6->addWidget(label_4);

        recommendedSize = new QLabel(widget_6);
        recommendedSize->setObjectName(QString::fromUtf8("recommendedSize"));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        recommendedSize->setPalette(palette1);
        recommendedSize->setFont(font1);

        horizontalLayout_6->addWidget(recommendedSize);


        horizontalLayout_5->addWidget(widget_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_5->addWidget(widget_5);

        widget_4 = new QWidget(groupBox);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(widget_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_4->addWidget(label);

        instrumentLabel = new QLabel(widget_4);
        instrumentLabel->setObjectName(QString::fromUtf8("instrumentLabel"));
        QFont font2;
        font2.setPointSize(9);
        font2.setBold(false);
        font2.setUnderline(false);
        font2.setWeight(50);
        instrumentLabel->setFont(font2);

        horizontalLayout_4->addWidget(instrumentLabel);

        instrumentSettingsButton = new QPushButton(widget_4);
        instrumentSettingsButton->setObjectName(QString::fromUtf8("instrumentSettingsButton"));

        horizontalLayout_4->addWidget(instrumentSettingsButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_5->addWidget(widget_4);


        verticalLayout_2->addWidget(groupBox);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::HLine);
        frame_2->setFrameShadow(QFrame::Sunken);
        frame_2->setLineWidth(1);
        frame_2->setMidLineWidth(0);

        verticalLayout_2->addWidget(frame_2);

        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        historyBox = new QGroupBox(widget_3);
        historyBox->setObjectName(QString::fromUtf8("historyBox"));
        historyBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        historyBox->setFlat(false);
        historyBox->setCheckable(false);
        verticalLayout = new QVBoxLayout(historyBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        eventsView = new QListView(historyBox);
        eventsView->setObjectName(QString::fromUtf8("eventsView"));
        eventsView->setSelectionMode(QAbstractItemView::SingleSelection);

        verticalLayout->addWidget(eventsView);


        horizontalLayout_3->addWidget(historyBox);

        newSongsBox = new QGroupBox(widget_3);
        newSongsBox->setObjectName(QString::fromUtf8("newSongsBox"));
        newSongsBox->setFlat(false);
        verticalLayout_4 = new QVBoxLayout(newSongsBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 9, -1, -1);
        newSongsView = new QTreeView(newSongsBox);
        newSongsView->setObjectName(QString::fromUtf8("newSongsView"));
        newSongsView->setSelectionMode(QAbstractItemView::MultiSelection);
        newSongsView->setIndentation(20);
        newSongsView->setItemsExpandable(false);
        newSongsView->setSortingEnabled(true);
        newSongsView->header()->setCascadingSectionResizes(false);
        newSongsView->header()->setDefaultSectionSize(150);
        newSongsView->header()->setMinimumSectionSize(100);
        newSongsView->header()->setStretchLastSection(true);

        verticalLayout_4->addWidget(newSongsView);

        widget_2 = new QWidget(newSongsBox);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        fileUnfiledButton = new QPushButton(widget_2);
        fileUnfiledButton->setObjectName(QString::fromUtf8("fileUnfiledButton"));

        horizontalLayout_2->addWidget(fileUnfiledButton);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);

        frame = new QFrame(widget_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::VLine);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(frame);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_4->addWidget(widget_2);


        horizontalLayout_3->addWidget(newSongsBox);

        horizontalLayout_3->setStretch(1, 1);

        verticalLayout_2->addWidget(widget_3);

        songbookBox = new QGroupBox(centralwidget);
        songbookBox->setObjectName(QString::fromUtf8("songbookBox"));
        verticalLayout_3 = new QVBoxLayout(songbookBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, -1, 9);
        allSongsView = new QTreeView(songbookBox);
        allSongsView->setObjectName(QString::fromUtf8("allSongsView"));
        allSongsView->setSelectionMode(QAbstractItemView::MultiSelection);
        allSongsView->setSortingEnabled(true);
        allSongsView->setHeaderHidden(false);
        allSongsView->header()->setDefaultSectionSize(250);
        allSongsView->header()->setHighlightSections(false);
        allSongsView->header()->setMinimumSectionSize(100);
        allSongsView->header()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout_3->addWidget(allSongsView);

        widget = new QWidget(songbookBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout_3->addWidget(widget);


        verticalLayout_2->addWidget(songbookBox);

        MainWindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(MainWindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(MainWindow);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 872, 19));
        menuSoubor = new QMenu(menuBar);
        menuSoubor->setObjectName(QString::fromUtf8("menuSoubor"));
        menuSongbook = new QMenu(menuBar);
        menuSongbook->setObjectName(QString::fromUtf8("menuSongbook"));
        MainWindow->setMenuBar(menuBar);

        toolBar->addAction(actionNew);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar_2->addAction(actionAdd_song);
        toolBar_3->addAction(actionGenerate_songbook);
        toolBar_3->addAction(actionGenerate_songbook_from);
        menuBar->addAction(menuSoubor->menuAction());
        menuBar->addAction(menuSongbook->menuAction());
        menuSoubor->addAction(actionNew);
        menuSoubor->addAction(actionOpen);
        menuSoubor->addSeparator();
        menuSoubor->addAction(actionSave);
        menuSoubor->addAction(actionSave_As);
        menuSoubor->addSeparator();
        menuSoubor->addAction(actionQuit);
        menuSongbook->addAction(actionAdd_song);
        menuSongbook->addSeparator();
        menuSongbook->addAction(actionInstrument_settings);
        menuSongbook->addSeparator();
        menuSongbook->addAction(actionGenerate_songbook);

        retranslateUi(MainWindow);
        QObject::connect(instrumentSettingsButton, SIGNAL(clicked()), actionInstrument_settings, SLOT(trigger()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "&Open", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("MainWindow", "Open existing songbook", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "New songbook", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionNew->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("MainWindow", "Save current songbook", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionAdd_song->setText(QApplication::translate("MainWindow", "Add song", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAdd_song->setToolTip(QApplication::translate("MainWindow", "Add new song to the songbook", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionGenerate_songbook->setText(QApplication::translate("MainWindow", "Generate songbook", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionGenerate_songbook->setToolTip(QApplication::translate("MainWindow", "Generate complete songbook", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionGenerate_songbook_from->setText(QApplication::translate("MainWindow", "Generate songbook from", 0, QApplication::UnicodeUTF8));
        actionSave_As->setText(QApplication::translate("MainWindow", "Save As ...", 0, QApplication::UnicodeUTF8));
        actionQuit->setText(QApplication::translate("MainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
        actionQuit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionInstrument_settings->setText(QApplication::translate("MainWindow", "Instrument settings", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Paper size: ", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Base font size: ", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "   Recomended: ", 0, QApplication::UnicodeUTF8));
        recommendedSize->setText(QApplication::translate("MainWindow", "10pt", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Instrument: ", 0, QApplication::UnicodeUTF8));
        instrumentLabel->setText(QApplication::translate("MainWindow", "-- No instrument --", 0, QApplication::UnicodeUTF8));
        instrumentSettingsButton->setText(QApplication::translate("MainWindow", "Instrument settings ...", 0, QApplication::UnicodeUTF8));
        historyBox->setTitle(QApplication::translate("MainWindow", "History", 0, QApplication::UnicodeUTF8));
        newSongsBox->setTitle(QApplication::translate("MainWindow", "New songs", 0, QApplication::UnicodeUTF8));
        fileUnfiledButton->setText(QApplication::translate("MainWindow", "File unfiled songs", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Generate only new songs", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWindow", "Remove selected", 0, QApplication::UnicodeUTF8));
        songbookBox->setTitle(QApplication::translate("MainWindow", "Songbook", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWindow", "Remove selected", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("MainWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
        toolBar_3->setWindowTitle(QApplication::translate("MainWindow", "toolBar_3", 0, QApplication::UnicodeUTF8));
        menuSoubor->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuSongbook->setTitle(QApplication::translate("MainWindow", "Songbook", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
