#include <iostream>
#include <memory>

///Умные указатели

class Toy {
    std::string name;
public:
    Toy(std::string _name) : name(_name){}
    Toy() : name("SomeToy") {}
    std::string getName() {
        return name;
    }
};
class SmartPtrToy {
    Toy* obj;
public:
    SmartPtrToy() {
        obj = new Toy("SomeToy");
    }
    SmartPtrToy(std::string _name) {
        obj = new Toy(_name);
    }
    SmartPtrToy(const SmartPtrToy& other) {
        obj = new Toy(*other.obj);
    }
    SmartPtrToy& operator=(const SmartPtrToy& other) { /// умный указатель
        if (this == &other) {
            return *this;
        }
        if (obj != nullptr) {
            delete obj;
        }
        obj = new Toy("SomeToy");
        return *this;
    }
    ~SmartPtrToy() {
        delete obj;
    }
};
class Dog {
    std::string name;
    int age;
    SmartPtrToy lovelyToy;
public:
    Dog(std::string _name, std::string _toyName, int _age) : name(_name), lovelyToy(_toyName) {
        if (_age >= 0 && _age <= 30) {
            age = _age;
        }
        printNameAge();
    }
    Dog() : Dog("Snow", "SomeToy", 0) {}
    Dog(std::string _name) : Dog(_name, "SomeToy", 0) {}
    Dog(int _age) : Dog("Snow" , "SomeToy", _age) {}


    void printNameAge() {
        std::cout << name << " " << age << std::endl;
    }

};



int main() {


    std::cout << "=======================" << std::endl;
    Dog dog1("Druzhok", "Ball", 10);
   // Dog dog2(dog1); /// копирование объекта c копированием объекта игрушка
    std::cout << "=======================" << std::endl;

    std::unique_ptr<Dog> d = std::make_unique<Dog>("Sharik","toyName",10); // ограничен доступ,
                                                                                // копирование и присваивание запрещены
    return 0;
}
