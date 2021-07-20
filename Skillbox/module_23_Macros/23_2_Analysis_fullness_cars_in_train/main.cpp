#include <iostream>
#define OVERLOAD(passengers) (passengers > 20) ? 1 : 0
#define EMPTY(passengers) (passengers == 0) ? 1 : 0


void Overload(int passengers[]) {
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        count += OVERLOAD(passengers[i]);
    }
    std::cout << "Overload car: " << count << std::endl;
}

void Empty(int passengers[]) {
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        count += EMPTY(passengers[i]);
    }
    std::cout << "Empty car: " << count << std::endl;
}

void Sum(int passengers[]) {
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        count += passengers[i];
    }
    std::cout << "All passengers: " << count << std::endl;
}


int main() {
    std::cout << "Analysis fullness cars in train" << std::endl;
    std::cout << "Enter count passengers in car train: " << std::endl;
    int car[10];
    for (int i = 0; i < 10; ++i) {
        std::cout << "Car " << i << ": " << std::endl;
        std::cin >> car[i];
    }

    //Вариант 1
    Overload(car);
    Empty(car);
    Sum(car);

    //Вариант 2
/*  int OverloadCount = 0;
    int EmptyCount = 0;
    int SumCount = 0;
    for (int i = 0; i < 10; ++i) {
        OverloadCount += OVERLOAD(car[i]);
        EmptyCount += EMPTY(car[i]);
        SumCount += car[i];
    }
    std::cout << "Overload car: " << OverloadCount << std::endl;
    std::cout << "Empty car: " << EmptyCount << std::endl;
    std::cout << "All passengers: " << SumCount << std::endl;
*/
    return 0;
}
/*
Задание 2. Анализ заполненности вагонов в поезде


Что нужно сделать

В поезде всего 10 вагонов. В каждом из этих вагонов может находиться до 20-ти пассажиров — это оптимальное их
 количество. Проанализируйте количество людей в каждом из вагонов и сначала сообщите об излишне заполненных вагонах,
 далее о вагонах с пустыми пассажирскими местами. В заключении выведите общее количество пассажиров во всех вагонах.

При старте программы пользователь вводит количество пассажиров в каждом из вагонов. Замечания о вагонах должны
 выводиться в стандартную консоль.

При выполнении задания пользоваться for-циклами напрямую не разрешается, только опосредованно, через макросы.



Советы и рекомендации

С помощью макроса реализуйте модульный способ вызова функции-предиката над элементами массива. Сами функции-предикаты
 реализуйте отдельно, в виде обычных классических функций (не макросов).

Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью “Shift-Shift -> Preprocess current TU”.



Что оценивается

Корректность работы программы. Модульность и элегантность решения с помощью макросов.
 */