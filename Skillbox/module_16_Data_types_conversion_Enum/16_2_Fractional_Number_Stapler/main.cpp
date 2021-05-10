#include <iostream>

double TwoIntToDouble(std::string integer, std::string fraction);
std::string Input(const std::string& nameValue);

int main() {
    std::cout << "Fractional Number Stapler!" << std::endl;
    std::string integer;
    std::string fraction;
    double fractionalNumber;

    integer = Input ("integer");
    fraction = Input ("fraction");
    fractionalNumber = TwoIntToDouble(integer, fraction);
    std::cout << "Fractional number " << fractionalNumber;

    return 0;
}

double TwoIntToDouble(std::string integer, std::string fraction) {
    return std::stod(integer + "." + fraction);
}


std::string Input(const std::string& nameValue) {
    std::string value;
    std::cout << "Enter the " << nameValue << " part of the number: " << std::endl;
    std::cin >> value;
    return value;
}

/*Сшиватель дробных чисел

Что нужно сделать

Надо написать небольшую программу. Из целой и дробной частей числа, которые в отдельности вводит пользователь надо
 составить новое число с плавающей точкой (типа double) и вывести это число обратно в консоль, для проверки. Целая
 часть - это та, часть числа, которая находится до точки (запятой), дробная - после.*/