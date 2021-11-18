#include <iostream>

template <typename T>
void input(T arr[]) {
    std::cout << "Enter 5 numbers (typename int, double, float): " << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "number " << i + 1 << ":";
        std::cin >> arr[i];
    }
    std::cout << std::endl;
}

template <typename T>
void ArithmeticMean (const T arr[]) {
    T sum = 0;
    for(int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    std::cout << "Arithmetic mean = " << sum / 5 << std::endl;
}

int main() {
    std::cout << "Arithmetic mean in the array" << std::endl;

    double arr[5];

    input(arr);

    ArithmeticMean(arr);

    return 0;
}

/*
Среднее арифметическое в массиве


Что нужно сделать
Реализуйте шаблонную функцию подсчёта среднего арифметического числа в массиве скалярных чисел произвольного типа. Это
 может быть int, double, float и так далее.

Ввод данных массива и вывод результата производится через стандартную консоль.



Советы и рекомендации
Для простоты вы можете реализовать подсчёт в массиве фиксированной длины. Функцию ввода данных массива тоже
 рекомендуется реализовать как шаблонную.



Что оценивается
Корректность работы программы при различных пользовательских данных и различных типах используемых данных массива.
 */