#include <iostream>

/// Наследование 2
/// Наследование — это свойство системы, позволяющее описать новый класс на основе уже существующего с частично или
/// полностью заимствующейся функциональностью. Класс, от которого производится наследование, называется базовым,
/// родительским или суперклассом.

class Animal {
protected:
    std::string name;
    int age;
public:
    void setAge(int _age) {
        if (_age >= 0 && _age < 30) {
            age = _age;
        } else {
            std::cout << "Incorrect age" << std::endl;
        }
    }

    int getAge() {
        return age;
    }
};

class Dog : virtual public Animal {
public:
    Dog() {}

    Dog(int _age, std::string _name) {
        name = name;
        setAge(_age);
    }

    void barkAge() {
        for (int i = 0; i < age; ++i) {
            std::cout << "Bark!";
        }
        std::cout << std::endl;
    }
};

class Cat : virtual public Animal {
public:
    Cat() {}

    Cat(int _age, std::string _name) {
        name = name;
        setAge(_age);
    }

    void meowAge() {
        for (int i = 0; i < age; ++i) {
            std::cout << "Meow!";
        }
        std::cout << std::endl;
    }
};

class CatDog : public Cat, public Dog {
public:
    CatDog(int _age, std::string _name) {
        name = name;
        setAge(_age);
    }
};

int main() {

    Dog dog(10, "Sharik");
    dog.barkAge();
    dog.setAge(5);
    dog.barkAge();

    CatDog catDog(7, "SharikBarsik");
    catDog.meowAge();


    return 0;
}
