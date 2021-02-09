#include <iostream>

double TwoIntToDouble(int integer, int fraction);
int Input(const std::string& nameValue);

int main() {
    std::cout << "Fractional Number Stapler!" << std::endl;
    int integer;
    int fraction;
    double fractionalNumber;

    integer = Input ("integer");
    fraction = Input ("fraction");
    fractionalNumber = TwoIntToDouble(integer, abs(fraction));
    std::cout << "Fractional number " << fractionalNumber;

    return 0;
}

double TwoIntToDouble(int integer, int fraction) {
    return std::stod(std::to_string(integer) + "." + std::to_string(fraction));
}

int Input(const std::string& nameValue) {
    int value;
    std::cout << "Enter the " << nameValue << " part of the number: " << std::endl;
    std::cin >> value;
    return value;
}

/*Сшиватель дробных чисел

Что нужно сделать

Надо написать небольшую программу. Из целой и дробной частей числа, которые в отдельности вводит пользователь надо
 составить новое число с плавающей точкой (типа double) и вывести это число обратно в консоль, для проверки. Целая
 часть - это та, часть числа, которая находится до точки (запятой), дробная - после.*/