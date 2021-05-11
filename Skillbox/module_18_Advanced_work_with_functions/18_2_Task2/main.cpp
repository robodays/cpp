#include <iostream>
#include <string>

void funcCount(int step, int &lengthJump, int &countStep, int &result, std::string &str ) {
    if (step == countStep) {
        result++;
        std::cout << str << std::endl;
        return;
    }
    for (int i = 1; i <= lengthJump; ++i) {
        step += i;
        if (step <= countStep) {
            str += std::to_string(i);
            funcCount(step, lengthJump, countStep, result, str);
            str = str.substr(0,str.length()-1);
            step -= i;
        }
    }
}

int main()
{
    int lengthJump = 3;
    int countStep;
    int result = 0;
    std::string stringResult;

    std::cout << "Enter the number of steps: " << std::endl;
    std::cin >> countStep;
    std::cout << "Variants: " << std::endl;
    funcCount(0, lengthJump, countStep, result, stringResult);

    std::cout << "Result: " << result << std::endl;
}
/*

Задача 2
Что нужно сделать

Кролик сидит на нулевой ступеньке большой лестницы. Он может прыгать на 1, 2 или 3 ступеньки вверх. Кролик хочет
 допрыгать до n-й ступеньки, но может сделать это большим количеством способов.

Напишите рекурсивную функцию, которая принимает число n типа int, а возвращает количество способов, которыми кролик может доскакать до n-й ступеньки.

Пример:

Ввод: 3

Вывод : 4

Пояснение: (3), (1,2), (2,1), (1,1,1)



Чек-лист для проверки задачи

Функция принимает корректные типы данных, тип возвращаемого значения —  int.
Функция не использует библиотек кроме <iostream>.
Функция рекурсивная.


Как отправить задание на проверку

Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.

 * */