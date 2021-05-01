#include <iostream>
#include <map>
#include <string>

void PrintLastName(std::map<std::string, int>& lastName);
void AddLastName(std::map<std::string, int>& lastNameMap, const std::string& str);

int main() {
    std::cout << "Registration." << std::endl;
    std::map<std::string, int> lastName;
    std::cout << "Enter last name, \"next\" or \"exit\"" << std::endl;
    std::string inputString;
    int count = 0;
    while (true) {
        std::cin >> inputString;
        if (inputString == "exit"){
            break;
        } else if (inputString == "next") {
            PrintLastName(lastName);
        } else {
            AddLastName(lastName, inputString);
            count++;
        }
    }
    return 0;
}

void AddLastName(std::map<std::string, int>& lastNameMap, const std::string& str) {
    if (lastNameMap.count(str) > 0) {
        auto itf = lastNameMap.find(str);
        lastNameMap[itf->first]++;
    } else {
        lastNameMap.insert(std::make_pair(str, 1));
    }
}

void PrintLastName(std::map<std::string, int>& lastNameMap) {
    if (!lastNameMap.empty()) {
        std::cout << lastNameMap.begin()->first << std::endl;
        lastNameMap.begin()->second--;
        if (lastNameMap.begin()->second == 0) {
            lastNameMap.erase(lastNameMap.begin());
        }
    } else {
        std::cout << "The list is empty!" << std::endl;
    }
}
/*
Регистратура


Что нужно сделать

Напишите программу «Регистратура».

На вход программе приходят строки с фамилиями или строка Next. Пришедшие люди становятся в очередь, а по запросу Next
 необходимо вызвать в регистратуру человека с фамилией, идущей первой в лексикографическом порядке (по алфавиту), и
 вывести его фамилию на экран. Фамилии пациентов могут повторяться.

Каждый запрос (на добавление и вывод) должен работать за O(logn).



Пример:

← Sidorov

← Ivanov

← Ivanov

← Petrov

← Next

→ Ivanov

← Next

→ Ivanov

← Next

→ Petrov



Чек-лист для проверки задачи

Программа корректно выводит фамилии в лексикографическом порядке.
Программа использует только заголовочные файлы <iostream>, <string>, <map>.
*/