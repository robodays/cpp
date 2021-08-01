#include <iostream>
#include <ctime> // для работ с датами

#include <iomanip> // манипулирование и настройка ввода вывода

int main() {
    //1
    std::srand(std::time(nullptr));// зерно для генератора случайных чисел

    std::cout << std::time(nullptr) << std::endl;// выводит юникс время в секундах UTC 1626819063

    std::time_t t = std::time(nullptr); // возвращает std::time_t и принимает std::time_t

    std::tm* local = std::localtime(&t); // возвращает структуру, подробная информация о локальном времени
    std::cout << local->tm_hour << std::endl; // выводит часы
    std::cout << asctime(local) << std::endl; // выводит полный формат времени Wed Jul 21 01:11:03 2021
    //2
    std::cout << std::put_time(local, "%Y/%m/%d %H:%M:%S") << std::endl; // Вывод даты по формату
    //3
    std::time_t t3 = std::time(nullptr); // возвращает std::time_t и принимает std::time_t
    std::tm* local3 = std::localtime(&t3); // возвращает структуру, подробная информация о локальном времени
    std::cin >> std::get_time(local3, "%H:%M"); // ввод даты с клавиатуры
    std::cout << std::asctime(local3) << std::endl;
    // или так
    //    std::tm local3 = *std::localtime(&t3); // возвращает структуру, подробная информация о локальном времени
    //    std::cin >> std::get_time(&local3, "%H:%M"); // ввод даты с клавиатуры
    //    std::cout << std::asctime(&local3) << std::endl;

    //4
    std::time_t t41 = std::time(nullptr); // возвращает std::time_t и принимает std::time_t
    int pause;
    std::cin >> pause;
    std::time_t t42= std::time(nullptr); // возвращает std::time_t и принимает std::time_t

    std::tm* local41 = std::localtime(&t41); // возвращает структуру, подробная информация о локальном времени
    std::cout << "41 " << std::asctime(local41) << std::endl;
    std::tm* local42 = std::localtime(&t42); // возвращает структуру, подробная информация о локальном времени
    std::cout << "42 " << std::asctime(local42) << std::endl;

    //double t43 = difftime(t41,600); // из первого элемента вычисляет второй
    double t43 = difftime(t42, t41); // из первого элемента вычисляет второй
    std::cout << "difftime " << (int) t43 << std::endl;

    t41 +=  (std::time_t) 600;
    std::tm* local43 = std::localtime(&t41);
    std::cout << std::asctime(local43) << std::endl;

    local43->tm_sec += 30; // добавляем 10 секунд, но нельзя чтобы было больше 60 ничего не выводится
    std::cout << "+10 sec" << std::asctime(local43) << std::endl;


    return 0;
}
