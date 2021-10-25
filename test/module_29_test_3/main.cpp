#include <iostream>

/// Полиморфизм – это способность программы идентично использовать объекты с одинаковым интерфейсом без информации о
/// конкретном типе этого объекта.

class Animal {
public:
    virtual void voice() = 0;
};

class Dog : virtual public Animal {
public:
    virtual void voice() {
        std::cout << "Bark!" << std::endl;
    }
};

class Cat : virtual public Animal {
public:
    virtual void voice() {
        std::cout << "Meow!" << std::endl;
    }
};

class CatDog : public Cat, public Dog {
public:
    virtual void voice() {
        std::cout << "MeowBark!" << std::endl;
    }
};

int main() {
    Animal* arr[4];

    arr[0] = new Cat;
    arr[1] = new Dog;
    arr[2] = new CatDog;
    arr[3] = new Dog;

    for (int i = 0; i < 4; ++i) {
        arr[i]->voice();
    }

    return 0;
}
