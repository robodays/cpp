#include <iostream>
#include "operations.h"

int main() {
    std::cout << "Simulator_of_operations." << std::endl;

    XYPoint scalpelBeginPoint;
    XYPoint scalpelEndPoint;
    std::cout << "Command \"scalpel\":" << std::endl;
    std::cout << "Input x y begin: " << std::endl;
    std::cin >> scalpelBeginPoint.x >> scalpelBeginPoint.y;
    std::cout << "Input x y end: " << std::endl;
    std::cin >> scalpelEndPoint.x >> scalpelEndPoint.y;
    Scalpel(scalpelBeginPoint, scalpelEndPoint);

    XYPoint hemostatPoint;
    std::cout << "Command \"hemostat\":" << std::endl;
    std::cout << "Input x y: " << std::endl;
    std::cin >> hemostatPoint.x >> hemostatPoint.y;
    Hemostat(hemostatPoint);

    XYPoint tweezersPoint;
    std::cout << "Command \"tweezers\":" << std::endl;
    std::cout << "Input x y: " << std::endl;
    std::cin >> tweezersPoint.x >> tweezersPoint.y;
    Tweezers(tweezersPoint);


    XYPoint sutureBeginPoint;
    XYPoint sutureEndPoint;
    do {
        std::cout << "Command \"suture\":" << std::endl;
        std::cout << "Input x y begin: " << std::endl;
        std::cin >> sutureBeginPoint.x >> sutureBeginPoint.y;
        std::cout << "Input x y end: " << std::endl;
        std::cin >> sutureEndPoint.x >> sutureEndPoint.y;
        Suture(sutureBeginPoint, sutureEndPoint);
        if (Compare(sutureBeginPoint,scalpelBeginPoint) && Compare(sutureEndPoint,scalpelEndPoint)) {
            break;
        } else {
            std::cout << "Does not match with a scalpel! " << std::endl;
        }
    } while (true);
    std::cout << "Operation end!" << std::endl;

    return 0;
}

/*
Задание 1. Симулятор проведения операций


Что нужно сделать

Реализуйте простой симулятор проведения медицинской операции у пациента. Пользователь выступает в роли хирурга, который
 запрашивает инструменты у ассистента и применяет их сообразно ситуации.

Пользователь взаимодействует с программой с помощью команд. Команды не имеют сложной встроенной логики: они просто
 принимают нужные данные в качестве аргументов и выводят сообщения в консоль о выполнении. Данные команд — это одна или
 две двумерные точки в формате double с координатами X и Y соответственно.

scalpel — принимает на вход две двумерные координаты начала и конца разреза или линии отсечения. При выполнении этой
 команды в консоль выводится сообщение о том, что был сделан разрез между введёнными координатами.

hemostat — эта команда принимает на вход одну точку, в которой требуется сделать зажим, о чём также сообщает в консоль.

tweezers — пинцет, как и зажим, принимает одну точку для применения. Сообщение об этом выводится в консоль.

suture — команда хирургической иглы, которая делает шов между двумя указанными точками.

Операция всегда начинается с команды scalpel и заканчивается командой suture. Для окончания работы программы их
 параметры-точки при этом должны совпасть.

Программу требуется реализовать именно с помощью одного заголовочного файла и одного файла с исходным кодом (cpp). В
 заголовочном файле должны находиться функции-инструменты. В основном файле — основная логика программы, обработка
 ввода пользователя.



Советы и рекомендации

Для удобства создайте структуру с типом двумерной координаты (точки) вместе с набором функций для ввода этой координаты
 из консоли, её вывода в консоль и сравнения на предмет равенства. Для этих целей удобнее всего создать ещё один
 заголовочный файл.



Что оценивается

Корректность работы программы и составленного CMake-файла конфигурации проекта.



Как отправить задание на проверку

Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.
 */