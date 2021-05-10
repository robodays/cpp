#include <iostream>
#include <fstream>
#include <string>

struct record{
    std::string firstName;
    std::string lastName;
    std::string date;
    int cash;
};

// function for writing data to a file
bool Writing(const std::string&, record&);
// function for reading data for a file and print
bool ReadingAndPrint(const std::string&);
// Go to the next record
bool FuncNext(const std::string&, const std::string&, const std::string&);
// check data entry function
bool CheckingDate(const std::string&);
// function checking entry cash
bool CheckingCash(int);
// checking string
bool CheckingSting(const std::string&);

int main() {
    std::cout << "Program realization the accounting list." << std::endl;
    std::string path = "list_accounting_git.txt";
    record oneRecord;
    std::string message = R"(Enter the command: ("list" - to output records/"add" - to add a new record))";
    if (FuncNext(message, "list", "add")) {
        ReadingAndPrint(path);
    } else {
        do {
            do {
                std::cout << "Enter payee name" << std::endl;
                std::cin >> oneRecord.firstName;
            } while (!CheckingSting(oneRecord.firstName));
            do {
                std::cout << "Enter last name payee" << std::endl;
                std::cin >> oneRecord.lastName;
            } while (!CheckingSting(oneRecord.lastName));
            do {
                std::cout << "Date issue of cash(DD.MM.YYYY)" << std::endl;
                std::cin >> oneRecord.date;
            } while (!CheckingDate(oneRecord.date));
            do {
                std::cout << "Enter cash" << std::endl;
                std::cin >> oneRecord.cash;
            } while (!CheckingCash(oneRecord.cash));
            if (!Writing(path, oneRecord)) {
                std::cerr << "Error writing.(" << path << ")" << std::endl;
            }
        } while (FuncNext("Enter next entry?(yes/no)", "yes", "no"));
    }
    return 0;
}

// function checking entry cash
bool CheckingCash(const int cash) {
    if (cash <= 0) {
        std::cout << "The cash format is incorrect(less than or equal to zero). Enter it again." << std::endl;
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
bool Writing(const std::string& path, record& oneRecord) {
    std::ofstream wFile(path, std::ios::app);
    if (!wFile.is_open()) return false;
    wFile << oneRecord.firstName << " " << oneRecord.lastName << " " << oneRecord.date << " "
          << oneRecord.cash << std::endl;
    wFile.close();
    return true;
}

// function for reading data for a file and print
bool ReadingAndPrint(const std::string& path) {
    std::ifstream rFile(path, std::ios::app);
    if (!rFile.is_open()) return false;
    std::cout << "-----------------------------------------------------" << std::endl;
    while (!rFile.eof()) {
        record oneRecord;
        rFile >> oneRecord.firstName >> oneRecord.lastName >> oneRecord.date
              >> oneRecord.cash;
        if (!oneRecord.firstName.empty()) {
            std::cout << "| ";
            std::cout.width(10);
            std::cout << (oneRecord.firstName.length() > 10? oneRecord.firstName.substr(0,9)+"~"
                                                             :oneRecord.firstName) << " | ";
            std::cout.width(10);
            std::cout << (oneRecord.firstName.length() > 10? oneRecord.firstName.substr(0,9)+"~"
                                                             :oneRecord.firstName) << " | ";
            std::cout.width(10);
            std::cout << oneRecord.date << " | ";
            std::cout.width(10);
            std::cout << oneRecord.cash  << " |" << std::endl;
        }
    }
    std::cout << "-----------------------------------------------------" << std::endl;

    rFile.close();
    return true;
}


// Go to the next record
bool FuncNext(const std::string& text, const std::string& strNext, const std::string& strNoNext) {
    std::string strNextEntry;
    do {
        std::cout << text << std::endl;
        std::cin >> strNextEntry;
        if (strNextEntry == strNext) {
            return true;
        } else if (strNextEntry == strNoNext) {
            return false;
        }
    } while (true);
}

// checking string
bool CheckingSting(const std::string& str) {
    if (str.length() == 0) {
        std::cout << "You entered an empty value!";
        return false;
    }
    return true;
}

/*
 Задание 1. Реализация ведомости учёта


Что нужно сделать

Вы уже создавали программу чтения и записи ведомости. Теперь её надо будет обобщить и дополнить использованием структур.

Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных средств, далее — дата выдачи в формате
 ДД.ММ.ГГГГ., затем — сумма выплаты в рублях. Данные разделяются между собой пробелами. В конце каждой записи должен
 быть перевод строки.

Структура данных записи должна соответствовать указанному формату.

При старте программы пользователь указывает команду, которую следует осуществить: list или add. Команда read
 осуществляет чтение из файла ведомости как и прежде, только уже в структуры данных и отображает их на экране.

Команда add добавляет новую запись в конец ведомости.



Советы и рекомендации

Чтобы определить конец файла, используйте функцию file.eof() как и прежде. Из-за завершающего переноса строки, также
 стоит проверить и имя. Если оно было считает пустым, то можно считать, что файл закончился.



Что оценивается

Корректность работы программы. Программа должна всегда использовать структуры и все операции проводить через них.



Как отправить задание на проверку

Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.*/