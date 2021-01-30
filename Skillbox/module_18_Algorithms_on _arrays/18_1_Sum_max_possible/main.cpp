#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    int maxSum = 0;
    int idBegin;
    int idEnd;
    for (int i = 0; i < vec.size(); ++i) {
        int sum = 0;
        for (int j = i; j < vec.size(); ++j) {
            sum += vec[j];
            if (sum > maxSum) {
                maxSum = sum;
                idBegin = i;
                idEnd = j;
            }
        }
    }

    std::cout << "Max Sum = " << maxSum << std::endl;
    std::cout << "Range id " << idBegin << " - " << idEnd << std::endl;
    return 0;
}

/*
Задача 1

Вам даётся массив целых чисел. Необходимо найти такие два индекса i и j в этом массиве, что сумма
 a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и вывести их.

Пример:

a = {-2,1,-3,4,-1,2,1,-5,4}

Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6: {4,-1,2,1}, сумма = 6.
 Необходимо вывести 3 и 6
*/