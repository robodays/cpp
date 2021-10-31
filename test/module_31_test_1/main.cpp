#include <iostream>

///Перегрузка методов

class Dog {
    std::string name;
    int age;
public:
    Dog(std::string _name, int _age) : name(_name) {
        if (_age >= 0 && _age <= 30) {
            age = _age;
        }
        printNameAge();
    }
    Dog() : Dog("Snow", 0) {}
    Dog(std::string _name) : Dog(_name, 0) {}
    Dog(int _age) : Dog("Snow" , _age) {}

    void printNameAge() {
        std::cout << name << " " << age << std::endl;
    }


};

int main() {
    Dog a("Bob", 10);
    Dog b("Bobik");
    Dog c(10);
    Dog d;
    return 0;
}
