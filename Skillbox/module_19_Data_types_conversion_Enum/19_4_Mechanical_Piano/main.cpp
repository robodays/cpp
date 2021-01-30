#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
/*Механическое пианино

Что нужно сделать

Создать упрощённую модель механического пианино. Всего у данного пианино - 7 клавиш, соответствуют они семи нотам.
 Каждая клавиша кодируется уникальной битовой маской, которая записывается в enum. Вначале программы пользователь
 вводит мелодию. Ввод осуществляется с помощью цифр на клавиатуре, от 1 до 7 включительно (от ноты “до” до ноты “си”).
 В результате из чисел может быть составлена любая комбинация нот. К примеру 512 или 154. После ввода комбинации,
 вводится следующая. Всего таких комбинаций нот - 12. Как только все комбинации были введены пользователем, мелодия
 проигрывается. Для этого каждая комбинация нот последовательно выводится на экран. Однако, на этот раз она печатается
 “красиво”, т.е. все ноты указываются словами, а не цифрами. При этом слова разделяются пробелами.



Советы и рекомендации

Для вычленения отдельных символов-цифр из строки с нотами используйте оператор индексации строки. Для дальнейшей
 конвертации символа в строку используйте соответствующий конструктор.



Для простоты, чтобы из индекса ноты получить саму ноту-флаг из enum, используйте оператор сдвига. Общая формула
 такова: 1 << индекс ноты (начинается с нуля). К примеру 1 << 0 - битовый флаг ноты до, 1 << 6 битовая маска ноты си.

*/