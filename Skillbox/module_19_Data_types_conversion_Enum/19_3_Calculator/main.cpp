#include <iostream>

int main() {
    std::cout << "Calculator." << std::endl;
    std::cout << "Enter an expression of two numbers: " << std::endl;
    std::cout << "input format (<num1><action><num2>) <num1> and <num2> type double" << std::endl;
    std::string inputStr;
    std::cin >> inputStr;
    std::string firstTerm = inputStr.find('*')

    return 0;
}
/*Калькулятор

Что нужно сделать

Требуется создать небольшую программу для вычисления простых действий с числами. При запуске программа ожидает
 пользовательского ввода во временную переменную строку. После ввода строки, она распарсивается на отдельные члены.
 Строка записывается в форме “<число-1><действие><число-2>” (без пробелов). Оба числа - это значения с плавающей
 точкой, повышенной точности (double). Действие может быть одним из: +, -, /, *. Результат действия выводится в
 стандартный вывод cout.*/