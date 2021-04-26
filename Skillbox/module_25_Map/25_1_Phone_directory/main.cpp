#include <iostream>
#include <string>
#include <map>

void Add(std::map<std::string, std::string>& directory);
void FindPhone(std::map<std::string, std::string>& directory);
void FindName(std::map<std::string, std::string>& directory);
void Print(std::map<std::string, std::string>& directory);

int main() {
    std::cout << "Phone directory." << std::endl;
    std::map<std::string,std::string> directory;
    directory.insert(std::make_pair("111-11-11","Ivanov"));
    directory.insert(std::make_pair<std::string, std::string>("444-44-44","Morozov"));
    directory.insert(std::pair<std::string, std::string>("222-22-22","Smirnov"));
    directory["333-33-33"] = "Petrov";
    directory["555-55-55"] = "Petrov";
    std::string command;
    while (command != "exit") {
        std::cout << "Enter command:" << std::endl;
        std::cout << "\"add\" - for added new record" << std::endl;
        std::cout << "\"find_phone\" - for finding a phone number by last name" << std::endl;
        std::cout << "\"find_name\" - for finding a last name by phone number" << std::endl;
        std::cout << "\"print\" - for print all list" << std::endl;
        std::cout << "\"exit\" - for exit" << std::endl;
        std::cin >> command;
        if (command == "add") {
            Add(directory);
        } else if (command == "find_phone") {
            FindPhone(directory);
        } else if (command == "find_name") {
            FindName(directory);
        } else if (command == "print") {
            Print(directory);
        }
        std::cout << "=====================" << std::endl;
    }
    return 0;
}

void Print(std::map<std::string, std::string>& directory) {
    for (std::map<std::string, std::string>::iterator it = directory.begin();
         it != directory.end(); ++it) {
        std::cout << it->first << " " << it->second << std::endl;
    }
    /*
    std::cout << "Print test without iterators: " << std::endl;
    for (auto &dir : directory) {
        std::cout << dir.first << " " << dir.second << std::endl;
    }
     */
}

void FindName(std::map<std::string, std::string>& directory) {
    std::cout << "Find last name." << std::endl;
    std::cout << "  Enter phone number: " << std::endl;
    std::string phoneNumber;
    std::cin >> phoneNumber;
    if (directory.count(phoneNumber) > 0) {
        std::map<std::string, std::string>::iterator itf = directory.find(phoneNumber);
        //auto itf = directory.find(phoneNumber);
        std::cout << itf->second << std::endl;
    } else {
        std::cout << "Nothing found" << std::endl;
    }
}

void FindPhone(std::map<std::string, std::string>& directory) {
    std::cout << "Find phone." << std::endl;
    std::cout << "  Enter last name: " << std::endl;
    std::string lastName;
    std::cin >> lastName;
    bool nothingFound = true;
    for (auto record : directory) {
        if (record.second == lastName) {
            std::cout << record.first << std::endl;
            nothingFound = false;
        }
    }
    if (nothingFound) {
        std::cout << "Nothing found" << std::endl;
    }
}

void Add(std::map<std::string, std::string>& directory) {
    std::cout << "New record." << std::endl;
    std::cout << "  Enter phone number(XXX-XX-XX): " << std::endl;
    std::string phoneNumber;
    std::cin >> phoneNumber;
    std::cout << "  Enter last name: " << std::endl;
    std::string lastName;
    std::cin >> lastName;
    directory.insert(std::pair<std::string, std::string>(phoneNumber, lastName));
}

/*
Задание 1. Телефонный справочник


Что нужно сделать

Напишите программу «Телефонный справочник».

На вход программе поступают запросы трёх типов:

69-70-30 Ivanov — добавить телефон и фамилию абонента в справочник

69-70-30 — узнать фамилию абонента по номеру телефона

Ivanov — узнать телефон абонента по фамилии



Необходимо выводить в консоль ответ на запросы 2 и 3. Обратите внимание, что абоненты по разным номерам могут иметь
 одинаковые фамилии. В таком случае на запрос 3 необходимо выдать все номера через пробелы.

Операции запросов должны работать за O(logn) или O(logn × количество номеров с этой фамилией).



Чек-лист для проверки задачи

Программа корректно выводит фамилии и списки номеров.
Программа использует только заголовочные файлы <iostream>, <string>, <map> и, возможно, вектор.

*/