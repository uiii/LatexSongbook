/********************************************************************************
** Form generated from reading UI file 'LatexSongbook.ui'
**
** Created: Sun Nov 20 16:29:15 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LATEXSONGBOOK_H
#define UI_LATEXSONGBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LatexSongbook
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *songEditorButton;
    QPushButton *songbookEditorButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *LatexSongbook)
    {
        if (LatexSongbook->objectName().isEmpty())
            LatexSongbook->setObjectName(QString::fromUtf8("LatexSongbook"));
        LatexSongbook->resize(285, 45);
        horizontalLayout = new QHBoxLayout(LatexSongbook);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        songEditorButton = new QPushButton(LatexSongbook);
        songEditorButton->setObjectName(QString::fromUtf8("songEditorButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(songEditorButton->sizePolicy().hasHeightForWidth());
        songEditorButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(songEditorButton);

        songbookEditorButton = new QPushButton(LatexSongbook);
        songbookEditorButton->setObjectName(QString::fromUtf8("songbookEditorButton"));
        sizePolicy.setHeightForWidth(songbookEditorButton->sizePolicy().hasHeightForWidth());
        songbookEditorButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(songbookEditorButton);

        pushButton_3 = new QPushButton(LatexSongbook);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(pushButton_3);


        retranslateUi(LatexSongbook);

        QMetaObject::connectSlotsByName(LatexSongbook);
    } // setupUi

    void retranslateUi(QDialog *LatexSongbook)
    {
        LatexSongbook->setWindowTitle(QApplication::translate("LatexSongbook", "LatexSongbook", 0, QApplication::UnicodeUTF8));
        songEditorButton->setText(QApplication::translate("LatexSongbook", "Song", 0, QApplication::UnicodeUTF8));
        songbookEditorButton->setText(QApplication::translate("LatexSongbook", "Songbook", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("LatexSongbook", "Database", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LatexSongbook: public Ui_LatexSongbook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LATEXSONGBOOK_H
