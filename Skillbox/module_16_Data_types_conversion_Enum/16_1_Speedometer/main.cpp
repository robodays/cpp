#include <iostream>
#include <cstdio>
#include <sstream>
#include <cmath>

bool compare(double value, double reference, double epsilon) {
    return value >= reference - epsilon && value <= reference + epsilon;
}

int main() {

    float speed = 0.0f;
    float delta = 0.01;
    float speedMin = 0;
    float speedMax = 150;
    char bufferStr1[20];
    std::stringstream bufferStr2;

    float diff;
    do {
        std::cout << "Enter the difference in speed: " << std::endl;
        std::cin >> diff;
        speed += diff;
        if (speed > speedMax) {
            speed = speedMax;
        } else if (speed < speedMin) {
            speed = speedMin;
            break;
        } else if (compare(speed, speedMin , delta)) {
            break;
        }
        // different output methods
        std::sprintf(bufferStr1, "Speed: %.1f %s", speed, "km/h (sprintf)");
        std::cout << bufferStr1 << std::endl;
        bufferStr2.str("");
        bufferStr2 << "Speed: " << round(speed * 10.0)/10.0f << " km/h (stringstream)";
        std::cout << bufferStr2.str() << std::endl;
        std::cout << "Speed: " << speed << " km/h (ordinary)" << std::endl;
    } while(true);
    bufferStr2.str("");
    bufferStr2 << "Speed: " << speed << " km/h";
    std::cout << round(speed * 10.0)/10 << std::endl;
    return 0;
}
/*Спидометр

Что нужно сделать

Надо реализовать цифровой спидометр автомобиля. Сама модель автомобиля, которую нужно будет воссоздать весьма проста.
 Начальная скорость - 0 км/ч. Пользователь вводит в стандартный ввод разницу (дельту) в скорости и результирующая
 скорость показывается на спидометре в стандартный вывод. Так происходит до той поры, пока машина снова не
 остановится, т.е. пока скорость не станет меньше или равна нулю (сравнение должно происходить с дельтой в 0.01).
 Диапазон возможных значений скорости машины от 0 до 150 км/ч. Сам показатель спидометра, вместе с единицами
 измерения, требуется записывать в отдельную строку-буфер, которая потом и будет показываться на экране. Точность
 отображения скорость до 0.1 км/ч.*/