#include <QApplication>
#include "./ui_calculator.h"
#include "calculatormainwidow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    CalculatorMainWindow window(nullptr);
    Ui::MainWindow calculator;
    calculator.setupUi(&window);
    window.result = calculator.result;
    window.operand1 = calculator.operand1;
    window.operand2 = calculator.operand2;
    window.resize(200, 100);
    window.show();
    return QApplication::exec();
}
