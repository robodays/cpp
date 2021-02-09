#include <iostream>
#include <bitset>
#include <vector>

enum notes {
    DO = 1,
    RE = 2,
    MI = 4,
    FA = 8,
    SOL = 16,
    LA = 32,
    SI = 64
};

int main() {
    std::vector<int> vecCombinations;
    std::cout << "Enter 12 note combinations (use digits from 1 to 7)" << std::endl;

    for (int i = 0; i < 12; ++i) {
        std::cout << "Enter " << i + 1 <<" for 12:" << std::endl;
        std::string combinationNotes;
        std::cin >> combinationNotes;

        int notesBit = 0;
        int noteInt;
        for (char noteChar : combinationNotes) {
            if (noteChar > '0' && noteChar <= '7') {
                noteInt = std::stoi(std::string(1, noteChar));
                notesBit |= 1 << (noteInt - 1);
            }
        }
        vecCombinations.push_back(notesBit);
        std::cout << std::bitset<7>(notesBit) << std::endl;
    }
    std::cout << "Output: " << std::endl;
    for (int i= 0; i < 12; ++i) {
        std::string listNotes;
        if (vecCombinations[i] & DO) listNotes += "DO ";
        if (vecCombinations[i] & RE) listNotes += "RE ";
        if (vecCombinations[i] & MI) listNotes += "MI ";
        if (vecCombinations[i] & FA) listNotes += "FA ";
        if (vecCombinations[i] & SOL) listNotes += "SOL ";
        if (vecCombinations[i] & LA) listNotes += "LA ";
        if (vecCombinations[i] & SI) listNotes += "SI ";
        if (!listNotes.empty()) {
            std::cout << listNotes << std::endl;
        }
    }
}
void addNote(char ch){

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