#include <iostream>

bool tinyShip[4];
bool smallShip[3];
bool mediumShip[2];
bool bigShip[1];

int main() {

    std::cout << "Size tinyShip: " << sizeof(tinyShip) << std::endl;
    std::cout << "Size smallShip: " << sizeof(smallShip) << std::endl;
    std::cout << "Size mediumShip: " << sizeof(mediumShip) << std::endl;
    std::cout << "Size bigShip: " << sizeof(bigShip) << std::endl;
    return 0;

}
/*
 * Требуется объявить массивы для игры в морской бой и вывести их размеры в консоль,
 * не используя констант с размерами. Всего таких типов 4: крошечный, малый, средний и большой.
 * Для простоты, типом элементов корабля могут быть обычные bool (размер 1 байт).
 * */