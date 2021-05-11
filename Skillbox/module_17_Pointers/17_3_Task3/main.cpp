#include <iostream>

bool substr(char* pstr1, char* pstr2) {
    int i = 0;
    int j = 0;
    while (*(pstr1 + i) != '\0') {
        if (*(pstr1 + i) == *(pstr2 + j)) {
            j++;
            if (*(pstr2 + j) == '\0') return true;
        } else {
            j = 0;
        }
        i++;
    }
    return false;
}

int main() {
    char str[] = "Hello, World!";
    char stra[] = "World";
    char strb[] = "banana";
    std::cout << "substr(str,stra) " << (substr(str, stra) ? "true" : "false") << std::endl;
    std::cout << "substr(str,strb) " << (substr(str, strb) ? "true" : "false") << std::endl;
    return 0;
}
// если написать char* stra = "World"; выдается предупреждение: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]



/*
 Задача 3.

Что нужно сделать:

Написать функцию, которая принимаем указатель на char, по которому лежит строка.

Функция должна возвращать true, если вторая строка является подстрокой первой.



Пример:

char* a = “Hello world”;

char* b = “wor”;

char* c = “banana”;

std::cout << substr(a,b) << “ “ << substr(a,c);

// true false


Чек-лист для проверки задачи

Функция принимает корректные типы данных, тип возвращаемого значения -- bool
Функция не использует библиотек кроме <iostream>
Функция корректно определяет, является ли вторая строка подстрокой первой
 */