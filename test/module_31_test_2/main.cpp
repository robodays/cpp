#include <iostream>

///Деструкторы
class Animal {
public:
    virtual ~Animal() {
        std::cout << "Del Animal!" << std::endl;
    }

    virtual void voice() = 0;
};

class Toy {
    std::string name;
public:
    Toy(std::string _name) : name(_name){}
    Toy() : name("SomeToy") {}
    std::string getName() {
        return name;
    }
};

class Dog : public Animal {
    std::string name;
    int age;
    Toy* lovelyToy;
public:
    Dog(std::string _name, std::string _toyName, int _age) : name(_name) {
        if (_age >= 0 && _age <= 30) {
            age = _age;
        }
        lovelyToy = new Toy(_toyName);
        printNameAge();
    }
    Dog() : Dog("Snow", "SomeToy", 0) {}
    Dog(std::string _name) : Dog(_name, "SomeToy", 0) {}
    Dog(int _age) : Dog("Snow" , "SomeToy", _age) {}

    Dog(const Dog& other) { /// копирование объекта
        name = other.name;
        age = other.age;
        lovelyToy = new Toy(* other.lovelyToy); // копирование объекта игрушки
    }

    Dog& operator=(const Dog& other) { /// присваивание  объекта
        if (this == &other) { // если объект присваиваем самого к себе
            return *this;
        }
        name = other.name;
        age = other.age;
        if (lovelyToy != 0) { // если уже существует, то надо его сначала удалить
            delete lovelyToy;
        }
        lovelyToy = new Toy(* other.lovelyToy); // копирование объекта игрушки
    }

    void voice() override { /// переопределена выше
        std::cout << "Bark" << std::endl;
    }

    void printNameAge() {
        std::cout << name << " " << lovelyToy->getName() << " " << age << std::endl;
    }

    virtual ~Dog() {
        delete lovelyToy;
        std::cout << "Del Dog" << std::endl;
    }
};

class OperaDog : public Dog {
public:
    void voice() override final { /// больше нельзя переопределить, финальная
        std::cout << "Baaaaaaaaaark" << std::endl;
    }
};

int main() {

    Animal* dog = new Dog("Druzhok", "Ball", 10);
    delete dog;
    OperaDog d;
    d.voice();
    std::cout << "=======================" << std::endl;
    Dog dog1("Druzhok", "Ball", 10);
    Dog dog2(dog1); /// копирование объекта c копированием объекта игрушка
    std::cout << "=======================" << std::endl;

    return 0;
}
