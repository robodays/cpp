#include <iostream>
#include <string>

void funcCount(int step, int &countStep, int &result, std::string &str, int lengthJump = 3) {
    if (step == countStep) {
        result++;
        std::cout << str << std::endl;
        return;
    }
    for (int i = 1; i <= lengthJump; ++i) {
        step += i;
        if (step <= countStep) {
            str += std::to_string(i);
            funcCount(step, countStep, result, str, lengthJump);
            str = str.substr(0,str.length()-1);
            step -= i;
        }
    }
}

int main()
{
    int lengthJump;
    int countStep;
    int result = 0;
    std::string stringResult;

    std::cout << "Enter the number of steps: " << std::endl;
    std::cin >> countStep;
    std::cout << "Enter the maximum jump length in steps(if you enter 0 the default jump output length 3): " << std::endl;
    std::cin >> lengthJump;
    std::cout << "Variants: " << std::endl;
    if (lengthJump > 0) {
        funcCount(0,  countStep, result, stringResult, lengthJump);
    } else {
        funcCount(0,  countStep, result, stringResult);
    }
    std::cout << "Result: " << result << std::endl;
}
/*
Задача 3
Что нужно сделать

Кролик сидит на нулевой ступеньке большой лестницы. Он может прыгать на одну или более ступенек вверх, но не далее чем
 на k. Кролик хочет допрыгать до n-й ступеньки, но может сделать это большим количеством способов.

Напишите рекурсивную функцию, которая принимает число n типа int и число k — максимальную длину прыжка, а возвращает
 количество способов, которым кролик может доскакать до n-й ступеньки. Если максимальная длина прыжка не задана —
 считать её равной трём.

Пример:

Ввод: 3, 2

Вывод: 3

Пояснение: (1,2), (2,1), (1,1,1)



Чек-лист для проверки задачи

Функция принимает корректные типы данных, тип возвращаемого значения —  int.
Функция не использует библиотек кроме <iostream>.
Функция рекурсивная.
Функция содержит значение по умолчанию.


Как отправить задание на проверку

Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.
 * */