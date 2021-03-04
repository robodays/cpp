#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

// function verification entry data
bool CheckingDate(int size);

int main() {
    std::srand(std::time(nullptr));
    int height;
    int width;
    std::cout << "Programs for drawing random pictures." << std::endl;
    do {
        std::cout << "Enter the height of the picture" << std::endl;
        std::cin >> height;
    } while (!CheckingDate(height));
    do {
        std::cout << "Enter the width of the picture" << std::endl;
        std::cin >> width;
    } while (!CheckingDate(width));
    std::ofstream file("pic.txt");
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            file << std::rand() % 2;
        }
        file << std::endl;
    }
    file.close();
    return 0;
}

bool CheckingDate(int size) {
    if (size < 1 ) {
        std::cout << "Cannot be less than or equal to zero. Please enter again." << std::endl;
        return false;
    } else if (size > 1000 ) {
        std::cout << "You have entered a very large value. Please enter no more than 1000." << std::endl;
        return false;
    }
    return true;
}
/*
Задание 2. Реализация рисования случайных картин


Что нужно сделать

С помощью генератора случайных чисел рисуется картинка из нулей и единиц. На вход от пользователя принимается размер
 картины: высота и ширина в пикселях. На выходе нужно создать файл pic.txt, содержимое которого будет наполнено
 случайными нулями и единицами в рамках размера картины.

Это ещё не всё. Если вы запустите программу несколько раз на одних и тех же исходных данных (ширина и высота картины),
 вы очень скоро обнаружите, что всё время выводится одна и та же картинка. Дело в том, что у генератора случайных
 чисел есть ещё и «зерно», от которого он отталкивается. Если это зерно не меняется, то и серия из rand() всегда будет
 возвращать одни и те же случайные числа.

Чтобы разнообразить вывод, вы можете использовать вызов std::srand(std::time(nullptr)); в самом начале программы. Эта
 операция задаёт начальное зерно случайных чисел в зависимости от текущего времени. Для её корректной работы не
 забудьте также включить заголовочный файл <ctime>.



Что оценивается

Корректность работы программы по созданию случайных изображений заданного размера.



Как отправить задание на проверку

Выполните задание в Google Docs, откройте доступ для комментирования. Ссылку пришлите через форму для сдачи домашнего
 задания.
 */