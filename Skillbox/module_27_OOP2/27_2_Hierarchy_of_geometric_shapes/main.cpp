#include <iostream>
#include <cmath>

enum Color {
    NONE,
    RED,
    BLUE,
    GREEN
};
struct Coordinates {
    int X;
    int Y;
};

struct DescribingRectangle {
    double width;
    double height;
};

class Figure {
    std::string nameFigure;
    Coordinates centreFigure = {0,0};
    Color colorFigure = NONE;
public:
    Coordinates getCentreFigure() {
        return centreFigure;
    }

    Color getColorFigure() {
        return colorFigure;
    }

    std::string getNameFigure() {
        return nameFigure;
    }

    void setCentreFigure(Coordinates inCentreFigure) {
        centreFigure = inCentreFigure;
    }

    void setColorFigure(Color inColorFigure) {
        colorFigure = inColorFigure;
    }

    void setNameFigure(std::string inNameFigure) {
        nameFigure = inNameFigure;
    }

    void enterCoordinatesCentre() {
        int x,y;
        std::cout << "Enter coordinates centre figure " << nameFigure << " X Y(separated by a space):" << std::endl;
        std::cin >> x >> y;
        setCentreFigure({x,y});
    }
    void enterColorFigure() {
        std::string color;
        do {
            std::cout << "Enter color figure " << nameFigure << " (none, red, blue, green):" << std::endl;
            std::cin >> color;
            if (color == "none") {
                setColorFigure(NONE);
            } else if (color == "red") {
                setColorFigure(RED);
            } else if (color == "blue") {
                setColorFigure(BLUE);
            } else if (color == "green") {
                setColorFigure(GREEN);
            } else {
                std::cout << "Incorrect input, enter again!" << std::endl;
                continue;
            }
            break;
        } while (true);
    }
};

class Rectangle  : public Figure {
    double width = 0;
    double height = 0;

public:
/*    Rectangle(double inWidth, double inHeight, Coordinates inCentreFigure, Color inColorFigure)
    : width(inWidth), height(inHeight){
        setCentreFigure(inCentreFigure);
        setColorFigure(inColorFigure);
    };*/

    Rectangle() {
        setNameFigure("rectangle");
        enterCoordinatesCentre();
        enterColorFigure();
        enterOtherParams();
    };

    double getWidth() const {
        return width;
    }

    double getHeight() const {
        return height;
    }

    void setWidth(double inWidth) {
        width = inWidth;
    }

    void setHeight(double inHeight) {
        height = inHeight;
    }

    void enterOtherParams() {
        double inputWidth, inputHeight;
        std::cout << "Enter width rectangle:" << std::endl;
        std::cin >> inputWidth;
        setWidth(inputWidth);
        std::cout << "Enter height rectangle:" << std::endl;
        std::cin >> inputHeight;
        setHeight(inputHeight);
    }

    double findingArea () const {
        return width * height;
    }

    DescribingRectangle findingRectangle() {
        return {width, height};
    }


};


class Circle : public Figure {
    double radius = 0;

public:
    Circle() {
        setNameFigure("circle");
        enterCoordinatesCentre();
        enterColorFigure();
        enterOtherParams();
    };

    double getRadius() const {
        return radius;
    }

    void setRadius(double inRadius) {
        radius = inRadius;
    }

    void enterOtherParams() {
        double inputRadius;
        std::cout << "Enter radius circle:" << std::endl;
        std::cin >> inputRadius;
        setRadius(inputRadius);
    }

    double findingArea() const {
        return M_PI * pow (radius, 2);
    }

    DescribingRectangle findingRectangle() const {
        return {(radius * 2),(radius * 2)};
    }
};



class Square  : public Figure {
    double lengthSide = 0;

public:
    Square() {
        setNameFigure("square");
        enterCoordinatesCentre();
        enterColorFigure();
        enterOtherParams();
    };

    double getLengthSide() const {
        return lengthSide;
    }

    void setLengthSide(double inLengthSide) {
        lengthSide = inLengthSide;
    }

    void enterOtherParams() {
        double inputLengthSide;
        std::cout << "Enter length side square:" << std::endl;
        std::cin >> inputLengthSide;
        setLengthSide(inputLengthSide);
    }

    double findingArea () const {
        return pow(lengthSide, 2);
    }

