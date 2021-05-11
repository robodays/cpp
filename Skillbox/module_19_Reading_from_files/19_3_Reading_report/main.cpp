#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file;
    file.open("report.txt");
    if (file.is_open()) {
        std::cout << "File report.txt open." << std::endl;
        std::string first_name;
        std::string second_name;
        int cash;
        std::string date;

        int allCash = 0;
        int max = 0;
        std::string person;

        while (!file.eof()) {
            file >> first_name >> second_name >> cash >> date;
            allCash += cash;
            if (max < cash) {
                max = cash;
                person = first_name + " " + second_name;
            }
        }
        file.close();
        std::cout << "Total amount of money paid: " << allCash << std::endl;
        std::cout << "Person " << person <<  " with the maximum payout amount " << max << std::endl;

    } else std::cout << "File report.txt no open" << std::endl;

    return 0;
}
/*
Задание 3. Реализация программы чтения ведомости


Что нужно сделать
Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость представляет собой следующую
 таблицу:

имя и фамилия человека;
количество денег, которые были выплачены лицу;
дата выплаты в формате ДД.ММ.ГГГГ.
На основе данных из ведомости следует подсчитать общее количество выплаченных средств и определить человека с
 максимальной суммой выплат.



Пример данных ведомости

Tom Hanks 35500 10.11.2020

Rebecca Williams 85000 1.1.2021

Sally Field 15600 15.8.2021

Michael Humphreys 29400 23.5.2020

Harold Herthum 74300 9.6.2019

George Kelly 45000 12.3.2018

Bob Penny 12500 13.5.2020

John Randall 23400 2.10.2020

Sam Anderson 6500 15.7.2020

Margo Moorer 12350 24.2.2019



Что оценивается
Корректное отображение общей суммы выплат и самого крупного получателя денежных средств.



Как отправить задание на проверку
Выполните задание в Google Документах, откройте доступ для комментирования. Ссылку пришлите через форму для сдачи
 домашнего задания.


 */