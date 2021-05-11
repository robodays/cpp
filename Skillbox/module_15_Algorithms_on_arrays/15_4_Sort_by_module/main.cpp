#include <iostream>
#include <vector>

int Abs(int num);
void SortABS(std::vector<int> &vec);
void SortABS2(std::vector<int> &vec);
void Output(std::vector<int> &vec);
bool Compare(std::vector<int> &vec, int iMinus , int iPlus);

int main() {
    std::vector<int> vec = {-100,-50, -5, -1, 10, 15};
//    std::vector<int> vec = {-100,-50, -5, -1}; // for test
//    std::vector<int> vec = {1, 10, 15 , 200}; // for test
    std::cout << "Sort array: ";
    Output(vec);

    //SortABS(vec); // old function
    std::cout << "Sort array by module: ";
    SortABS2(vec); // new function
    //Output(vec); // for old function
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

void SortABS2(std::vector<int> &vec) {
    int i = 0;
    while (vec[i] < 0) {
        i++;
    }
    if (i == vec.size()) i--; //if all digits are less than zero
    std::cout << vec[i] << " ";
    int iMinus = i - 1;
    int iPlus = i + 1;
    while (iMinus >= -1 && iPlus <= vec.size()) {
        if ((Compare(vec, iMinus, iPlus) || iPlus > vec.size() - 1) && iMinus >= 0) {
            std::cout << vec[iMinus] << " ";
            iMinus--;
        } else if ((!Compare(vec, iMinus, iPlus) || iMinus < 0) && iPlus <= vec.size() - 1){
            std::cout << vec[iPlus] << " ";
            iPlus++;
        } else break;
    }
}

bool Compare(std::vector<int> &vec, int iMinus , int iPlus) {
    return Abs(vec[iMinus]) < vec [iPlus];
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