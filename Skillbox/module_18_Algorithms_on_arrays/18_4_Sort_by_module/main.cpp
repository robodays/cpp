#include <iostream>
#include <vector>

int Abs(int num);
void SortABS(std::vector<int> &vec);
void Output(std::vector<int> &vec);

int main() {
    std::vector<int> vec = {-100,-50, -5, 1, 10, 15};
    std::cout << "Sort array: ";
    Output(vec);

    SortABS(vec);
    std::cout << "Sort array by module: ";
    Output(vec);
    return 0;
}

// without functions <cmath>
int  Abs(int num) {
    return num < 0 ? -num : num;
}

void SortABS(std::vector<int> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size() - 1 - i; ++j) {
            if(Abs(vec[j]) > Abs(vec[j+1])) {
                int tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
            }
        }
    }
}

void Output(std::vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << (i != vec.size() - 1 ? ", " : "");
    }
    std::cout << std::endl;
}

/*Задача 4

Вам даётся массив целых чисел, отсортированных по возрастанию. Необходимо вывести его на экран отсортированным в
 порядке возрастания модуля чисел

Пример:

Массив {-100,-50, -5, 1, 10, 15}

Вывод: 1, -5, 10, 15, -50, -100

Задание со звёздочкой: оптимизировать решение четвёртой задачи, чтобы оно совершало как можно меньше операций

*/