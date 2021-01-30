#include <iostream>
#include <vector>

int main() {
    std::cout << "How many numbers do we enter? ";
    int count;
    std::cin >> count;

    std::vector<int> numbers(count);

    for (int i = 0; i < count; ++i) {
        std::cout << "Enter number №" << i << " : ";
        std::cin >> numbers[i];
    }

    int value;
    do {
        std::cout << "Enter a value from the list to delete? ";
        std::cin >> value;
        for (int i = 0; i < numbers.size(); ++i) {
            if (numbers[i] == value) {
               numbers.erase(numbers.begin() + i);
               i--;
            }
        }
        std::cout << (numbers.size()? "List: ":"");
        for (int i = 0; i < numbers.size(); ++i) {
            std::cout << numbers[i] << " ";
        }
        std::cout << "\n";
    } while (value != -1 && numbers.size() != 0);
    std::cout << "Exit!\n";
    return 0;
}
/*
 * Задача 1.

Пользователь вводит с клавиатуры число n, далее -- n целых чисел, которые нужно записать в вектор.

Потом пользователь вводит ещё одно значение. Нужно удалить из вектора все элементы, которые равны данному значению, и
 вывести итоговое состояние вектора

Пример:

Пользователь ввёл 5, потом числа 1, 3, 3, 5, 1. И потом -- число 3. Необходимо, чтобы в векторе остались числа 1, 5, 1,
которые надо вывести их на экран.
 * */