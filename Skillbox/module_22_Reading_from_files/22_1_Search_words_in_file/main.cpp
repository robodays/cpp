#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file;
    //file.open("D:\\github\\cpp\\Skillbox\\module_22_Reading_from_files\\22_1_Search_words_in_file\\cmake-build-debug\\words.txt");
    file.open("words.txt");
    if (file.is_open()) {
        std::cout << "File open." << std::endl;
        std::string word;
        int count = 0;
        std::string findStr;
        std::cout << "Enter word for find: " << std::endl;
        std::cin >> findStr;

        while (!file.eof()) {
            file >> word;
            //std::cout << word  << " "; // output all text
            if (findStr == word) {
                count++;
            }
        }
        file.close();
        std::cout << std::endl;
        std::cout << "Count word \"" << findStr << "\": " << count << std::endl;
    } else {
        std::cout << "Error! File not open." << std::endl;
    }
    return 0;
}
/*
 Задание 1. Разработка программы поиска слов в файле

Что нужно сделать
Составьте небольшой текстовый файл «words1.txt», в котором последовательно, через пробелы и переносы строк расположены
 различные слова. Можете использовать любые англоязычные слова. Разработайте программу, которая искала бы среди этих
 слов нужное пользователю и выводила бы общее количество повторений этого слова. 0 — если слово вообще не присутствует
 в файле.



Что оценивается
Корректность работы программы на созданных вами вводных данных. Число найденных слов должно соответствовать.



Как отправить задание на проверку
Выполните задание в Google Документах, откройте доступ для комментирования. Ссылку пришлите через форму для сдачи
 домашнего задания.
 */