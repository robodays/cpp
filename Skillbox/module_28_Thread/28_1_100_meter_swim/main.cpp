#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <string>

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

void swim(Swimmer* swimmer, int periodOutputSec);
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

    int periodOutputSec = 1;
    periods.reserve(swimmers.size());
    for (int i = 0; i < swimmers.size(); ++i) {
        periods.emplace_back(std::thread(swim, swimmers[i], periodOutputSec));
    }

    //Sorting and output of results

    for (int i = 0; i < swimmers.size(); ++i) {
        periods[i].join();
    }

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
void swim(Swimmer* swimmer, int periodOutputSec) {
    while (swimmer->getDistance() < 100) {
        std::this_thread::sleep_for(std::chrono::seconds(periodOutputSec));

        swimmer->distancePlus();

        update.lock();
        std::cout << swimmer->getName() << "\t sec: " << swimmer->getResultSec() << "\t Dist: "
                    << swimmer->getDistance() << std::endl;
        update.unlock();
    }
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