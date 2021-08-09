#include <iostream>
#include <ctime>
#include <iomanip>

int main() {
    std::cout << "Program timer." << std::endl;

    std::time_t nowTime = 0;
    std::tm *local = localtime(&nowTime);

    std::cout << "Input time in format MM:SS" << std::endl;
    std::cin >> std::get_time(local, "%M:%S");

    int min = local->tm_min;
    int sec = local->tm_sec;

    nowTime = time(nullptr);
    std::time_t newTime = nowTime + min * 60 + sec;
    std::time_t dTime;
    std::time_t oldTime = 0;
    do {
        nowTime = time(nullptr);
        if (nowTime != oldTime){
            oldTime = nowTime;
            dTime = newTime - nowTime;
            local = localtime(&dTime);
            std::cout << "Timer " << std::put_time(local, "%M:%S") << std::endl;
        }
    } while (dTime > 0);
    std::cout << "DING! DING! DING!" << std::endl;

    return 0;
}
/*
Задание 3. Реализация программы таймера
Что нужно сделать

Реализуйте работу точного таймера с визуальной отдачей.

В начале программы пользователь вводит количество минут и секунд, которые требуется засечь на таймере, и нажимает
«Ввод».


После этого начинается обратный отсчёт времени, о чём незамедлительно и последовательно сообщается пользователю.
Формат вывода такой же, как и при вводе интервала: минуты и секунды.

Как только отсчёт на таймере иссяк, программа сообщает об этом с помощью вывода в консоль специального сообщения.
Сообщение вместо аудиосигнала может выглядеть так: DING! DING! DING!



Советы и рекомендации

Для ввода значения для засекания времени используйте std::get_time, но в качестве формата запросите только минуты и
секунды. Целевое время для остановки таймера вычислите сами с помощью манипуляции над текущим std::time. Количество
оставшегося времени выводите в цикле и вычислите его самостоятельно с помощью обращения с типом std::time_t как с
секундами.



Что оценивается

Корректность работы программы при разных заданных дефинициях макросов.


 */