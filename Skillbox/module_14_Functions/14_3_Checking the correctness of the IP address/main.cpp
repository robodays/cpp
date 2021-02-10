#include <iostream>

bool checkOctet(std::string str) {
    if (str.length() > 0 && str.length() <= 3) {
        if (str.length() > 1 && str[0] == '0') {
            return false;
        }
        for (char ch : str) {
            if (ch <'0' || ch > '9') {
                return false;
            }
        }
        int num = std::stoi(str);
        if (num >= 0 && num <= 255) {
            return true;
        }
    }
    return false;
}

int main() {

    std::cout << "Enter IP-address:" << std::endl;
    std::string ipAddress;
    std::cin >> ipAddress;

    bool correct = true;
    int count = 0;
    while (correct && count < 5){
        std::string octet = ipAddress.substr(0, ipAddress.find('.'));
        count++;
        correct = checkOctet(octet);
        if (ipAddress.find('.') == -1) break;
        ipAddress = ipAddress.substr(ipAddress.find('.') + 1, ipAddress.length());
    }
    if (count != 4) {
        correct = false;
    }

    std::cout << (correct?"Yes":"No") << std::endl;

    return 0;
}

/*    Проверка корректности IP-адреса

На этот раз вам нужно проверить, задает ли введенная пользователем строка корректный IP-адрес. IP-адрес должен
 представлять из себя 4 числа, разделенных точками без пробелов, причем каждое число должно быть в диапазоне
 от 0 до 255 включительно. Числа не должны содержать ведущих нулей. Других символов в строке, кроме вышеописанных,
 присутствовать не должно.

Пользователь вводит строку, задающую email-адрес. Программа должна вывести слово Yes, если адрес корректен, а в
 противном случае - слово No.


Примеры корректных IP-адресов:

127.0.0.1

255.255.255.255

1.2.3.4

55.77.213.101



Примеры строк, не являющихся корректными IP-адресами:

255.256.257.258 (числа больше 255)

0.55.33.22. (лишняя точка в конце)

10.00.000.0 (лишние нули)

23.055.255.033 (опять лишние нули)

65.123..9 (две точки подряд)

a.b.c.d (посторонние символы, помимо цифр и точек)

*/
