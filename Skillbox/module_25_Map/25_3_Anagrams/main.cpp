#include <iostream>
#include <map>
#include <string>

bool CheckAnagrams(std::string& str1, std::string& str2);

int main() {
    std::cout << "Anagrams" << std::endl;
    std::string str1;
    std::string str2;
    std::cout << "Enter first string: " << std::endl;
    std::cin >> str1;
    std::cout << "Enter second string: " << std::endl;
    std::cin >> str2;
    std::cout << (CheckAnagrams(str1,str2) ? "Yes" : "No") << std::endl;
    return 0;
}

bool CheckAnagrams(std::string& str1, std::string& str2) {
    std::map<char, int> map1, map2;
    for (char ch : str1) {
        map1[ch]++;
    }
    for (char ch : str2) {
        map2[ch]++;
    }
    return map1 == map2;
}
/*
Анаграммы

qwertyasas
sasaytrewq
Что нужно сделать

Напишите функцию, которая принимает две строки и возвращает true, если первая строка является анаграммой второй (то
 есть можно получить первую строку из второй путём перестановки букв местами), и false иначе. Для достижения хорошей
 асимптотики решения рекомендуется использовать std::map.

Пример анаграммы: лекарство — стекловар



Чек-лист для проверки задачи

Функция принимает корректные типы данных, тип возвращаемого значения — bool.
Функция не использует библиотек, кроме <iostream>, <map>, <string>.
Функция корректно определяет, являются ли строки анаграммами.

 */