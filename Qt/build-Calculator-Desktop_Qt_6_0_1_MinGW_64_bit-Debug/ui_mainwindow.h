/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *result;
    QPushButton *pushButtonReset;
    QPushButton *pushButtonAddSub;
    QPushButton *pushButtonPercent;
    QPushButton *pushButtonDivision;
    QPushButton *pushButtonNum9;
    QPushButton *pushButtonNum8;
    QPushButton *pushButtonNum7;
    QPushButton *pushButtonMultiplying;
    QPushButton *pushButtonNum6;
    QPushButton *pushButtonNum5;
    QPushButton *pushButtonNum4;
    QPushButton *pushButtonSubtraction;
    QPushButton *pushButtonNum3;
    QPushButton *pushButtonNum2;
    QPushButton *pushButtonNum1;
    QPushButton *pushButtonAddition;
    QPushButton *pushButtonEqual;
    QPushButton *pushButtonNum0;
    QPushButton *pushButtonPoint;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(235, 365);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        result = new QLabel(centralwidget);
        result->setObjectName(QString::fromUtf8("result"));
        result->setGeometry(QRect(0, 0, 231, 61));
        QFont font;
        font.setPointSize(20);
        result->setFont(font);
        pushButtonReset = new QPushButton(centralwidget);
        pushButtonReset->setObjectName(QString::fromUtf8("pushButtonReset"));
        pushButtonReset->setGeometry(QRect(-1, 70, 61, 61));
        pushButtonAddSub = new QPushButton(centralwidget);
        pushButtonAddSub->setObjectName(QString::fromUtf8("pushButtonAddSub"));
        pushButtonAddSub->setGeometry(QRect(58, 70, 61, 61));
        pushButtonPercent = new QPushButton(centralwidget);
        pushButtonPercent->setObjectName(QString::fromUtf8("pushButtonPercent"));
        pushButtonPercent->setGeometry(QRect(117, 70, 61, 61));
        pushButtonDivision = new QPushButton(centralwidget);
        pushButtonDivision->setObjectName(QString::fromUtf8("pushButtonDivision"));
        pushButtonDivision->setGeometry(QRect(176, 70, 61, 61));
        pushButtonNum9 = new QPushButton(centralwidget);
        pushButtonNum9->setObjectName(QString::fromUtf8("pushButtonNum9"));
        pushButtonNum9->setGeometry(QRect(117, 129, 61, 61));
        pushButtonNum8 = new QPushButton(centralwidget);
        pushButtonNum8->setObjectName(QString::fromUtf8("pushButtonNum8"));
        pushButtonNum8->setGeometry(QRect(58, 129, 61, 61));
        pushButtonNum7 = new QPushButton(centralwidget);
        pushButtonNum7->setObjectName(QString::fromUtf8("pushButtonNum7"));
        pushButtonNum7->setGeometry(QRect(-1, 129, 61, 61));
        pushButtonMultiplying = new QPushButton(centralwidget);
        pushButtonMultiplying->setObjectName(QString::fromUtf8("pushButtonMultiplying"));
        pushButtonMultiplying->setGeometry(QRect(176, 129, 61, 61));
        pushButtonNum6 = new QPushButton(centralwidget);
        pushButtonNum6->setObjectName(QString::fromUtf8("pushButtonNum6"));
        pushButtonNum6->setGeometry(QRect(117, 188, 61, 61));
        pushButtonNum5 = new QPushButton(centralwidget);
        pushButtonNum5->setObjectName(QString::fromUtf8("pushButtonNum5"));
        pushButtonNum5->setGeometry(QRect(58, 188, 61, 61));
        pushButtonNum4 = new QPushButton(centralwidget);
        pushButtonNum4->setObjectName(QString::fromUtf8("pushButtonNum4"));
        pushButtonNum4->setGeometry(QRect(-1, 188, 61, 61));
        pushButtonSubtraction = new QPushButton(centralwidget);
        pushButtonSubtraction->setObjectName(QString::fromUtf8("pushButtonSubtraction"));
        pushButtonSubtraction->setGeometry(QRect(176, 188, 61, 61));
        pushButtonNum3 = new QPushButton(centralwidget);
        pushButtonNum3->setObjectName(QString::fromUtf8("pushButtonNum3"));
        pushButtonNum3->setGeometry(QRect(117, 247, 61, 61));
        pushButtonNum2 = new QPushButton(centralwidget);
        pushButtonNum2->setObjectName(QString::fromUtf8("pushButtonNum2"));
        pushButtonNum2->setGeometry(QRect(58, 247, 61, 61));
        pushButtonNum1 = new QPushButton(centralwidget);
        pushButtonNum1->setObjectName(QString::fromUtf8("pushButtonNum1"));
        pushButtonNum1->setGeometry(QRect(-1, 247, 61, 61));
        pushButtonAddition = new QPushButton(centralwidget);
        pushButtonAddition->setObjectName(QString::fromUtf8("pushButtonAddition"));
        pushButtonAddition->setGeometry(QRect(176, 247, 61, 61));
        pushButtonEqual = new QPushButton(centralwidget);
        pushButtonEqual->setObjectName(QString::fromUtf8("pushButtonEqual"));
        pushButtonEqual->setGeometry(QRect(176, 306, 61, 61));
        pushButtonNum0 = new QPushButton(centralwidget);
        pushButtonNum0->setObjectName(QString::fromUtf8("pushButtonNum0"));
        pushButtonNum0->setGeometry(QRect(-1, 306, 120, 61));
        pushButtonPoint = new QPushButton(centralwidget);
        pushButtonPoint->setObjectName(QString::fromUtf8("pushButtonPoint"));
        pushButtonPoint->setGeometry(QRect(117, 306, 61, 61));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        result->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButtonReset->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButtonAddSub->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButtonPercent->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButtonDivision->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButtonNum9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButtonNum8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButtonNum7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButtonMultiplying->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        pushButtonNum6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButtonNum5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButtonNum4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButtonSubtraction->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButtonNum3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButtonNum2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButtonNum1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButtonAddition->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButtonEqual->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButtonNum0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButtonPoint->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
