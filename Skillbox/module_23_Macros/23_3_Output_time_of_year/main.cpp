#include <iostream>
//#define SPRING
//#define SUMMER
#define AUTUMN
//#define WINTER

#ifdef SPRING
int main() {
    std::cout << "SPRING" << std::endl;
    return 0;
}
#endif
#ifdef SUMMER
int main() {
    std::cout << "SUMMER" << std::endl;
    return 0;
}
#endif
#ifdef AUTUMN
int main() {
    std::cout << "AUTUMN" << std::endl;
    return 0;
}
#endif
#ifdef WINTER
int main() {
    std::cout << "WINTER" << std::endl;
    return 0;
}
#endif

/*
Задание 3. Вывод времени года


Что нужно сделать

Используя макросы вместе с условными директивами прекомпиляции (#if / #endif), реализуйте простую программу по выводу
 названия времени года в консоль.

Пользователь программы в данном случае сам программист. С помощью определения одного из макросов: SPRING, SUMMER,
 AUTUMN или WINTER, он задаёт сезон, название которого хочет увидеть на экране. При компиляции и запуске программы на
 экране должно появиться название именно этого сезона и только его.



Советы и рекомендации

Так как препроцессор работает вообще до компиляции, то в #if / #endif директивы вы можете обернуть всю функцию main
 сразу.

Обязательно просмотрите итоговый код после препроцессинга из CLion с помощью “Shift-Shift -> Preprocess current TU”.



Что оценивается

Корректность работы программы при разных заданных дефинициях макросов.


 */