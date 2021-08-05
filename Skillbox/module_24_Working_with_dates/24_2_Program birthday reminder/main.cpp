#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <vector>

struct Friend{
    std::string nameFriend;
    std::time_t dateBirthday = 0;
};

std::time_t DateConverterIn1970(std::time_t time) {
    std::time_t time1970 = 0;

    std::tm* localTime = localtime(&time);
    int mon = localTime->tm_mon;
    int day = localTime->tm_mday;

    std::tm* localTime1970 = localtime(&time1970);
    localTime1970->tm_mon = mon;
    localTime1970->tm_mday = day;

    return mktime(localTime1970);
}

int main() {
    std::cout << "Birthday reminder." << std::endl;
    std::vector<Friend> friends;
    std::vector<Friend> nearestBirthday;
    Friend oneFriend;
    std::time_t nullTime = 0;

    std::cout << "Enter name friend and \"end\"" << std::endl;
    std::cin >> oneFriend.nameFriend;

    while (oneFriend.nameFriend != "end") {
        std::cout << "Enter date birthday(YYYY/MM/DD): " << std::endl;
        std::tm* local = localtime(&nullTime);
        std::cin >> std::get_time(local,"%Y/%m/%d");
        oneFriend.dateBirthday = mktime(local);
        friends.push_back(oneFriend);

        std::cout << "Enter name friend and \"end\"" << std::endl;
        std::cin >> oneFriend.nameFriend;
    }

    std::time_t nowTime = std::time(nullptr);

    // until the end of the year
    for (int i = 0; i < friends.size(); ++i) {
        if (DateConverterIn1970(friends[i].dateBirthday) >= DateConverterIn1970(nowTime)) {
            if (nearestBirthday.empty() || DateConverterIn1970(friends[i].dateBirthday)
                                            == DateConverterIn1970(nearestBirthday.back().dateBirthday)) {
                nearestBirthday.push_back(friends[i]);
            } else if (DateConverterIn1970(friends[i].dateBirthday)
                        < DateConverterIn1970(nearestBirthday.back().dateBirthday)) {
                nearestBirthday.clear();
                nearestBirthday.push_back(friends[i]);
            }
        }
    }

    // next year, if not found this year
    if (nearestBirthday.empty()){
        for (int i = 0; i < friends.size(); ++i) {
            if (DateConverterIn1970(friends[i].dateBirthday) >= 0) {
                if (nearestBirthday.empty() || DateConverterIn1970(friends[i].dateBirthday)
                                                == DateConverterIn1970(nearestBirthday.back().dateBirthday)) {
                    nearestBirthday.push_back(friends[i]);
                } else if (DateConverterIn1970(friends[i].dateBirthday)
                            < DateConverterIn1970(nearestBirthday.back().dateBirthday)) {
                    nearestBirthday.clear();
                    nearestBirthday.push_back(friends[i]);
                }
            }
        }
    }

    if (!nearestBirthday.empty()) {
        std::cout << "Nearest Birthday:" << std::endl;
        for (int i = 0; i < nearestBirthday.size(); i++) {
            std::cout << nearestBirthday[i].nameFriend << std::endl;
            std::tm *local = localtime(&nearestBirthday[i].dateBirthday);
            std::cout << "  " << local->tm_mon + 1<< "/" << local->tm_mday<< std::endl;
        }
    } else {
        std::cout << "No birthdays!" << std::endl;
    }
    return 0;
}
/*
name1
2010/10/10
name2
2010/10/09
name3
2010/10/08
name4
2010/10/08

end

name1
2010/01/10
name2
2010/01/09
name3
2010/02/08
name4
2010/01/08

name1
2010/01/10
name2
2010/01/09
name3
2010/02/08
name4
2010/01/08
name5
2010/10/08

Задание 2. Реализация программы напоминания о днях рождения
Что нужно сделать

Реализуйте простую программу по вычислению ближайшего дня рождения.

В начале программы пользователь последовательно вводит данные о днях рождения своих друзей: вводит имя друга и саму
дату рождения полностью, включая месяц и год, в формате год/месяц/день. Сигналом окончания ввода дней рождения
является “end” введённое в качестве имени.

После этого программа вычисляет ближайший день рождения по отношению к текущему времени и выводит его на экран вместе
с именем в удобном, локальном формате - месяц/день. Если день рождения уже был в этом году, данные о пользователе
пропускаются. Если у кого-то из друзей день рождения сегодня, то в консоль выводится специальное сообщение об этом.
Учтите, что таких сообщений может быть несколько, ведь сразу несколько людей могут иметь дни рождения в один день.



Советы и рекомендации

Для подсчёта ближайшего дня используйте данные из структуры даты std::tm.



Что оценивается

Корректность работы программы.


 */