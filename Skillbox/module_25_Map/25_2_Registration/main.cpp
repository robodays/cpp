#include <iostream>
#include <map>
#include <string>

void PrintLastName(std::map<std::string, std::string>& lastName);
void AddLastName(std::map<std::string, std::string>& lastNameMap, const std::string& str, int count);

int main() {
    std::cout << "Registration." << std::endl;
    std::map<std::string, std::string> lastName;
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
            AddLastName(lastName, inputString, count);
            count++;
        }
    }
    return 0;
}

void AddLastName(std::map<std::string, std::string>& lastNameMap, const std::string& str, const int count) {
    lastNameMap.insert(std::make_pair(str + std::to_string(count), str));
}

void PrintLastName(std::map<std::string, std::string>& lastNameMap) {
    if (!lastNameMap.empty()) {
        std::cout << lastNameMap.begin()->second << std::endl;
        lastNameMap.erase(lastNameMap.begin());
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