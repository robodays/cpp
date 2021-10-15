#include <iostream>
#include <utility>
#include <vector>
#include <thread>
#include <mutex>

std::mutex update;

class Swimmer {
    std::string name;
    int speed;
    int distance = 0;
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
    void distancePlus() {
        if (distance > 100) {
            distance = 100;
        } else if (distance < 100) {
            distance += speed;
        }
    }
};

bool allFinish(const std::vector<Swimmer*>& swimmers);

void swim(Swimmer* swimmer);



int main() {
    std::cout << "100 - meter swim." << std::endl;

    std::vector<Swimmer*> swimmers;
    for (int i = 0; i < 6; ++i) {
/*        std::string nameSwimmer;
        std::cout << "Enter name " << i << " swimmer: " << std::endl;
        std::cin >> nameSwimmer;

        int speedSwimmer;
        std::cout << "Enter speed " << i << " swimmer: " << std::endl;
        std::cin >> speedSwimmer;
        swimmers.push_back(new Swimmer(nameSwimmer, speedSwimmer));*/

        swimmers.push_back(new Swimmer("name" + std::to_string(i), (i + 1) * 2));
    }

    std::vector<std::thread> periods;
   // periods.resize(1);
    while (!allFinish(swimmers)) {
        for (int i = 0; i < swimmers.size(); ++i) {
            if (swimmers[i]->getDistance() < 100) {
                periods.emplace_back(std::thread(swim, swimmers[i]));
            }

        }
        ///не нужно
        //std::thread per(swim);
        //per.join();
        //for (int i = 0; i < 100000000; ++i) {

        //}

        for (int i = 0; i < swimmers.size(); ++i) {
           if (periods[i].joinable()) {
               periods[i].join();
           }
           //periods[i].detach();
        }
    }
    /// Сортировка и вывод результатов

    for (int i = 0; i < swimmers.size(); ++i) {
        delete swimmers[i];
    }

    return 0;
}

void swim(Swimmer* swimmer) {
    std::this_thread::sleep_for(std::chrono::seconds(5));
    update.lock();
    swimmer->distancePlus();
    update.unlock();

    //std::cout << swimmer->getName() << ": " << swimmer->getDistance() << std::endl;

    //std::cout << "swimmer->getName()  swimmer->getDistance()" << std::endl;
}

bool allFinish(const std::vector<Swimmer*>& swimmers) {
    for (int i = 0; i < swimmers.size(); ++i) {
        if (swimmers[i]->getDistance() < 100) {
            return false;
        }
    }
    return true;
};

///Ошибка
///terminate called after throwing an instance of 'std::system_error'
///  what():  Invalid argument

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