#include <iostream>
int* reverse (int* pArr, int ArrNew[]) {
    int j = 0;
    for (int i = 9; i >= 0; i--){
        ArrNew[i] = *(pArr + j);
        j++;
    }
    return ArrNew;
}

int main() {
    int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int arrayNew[10];
    int* pArrNew =  reverse(array, arrayNew);

    //output
    std::cout << "arrNew : ";
    for (int i = 0; i < 10; ++i) {
        std::cout << *(pArrNew + i)<< " ";
    }

    return 0;
}
/*
Задача 2.

Что нужно сделать:

Написать функцию, которая принимает указатель на тип int, по которому размещены 10 переменных типа int. Функция должна
 вернуть другой указатель на int, по которому лежат те же элементы, но в обратном порядке

Чек-лист для проверки задачи

Функция принимает корректные типы данных, тип возвращаемого значения --  int*
Функция не использует библиотек кроме <iostream>
По новому указателю лежат переменные в обратном порядке


Как отправить задание на проверку
 */