    DescribingRectangle findingRectangle() {
        return {lengthSide, lengthSide};
    }
};

class Triangle  : public Figure {
    double lengthSide = 0;

public:
    Triangle() {
        setNameFigure("triangle");
        enterCoordinatesCentre();
        enterColorFigure();
        enterOtherParams();
    };

    double getLengthSide() const {
        return lengthSide;
    }

    void setLengthSide(double inLengthSide) {
        lengthSide = inLengthSide;
    }

    void enterOtherParams() {
        double inputLengthSide;
        std::cout << "Enter length side triangle:" << std::endl;
        std::cin >> inputLengthSide;
        setLengthSide(inputLengthSide);
    }

    double findingArea () const {
        return pow(lengthSide, 2) / 2;
    }
    DescribingRectangle findingRectangle() const {
        double width = lengthSide;
        double height = sqrt(pow(lengthSide,2) - pow(lengthSide / 2,2));
        return {width, height};
    }

};

void printInformFigure(const std::string& nameFigure, double area, DescribingRectangle rectangle);

int main() {
    std::cout << "Hierarchy of geometric figure." << std::endl;

    std::string command;
    do {
        std::cout << "Enter command(circle, square, triangle, rectangle, exit):" << std::endl;
        std::cin >> command;
        if (command == "circle") {
            Circle* circle = new Circle();
            printInformFigure(circle->getNameFigure(), circle->findingArea(), circle->findingRectangle());

            delete circle;
            circle = nullptr;
        } else if (command == "square") {
            Square* square = new Square();
            printInformFigure(square->getNameFigure(), square->findingArea(), square->findingRectangle());

            delete square;
            square = nullptr;
        } else if (command == "triangle") {
            Triangle* triangle = new Triangle();
            printInformFigure(triangle->getNameFigure(), triangle->findingArea(), triangle->findingRectangle());

            delete triangle;
            triangle = nullptr;
        } else if (command == "rectangle") {
            Rectangle* rectangle = new Rectangle();
            printInformFigure(rectangle->getNameFigure(), rectangle->findingArea(), rectangle->findingRectangle());

            delete rectangle;
            rectangle = nullptr;
        } else if (command != "exit") {
            std::cout << "Incorrect input, enter again!" << std::endl;
            continue;
        }
    } while(command != "exit");

    return 0;
}

void printInformFigure(const std::string& nameFigure, double area, DescribingRectangle rectangle) {
    std::cout << "========================" << std::endl;
    std::cout << "Name Figure: " <<  nameFigure << std::endl;
    std::cout << "Area: " <<  area << std::endl;
    std::cout << "Describing rectangle " << std::endl;
    std::cout << "  width: " << rectangle.width << std::endl;
    std::cout << "  height: " << rectangle.height << std::endl;
    std::cout << "========================" << std::endl;
}

/*
Задание 2. Иерархия геометрических фигур


Что нужно сделать.
Спроектируйте иерархию классов различных фигур: круг, квадрат, равносторонний треугольник, прямоугольник (прямоугольный
 параллелепипед).

Для всех этих фигур есть общие поля-данные — это координаты их центра и условный цвет фигуры: красный, синий или
 зелёный.

Для отдельных фигур есть и уникальные параметры: радиус — для круга, длина ребра — для квадрата и равностороннего
 треугольника, ширина и высота для прямоугольника. Все данные — это вещественные числа с удвоенной точностью.

Для каждой из фигур требуется определить метод нахождения площади фигуры, а также метод нахождения прямоугольника,
 описывающего фигуру полностью (он может быть больше зоны фигуры, но не меньше).

Для лучшего понимания задачи приводится иллюстрация. На ней разными цветами помечены площади фигур, а пунктиром
 изображены прямоугольники, описывающие фигуры.

Для теста предусмотрите ввод пользователем команд: circle, square, triangle, rectangle, соответствующих фигурам.
 Команды должны получать параметры фигур и выводить их площадь и описывающий прямоугольник.

Советы и рекомендации
Для цвета фигуры вы можете использовать собственный тип enum, в котором может содержаться и константа отсутствия
 цвета - None.

Геометрические формулы вы можете найти в интернете.

Что оценивается
Элегантность выстроенной иерархии классов. Корректность работы методов вычислений для фигур важна, но не столь
 принципиальна.
 */