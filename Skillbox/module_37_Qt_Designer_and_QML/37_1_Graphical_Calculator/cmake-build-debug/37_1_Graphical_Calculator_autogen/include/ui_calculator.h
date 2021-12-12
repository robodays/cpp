/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLineEdit *operand2;
    QLabel *result;
    QLineEdit *operand1;
    QLabel *textResult;
    QGridLayout *gridLayout_2;
    QPushButton *buttonSub;
    QPushButton *buttonMult;
    QPushButton *buttonAdd;
    QPushButton *buttonDiv;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(573, 321);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        operand2 = new QLineEdit(centralwidget);
        operand2->setObjectName(QString::fromUtf8("operand2"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(operand2->sizePolicy().hasHeightForWidth());
        operand2->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(25);
        operand2->setFont(font);
        operand2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(operand2, 0, 1, 1, 1);

        result = new QLabel(centralwidget);
        result->setObjectName(QString::fromUtf8("result"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(result->sizePolicy().hasHeightForWidth());
        result->setSizePolicy(sizePolicy1);
        result->setFont(font);

        gridLayout->addWidget(result, 1, 1, 1, 1);

        operand1 = new QLineEdit(centralwidget);
        operand1->setObjectName(QString::fromUtf8("operand1"));
        sizePolicy.setHeightForWidth(operand1->sizePolicy().hasHeightForWidth());
        operand1->setSizePolicy(sizePolicy);
        operand1->setFont(font);
        operand1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(operand1, 0, 0, 1, 1);

        textResult = new QLabel(centralwidget);
        textResult->setObjectName(QString::fromUtf8("textResult"));
        sizePolicy1.setHeightForWidth(textResult->sizePolicy().hasHeightForWidth());
        textResult->setSizePolicy(sizePolicy1);
        textResult->setFont(font);
        textResult->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(textResult, 1, 0, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        buttonSub = new QPushButton(centralwidget);
        buttonSub->setObjectName(QString::fromUtf8("buttonSub"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(buttonSub->sizePolicy().hasHeightForWidth());
        buttonSub->setSizePolicy(sizePolicy2);
        buttonSub->setFont(font);
        buttonSub->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 255, 135);"));

        gridLayout_2->addWidget(buttonSub, 0, 1, 1, 1);

        buttonMult = new QPushButton(centralwidget);
        buttonMult->setObjectName(QString::fromUtf8("buttonMult"));
        sizePolicy2.setHeightForWidth(buttonMult->sizePolicy().hasHeightForWidth());
        buttonMult->setSizePolicy(sizePolicy2);
        buttonMult->setFont(font);
        buttonMult->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 255, 135);"));

        gridLayout_2->addWidget(buttonMult, 0, 2, 1, 1);

        buttonAdd = new QPushButton(centralwidget);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));
        sizePolicy2.setHeightForWidth(buttonAdd->sizePolicy().hasHeightForWidth());
        buttonAdd->setSizePolicy(sizePolicy2);
        buttonAdd->setFont(font);
        buttonAdd->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 255, 135);"));

        gridLayout_2->addWidget(buttonAdd, 0, 0, 1, 1);

        buttonDiv = new QPushButton(centralwidget);
        buttonDiv->setObjectName(QString::fromUtf8("buttonDiv"));
        sizePolicy2.setHeightForWidth(buttonDiv->sizePolicy().hasHeightForWidth());
        buttonDiv->setSizePolicy(sizePolicy2);
        buttonDiv->setFont(font);
        buttonDiv->setStyleSheet(QString::fromUtf8("background-color: rgb(131, 255, 135);"));

        gridLayout_2->addWidget(buttonDiv, 0, 3, 1, 1);


        verticalLayout_2->addLayout(gridLayout_2);


        gridLayout_5->addLayout(verticalLayout_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 573, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(buttonAdd, SIGNAL(clicked()), MainWindow, SLOT(add()));
        QObject::connect(buttonSub, SIGNAL(clicked()), MainWindow, SLOT(div()));
        QObject::connect(buttonMult, SIGNAL(clicked()), MainWindow, SLOT(mult()));
        QObject::connect(buttonDiv, SIGNAL(clicked()), MainWindow, SLOT(sub()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        operand2->setPlaceholderText(QCoreApplication::translate("MainWindow", "0", nullptr));
        result->setText(QString());
        operand1->setPlaceholderText(QCoreApplication::translate("MainWindow", "0", nullptr));
        textResult->setText(QCoreApplication::translate("MainWindow", "Result: ", nullptr));
        buttonSub->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        buttonMult->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        buttonAdd->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        buttonDiv->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
