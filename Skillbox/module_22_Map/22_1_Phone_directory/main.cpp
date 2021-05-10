#include <iostream>
#include <string>
#include <map>
#include <vector>

void FindPhone(const std::map<std::string, std::vector<std::string>>& directory);
void FindName(std::map<std::string, std::string>& directory);
void PrintByPhone(std::map<std::string, std::string>& directory);
void PrintByName(std::map<std::string, std::vector<std::string>>& directory);
void Add(std::map<std::string, std::string>& directory1, std::map<std::string, std::vector<std::string>>& directory2);

int main() {
    std::cout << "Phone directory." << std::endl;
    std::map<std::string,std::string> numberToSurname;
    std::map<std::string,std::vector<std::string>> surnameToNumber;
    std::vector<std::string> tmpVec;

    // various variable declaration options
    numberToSurname.insert(std::make_pair("111-11-11","Ivanov"));
    numberToSurname.insert(std::make_pair("111-11-22","Ivanov"));
    tmpVec.push_back("111-11-11");
    tmpVec.push_back("111-11-22");
    surnameToNumber.insert(std::make_pair("Ivanov",tmpVec));

    numberToSurname.insert(std::make_pair<std::string, std::string>("444-44-44","Morozov"));
    tmpVec.resize(0);
    tmpVec.push_back("444-44-44");
    surnameToNumber.insert(std::make_pair("Morozov",tmpVec));
    //surnameToNumber.insert(std::make_pair<std::string, std::vector<std::string>>("Morozov",tmpVec));// no work

    numberToSurname.insert(std::pair<std::string, std::string>("222-22-22","Smirnov"));
    tmpVec.resize(0);
    tmpVec.push_back("222-22-22");
    surnameToNumber.insert(std::pair<std::string, std::vector<std::string>>("Smirnov",tmpVec));

    numberToSurname["333-33-33"] = "Petrov";
    tmpVec.resize(0);
    tmpVec.push_back("333-33-33");
    surnameToNumber["Petrov"] = tmpVec;
    numberToSurname["333-33-44"] = "Petrov";
    tmpVec.push_back("333-33-44");
    surnameToNumber["Petrov"] = tmpVec;

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
            Add(numberToSurname, surnameToNumber);
        } else if (command == "find_phone") {
            FindPhone(surnameToNumber);
        } else if (command == "find_name") {
            FindName(numberToSurname);
        } else if (command == "print") {
            PrintByPhone(numberToSurname);
            PrintByName(surnameToNumber);
        }
        std::cout << "=====================" << std::endl;
    }
    return 0;
}

void PrintByName(std::map<std::string, std::vector<std::string>>& directory) {
    for (const auto& dir : directory) {
        std::cout << dir.first << std::endl;
        for (const auto& vec : dir.second  )
        std::cout << " " << vec << std::endl;
    }
}

void PrintByPhone(std::map<std::string, std::string>& directory) {
    for (std::map<std::string, std::string>::iterator it = directory.begin();
         it != directory.end(); ++it) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void FindName(std::map<std::string, std::string>& directory) {
    std::cout << "Find last name." << std::endl;
    std::cout << "  Enter phone number: " << std::endl;
    std::string phoneNumber;
    std::cin >> phoneNumber;
    if (directory.count(phoneNumber) > 0) {
        std::map<std::string, std::string>::iterator itf = directory.find(phoneNumber);
        std::cout << itf->second << std::endl;
    } else {
        std::cout << "Nothing found" << std::endl;
    }
}

void FindPhone(const std::map<std::string, std::vector<std::string>>& directory) {
    std::cout << "Find phone." << std::endl;
    std::cout << "  Enter last name: " << std::endl;
    std::string lastName;
    std::cin >> lastName;
    if (directory.count(lastName) > 0) {
        auto itf = directory.find(lastName);
        for (auto& vec : itf->second) {
            std::cout << vec << std::endl;
        }
    } else {
        std::cout << "Nothing found" << std::endl;
    }
}

void Add(std::map<std::string, std::string>& directory1, std::map<std::string, std::vector<std::string>>& directory2) {
    std::cout << "New record." << std::endl;
    std::cout << "  Enter phone number(XXX-XX-XX): " << std::endl;
    std::string phoneNumber;
    std::cin >> phoneNumber;
    std::cout << "  Enter last name: " << std::endl;
    std::string lastName;
    std::cin >> lastName;
    if (directory1.count(phoneNumber) > 0) {
        std::cout << "This phone number already exists." << std::endl;
    } else {
        directory1.insert(std::pair<std::string, std::string>(phoneNumber, lastName));
        if (directory2.count(lastName) > 0) {
            auto itf = directory2.find(lastName);
            bool isPhone = false;
            for (const auto &vec : itf->second) {
                if (vec == phoneNumber) {
                    isPhone = true;
                    break;
                }
            }
            if (!isPhone) {
                itf->second.push_back(phoneNumber);
                directory2[lastName] = itf->second;
            } else {
                std::cout << "This phone number already exists." << std::endl;
            }
        } else {
            std::vector<std::string> tmpVec = {phoneNumber};
            directory2.insert(std::pair<std::string, std::vector<std::string>>(lastName, tmpVec));
        }
    }
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