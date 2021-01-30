#include <iostream>
#include <vector>

int FuncInput(std::vector<int> &vec);
void FuncSort(std::vector<int> &vec);
void FuncOutput(std::vector<int> &vec, int num);

int main() {
    std::vector<int> vec;
    int element;
    std::cout << "Enter digits array:";
    do {
        element = FuncInput(vec);
        if (element == -1) {
            FuncSort(vec);
            FuncOutput(vec, 5);
        }
    } while (element != -2);
    return 0;
}

int FuncInput(std::vector<int> &vec) {
    int num;
    std::cin >> num;
    if (num != -1 && num != -2) {
        vec.push_back(num);
    }
    return num;
}

void FuncSort(std::vector<int> &vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size() - 1 - i; ++j) {
            if(vec[j] > vec[j+1]) {
                int tmp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = tmp;
            }
        }
    }
}

void FuncOutput(std::vector<int> &vec, int num) {
    std::cout << "Answer: " << vec[num-1] << std::endl;
    std::cout << "Sort array: ";
    for (int i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

/*
 * С клавиатуры вводятся числа. Когда пользователь вводит -1 -- необходимо выводить на экран пятое по возрастанию
 * число среди введённых. Когда пользователь вводит -2 -- программа завершает работу.

Пример:

ввод: 7 5 3 1 2 4 6 -1

вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})

ввод: 1 1 1 -1

вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})

ввод -2

завершение программы

*/