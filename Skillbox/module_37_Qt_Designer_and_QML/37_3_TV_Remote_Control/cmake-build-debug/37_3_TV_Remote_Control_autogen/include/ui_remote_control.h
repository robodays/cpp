/********************************************************************************
** Form generated from reading UI file 'remote_control.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REMOTE_CONTROL_H
#define UI_REMOTE_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QPushButton *button8;
    QPushButton *button7;
    QPushButton *button10;
    QPushButton *button5;
    QPushButton *button1;
    QPushButton *button4;
    QPushButton *button3;
    QPushButton *button9;
    QPushButton *button6;
    QPushButton *button2;
    QGridLayout *gridLayout_3;
    QPushButton *volumeUp;
    QPushButton *channelDown;
    QPushButton *volumDown;
    QPushButton *channelUp;
    QFrame *line;
    QGridLayout *gridLayout_4;
    QLabel *channelNowLabel;
    QLCDNumber *channelLcd;
    QLabel *volumeNowLabel;
    QProgressBar *volumeProgress;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(240, 680);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(240, 680));
        MainWindow->setMaximumSize(QSize(259, 680));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        button8 = new QPushButton(centralwidget);
        button8->setObjectName(QString::fromUtf8("button8"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button8->sizePolicy().hasHeightForWidth());
        button8->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(20);
        button8->setFont(font);
        button8->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 197, 194);"));

        gridLayout->addWidget(button8, 2, 1, 1, 1);

        button7 = new QPushButton(centralwidget);
        button7->setObjectName(QString::fromUtf8("button7"));
        sizePolicy1.setHeightForWidth(button7->sizePolicy().hasHeightForWidth());
        button7->setSizePolicy(sizePolicy1);
        button7->setFont(font);
        button7->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 197, 194);"));

        gridLayout->addWidget(button7, 2, 0, 1, 1);

        button10 = new QPushButton(centralwidget);
        button10->setObjectName(QString::fromUtf8("button10"));
        sizePolicy1.setHeightForWidth(button10->sizePolicy().hasHeightForWidth());
        button10->setSizePolicy(sizePolicy1);
        button10->setFont(font);
        button10->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 197, 194);"));

        gridLayout->addWidget(button10, 3, 1, 1, 1);

        button5 = new QPushButton(centralwidget);
        button5->setObjectName(QString::fromUtf8("button5"));
        sizePolicy1.setHeightForWidth(button5->sizePolicy().hasHeightForWidth());
        button5->setSizePolicy(sizePolicy1);
        button5->setFont(font);
        button5->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 197, 194);"));

        gridLayout->addWidget(button5, 1, 1, 1, 1);

        button1 = new QPushButton(centralwidget);
        button1->setObjectName(QString::fromUtf8("button1"));
        sizePolicy1.setHeightForWidth(button1->sizePolicy().hasHeightForWidth());
        button1->setSizePolicy(sizePolicy1);
        button1->setFont(font);
        button1->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 197, 194);"));

        gridLayout->addWidget(button1, 0, 0, 1, 1);

        button4 = new QPushButton(centralwidget);
        button4->setObjectName(QString::fromUtf8("button4"));
        sizePolicy1.setHeightForWidth(button4->sizePolicy().hasHeightForWidth());
        button4->setSizePolicy(sizePolicy1);
        button4->setFont(font);
        button4->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 197, 194);"));

        gridLayout->addWidget(button4, 1, 0, 1, 1);

        button3 = new QPushButton(centralwidget);
        button3->setObjectName(QString::fromUtf8("button3"));
        sizePolicy1.setHeightForWidth(button3->sizePolicy().hasHeightForWidth());
        button3->setSizePolicy(sizePolicy1);
        button3->setFont(font);
        button3->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 197, 194);"));

        gridLayout->addWidget(button3, 0, 2, 1, 1);

        button9 = new QPushButton(centralwidget);
        button9->setObjectName(QString::fromUtf8("button9"));
        sizePolicy1.setHeightForWidth(button9->sizePolicy().hasHeightForWidth());
        button9->setSizePolicy(sizePolicy1);
        button9->setFont(font);
        button9->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 197, 194);"));

        gridLayout->addWidget(button9, 2, 2, 1, 1);

        button6 = new QPushButton(centralwidget);
        button6->setObjectName(QString::fromUtf8("button6"));
        sizePolicy1.setHeightForWidth(button6->sizePolicy().hasHeightForWidth());
        button6->setSizePolicy(sizePolicy1);
        button6->setFont(font);
        button6->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 197, 194);"));

        gridLayout->addWidget(button6, 1, 2, 1, 1);

        button2 = new QPushButton(centralwidget);
        button2->setObjectName(QString::fromUtf8("button2"));
        sizePolicy1.setHeightForWidth(button2->sizePolicy().hasHeightForWidth());
        button2->setSizePolicy(sizePolicy1);
        button2->setFont(font);
        button2->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 197, 194);"));

        gridLayout->addWidget(button2, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        volumeUp = new QPushButton(centralwidget);
        volumeUp->setObjectName(QString::fromUtf8("volumeUp"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(volumeUp->sizePolicy().hasHeightForWidth());
        volumeUp->setSizePolicy(sizePolicy2);
        volumeUp->setFont(font);
        volumeUp->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 197, 194);"));

        gridLayout_3->addWidget(volumeUp, 0, 2, 1, 1);

        channelDown = new QPushButton(centralwidget);
        channelDown->setObjectName(QString::fromUtf8("channelDown"));
        sizePolicy2.setHeightForWidth(channelDown->sizePolicy().hasHeightForWidth());
        channelDown->setSizePolicy(sizePolicy2);
        channelDown->setFont(font);
        channelDown->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 197, 194);"));

        gridLayout_3->addWidget(channelDown, 1, 0, 1, 1);

        volumDown = new QPushButton(centralwidget);
        volumDown->setObjectName(QString::fromUtf8("volumDown"));
        sizePolicy2.setHeightForWidth(volumDown->sizePolicy().hasHeightForWidth());
        volumDown->setSizePolicy(sizePolicy2);
        volumDown->setFont(font);
        volumDown->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 197, 194);"));

        gridLayout_3->addWidget(volumDown, 1, 2, 1, 1);

        channelUp = new QPushButton(centralwidget);
        channelUp->setObjectName(QString::fromUtf8("channelUp"));
        sizePolicy2.setHeightForWidth(channelUp->sizePolicy().hasHeightForWidth());
        channelUp->setSizePolicy(sizePolicy2);
        channelUp->setFont(font);
        channelUp->setStyleSheet(QString::fromUtf8("background-color: rgb(184, 197, 194);"));

        gridLayout_3->addWidget(channelUp, 0, 0, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
        line->setSizePolicy(sizePolicy);
        line->setMinimumSize(QSize(20, 0));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 0, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        channelNowLabel = new QLabel(centralwidget);
        channelNowLabel->setObjectName(QString::fromUtf8("channelNowLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(channelNowLabel->sizePolicy().hasHeightForWidth());
        channelNowLabel->setSizePolicy(sizePolicy3);
        channelNowLabel->setFont(font);

        gridLayout_4->addWidget(channelNowLabel, 0, 0, 1, 1);

        channelLcd = new QLCDNumber(centralwidget);
        channelLcd->setObjectName(QString::fromUtf8("channelLcd"));
        sizePolicy3.setHeightForWidth(channelLcd->sizePolicy().hasHeightForWidth());
        channelLcd->setSizePolicy(sizePolicy3);

        gridLayout_4->addWidget(channelLcd, 0, 1, 1, 1);

        volumeNowLabel = new QLabel(centralwidget);
        volumeNowLabel->setObjectName(QString::fromUtf8("volumeNowLabel"));
        sizePolicy3.setHeightForWidth(volumeNowLabel->sizePolicy().hasHeightForWidth());
        volumeNowLabel->setSizePolicy(sizePolicy3);
        volumeNowLabel->setFont(font);

        gridLayout_4->addWidget(volumeNowLabel, 1, 0, 1, 1);

        volumeProgress = new QProgressBar(centralwidget);
        volumeProgress->setObjectName(QString::fromUtf8("volumeProgress"));
        sizePolicy3.setHeightForWidth(volumeProgress->sizePolicy().hasHeightForWidth());
        volumeProgress->setSizePolicy(sizePolicy3);
        volumeProgress->setValue(30);
        volumeProgress->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        volumeProgress->setTextVisible(true);
        volumeProgress->setOrientation(Qt::Horizontal);
        volumeProgress->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_4->addWidget(volumeProgress, 1, 1, 1, 1);


        verticalLayout->addLayout(gridLayout_4);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 240, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(button1, SIGNAL(clicked()), MainWindow, SLOT(key1()));
        QObject::connect(button2, SIGNAL(clicked()), MainWindow, SLOT(key2()));
        QObject::connect(button3, SIGNAL(clicked()), MainWindow, SLOT(key3()));
        QObject::connect(button4, SIGNAL(clicked()), MainWindow, SLOT(key4()));
        QObject::connect(button5, SIGNAL(clicked()), MainWindow, SLOT(key5()));
        QObject::connect(button6, SIGNAL(clicked()), MainWindow, SLOT(key6()));
        QObject::connect(button7, SIGNAL(clicked()), MainWindow, SLOT(key7()));
        QObject::connect(button8, SIGNAL(clicked()), MainWindow, SLOT(key8()));
        QObject::connect(button9, SIGNAL(clicked()), MainWindow, SLOT(key9()));
        QObject::connect(button10, SIGNAL(clicked()), MainWindow, SLOT(key0()));
        QObject::connect(channelUp, SIGNAL(clicked()), MainWindow, SLOT(channelUp()));
        QObject::connect(channelDown, SIGNAL(clicked()), MainWindow, SLOT(channelDown()));
        QObject::connect(volumeUp, SIGNAL(clicked()), MainWindow, SLOT(volumeUp()));
        QObject::connect(volumDown, SIGNAL(clicked()), MainWindow, SLOT(volumeDown()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        button8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        button7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        button10->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        button5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        button1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        button4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        button3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        button9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        button6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        button2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        volumeUp->setText(QCoreApplication::translate("MainWindow", "Vol +", nullptr));
        channelDown->setText(QCoreApplication::translate("MainWindow", "CH -", nullptr));
        volumDown->setText(QCoreApplication::translate("MainWindow", "Vol -", nullptr));
        channelUp->setText(QCoreApplication::translate("MainWindow", "CH +", nullptr));
        channelNowLabel->setText(QCoreApplication::translate("MainWindow", "Channel", nullptr));
        volumeNowLabel->setText(QCoreApplication::translate("MainWindow", "Volumn", nullptr));
        volumeProgress->setFormat(QCoreApplication::translate("MainWindow", "%p%", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REMOTE_CONTROL_H
