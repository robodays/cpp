#include <iostream>

class Window {
    int widthWindow = 0;
    int heightWindow = 0;
    int leftAngleByWidth = 0;
    int leftAngleByHeight = 0;
public:
    int getWidthWindow() {
        return widthWindow;
    }
    int getHeightWindow() {
        return heightWindow;
    }
    int getLeftAngleByWidth() {
        return leftAngleByWidth;
    }
    int getLeftAngleByHeight() {
        return leftAngleByHeight;
    }
    void setWidthWindow(int _widthWindow) {
        if (_widthWindow < 0) {
            widthWindow = 0;
        } else {
            widthWindow = _widthWindow;
        }
    }
    void setHeightWindow(int _heightWindow) {
        if (_heightWindow < 0) {
            heightWindow = 0;
        } else {
            heightWindow = _heightWindow;
        }
    }
    void setLeftAngleByWidth(int _leftAngleByWidth, int widthScreen) {
        if (_leftAngleByWidth < 0) {
            leftAngleByWidth = 0;
        } else if (_leftAngleByWidth >= widthScreen - 1){
            leftAngleByWidth = widthScreen - 1;
        } else {
            leftAngleByWidth = _leftAngleByWidth;
        }
    }
    void setLeftAngleByHeight(int _leftAngleByHeight, int heightScreen) {
        if (_leftAngleByHeight < 0) {
            leftAngleByHeight = 0;
        } else if (_leftAngleByHeight >= heightScreen - 1){
            leftAngleByHeight = heightScreen - 1;
        } else {
            leftAngleByHeight = _leftAngleByHeight;
        }
    }

};

class Display {
    int widthScreen = 80;
    int heightScreen = 50;

public:
    int getWidthScreen() {
        return widthScreen;
    }

    int getHeightScreen() {
        return heightScreen;
    }

    void printDisplay(Window* win) {
        for (int i = 0; i < heightScreen; ++i) {
            for (int j = 0; j < widthScreen; ++j) {
                if (i >= win->getLeftAngleByHeight() && i < win->getLeftAngleByHeight() + win->getHeightWindow() &&
                    j >= win->getLeftAngleByWidth() && j < win->getLeftAngleByWidth() + win->getWidthWindow()) {
                    std::cout << "1";
                } else {
                    std::cout << "0";
                }
            }
            std::cout << std::endl;
        }
    }
};


int main() {
    std::cout << "Control of the desktop window!" << std::endl;
    Display* display = new Display;
    Window* window = new Window;
    std::string command;
    do {
        std::cout << "Enter the command (move/resize/display/close):" << std::endl;
        std::cin >> command;

        if (command == "move") {
            std::cout << "Enter vector X and Y (separated by a space): " << std::endl;
            int x,y;
            std::cin >> x >> y;

            window->setLeftAngleByWidth(window->getLeftAngleByWidth() + x, display->getWidthScreen());
            window->setLeftAngleByHeight(window->getLeftAngleByHeight() + y, display->getHeightScreen());

            std::cout << "Coordinates window: \n  by width:" << window->getLeftAngleByWidth()
                    << "\n  by height: " << window->getLeftAngleByHeight() << std::endl;

        } else if (command == "resize") {
            std::cout << "Enter new size window width and height (separated by a space): " << std::endl;
            int width, height;
            std::cin >> width >> height;

            window->setWidthWindow(width);
            window->setHeightWindow(height);

            std::cout << "Size window: \n  width:" << window->getWidthWindow()
                    << "\n  height: " << window->getHeightWindow() << std::endl;

        } else if (command == "display") {
            std::cout << "Coordinates window: \n  by width:" << window->getLeftAngleByWidth()
                    << "\n  by height: " << window->getLeftAngleByHeight() << std::endl;
            std::cout << "Size window: \n  width:" << window->getWidthWindow()
                    << "\n  height: " << window->getHeightWindow() << std::endl;
            display->printDisplay(window);
        } else if (command != "close"){
            std::cout << "Incorrect command! Try entering again." << std::endl;
        }

    } while(command != "close");
    delete(window);
    window = nullptr;
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