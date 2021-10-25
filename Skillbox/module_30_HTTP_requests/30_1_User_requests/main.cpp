#include <iostream>
#include <cpr/cpr.h>

int main() {
    std::cout << "User requests!" << std::endl;


    std::cout << "Enter command(get, post, put, delete, patch or exit for exit): " << std::endl;
    std::string command;
    cpr::Response response;
    do{
        std::cin >> command;
        if (command == "get") {
            response = cpr::Get(cpr::Url("https://httpbin.org/get"));
        } else if (command == "post") {
            response = cpr::Post(cpr::Url("https://httpbin.org/post"));
        } else if (command == "put") {
            response = cpr::Put(cpr::Url("https://httpbin.org/put"));
        } else if (command == "delete") {
            response = cpr::Delete(cpr::Url("https://httpbin.org/delete"));
        } else if (command == "patch") {
            response = cpr::Patch(cpr::Url("https://httpbin.org/patch"));
        } else if (command != "exit") {
            std::cout << "Incorrect!" << std::endl;
            std::cout << "Enter command(get, post, put, delete, patch or exit for exit): " << std::endl;
            continue;
        }

        if (command != "exit") {
            std::cout << response.status_code << std::endl;
            std::cout << response.text << std::endl;
        }
    } while(command != "exit");



    return 0;
}


/*
Задание 1. Пользовательские запросы


Что нужно сделать
Реализуйте программу по осуществлению различных типов HTTP-запросов к сервису httpbin.org.

Пользователь взаимодействует с программой с помощью команд: «get», «post», «put», «delete», «patch». В зависимости от
 команды к серверу httpbin.org, осуществляется запрос того или иного типа. Содержимое ответа сервера выводится в
 стандартный вывод.

Программа завершается, когда пользователь вводит команду «ext».



Что оценивается
Корректность выполнения запросов к сервису в зависимости от пользовательских команд.


Что оценивается
Корректность работы программы при различных пользовательских данных.


 */