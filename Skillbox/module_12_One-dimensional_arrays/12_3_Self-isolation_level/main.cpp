#include <iostream>

int fiveStoreyHouse[5];

int main() {
    std::cout << "Input count residents: ";
    int countResidents;
    std::cin >> countResidents;

    for (int i = 0; i < sizeof(fiveStoreyHouse) / sizeof(fiveStoreyHouse[0]); ++i) {
        std::cout << "Input count self-isolation on " << i + 1 << " floor: ";
        std::cin >> fiveStoreyHouse[i];
    }
    int countIsolation = 0;

    for (int i = 0; i < sizeof(fiveStoreyHouse) / sizeof(fiveStoreyHouse[0]); ++i) {
        countIsolation += fiveStoreyHouse[i];
    }
    std::cout << "Self-isolation level " << countIsolation * 100 / countResidents << "%." << std::endl;
    return 0;
}

/*
 * В одной отдельно взятой пятиэтажке проживает N зарегистрированных жильцов - данное число требуется ввести с самого
 * начала программы. На каждом из этажей сейчас находится Ni людей. Это число также требуется ввести вначале. Используя
 * все эти данные требуется вычислить общий уровень самоизоляции в доме, как процентное отношение общего числа людей,
 * которые сейчас находятся на этажах к общему количеству жильцов, зарегистрированных в нём. Для этого можно
 * использовать формулу: (сумма Ni * 100) / N
 *
 *
 * */
