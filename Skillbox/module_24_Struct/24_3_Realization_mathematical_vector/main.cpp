#include <iostream>
#include <string>
#include <cmath>

struct Vector {
    float x;
    float y;
    float length;
};

std::string InputCommand(std::string listCommands[], int size);
Vector InputVector(Vector& vector, const std::string&);
float InputFloat();
void printResult(Vector vector, const std::string& command);
// Adding two vectors — add.
Vector Add();
// subtracting two vectors — subtract.
Vector Subtract();
// Multiplying a vector by a scalar - scale.
Vector Scale();
// Finding the length of a vector — length.
Vector Length();
// Нормализация вектора — команда normalize.
Vector Normalize();

int main() {
    int countCommands = 5;
    std::string listCommands[5] = {"add","subtract","scale","length","normalize"};
    Vector vector;
    std::cout << "Realization mathematical vector." << std::endl;
    std::string command;
    command = InputCommand(listCommands, countCommands);
    if (command == "add") vector = Add();
    else if (command == "subtract") vector = Subtract();
    else if (command == "scale") vector = Scale();
    else if (command == "length") vector = Length();
    else vector = Normalize();

    printResult(vector, command);
    return 0;
}

void printResult(Vector vector, const std::string& command) {
    if (command == "length") {
        std::cout << "Length vector equal " << vector.length << std::endl;
    } else {
        std::cout << "New vector equal {" << vector.x << "," << vector.y << "}" << std::endl;
    }
}

std::string InputCommand(std::string listCommands[], int size) {
    while(true) {
        std::cout << R"(Enter command ("add","subtract","scale","length","normalize"):)" << std::endl;
        std::string input;
        std::cin >> input;
        for (int i = 0; i < size; i++) {
            if (listCommands[i] == input) {
                return input;
            }
        }
        std::cout << "That input is invalid.  Please try again." << std::endl;
    }
}

Vector InputVector(Vector& vector, const std::string& addedStr= "") {
    while (true) {
        std::cout << "Enter vector " << addedStr << "separated by a space (X Y): " << std::endl;
        std::cin >> vector.x >> vector.y;
        if (std::cin.fail()) { // if the previous extraction failed,
            std::cin.clear(); // then we return cin to the 'normal' mode of operation
            std::cin.ignore(32767,'\n'); // and delete the values of the previous input from the input buffer
        } else {
            return vector;
        }
    }
}

float InputFloat() {
    float num;
    while (true) {
        std::cout << "Enter number (0 - 100): " << std::endl;
        std::cin >> num;
        if (std::cin.fail()) { // if the previous extraction failed,
            std::cin.clear(); // then we return cin to the 'normal' mode of operation
            std::cin.ignore(32767,'\n'); // and delete the values of the previous input from the input buffer
        } else {
            if (num >=0 && num <= 100) {
                return num;
            }
        }
        std::cout << "Enter again!" << std::endl;
    }
}

// Adding two vectors — add.
Vector Add() {
    std::cout << "Adding two vectors." << std::endl;
    Vector vec1,vec2;
    vec1 = InputVector(vec1, "No.1 ");
    vec2 = InputVector(vec2, "No.2 ");
    vec1.x += vec2.x;
    vec1.y += vec2.y;
    return vec1;
}

// subtracting two vectors — subtract.
Vector Subtract() {
    std::cout << "Subtracting two vectors." << std::endl;
    Vector vec1,vec2;
    vec1 = InputVector(vec1, "No.1 ");
    vec2 = InputVector(vec2, "No.2 ");
    vec1.x -= vec2.x;
    vec1.y -= vec2.y;
    return vec1;
}
// Multiplying a vector by a scalar - scale.
Vector Scale() {
    std::cout << "Multiplying a vector by a scalar." << std::endl;
    Vector vec;
    vec = InputVector(vec);
    float scalar;
    scalar = InputFloat();
    vec.x *= scalar;
    vec.y *= scalar;
    return vec;
}

// Finding the length of a vector — length.
Vector Length() {
    std::cout << "Finding the length of a vector." << std::endl;
    Vector vec;
    vec = InputVector(vec);
    vec.length = sqrtf(powf(vec.x,2) + powf(vec.y,2));
    return vec;
}
// Нормализация вектора — команда normalize.
Vector Normalize() {
    std::cout << "Finding the length of a vector." << std::endl;
    Vector vec;
    vec = InputVector(vec);
    vec.length = sqrtf(powf(vec.x,2) + powf(vec.y,2));
    vec.x /= vec.length;
    vec.y /= vec.length;
    return vec;
}

/*

Задание 3. Реализация математического вектора


Что нужно сделать

Реализуйте структуру двумерного математического вектора и основные операции над ним. Обе координаты вектора (x и y)
 должны быть вещественными числами.

Вначале программы пользователь вводит команду, которая соответствует требуемой операции. Далее, в зависимости от
 операции, пользователь вводит её аргументы. Это могут быть как вектора, так и обычные, скалярные значения. В
 результате в стандартный вывод помещается результат. Это тоже может быть или вектор, или скаляр.



Реализуйте следующие операции в виде отдельных функций:

Сложение двух векторов — команда add.
Вычитание двух векторов — команда subtract.
Умножение вектора на скаляр — команда scale.
Нахождение длины вектора — команда length.
Нормализация вектора — команда normalize.


Что оценивается

Корректность работы программы и всех операций над вектором или векторами.



Как отправить задание на проверку

Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.



 */