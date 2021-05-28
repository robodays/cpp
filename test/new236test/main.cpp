#include <iostream>
#include <string>
//1==============
#define TITLE "Skillbox"
//2==============
#define ONE 1
#define TWO 2
//3==============
#define UP (1 << 0)
#define DOWN (1 << 1)
#define LEFT (1 << 2)
#define RIGHT (1 << 3)
#define UP_LEFT (UP | LEFT)
#define UP_RIGHT (UP | RIGHT)
#define DOWN_LEFT (DOWN | LEFT)
#define DOWN_RIGHT (DOWN | RIGHT)
//4==============
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
//5==============
#define TANK(model, name) model ## _ ## name

void armata_shoot(int shoot){
    for (int i = 0; i < shoot; ++i) {
        std::cout << "Shoot!";
    }
}



int main() {
    //1==============
    std::string s1 = "1";
    std::string s2 = "2";
    std::string str = "The " TITLE " online" ;
    str = s1 + TITLE + " online" ;
    str = s1 + TITLE + s2 ;
    std::cout << TITLE << std::endl;
    std::cout << str << std::endl;
    //2==============
    int command;
    std::cout << "Enter int(1 or 2) " << std::endl;
    std::cin >> command;

    if (command == ONE) {
         std::cout << "Enter 1" << std::endl;
    } else if (command == TWO) {
        std::cout << "Enter 2" << std::endl;
    } else {
        std::cout << "no" << std::endl;
    }
    //3==============
    int command2;
    while (true) {
        std::cout << "Enter int (-1 exit)" << std::endl;
        std::cin >> command2;
        if (command2 == UP) {
            std::cout << "Enter UP" << std::endl;
        } else if (command2 == DOWN) {
            std::cout << "Enter DOWN" << std::endl;
        } else if (command2 == LEFT) {
            std::cout << "Enter LEFT";
        } else if (command2 == RIGHT) {
            std::cout << "Enter RIGHT" << std::endl;
        } else if (command2 == UP_LEFT) {
            std::cout << "Enter UP_LEFT" << std::endl;
        } else if (command2 == UP_RIGHT) {
            std::cout << "Enter UP_RIGHT" << std::endl;
        } else if (command2 == DOWN_LEFT) {
            std::cout << "Enter DOWN_LEFT" << std::endl;
        } else if (command2 == DOWN_RIGHT) {
            std::cout << "Enter DOWN_RIGHT" << std::endl;
        } else if (command2 == -1) {
            break;
        } else {
            std::cout << "no" << std::endl;
        }
    }
    //4=============================================
    std::cout << MIN(10, 20) << std::endl;
    std::cout << MAX(10.5, 10.9) << std::endl;
    std::cout << MAX(30, MIN(20, 40)) << std::endl;
    //5=============================================
    int armata_speed = 120;
    std::cout << armata_speed << std::endl;
    TANK(armata,speed) = 130; // присвоение переменной armata_speed = 130;
    std::cout << armata_speed << std::endl;

    TANK(armata, shoot)(5); // вызов функции armata_shoot(5)
    //6=============================================
#if 0
    std::cout << "NO PRINT"; // не выводится
#endif



    return 0;
}
