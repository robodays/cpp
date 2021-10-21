#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

enum Status {
    FOLLOW,
    ARRIVAL,
    WAITING,
    DEPARTING
};
enum NameTrain {
    A,
    B,
    C
};

class Train {
    NameTrain name = A;
    int distanceSec = 0;
    Status status = FOLLOW;
public:

    int getDistanceSec() const {
        return distanceSec;
    }

    Status getStatus() const {
        return status;
    }

    void setDistanceSec(int inDistance) {
        distanceSec = inDistance;
    }

    void setName(int i) {
        name = static_cast<NameTrain>(i);
    }

    void setStatus(Status inStatus) {
        status = inStatus;
    }

    std::string getNameStr() {
        if (name == A) return "A";
        else if (name == B) return "B";
        else if (name == C) return "C";
        return "NONE";
    }

    std::string getStatusStr() {
        if (status == FOLLOW) return "FOLLOW";
        else if (status == ARRIVAL) return "ARRIVAL";
        else if (status == WAITING) return "WAITING";
        else if (status == DEPARTING) return "DEPARTING";
        return "NONE";
    }

    void printNameAndStatus(bool isDistanceSec = true) {
        std::cout << "Train: " << getNameStr() << " \tStatus: " << getStatusStr();
        if (isDistanceSec) {
            std::cout << "\t\tDistance before station: " << distanceSec;
        }
        std::cout << std::endl;

    }

};

void trainThread(Train* train, bool &freeStation);

std::mutex updateTrains;
std::mutex updateStation;

int main() {
    std::cout << "Simulation of station work." << std::endl;
    Train* trains[3];
    for (int i = 0; i < 3; ++i) {
        trains[i] = new Train();
        trains[i]->setName(i);
        std::cout << "Enter distance before station in seconds for train \"" << trains[i]->getNameStr() << "\"" << std::endl;
        int distanceSec;
        std::cin >> distanceSec;
        trains[i]->setDistanceSec(distanceSec);
    }

    bool freeStation = true;
    std::cout << "Station: Free"  << std::endl;

    std::vector<std::thread> threads;
    threads.reserve(3);
    for (int i = 0; i < 3; i++) {
        threads.emplace_back(std::thread (trainThread, trains[i], std::ref(freeStation)));
    }

    for (int i = 0; i < 3; i++) {
        threads[i].join();
    }

    for (auto train: trains) {
        delete train;
    }

    return 0;
}

void trainThread(Train* train, bool &freeStation) {
    updateTrains.lock();
    train->printNameAndStatus();
    updateTrains.unlock();
    Status changeStatus = FOLLOW;
    while (train->getDistanceSec() != 0) {
        std::this_thread::sleep_for(std::chrono::seconds(1));

        updateTrains.lock();
        if (train->getDistanceSec() == 1) {
            if (freeStation) {
                train->setDistanceSec(train->getDistanceSec() - 1);
                train->setStatus(ARRIVAL);

                freeStation = false;
                std::cout << "Station: Busy" << std::endl;

            } else {
                train->setStatus(WAITING);
            }
        } else if (train->getDistanceSec() > 1) {
            train->setDistanceSec(train->getDistanceSec() - 1);
        }

        if (changeStatus != train->getStatus()) {
            train->printNameAndStatus();
            changeStatus = train->getStatus();
        }
        updateTrains.unlock();
    }
    updateStation.lock();
    if (train->getStatus() == ARRIVAL) {
        std::string command;
        do {
            std::cout << "Enter command to send train " << train->getNameStr() << ": " << std::endl;
            std::cin >> command;
        } while (command != "deport");

        train->setStatus(DEPARTING);
        freeStation = true;

        train->printNameAndStatus(false);
        std::cout << "Station: Free"  << std::endl;
    }
    updateStation.unlock();
}
/*
Задание 2. Симуляция работы вокзала


Что нужно сделать
С помощью многопоточности реализуйте простую модель железнодорожного вокзала.

С трёх точек отправления в разное время отбывают три разных поезда с условными обозначениями A, B, C. Все они идут на
 один и тот же вокзал и могут дойти до него в разное время.

На этом целевом вокзале единовременно может находиться только один поезд. Остальные поезда должны ждать, пока уже
 занятое место освободится.

В начале программы пользователь последовательно вводит для каждого поезда время в пути до вокзала (в секундах). После
 этого поезда начинают своё движение за заданное количество времени. Как только поезд прибыл на вокзал, он ожидает от
 пользователя команды depart, которая сигнализирует о его отбытии с вокзала.

По всем событиям (прибытие на вокзал, ожидание свободного места, отбытие с вокзала) вместе с условным обозначением
 поезда выводятся сообщения в консоль.

Программа завершается, когда на вокзале побывают все три поезда.



Советы и рекомендации
Используйте для вокзала отдельный мьютекс и симулируйте ожидание с помощью него.



Что оценивается
Корректность работы программы и безопасность использования общих ресурсов.
 */