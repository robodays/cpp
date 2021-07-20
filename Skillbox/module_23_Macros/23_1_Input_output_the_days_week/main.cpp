#include <iostream>
#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7
#define MONDAY_TEXT "Monday"
#define TUESDAY_TEXT "Tuesday"
#define WEDNESDAY_TEXT "Wednesday"
#define THURSDAY_TEXT "Thursday"
#define FRIDAY_TEXT "Friday"
#define SATURDAY_TEXT "Saturday"
#define SUNDAY_TEXT "Sunday"
#define CONCAT(a,b) a ## _ ## b

int main() {
    std::cout << "Input output the days week." << std::endl;
    int command;
    while (true) {
        std::cout << "Enter the number of the day of the week (1-7, 0 - exit): " << std::endl;
        std::cin >> command;

        if (MONDAY == command) {
            std::cout << CONCAT(MONDAY, TEXT) << std::endl;
        } else if (TUESDAY == command) {
            std::cout << CONCAT(TUESDAY, TEXT) << std::endl;
        } else if (WEDNESDAY == command) {
            std::cout << CONCAT(WEDNESDAY, TEXT) << std::endl;
        } else if (THURSDAY == command) {
            std::cout << CONCAT(THURSDAY, TEXT) << std::endl;
        } else if (FRIDAY == command) {
            std::cout << CONCAT(FRIDAY, TEXT) << std::endl;
        } else if (SATURDAY == command) {
            std::cout << CONCAT(SATURDAY, TEXT) << std::endl;
        } else if (SUNDAY == command) {
            std::cout << CONCAT(SUNDAY, TEXT) << std::endl;
        } else if (0 == command) {
            break;
        } else {
            std::cout << "Enter again!" << std::endl;
        }

    }
    return 0;
}
/*
Задание 1. Реализация продвинутый ввод и вывод дней недели


Что нужно сделать

Используя макросы, реализуйте небольшую программу по вводу дня недели и выводу этого дня недели в текстовом виде в
 консоль.

В начале программы пользователь вводит день недели в виде его порядкового номера. В результате в консоли появляется
 буквенное отображение этого дня недели.

В этом упражнении запрещается использовать классические переменные, кроме как для хранения ввода пользователя.
 Использовать строковые литералы напрямую тоже нельзя. Всё должно быть реализовано исключительно на макросах.



Советы и рекомендации

Конкатенация двух фрагментов может породить токен, который в свою очередь является именем макроса, и этот макрос тоже
 раскроется. Используйте данное свойство для перевода константы дня недели в строковый литерал.

Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью “Shift-Shift -> Preprocess current TU”.



Что оценивается

Корректность работы программы. Модульность и элегантность решения с помощью макросов.
*/