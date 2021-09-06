#include <iostream>
class Window {
    int width = 80;
    int height = 50;
    int leftAngleX = 0;
    int leftAngleY = 0;
public:
    int getWidth() {
        return width;
    }
    int getHeight() {
        return height;
    }
    int getLeftAngleX() {
        return leftAngleX;
    }
    int getLeftAngleY() {
        return leftAngleY;
    }
    void setWidth(int _width) {

    }
    void setHeight(int _height) {

    }
    void setLeftAngleX(int _leftAngleX) {

    }
    void setLeftAngleY(int _leftAngleY) {

    }



};


int main() {
    std::cout << "Control of the desktop window!" << std::endl;

    std::string command;
    do {
        std::cout << "Enter the command (move/resize/display/close):" << std::endl;
        std::cin >> command;

        if (command == "move") {
            std::cout << "Enter vector X and Y (separated by a space): " << std::endl;
            int x,y;
            std::cin >> x >> y;
        } else if (command == "resize") {
            std::cout << "Enter new size window width and height (separated by a space): " << std::endl;
            int width, height;
            std::cin >> width >> height;

        } else if (command == "display") {

        } else {
            std::cout << "Incorrect command! Try entering again." << std::endl;
        }

    } while(command != "close");
    return 0;
}

/*
Задание 3. Реализация программы управления окном рабочего стола


Что нужно сделать
Реализуйте симуляцию работы окна в визуальном интерфейсе пользователя.

Окно располагается на виртуальном экране монитора, размером 80 × 50 точек. У окна есть несколько параметров, которые
 также задаются в пикселях: двумерные координаты левого верхнего угла и размеры, ширина и высота. Ширина и высота при

 этом не могут быть отрицательными, а координаты не могут выходить за область экрана.

Пользователь взаимодействует с программой с помощью команд:

Команда move принимает вектор, на который надо сместить окно на экране. Сообщение с новыми координатами окна
 появляется на экране.
Команда resize запрашивает из стандартного ввода новый размер окна. После изменения размера сообщение с новым размером
 выводится на экране.
Команда display выводит текущее изображение монитора в консоль. 0 — это пиксель вне области окна, 1 — с окном.
Команда close закрывает окно, выход из программы.


Советы и рекомендации
Сам экран монитора вы тоже можете реализовать с помощью класса.


 */