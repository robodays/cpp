#include <iostream>
#include <string>
#include <cmath>

struct Vector {
    float x;
    float y;
    float length;
};

std::string InputCommand(std::string listCommands[], int size);
Vector InputVector();

// Adding two vectors — add.
Vector add();
// subtracting two vectors — subtract.
Vector subtract();


void printResult(Vector vector);

int main() {
    int countCommands = 5;
    std::string listCommands[5] = {"add","subtract","scale","length","normalize"};
    Vector vector;
    std::cout << "Realization mathematical vector." << std::endl;
    std::string command;
    command = InputCommand(listCommands, countCommands);
    if (command == "add") vector = add();
    if (command == "subtract") vector = subtract();
    if (command == "scale") vector = scale();
    if (command == "length") vector = length();
    else vector = normalize();

    printResult(vector);


    return 0;
}

void printResult(Vector vector) {
/////----------------------
}

std::string InputCommand(std::string listCommands[], int size) {
    while(true) {
        std::cout << R"(Enter command ("add","subtract","scale","length","normalize"):)" << std::endl;
        std::string input;
        std::cin >> input;
        for (int i = 0; i < size; i++) {
            if (listCommands[i] == input) {
                return input;
            } else {
                std::cout << "That input is invalid.  Please try again." << std::endl;
            }
        }
    }
}

Vector InputVector() {
    Vector vector;
    while (true) {
        std::cout << "Enter vector separated by a space (X Y): " << std::endl;
        std::cin >> vector.x >> vector.y;
        if (std::cin.fail()) { // if the previous extraction failed,
            std::cin.clear(); // then we return cin to the 'normal' mode of operation
            std::cin.ignore(32767,'\n'); // and delete the values of the previous input from the input buffer
        } else {
            return vector;
        }
    }
}

// Adding two vectors — add.
Vector add() {
    std::cout << "Adding two vectors." << std::endl;
    Vector vec1,vec2;
    vec1 = InputVector();
    vec2 = InputVector();
    vec1.x += vec2.x;
    vec1.y += vec2.y;
    return vec1;
}

// subtracting two vectors — subtract.
Vector subtract() {
    std::cout << "Subtracting two vectors." << std::endl;
    Vector vec1,vec2;
    vec1 = InputVector();
    vec2 = InputVector();
    vec1.x -= vec2.x;
    vec1.y -= vec2.y;
    return vec1;
}
// Умножение вектора на скаляр — команда scale.
void scale() {
/////----------------------
}
// Нахождение длины вектора — команда length.
void length() {
/////----------------------
}
// Нормализация вектора — команда normalize.
void normalize() {
/////----------------------
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