#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

struct Friend{
    std::string nameFriend;
    std::time_t dateBirthday;

};


int main() {
    std::cout << "Birthday reminder." << std::endl;
    std::vector<Friend> friends;
    std::vector<Friend> nearestBirthday;
    Friend oneFriend;
    std::time_t nullTime = 0;

    std::cout << "Enter name friend and \"end\"" << std::endl;
    std::cin >> oneFriend.nameFriend;
    while (oneFriend.nameFriend != "end") {
        //= std::localtime(&std::time(nullptr));
        std::cout << "Enter date birthday: " << std::endl;

        std::tm* local = localtime(&nullTime);
        std::cin >> std::get_time(local,"%Y/%m/%d");
        std::cout << "Enter name friend and \"end\"" << std::endl;
        friends.push_back(oneFriend);
        std::cin >> oneFriend.nameFriend;
    }
    // к нулевому добавляем месяц и год
    std::time_t nowTime = std::time(nullptr);
    for (int i = 0; i < friends.size(); ++i) {
        if (nowTime < friends[i].dateBirthday) {
            if (friends.empty()) {
                nearestBirthday.push_back(friends[i]);
            } else if (nearestBirthday.back() > {

            }
        }
    }
    return 0;
}
/*
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