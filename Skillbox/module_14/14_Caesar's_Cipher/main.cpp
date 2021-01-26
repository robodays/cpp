#include <iostream>
// unsigned char из-за того, что при превышении char > 127 он переходит на -127
// в место перевода char в int и обратно, было решено расширить до unsigned char
unsigned char CheckChar(unsigned char charStr, int shift, char char1, char char2) {
    if (charStr >= char1 && charStr <= char2) {
        charStr += shift;
        if (charStr < char1) {
            charStr += 26;
        } else if (charStr > char2) {
            charStr -= 26;
        }
    }
    return charStr;

}
std::string EncryptCaesar(std::string str, int shift) {
    for (int i = 0; i < str.length(); ++i) {
        // Вроде хотелось, повторяющее действие вынести в отдельную функцию, но как-то не очень красиво получилось.
        // Может, подскажете, как мне это надо было правильно организовать, или так вполне приемлемо?
        str[i] = CheckChar(str[i], shift, 'a', 'z');
        str[i] = CheckChar(str[i], shift, 'A', 'Z');
    }
    return str;
}

std::string DecryptCaesar(std::string str, int shift) {
    return EncryptCaesar(str, -shift);
}

int main() {
    std::string text;
    std::cout << "Enter text:";
    std::getline(std::cin,text);

    int shift;
    std::cout << "Enter shift:";
    std::cin >> shift;

    if (shift > 26 || shift < -26) {
        shift %= 26;
    }

    std::string encrypt = EncryptCaesar(text, shift);
    std::cout << "EncryptCaesar: " << encrypt << std::endl << std::endl;
    std::cout << "DecryptCaesar: " << DecryptCaesar(encrypt, shift) << std::endl;
    return 0;
}

/*
 * Шифр Цезаря
В древности для зашифрования сообщений использовался такой способ. Все буквы в сообщении сдвигались на одно и то же
 число позиций в алфавите. Число позиций могло быть как положительным, так и отрицательным, и являлось параметром
 шифра. Если для сдвига на данное число позиций алфавита не хватает, то он зацикливается (то есть буква с номером
 27 -  это снова a, буква с номером 28 - это b, и так далее). Например, слово abracadabra при сдвиге на 10 позиций
 превратится в klbkmknklbk. Этот простейший шифр называется шифром Цезаря. Регистр букв (заглавные и строчные) менять
 не нужно. Напишите функцию encryptCaesar от строки и числа, которая возвращает исходную строку, зашифрованную шифром
 Цезаря с параметром, равным данному числу. Также напишите функцию decryptCaesar, выполняющую обратное преобразование.
 Считаем, что входные строки состоят лишь из английских букв; если там содержатся и другие символы, то их надо
 игнорировать.

Подсказка: имея функцию encryptCaesar, функцию decryptCaesar можно реализовать в одну строчку.

Пример 1:

The quick brown fox jumps over the lazy dog

5

Пример 2:

Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

25


 * */