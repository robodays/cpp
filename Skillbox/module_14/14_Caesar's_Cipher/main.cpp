#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
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

Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna
 aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.
 Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint
 occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.

25


 * */