/********************************************************************************
** Form generated from reading UI file 'instrumentsettings.ui'
**
** Created: Wed Aug 31 11:58:04 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSTRUMENTSETTINGS_H
#define UI_INSTRUMENTSETTINGS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InstrumentSettings
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *instruments;
    QPushButton *pushButton_2;
    QPushButton *deleteInstrument;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *nameEdit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSpinBox *stringsCount;
    QSpacerItem *horizontalSpacer;
    QPlainTextEdit *chordsEdit;
    QCheckBox *reportUnknowChords;
    QGroupBox *imageBox;
    QVBoxLayout *verticalLayout_4;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *browseImage;
    QPushButton *removeImage;
    QSpacerItem *horizontalSpacer_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *image;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *controlButtons;

    void setupUi(QWidget *InstrumentSettings)
    {
        if (InstrumentSettings->objectName().isEmpty())
            InstrumentSettings->setObjectName(QString::fromUtf8("InstrumentSettings"));
        InstrumentSettings->resize(708, 452);
        verticalLayout = new QVBoxLayout(InstrumentSettings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(InstrumentSettings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(false);
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 9, 9, 9);
        instruments = new QComboBox(groupBox);
        instruments->setObjectName(QString::fromUtf8("instruments"));
        instruments->setEnabled(true);
        instruments->setFrame(true);
        instruments->setModelColumn(0);

        horizontalLayout_3->addWidget(instruments);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        deleteInstrument = new QPushButton(groupBox);
        deleteInstrument->setObjectName(QString::fromUtf8("deleteInstrument"));
        deleteInstrument->setEnabled(false);

        horizontalLayout_3->addWidget(deleteInstrument);

        horizontalLayout_3->setStretch(0, 1);

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(InstrumentSettings);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_6 = new QHBoxLayout(groupBox_2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, -1, -1, -1);
        nameEdit = new QLineEdit(groupBox_2);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setEnabled(false);
        nameEdit->setReadOnly(false);

        horizontalLayout_6->addWidget(nameEdit);


        verticalLayout->addWidget(groupBox_2);

        widget_3 = new QWidget(InstrumentSettings);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        groupBox_3 = new QGroupBox(widget_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, -1, 0);
        widget_4 = new QWidget(groupBox_3);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        horizontalLayout_5 = new QHBoxLayout(widget_4);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(widget_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);

        horizontalLayout_5->addWidget(label_2);

        stringsCount = new QSpinBox(widget_4);
        stringsCount->setObjectName(QString::fromUtf8("stringsCount"));
        stringsCount->setEnabled(false);

        horizontalLayout_5->addWidget(stringsCount);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        horizontalLayout_5->setStretch(2, 1);

        verticalLayout_3->addWidget(widget_4);

        chordsEdit = new QPlainTextEdit(groupBox_3);
        chordsEdit->setObjectName(QString::fromUtf8("chordsEdit"));
        chordsEdit->setEnabled(false);
        chordsEdit->setMinimumSize(QSize(450, 0));

        verticalLayout_3->addWidget(chordsEdit);

        reportUnknowChords = new QCheckBox(groupBox_3);
        reportUnknowChords->setObjectName(QString::fromUtf8("reportUnknowChords"));
        reportUnknowChords->setEnabled(false);
        reportUnknowChords->setChecked(true);

        verticalLayout_3->addWidget(reportUnknowChords);


        horizontalLayout_4->addWidget(groupBox_3);

        imageBox = new QGroupBox(widget_3);
        imageBox->setObjectName(QString::fromUtf8("imageBox"));
        verticalLayout_4 = new QVBoxLayout(imageBox);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, -1, 0);
        widget_5 = new QWidget(imageBox);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        horizontalLayout_7 = new QHBoxLayout(widget_5);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        browseImage = new QPushButton(widget_5);
        browseImage->setObjectName(QString::fromUtf8("browseImage"));
        browseImage->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(browseImage->sizePolicy().hasHeightForWidth());
        browseImage->setSizePolicy(sizePolicy);
        browseImage->setLayoutDirection(Qt::LeftToRight);
        browseImage->setAutoFillBackground(false);

        horizontalLayout_7->addWidget(browseImage);

        removeImage = new QPushButton(widget_5);
        removeImage->setObjectName(QString::fromUtf8("removeImage"));
        removeImage->setEnabled(false);

        horizontalLayout_7->addWidget(removeImage);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        verticalLayout_4->addWidget(widget_5);

        widget = new QWidget(imageBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        image = new QLabel(widget);
        image->setObjectName(QString::fromUtf8("image"));
        image->setEnabled(false);
        sizePolicy.setHeightForWidth(image->sizePolicy().hasHeightForWidth());
        image->setSizePolicy(sizePolicy);
        image->setMinimumSize(QSize(200, 200));
        image->setFrameShape(QFrame::StyledPanel);
        image->setTextFormat(Qt::PlainText);
        image->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(image);


        verticalLayout_4->addWidget(widget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horizontalLayout_4->addWidget(imageBox);

        horizontalLayout_4->setStretch(0, 1);

        verticalLayout->addWidget(widget_3);

        controlButtons = new QDialogButtonBox(InstrumentSettings);
        controlButtons->setObjectName(QString::fromUtf8("controlButtons"));
        controlButtons->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        controlButtons->setCenterButtons(false);

        verticalLayout->addWidget(controlButtons);

        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(3, 1);

        retranslateUi(InstrumentSettings);
        QObject::connect(controlButtons, SIGNAL(rejected()), InstrumentSettings, SLOT(close()));

        instruments->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(InstrumentSettings);
    } // setupUi

    void retranslateUi(QWidget *InstrumentSettings)
    {
        InstrumentSettings->setWindowTitle(QApplication::translate("InstrumentSettings", "InstrumentSettings", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("InstrumentSettings", "Instrument", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("InstrumentSettings", "Add instrument", 0, QApplication::UnicodeUTF8));
        deleteInstrument->setText(QApplication::translate("InstrumentSettings", "Delete instrument", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("InstrumentSettings", "Name", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("InstrumentSettings", "Chord diagrams", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("InstrumentSettings", "Strings count:", 0, QApplication::UnicodeUTF8));
        reportUnknowChords->setText(QApplication::translate("InstrumentSettings", "Report unknow chords", 0, QApplication::UnicodeUTF8));
        imageBox->setTitle(QApplication::translate("InstrumentSettings", "Image", 0, QApplication::UnicodeUTF8));
        browseImage->setText(QApplication::translate("InstrumentSettings", "Browse ...", 0, QApplication::UnicodeUTF8));
        removeImage->setText(QApplication::translate("InstrumentSettings", "Remove", 0, QApplication::UnicodeUTF8));
        image->setText(QApplication::translate("InstrumentSettings", "Image", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InstrumentSettings: public Ui_InstrumentSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSTRUMENTSETTINGS_H
