#include <iostream>
#include <vector>
class Print {
public:
    Print(std::initializer_list<int> arr) {
        for( auto a : arr) {
            std::cout << a << " ";
        }
    }
};
int main() {
    Print print1 = {1, 2, 3, 4, 5};
    std::cout << std::endl;
    Print print2({1, 2, 3, 4, 5});

    return 0;
}

/*
Задание 1 (к уроку 2)


Цель задания
Закрепить работу с нововведениями в базовых конструкциях языка.



Что нужно сделать
  Вспомните пример с range-based циклом по закрытию файлов:

for(auto ¤tFile : files)
    currentFile.close();
По аналогии распечатайте числа от 1 до 5, используя auto и initializer_list.
 */