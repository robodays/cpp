#include <iostream>
#include <string>
#include <fstream>

bool FileOpen(std::ifstream&);
bool IsPNG(const std::string&);

int main() {
    std::string fileName;
    std::ifstream file;
    do {
        std::cout << "Enter the file path or file name: " << std::endl;
        std::cout << "(for test: paint.png, paint_new.png, paint_new.jpg, dir\\paint1.png, notpng.png)" << std::endl;
        std::cin >> fileName;
        if (!IsPNG(fileName)) continue;
        file.open(fileName, std::ios::binary);
    } while (!FileOpen(file));
    char buffer[4];
    file.read(buffer, 4);

    // output
    if (buffer[0] == -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G') {
        std::cout << "File totally is PNG!" << std::endl;
    } else {
        std::cout << "File not is PNG!" << std::endl;
    }
    return 0;
}

// checking file open
bool FileOpen(std::ifstream& file) {
    if (file.is_open()) {
        std::cout << "File open!" << std::endl;
        return true;
    } else {
        std::cout << "File no open!" << std::endl;
        return false;
    }
}

// checking file extension
bool IsPNG (const std::string& str) {
    if (str.substr(str.size()-4, 4) == ".png") {
        std::cout << "File name extension is PNG!!" << std::endl;
        return true;
    } else {
        std::cout << "File name extension is not PNG!" << std::endl;
        return false;
    }
}

/*
Задание 4. Разработка детектора PNG-файла
Что нужно сделать
Разработайте программу, которая получает на вход, в стандартный ввод, путь к файлу. На выходе программа должна
 определить, является ли данный файл PNG-изображением. Данная процедура не просто должна смотреть на расширение файла,
 но и произвести минимальный анализ его внутренностей, в бинарном режиме.

Внутренности валидного бинарного файла начинаются со специального 8-байтового заголовка. Нас будут интересовать первые
 четыре байта. Первый байт всегда имеет значение ?119 (число со знаком минус), а следующие — это просто
 символы ‘P’, ‘N’, ‘G’, расположенные друг за другом. Обратите внимание, что все они в верхнем регистре.

По результатам проверки пути и внутренностей требуется сообщить пользователю о результате проверки в стандартный вывод.



Советы и рекомендации
Чтобы определить расширение файла, используйте функцию substr, которая получает офсет и длину подстроки и возвращает её.



Что оценивается
Для произвольных путей файлов, введённых пользователем, требуется выдавать корректный результат — являются ли они
 PNG-файлами или нет.


Как отправить задание на проверку
Выполните задание в Google Документах, откройте доступ для комментирования. Ссылку пришлите через форму для сдачи
 домашнего задания.
 */