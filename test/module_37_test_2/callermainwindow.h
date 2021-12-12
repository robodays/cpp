

#ifndef MODULE_37_TEST_2_CALLERMAINWINDOW_H
#define MODULE_37_TEST_2_CALLERMAINWINDOW_H

#include "QMainWindow"
#include <QtWidgets/QLineEdit>

class CallerMainWindow : public QMainWindow {
    Q_OBJECT
public:

    QLineEdit *lineEdit = nullptr;
    CallerMainWindow(QWidget *parent = nullptr) : QMainWindow(parent){};

    void addPlus() {
        if (lineEdit->text() == "") lineEdit->setText("+");
    };

public slots:
    void add0() {addPlus();lineEdit->setText(lineEdit->text() + "0");};
    void add1() {addPlus();lineEdit->setText(lineEdit->text() + "1");};
    void add2() {addPlus();lineEdit->setText(lineEdit->text() + "2");};
    void add3() {addPlus();lineEdit->setText(lineEdit->text() + "3");};
    void add4() {addPlus();lineEdit->setText(lineEdit->text() + "4");};
    void add5() {addPlus();lineEdit->setText(lineEdit->text() + "5");};
    void add6() {addPlus();lineEdit->setText(lineEdit->text() + "6");};
    void add7() {addPlus();lineEdit->setText(lineEdit->text() + "7");};
    void add8() {addPlus();lineEdit->setText(lineEdit->text() + "8");};
    void add9() {addPlus();lineEdit->setText(lineEdit->text() + "9");};
    void makeCall() {lineEdit->setText(lineEdit->text() + " call");};
};



#endif //MODULE_37_TEST_2_CALLERMAINWINDOW_H
