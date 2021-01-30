#include <iostream>

double TwoIntToDouble(int integer, int fraction) {
    return std::stod(std::to_string(integer) + "." + std::to_string(fraction));
}

int main() {
    std::cout << "Fractional Number Stapler!" << std::endl;
    int integer;
    int fraction;
    double fractionalNumber;

    std::cout << "Enter the integer part of the number: " << std::endl;
    std::cin >> integer;

    std::cout << "Enter the fractional part of the number: " << std::endl;
    std::cin >> fraction;

    fractionalNumber = TwoIntToDouble(integer, abs(fraction));
    std::cout << "Fractional number " << fractionalNumber;

    return 0;
}
/*Сшиватель дробных чисел

Что нужно сделать

Надо написать небольшую программу. Из целой и дробной частей числа, которые в отдельности вводит пользователь надо
 составить новое число с плавающей точкой (типа double) и вывести это число обратно в консоль, для проверки. Целая
 часть - это та, часть числа, которая находится до точки (запятой), дробная - после.*/