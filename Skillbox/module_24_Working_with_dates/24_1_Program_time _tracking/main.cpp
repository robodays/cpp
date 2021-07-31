#include <iostream>
#include <ctime>
#include <string>
#include <vector>

struct tasks{
    bool statusTask = true;
    std::string nameTask = " ";
    std::time_t beginTask = std::time(nullptr);
    std::time_t endTask = 0;
};

void BeginTask(std::vector<tasks> &task);

void StatusTask(std::vector<tasks> &task);

void EndTask(std::vector<tasks> &task);

int main() {
    std::cout << "Program time tracking!" << std::endl;

    std::vector<tasks> task;
    std::cout << "Input command (begin, end, status, exit): " << std::endl;
    std::string command;
    std::cin >> command;

    while (command != "exit") {
        if (command == "begin") {
            BeginTask(task);
         } else if (command == "status") {
            StatusTask(task);
        } else if (command == "end") {
            EndTask(task);
        }
        std::cout << "Input command (begin, end, status, exit): " << std::endl;
        std::cin >> command;

    }
    return 0;
}


void BeginTask(std::vector<tasks> &task) {
    if (!task.empty() && task.back().statusTask) {
        task.back().statusTask = false;
        task.back().endTask = std::time(nullptr);
        std::cout << "Back task close! " << std::endl;
    }
    tasks newTask;
    std::string inputNameTask;
    std::cout << "Input task name: " << std::endl;
    std::cin >> inputNameTask;

    newTask.statusTask = true;
    newTask.nameTask = inputNameTask;
    newTask.beginTask = std::time(nullptr);
    newTask.endTask = 0;
    task.push_back(newTask);

    std::cout << "Add new task: " << newTask.nameTask << std::endl;
    std::cout << "  time begin: " << asctime(std::localtime(&newTask.beginTask)) << std::endl;
}

void EndTask(std::vector<tasks> &task) {
    if (task.back().statusTask) {
        task.back().statusTask = false;
        task.back().endTask = std::time(nullptr);
        std::cout << "Back task close! " << std::endl;
    } else {
        std::cout << "No tasks started! " << std::endl;
    }
}

void StatusTask(std::vector<tasks> &task) {
    std::cout << "Output all task:" << std::endl;
    for (int i = 0; i < task.size(); ++i) {
        std::cout << "ID task: " << i << std::endl;
        std::cout << "  Name task: " << task[i].nameTask << std::endl;
        std::cout << "  Time begin: " << asctime(std::localtime(&task[i].beginTask)) << std::endl;

        std::time_t timeWorkSec;
        if (task[i].statusTask){
            std::cout << "  Status: work" << std::endl;
            timeWorkSec = std::time(nullptr) - task[i].beginTask;
        } else {
            std::cout << "  Time end: " << asctime(std::localtime(&task[i].endTask)) << std::endl;
            std::cout << "  Status: end" << std::endl;
            timeWorkSec = task[i].endTask - task[i].beginTask;
        }
        std::cout << "  Time work: " << timeWorkSec / 60 / 60 << " hours " << timeWorkSec / 60 % 60 << " minutes "
                  << timeWorkSec % 60 << " seconds"<< std::endl;

    }
}

/*
Задание 1. Реализация программы учёта времени
Что нужно сделать

Используя функцию получения текущего времени std::time, реализуйте простейший менеджер учёта времени.

Пользователь взаимодействует с программой с помощью команд:

Команда begin начинает отслеживание новой задачи. После ввода этой команды пользователь должен ввести название задачи,
над которой он планирует сейчас работать. Если уже была начата какая-то другая задача, предыдущая должна быть
автоматически завершена и начата новая.
Команда end заканчивает отслеживание текущей задачи. Если текущей начатой задачи нет, то команда ничего не делает.
Команда status выводит на экран информацию о всех законченных задачах и времени, которое было на них потрачено. Также
выводится название текущей выполняемой задачи, если таковая имеется.
Команда exit выходит из программы.


Советы и рекомендации

Тип std::time_t принимайте за секунды и с помощью него рассчитывайте время в часах, которое было затрачено.



Что оценивается

Корректность работы программы.
 */