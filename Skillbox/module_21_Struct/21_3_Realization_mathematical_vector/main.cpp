#include <iostream>
#include <string>
#include <cmath>

struct Vector {
    float x = 0.;
    float y = 0.;
    float length = 0.;
};

void InputCommand(std::string& input, std::string listCommands[], int size);
void InputVector(Vector& vector, const std::string& = "");
float InputFloat(float num);
void printResult(const Vector& vector, const std::string& command);
// Adding two vectors — add.
void Add(Vector& vec1, Vector& vec2);
// subtracting two vectors — subtract.
void Subtract(Vector& vec1, Vector& vec2);
// Multiplying a vector by a scalar - scale.
void Scale(Vector& vec1, float scalar);
// Finding the length of a vector — length.
void Length(Vector& vec1);
// Нормализация вектора — команда normalize.
void Normalize(Vector& vec1);

int main() {
    int countCommands = 5;
    std::string listCommands[5] = {"add","subtract","scale","length","normalize"};
    std::cout << "Realization mathematical vector." << std::endl;
    std::string command;
    std::cout << R"(Enter command ("add","subtract","scale","length","normalize"):)" << std::endl;
    std::cin >> command;
    InputCommand(command, listCommands, countCommands);
    Vector vec1;
    if (command == "add") {
        std::cout << "Adding two vectors." << std::endl;
        Vector vec2;
        InputVector(vec1, "No.1 ");
        InputVector(vec2, "No.2 ");
        Add(vec1,vec2);
    }
    else if (command == "subtract") {
        std::cout << "Subtracting two vectors." << std::endl;
        Vector vec2;
        InputVector(vec1, "No.1 ");
        InputVector(vec2, "No.2 ");
        Subtract(vec1,vec2);
    }
    else if (command == "scale") {
        std::cout << "Multiplying a vector by a scalar." << std::endl;
        InputVector(vec1);
        float scalar = 0;
        scalar = InputFloat(scalar);
        Scale(vec1, scalar);
    }
    else if (command == "length") {
        std::cout << "Finding the length of a vector." << std::endl;
        InputVector(vec1);
        Length(vec1);
    }
    else {
        std::cout << "Finding the length of a vector." << std::endl;
        InputVector(vec1);
        Length(vec1);
        Normalize(vec1);
    }
    printResult(vec1, command);
    return 0;
}

void printResult(const Vector& vector, const std::string& command) {
    if (command == "length") {
        std::cout << "Length vector equal " << vector.length << std::endl;
    } else {
        std::cout << "New vector equal {" << vector.x << "," << vector.y << "}" << std::endl;
    }
}

void InputCommand(std::string& input, std::string listCommands[], int size) {
    while(true) {
        bool isCorrectInput = false;
        for (int i = 0; i < size; i++) {
            if (listCommands[i] == input) {
                isCorrectInput = true;
                break;
            }
        }
        if (isCorrectInput) {
            break;
        }
        std::cout << "That input is invalid.  Please try again." << std::endl;
        std::cout << R"(Enter command ("add","subtract","scale","length","normalize"):)" << std::endl;
        std::cin >> input;
    }
}

void InputVector(Vector& vector, const std::string& addedStr) {
    while (true) {
        std::cout << "Enter vector " << addedStr << "separated by a space (X Y): " << std::endl;
        std::cin >> vector.x >> vector.y;
        if (std::cin.fail()) { // if the previous extraction failed,
            std::cin.clear(); // then we return cin to the 'normal' mode of operation
            std::cin.ignore(32767,'\n'); // and delete the values of the previous input from the input buffer
        } else {
            break;
        }
    }
}

float InputFloat(float num) {
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
void Add(Vector& vec1, Vector& vec2) {
    vec1.x += vec2.x;
    vec1.y += vec2.y;
}

// subtracting two vectors — subtract.
void Subtract(Vector& vec1, Vector& vec2) {
    vec1.x -= vec2.x;
    vec1.y -= vec2.y;
}
// Multiplying a vector by a scalar - scale.
void Scale(Vector& vec, float scalar) {
    vec.x *= scalar;
    vec.y *= scalar;
}

// Finding the length of a vector — length.
void Length(Vector& vec) {
    vec.length = sqrtf(powf(vec.x,2) + powf(vec.y,2));
}
// Нормализация вектора — команда normalize.
void Normalize(Vector& vec) {
    vec.x /= vec.length;
    vec.y /= vec.length;
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