#include <iostream>
#define OVERLOAD(passengers) (passengers > 20) ? 1 : 0
#define EMPTY(passengers) (passengers == 0) ? 1 : 0
#define ALL_CARS(action,car) action ## car
#define CALL_FUNC(name_func) for (int i = 0; i < 10; i++) {name_func(i, cars[i]);}

void OverloadCar(int index, int count) {
    if (count > 20) {
        std::cout << "Overload car : " << index << std::endl;
    }
}

void EmptyCar(int index, int count) {
    if (count == 0) {
        std::cout << "Empty car: " << index << std::endl;
    }

}
int count_passengers = 0;
void SumAllPassengersInCar(int index, int count)  {
    count_passengers += count;
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
    CALL_FUNC(ALL_CARS(Overload,Car));
    CALL_FUNC(ALL_CARS(Empty,Car));
    CALL_FUNC(ALL_CARS(SumAllPassengersIn,Car));
    std::cout << "All passengers: " << count_passengers << std::endl;
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