#include <iostream>
#define OVERLOAD(passengers) (passengers > 20) ? 1 : 0
#define EMPTY(passengers) (passengers == 0) ? 1 : 0
#define ALL_CARS(action,car) action ## car

void OverloadCar(int cars[]) {
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        count += OVERLOAD(cars[i]);
    }
    std::cout << "Overload car: " << count << std::endl;
}

void EmptyCar(int cars[]) {
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        count += EMPTY(cars[i]);
    }
    std::cout << "Empty car: " << count << std::endl;
}

void SumAllPassengersInCar(int cars[]) {
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        count += cars[i];
    }
    std::cout << "All passengers: " << count << std::endl;
}

void InputCar(int cars[]){
    std::cout << "Analysis fullness cars in train" << std::endl;
    std::cout << "Enter count passengers in car train: " << std::endl;

    for (int i = 0; i < 10; ++i) {
        std::cout << "Car " << i << ": " << std::endl;
        std::cin >> cars[i];
    }
}

int main() {
    int cars[10];
    ALL_CARS(Input,Car)(cars);
    ALL_CARS(Overload,Car)(cars);
    ALL_CARS(Empty,Car)(cars);
    ALL_CARS(SumAllPassengersIn,Car)(cars);
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