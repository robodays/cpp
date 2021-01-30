#include <iostream>

bool CheckRealNum (std::string number){ // copy and update homework12.7.3
    bool numberGood = false;
    bool pointNo = true;
    for (int i = 0; i < number.length() && !numberGood; i++) {
        if (number[i] >= '0' && number[i] <='9') {
            numberGood = true;
        }
    }

    if (numberGood && (number[0] == '-' ||  number[0] == '.' || (number[0] >= '0' && number[0] <='9'))) {
        if (number[0] == '.') {
            for (int i = 1; i < number.length(); i++) {
                if (number[i] < '0' || number[i] > '9' ) {
                    return false;
                }
            }
        } else {
            for (int i = 1; i < number.length(); i++) {
                if ((number[i] >= '0' && number[i] <= '9') || number[i] == '.') {
                    if (number[i] == '.') {
                        if (pointNo) {
                            pointNo = false;
                        } else {
                            return false;
                        }
                    }
                } else {
                    return false;
                }
            }
        }
    } else {
        return false;
    }
    return true;
}

std::string Input(std::string str, const std::string& countStr) {
    do {
        std::cout << "Enter real number " << countStr << ": " << std::endl;
        std::cin >> str;
        if (!CheckRealNum(str)) {
            std::cout << "Non-real number! Try again!" << std::endl;
        }
    } while (!CheckRealNum(str));
    return str;
}


int main() {
    std::string realNumber1;
    std::string realNumber2;
    realNumber1 = Input(realNumber1, "one");
    realNumber2 = Input(realNumber2, "two");
    float fNum1 = std::stof(realNumber1);
    float fNum2 = std::stof(realNumber2);
    std::cout << (fNum1 < fNum2?"Less":fNum1 > fNum2?"More":"Equal")<< std::endl;

    return 0;
}

/*
 * Сравнение длинных вещественных чисел

Вы продолжаете писать калькулятор, работающий с вещественными числами с очень высокой точностью. Вы уже научились
 проверять корректность записи вещественных чисел в виде строк, и теперь перед вами новая цель - научиться сравнивать
 такие вещественные числа.

Пользователь вводит две строки, задающие вещественные числа, в том же формате, как было описано в задаче “Длинное
 вещественное число”. Программа должна проверить корректность ввода (для этого можно переиспользовать код, написанный
 в задаче “Длинное вещественное число”), после чего вывести слово Less, если первое число строго меньше второго; слово
 More, если первое число строго больше второго; и слово Equal, если введенные числа равны.


Примеры:

Ввод: 2.39 3.61


Ввод: 0123 12.3


Ввод: 12345678 12345678.00


Ввод: -1.0 1.0
 * */