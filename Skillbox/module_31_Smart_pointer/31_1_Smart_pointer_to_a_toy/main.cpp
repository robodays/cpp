#include <iostream>
#include <memory>

class Toy {
    std::string name;
public:
    Toy(std::string _name) : name(_name) {};

    Toy() : name("SomeToy") {};

    std::string getName() {
        return name;
    }
};

/*class smart_ptr_toy {
    Toy *toy;
public:
    smart_ptr_toy() {
        toy = new Toy();
    }
    smart_ptr_toy(std::string name) {
        toy = new Toy(name);
    }
    smart_ptr_toy(const smart_ptr_toy& other) {
        toy - new Toy(*other.toy);
    }
    smart_ptr_toy& operator=(const smart_ptr_toy& other) {
        if (this == &other) {
            return *this;
        }
        if (toy != nullptr) {
            delete toy;
        }
        toy = new Toy(*other.toy);
        return *this;
    }
    ~smart_ptr_toy() {
        delete toy;
    }
}*/;

class shared_ptr_toy {
    Toy *toy;
    int *count = nullptr;
public:
    shared_ptr_toy() {
        toy = new Toy("SomeToy");
        count = nullptr;
    }

    shared_ptr_toy(std::string name) {
            toy = new Toy(name);
            count = new int(0);
    }

    shared_ptr_toy(const shared_ptr_toy& other) {
        //toy = new Toy(*other.toy);
        ++*count;
    }

    shared_ptr_toy& operator=(const shared_ptr_toy& other) {
        if (this == &other) {
            return *this;
        }
        if (toy != nullptr) {
            delete toy;
        }
        toy = new Toy(*other.toy);
        ++*count;
        return *this;
    }

    ~shared_ptr_toy() {
      /*  if (*count == 1) {
            delete toy;
        } else {
            --*count;
        }
        */
    }
    void del() {
        if (*count == 1) {
            *count = 0;
            delete toy;
        } else {
            --*count;
        }
    }

    void addCount() {
        ++*count;
    }

};


class Dog {
    std::string name;
    int age;
    shared_ptr_toy *lovelyToy = nullptr;
public:
    Dog(std::string _name, shared_ptr_toy *toy, int _age) : name(_name) {
        if (_age >= 0 && _age < 30) {
            age = _age;
        }
        lovelyToy = toy;
        lovelyToy->addCount();

    }
    //Dog() : Dog("Snow", shared_ptr_toy("SomeToy"), 0) {};
    //Dog(std::string _name) : Dog(_name, shared_ptr_toy("SomeToy") , 0) {};
    //Dog(int _age) : Dog("Snow", shared_ptr_toy("SomeToy"), _age) {};
    ~Dog(){
        //if (lovelyToy->isLast())
        //lovelyToy;
        lovelyToy->del();
        //delete(lovelyToy);
        //lovelyToy->del2();
    }
};

int main() {
    std::cout << "Smart pointer to a toy" << std::endl;

    shared_ptr_toy ball("ball");
    shared_ptr_toy bonn("boon");
    Dog* d = new Dog("Bob", &ball , 3);
    Dog d2("Sharik", &ball , 4);
    Dog d3("Tuzik", &ball , 5);
    Dog d4("Snow", &bonn , 6);
    Dog d5("Dog", &bonn , 7);


    return 0;
}

/*
 Задача 1. Умный указатель на игрушку


Что нужно сделать:
Реализуйте умный указатель shared_ptr_toy с распределённым доступом и механикой подсчёта ссылок для класса Toy, реализованного в задании.

Указатель должен иметь все стандартные методы класса и должен быть функциональной заменой использованию shared_ptr<Toy>.

Также реализуйте свободную функцию make_shared_toy, принимающую набор аргументов и конструирующую игрушку либо от названия, либо копируя другую игрушку.



Чек-лист для проверки задачи
Класс называется shared_ptr_toy
Реализован конструктор, конструктор копий, оператор присваивания копированием, деструктор и функция make_shared
 */