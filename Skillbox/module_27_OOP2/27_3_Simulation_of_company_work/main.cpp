#include <iostream>
#include <vector>

enum TypeTask {
    NONE = 0,
    A,
    B,
    C,
    MAX_ENUM
};

class Worker {
    bool free = true;
    TypeTask typeTask = NONE;
public:

    bool getFree() {
        return free;
    }

    TypeTask getTypeTask() {
        return typeTask;
    }

    void setFree(bool inFree) {
        free = inFree;
    }

    void setTypeTask(TypeTask inTypeTask) {
        typeTask = inTypeTask;
    }
};

class Manager {

    std::vector<Worker*> workers;
    int idManager = 0;
    int quantityTasks = 0;
    int individualCommand;

public:
    Manager(int inIdManager, int inQuantityWorkers) : idManager(inIdManager){
        for (int i = 0; i < inQuantityWorkers; ++i) {
            workers.push_back(new Worker);
        }
    }

    int getCountFreeWorkers() {
        int countFreeWorkers = 0;
        for (int i = 0; i < workers.size(); ++i) {
            if(workers[i]->getFree()) {
                countFreeWorkers++;
            }
        }
        return countFreeWorkers;
    }

    int getIdManager() const {
        return idManager;
    }

    std::vector<Worker*> getWorkers() const {
        return workers;
    }

    void setIndividualCommand(int command) {
        individualCommand = command + idManager;
    }

    int getIndividualCommand() const {
        return individualCommand;
    }

    bool processingTasks() {
        std::srand(individualCommand);
        if (getCountFreeWorkers() != 0) {
            quantityTasks = std::rand() % getCountFreeWorkers() + 1;
            int j = 0;
            for (int i = 0; i < quantityTasks; ++i) {
                while (!workers[j]->getFree()) {
                    j++;
                }
                workers[j]->setTypeTask(static_cast<TypeTask>(std::rand() % (MAX_ENUM - 1) + 1));
                workers[j]->setFree(false);
            }
        }
        return getCountFreeWorkers() != 0;
    }


};

class Director {
    int command = 0;
    std::vector<Manager*> managers;

public:
    void addManager(int inIdManager, int inQuantityWorkers){
        managers.push_back(new Manager(inIdManager,inQuantityWorkers));
    }

    std::vector<Manager*> getManager() const{
        return managers;
    }

    int getCommand() const{
        return command;
    }

    void inputCommand() {
        std::cout << "Enter a numeric command:";
        std::cin >> command;
    }
};




int main() {
    std::cout << "Simulation of company work." << std::endl;

    std::cout << "Enter quantity teams:";
    int quantityTeams;
    std::cin >> quantityTeams;
    Director* director = new Director();
    for (int i = 0; i < quantityTeams; ++i) {
        std::cout << "Enter quantity of workers in teams #" << i + 1 << ":" << std::endl;
        int quantityWorkers;
        std::cin >> quantityWorkers;
        director->addManager(i + 1, quantityWorkers);
    }

    bool isFreeWorkers;
    do {
        director->inputCommand();
        isFreeWorkers = false;
        for (int i = 0; i < director->getManager().size(); ++i) {
             director->getManager()[i]->setIndividualCommand(director->getCommand());
             if (director->getManager()[i]->processingTasks()) {
                 isFreeWorkers = true;
             }
        }

        // test print
        std::cout << "Quantity Team: " << director->getManager().size() << std::endl;
        for (int i = 0; i < quantityTeams; ++i) {
            std::cout << "===============================================" << std::endl;
            std::cout << "===============================================" << std::endl;
            std::cout << "id Manager: " << director->getManager()[i]->getIdManager() << std::endl;
            std::cout << "  workers size: " << director->getManager()[i]->getWorkers().size() << std::endl;
            std::cout << "===============================================" << std::endl;
            for (int j = 0; j < director->getManager()[i]->getWorkers().size(); ++j) {
                std::cout << "-------------------------------------------" << std::endl;
                std::cout << "managers:" << i << " workers:" << j << " typeTask: " << director->getManager()[i]->getWorkers()[j]->getTypeTask() << std::endl;
                std::cout << "managers:" << i << " workers:" << j << " free: " << director->getManager()[i]->getWorkers()[j]->getFree() << std::endl;
             }
        } // end test print

    } while(isFreeWorkers && director->getCommand() != 0);

    return 0;
}

/*
Задание 3. Симуляция работы компании


Что нужно сделать
Реализуйте симуляцию работы компании. В компании осуществляется вертикальное управление с иерархией. Есть основные
 рабочие подчинённые, разбитые на команды. У каждой команды есть свой менеджер среднего звена. Во главе всей компании
 стоит её руководитель — глава компании.

Глава компании осуществляет стратегическое управление. Он определяет основной вектор движения — задачи верхнего уровня.
 Менеджеры среднего звена разбивают эти задачи на подзадачи и раздают их своим подчинённым. Подчинённые осуществляют
 выполнение работ.

Реализация данной логики должна проходить упрощённым образом. Указания главы компании поступают из стандартного ввода и
 являются не более чем целочисленными идентификаторами.

Данные идентификаторы служат зерном для генератора случайных чисел. Каждый из менеджеров, принимая себе эту
 целочисленную команду, добавляет к ней свой порядковый номер и вызывает с результирующей суммой функцию std::srand().

На основе этой суммы вычисляется общее количество задач, которое требуется выполнить данной командой, — от 1 до
 количества работников в группе. Всего существует три типа задач для работников: A, B и C. Они тоже выбираются случайно
 и распределяются между незанятыми рабочими.

При старте программы пользователь указывает в стандартном вводе количество команд и количество работников в каждой из
 команд.

Далее пользователь вводит целые числа, которые соответствуют указаниям руководителя компании. Программа завершается,
 когда все работники заняты какими-то задачами.



Советы и рекомендации
Пользуйтесь всем изученным в модуле, включая иерархии классов для представления сотрудников и указатель this, если
 потребуется.



Что оценивается
Корректность работы программы и элегантность архитектурных решений.


 */