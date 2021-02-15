#include <iostream>
#include <vector>

void swapvec(std::vector<int>& v, int arr[]) {
    for (int i = 0; i < v.size(); i++) {
        int tmp = v[i];
        v[i] = arr[i];
        arr[i] = tmp;

    }
}

int main() {
    std::vector<int>  vec = {1, 2, 3, 4};
    int array[] = {2, 4, 6, 8};
    swapvec(vec, array);
    std::cout << "vec = ";
    for(int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "array = ";
    for(int i = 0; i < sizeof(array)/ sizeof(int); i++) {
        std::cout << array[i] << " ";
    }
    return 0;
}
/*
Задача 1
Что нужно сделать

Напишите функцию swapvec, принимающую std::vector<int> и указатель на массив переменных типа int (одного размера) и
 обменивающую значения этих массивов.

Пример:

std::vector<int> a = {1,2,3,4};

int b[] = {2,4,6,8};

swapvec(a,b);

for(int i = 0; i < 4; ++i)

   std::cout << a[i];

std::cout << std::endl;

for(int i = 0; i < 4; ++i)

   std::cout << b[i];


Вывод:

2468

1234



Чек-лист для проверки задачи

Функция принимает корректные типы данных, тип возвращаемого значения — void.
Функция не использует библиотек кроме <iostream> и <vector>.
Функция меняет значения между объектами.
Вектор передаётся по ссылке.


Как отправить задание на проверку

Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.
 */