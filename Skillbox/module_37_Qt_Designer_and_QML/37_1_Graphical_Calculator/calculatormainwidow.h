#ifndef INC_37_1_GRAPHICAL_CALCULATOR_CALCULATORMAINWIDOW_H
#define INC_37_1_GRAPHICAL_CALCULATOR_CALCULATORMAINWIDOW_H

#include "QMainWindow"
#include <QLineEdit>
#include <QLabel>

class CalculatorMainWindow : public QMainWindow {
    Q_OBJECT
public:

    QLineEdit *operand1 = nullptr;
    QLineEdit *operand2 = nullptr;
    QLabel *result = nullptr;

    CalculatorMainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {};

    bool isNum(QLineEdit *lineEdit) const {
        bool ok;
        lineEdit->text().toDouble(&ok);
        return ok;
    }

public slots:

    void add() const {
        if (isNum(operand1) && isNum(operand2)) {
            result->setText(QString::number(operand1->text().toDouble() + operand2->text().toDouble()));
        } else {
            result->setText("ERROR");
        }
    };

    void sub() const {
        if (isNum(operand1) && isNum(operand2)) {
            result->setText(QString::number(operand1->text().toDouble() - operand2->text().toDouble()));
        } else {
            result->setText("ERROR");
        }
    };

    void mult() const {
        if (isNum(operand1) && isNum(operand2)) {
            result->setText(QString::number(operand1->text().toDouble() * operand2->text().toDouble()));
        } else {
            result->setText("ERROR");
        }
    };

    void div() const {
        if (operand2->text().toDouble()  != 0 && isNum(operand1) && isNum(operand2)) {
            result->setText(QString::number(operand1->text().toDouble() / operand2->text().toDouble()));
        } else {
            result->setText("ERROR");
        }
    };

};



#endif //INC_37_1_GRAPHICAL_CALCULATOR_CALCULATORMAINWIDOW_H
