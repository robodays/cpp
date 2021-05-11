#include <iostream>
void swapPlaces (int* pa, int* pb) {
    int Tmp = *pa;
    *pa = *pb;
    *pb = Tmp;
}

int main() {
    int a = 10;
    int b = 20;
    std::cout << "a" << a << " " << "b" << b << std::endl;;
    swapPlaces(&a, &b);
    std::cout << "a" << a << " " << "b" << b << std::endl;;

    return 0;
}
//

/*Задача 1.

Что нужно сделать:

Написать функцию, принимающую два указателя на int и меняет местами содержимое данных указателей.

Пример:

int a = 10;

int b = 20;

swap(&a, &b);

std::cout << a << “ “ << b;

// 20 10


Чек-лист для проверки задачи

Функция принимает корректные типы данных, тип возвращаемого значения -- void
Функция не использует библиотек кроме <iostream>
Функция меняет значения по указателям
 */