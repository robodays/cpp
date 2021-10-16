#include <iostream>
#include <utility>
#include <vector>
#include <thread>
#include <mutex>
#include <string>
#include <windows.h>
#include <algorithm>

std::mutex update;

class Swimmer {
    std::string name;
    int speed;
    int distance = 0;
    int resultSec = 0;
public:
    Swimmer(std::string inName, int inSpeed): name(std::move(inName)), speed(inSpeed) {
    }

    std::string getName() const {
        return name;
    }

    int getSpeed() const {
        return speed;
    }

    int getDistance() const {
        return distance;
    }

    int getResultSec() const {
        return resultSec;
    }

    void distancePlus() {
        if (distance != 100) {
            resultSec++;
            if (distance < 100) {
                distance += speed;
            }
            if (distance > 100) {
                distance  = 100;
            }
        }
    }
};

bool allFinish(const std::vector<Swimmer*>& swimmers);

void swim(std::vector<Swimmer*> swimmers, int sec); // не получилось послать swimmer по ссылке. Ругается periods.emplace_back(std::thread(swim, swimmers, secFromBegin));

int maxIterations(std::vector<Swimmer*>& swimmers);

void sortResult(std::vector<Swimmer*>& swimmers);

int main() {

    std::cout << "100 - meter swim." << std::endl;

    std::vector<Swimmer*> swimmers;
    swimmers.reserve(6);
    for (int i = 0; i < 6; ++i) {
        /*// hand fill
        std::string nameSwimmer;
        std::cout << "Enter name " << i << " swimmer: " << std::endl;
        std::cin >> nameSwimmer;

        int speedSwimmer;
        std::cout << "Enter speed " << i << " swimmer: " << std::endl;
        std::cin >> speedSwimmer;
        swimmers.push_back(new Swimmer(nameSwimmer, speedSwimmer));
        */

        // autofill
        swimmers.push_back(new Swimmer("name" + std::to_string(i), (i + 5) * 2));
    }

    std::vector<std::thread> periods;

    int secFromBegin = 1;
    while (!allFinish(swimmers)) { // не выходит из цикла, пока стоит какая-нибудь задержка ниже по программе (Sleep(5000); или //std::this_thread::sleep_for(std::chrono::seconds(secFromBegin++));)
    //for (int i = 0; i < maxIterations(swimmers); i++) {  // так работает корректнее, так как заранее определено количество итераций
        periods.emplace_back(std::thread(swim, swimmers, secFromBegin));
        periods[secFromBegin - 1].detach();
        secFromBegin++;
    }

    //Sorting and output of results

    //std::this_thread::sleep_for(std::chrono::seconds(secFromBegin++));
    Sleep(5000);

    sortResult(swimmers);
    std::cout << "========= Result =========" << std::endl;
    for (int i = 0; i < 6; ++i) {
        std::cout << swimmers[i]->getName() << " -> " << swimmers[i]->getResultSec() << std::endl;
    }

    for (int i = 0; i < swimmers.size(); ++i) {
        delete swimmers[i];
    }

    return 0;
}


//functions
void swim(std::vector<Swimmer*> swimmers, int sec) {
    std::this_thread::sleep_for(std::chrono::seconds(sec));

    std::cout << "<<<<<<<<< sec " << sec << " >>>>>>>>>" << std::endl;

    for (int i = 0; i < 6; ++i) {
        update.lock();
        swimmers[i]->distancePlus();
        update.unlock();

        std::cout << swimmers[i]->getName() << ": " << swimmers[i]->getDistance() << std::endl;
    }
}

bool allFinish(const std::vector<Swimmer*>& swimmers) {
    for (int i = 0; i < swimmers.size(); ++i) {
        if (swimmers[i]->getDistance() < 100) {
            return false;
        }
    }
    return true;
};

int maxIterations(std::vector<Swimmer*>& swimmers) {
    int minSpeed = swimmers[0]->getSpeed();
    for (int i = 0; i < swimmers.size(); ++i) {
        if (minSpeed > swimmers[i]->getSpeed()) {
            minSpeed = swimmers[i]->getSpeed();
        }
    }
    return 100 / minSpeed + 1;
}

