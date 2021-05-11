#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {2, 7, 11, 3, 6, 15};
    int result;
    std::cout << "Enter result:" << std::endl;
    std::cin >> result;
    int id1, id2;

    bool ok = false;
    for (int i = 0; i < vec.size() - 1 && !ok; ++i) {
        for (int j = i + 1; j < vec.size() && !ok; ++j) {
            if (i != j && vec[i] + vec[j] == result) {

                id1 = i;
                id2 = j;
                ok = true;
            }
        }
    }
    if (ok) {
        std::cout << vec[id1] << " + " << vec[id2] << " = " << result << std::endl;
    } else {
        std::cout << "The sum does not give the result!" << std::endl;
    }
    return 0;
}

/*
Задача 2

Вам даётся массив целых чисел и одно число -- результат. Необходимо найти в массиве 2 числа, сумма которых будет
 давать результат, и вывести их на экран. Гарантируется, что только одна пара чисел в массиве даёт в сумме результат.

Пример:

a = {2, 7, 11, 15}. Результат = 9

2 + 7 = 9, так что надо вывести числа 2 и 7


*/