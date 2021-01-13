#include <iostream>
#include <cmath>

bool fitnessClub[2];
bool shop[1];
bool cottage[3];
bool house[15];
bool skyscraper[50];



int main() {
    float arithmeticAverage;
    arithmeticAverage = (sizeof(fitnessClub) + sizeof(shop) + sizeof(cottage) + sizeof(house) + sizeof(skyscraper)) / 5.0;
    std::cout << "Arithmetic average number of floors: " << round(arithmeticAverage) << std::endl;
    return 0;
}
/*
 *С помощью массивов объявите 5 зданий, каждый элемент которых будет обозначать отдельный этаж.
 * Это могут быть совершенно разные здания: фитнес-клуб (2 этажа), магазин (1 этаж), коттедж (3 этажа),
 * квартирный дом (15) и небоскрёб (50 этажей). Используя среднее арифметическое число, узнайте итоговую
 * этажность вашего “квартала”.
 *
 * */