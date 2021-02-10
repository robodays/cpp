#include <iostream>
char checkSign(std::string inputStr);
double FuncResult(double first, double second, char sing);

int main() {
    std::cout << "Calculator." << std::endl;
    std::cout << "Enter an expression of two numbers: " << std::endl;
    std::cout << "input format: <num1><action><num2>, where <num1> and <num2> type double, and <action> +, -, /, *" << std::endl;
    std::string inputStr;
    std::cin >> inputStr;

    char sing =  checkSign(inputStr);
    int findPosSing = inputStr.find(sing,1);

    double first = std::stod(inputStr.substr(0,findPosSing));
    double second = std::stod(inputStr.substr(findPosSing + 1,inputStr.length()));
    double result = FuncResult (first, second, sing);

    std::cout << "Result " << first << " " << sing << " " << second << " = " <<  result << std::endl;

    return 0;
}

char checkSign(std::string inputStr) {
    char sing[4] = { '*', '/', '+', '-'};
    for (char ch : sing) {
        int pos = inputStr.find(ch,1);
        if (pos > 0) {
            return ch;
        }
    }
    return '0';
}

double FuncResult(double first, double second, char sing) {
    if (sing == '+') return first + second;
    else if (sing == '-') return first - second;
    else if (sing == '*') return first * second;
    else if (second != 0) return first / second;
    else {
        std::cerr << "Error! Can't be divided by zero";
        return 0;
    }
}
/*Калькулятор

Что нужно сделать

Требуется создать небольшую программу для вычисления простых действий с числами. При запуске программа ожидает
 пользовательского ввода во временную переменную строку. После ввода строки, она распарсивается на отдельные члены.
 Строка записывается в форме “<число-1><действие><число-2>” (без пробелов). Оба числа - это значения с плавающей
 точкой, повышенной точности (double). Действие может быть одним из: +, -, /, *. Результат действия выводится в
 стандартный вывод cout.*/