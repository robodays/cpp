#include <iostream>
#include <fstream>
#include <string>

// function for writing data to a file
bool Writing(const std::string& path, std::string record[]);
// Go to the next record
bool FuncNext();
// check data entry function
bool CheckingDate(const std::string& dateStr);
// function checking entry cash
bool CheckingCash(const std::string& cashStr);

int main() {
    std::cout << "Program writing to list accounting" << std::endl;
    std::string path = "list_accounting.txt";
    std::string oneRecord[4];
    do {
        std::cout << "Enter payee name" << std::endl;
        std::cin >> oneRecord[0];
        std::cout << "Enter last name payee" << std::endl;
        std::cin >> oneRecord[1];
        do {
            std::cout << "Enter cash" << std::endl;
            std::cin >> oneRecord[2];
        } while (!CheckingCash(oneRecord[2]));
        do {
            std::cout << "Date issue of cash(DD.MM.YYYY)" << std::endl;
            std::cin >> oneRecord[3];
        } while (!CheckingDate(oneRecord[3]));
        if (!Writing(path, oneRecord)) {
            std::cerr << "Error writing.(" << path << ")" << std::endl;
        }
    } while (FuncNext());
    return 0;
}

// function checking entry cash
bool CheckingCash(const std::string& cashStr) {
    if (cashStr.length() <= 15) {
        int point = 0;
        for (char i : cashStr) {
            if ((i >= '0' && i <= '9') || (i == '.' && point < 1)) {
                if (i == '.') point++;
            } else {
                std::cout << "The cash format is incorrect. Enter it again." << std::endl;
                return false;
            }
        }
    } else {
        std::cout << "You entered a very long number (more than 15 characters)." << std::endl;
        return false;
    }
    return true;
}
// check data entry function
bool CheckingDate(const std::string& dateStr) {
    if (dateStr.length() == 10) {
        if (dateStr.substr(2, 1) == "." && dateStr.substr(5, 1) == ".") {
            if (std::stoi(dateStr.substr(0, 2)) > 0 && std::stoi(dateStr.substr(0, 2)) <= 31 &&
                    std::stoi(dateStr.substr(3, 2)) > 0 && std::stoi(dateStr.substr(3, 2)) <= 12 &&
                    std::stoi(dateStr.substr(6, 4)) > 1900 && std::stoi(dateStr.substr(6, 4)) <= 2200) {
                return true;
            }
        }
    }
    std::cout << "The date format is incorrect. Enter it again." << std::endl;
    return false;
}

// function for writing data to a file
bool Writing(const std::string& path, std::string record[]) {
    std::ofstream wFile(path, std::ios::app);
    if (!wFile.is_open()) return false;
    for (int i = 0; i < 4; ++i) {
        wFile << record[i] << " ";
    }
    wFile << std::endl;
    wFile.close();
    return true;
}

// Go to the next record
bool FuncNext() {
    std::string strNextEntry;
    do {
        std::cout << "Enter next entry?(yes/no)" << std::endl;
        std::cin >> strNextEntry;
        if (strNextEntry == "yes") {
            return true;
        } else if (strNextEntry == "no") {
            return false;
        }
    } while (true);
}
/*
Задание 1. Реализация записи в ведомость учёта


Что нужно сделать

В одном из прошлых заданий мы уже создавали программу чтения и анализа ведомости выплат. Теперь требуется создать
 простую программу записи в эту ведомость.

Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств, далее располагается дата выдачи в
 формате ДД.ММ.ГГГГ. Завершает запись сумма выплаты в рублях. Данные разделяются между собой пробелами. В конце каждой
 записи должен быть расположен перевод строки.

При старте программы пользователь последовательно вводит данные для новой записи, которые записываются затем в файл в
 текстовом режиме. Программа должна добавлять новые записи в конец файла, не удаляя его текущее содержимое.



Советы и рекомендации

Введённые данные рекомендуется хотя бы минимально валидировать перед их записью.

Для валидации даты в указанном формате можно использовать функции std::stoi и std::subtr с корректно указанным
 диапазоном символов в дате. К примеру, вызов std::stoi(date.substr(3, 2)) вычленит из строковой даты целочисленный
 месяц для последующего анализа.



Что оценивается

Корректность работы программы. Программа должна дозаписывать данные в конец существующего списка.



Как отправить задание на проверку

Выполните задание в Google Docs, откройте доступ для комментирования. Ссылку пришлите через форму для сдачи домашнего
 задания.

*/