void sortResult(std::vector<Swimmer*>& swimmers) {
    for (int i = 0; i < swimmers.size(); ++i) {
        for (int j = i + 1; j < swimmers.size(); ++j) {
            if (swimmers[i]->getResultSec() > swimmers[j]->getResultSec()) {
                std::swap(swimmers[i],swimmers[j]);
            }
        }
    }
}
// пример вывод
// Не всегда коректная последовательнасть выводиться
// Может, конечно, из-за того что комп тормозит...
/*
100 - meter swim.
<<<<<<<<< sec 1 >>>>>>>>>
name0: 10
name1: 12
name2: 14
name3: 16
name4: 18
name5: 20
<<<<<<<<< sec 2 >>>>>>>>>
name0: 20
name1: 24
name2: 28
name3: 32
name4: 36
name5: 40
<<<<<<<<< sec <<<<<<<<< sec 4 >>>>>>>>>
name0: 30
name1: 36
name2: 42
name3: 48
name4: 54
name5: 60
3 >>>>>>>>>
name0: 40
name1: 48
name2: 56
name3: 64
name4: 72
name5: 80
<<<<<<<<< sec 5 >>>>>>>>>
name0: 50
name1: 60
name2: 70
name3: 80
name4: 90
name5: 100
<<<<<<<<< sec <<<<<<<<< sec 7 >>>>>>>>>
name0: 60
name1: 72
name2: 84
name3: 96
name4: 100
name5: 100
6 >>>>>>>>>
name0: 70
name1: 84
name2: 98
name3: 100
name4: 100
name5: 100
<<<<<<<<< sec 8 >>>>>>>>>
name0: 80
name1: 96
name2: 100
name3: 100
name4: 100
name5: 100
<<<<<<<<< sec <<<<<<<<< sec 10 >>>>>>>>>
name0: 90
name1: 100
name2: 100
name3: 100
name4: 100
name5: 100
9 >>>>>>>>>
name0: 100
name1: 100
name2: 100
name3: 100
name4: 100
name5: 100
<<<<<<<<< sec 11 >>>>>>>>>
name0: 100
name1: 100
name2: 100
name3: 100
name4: 100
name5: 100
<<<<<<<<< sec 12 >>>>>>>>>
name0: 100
name1: 100
name2: 100
name3: 100
name4: 100
name5: 100
<<<<<<<<< sec 13 >>>>>>>>>
name0: 100
name1: 100
name2: 100
name3: 100
name4: 100
name5: 100
<<<<<<<<< sec <<<<<<<<< sec 15 >>>>>>>>>
name0: 100
name1: 100
name2: 100
name3: 100
name4: 100
name5: 100
14 >>>>>>>>>
name0: 100
name1: 100
name2: 100
name3: 100
name4: 100
name5: 100
<<<<<<<<< sec 16 >>>>>>>>>
name0: 100
name1: 100
name2: 100
name3: 100
name4: 100
name5: 100
========= Result =========<<<<<<<<< sec 17 >>>>>>>>>
name0: 100
name1: 100
name2: 100
name3: 100
name4: 100
name5: 100
<<<<<<<<< sec 18 >>>>>>>>>
name0: 100
name1: 100
name2: 100
name3: 100
name4: 100
name5: 100

name5 -> 5
name4 -> 6
name3 -> 7
name2 -> 8
name1 -> 9
name0 -> 10
 */




/*
Задание 1. Заплыв на 100 метров


Что нужно сделать
Реализуйте симуляцию состязаний по заплыву на 100 метров.

Всего шесть дорожек и шесть пловцов. Имена пловцов указываются вначале из стандартного ввода. Каждый из них плывёт с
 разной скоростью, которая также задаётся пользователем при старте, через стандартный ввод в метрах в секунду.

Каждую секунду в стандартный вывод выдаётся информация о том, сколько проплыл тот или иной пловец.

Как только все пловцы коснулись 100-метровой отметки, заплыв заканчивается и выводится таблица с итоговыми результатами,
 отсортированная по возрастанию итогового времени заплыва.



Советы и рекомендации
Используйте нити для реализации движения каждого пловца в отдельности.



Что оценивается
Корректность работы программы, использующей многопоточность.
 */