#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
/*
Анаграммы


Что нужно сделать

Напишите функцию, которая принимает две строки и возвращает true, если первая строка является анаграммой второй (то есть можно получить первую строку из второй путём перестановки букв местами), и false иначе. Для достижения хорошей асимптотики решения рекомендуется использовать std::map.

Пример анаграммы: лекарство — стекловар



Чек-лист для проверки задачи

Функция принимает корректные типы данных, тип возвращаемого значения — bool.
Функция не использует библиотек, кроме <iostream>, <map>, <string>.
Функция корректно определяет, являются ли строки анаграммами.

 */