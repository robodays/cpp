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

class Dog {
    std::string name;
    int age;
    std::shared_ptr<Toy> lovelyToy;
    std::weak_ptr<Dog> bestie;
public:
    Dog(std::string _name, std::shared_ptr<Toy> toy, int _age) : name(_name), lovelyToy(toy) {
        if (_age >= 0 && _age <= 30) {
            age = _age;
        }
        printNameAge();
    }
    Dog() : Dog("Snow", std::make_shared<Toy>("SomeToy"), 0) {}
    Dog(std::string _name) : Dog(_name, std::make_shared<Toy>("SomeToy"), 0) {}
    Dog(int _age) : Dog("Snow" , std::make_shared<Toy>("SomeToy"), _age) {}

    void copyLovelyToy(const Dog& oth) {
        lovelyToy = oth.lovelyToy;
    }

    void setBestie(std::shared_ptr<Dog> _bestie) {
        bestie = _bestie;
    }

    void printNameAge() {
        std::cout << name << " " << age << std::endl;
    }

};



int main() {
    std::shared_ptr<Toy> ball = std::make_shared<Toy>("Ball");
    std::shared_ptr<Toy> bone = std::make_shared<Toy>("Bone");

    Dog a("Sharik", ball, 10);
    Dog b("Druzhok", ball, 11);
    Dog c("Pushok", ball, 12);
    Dog d("Vanya", bone, 13);
    Dog e("Iriska", bone, 14);


    std::shared_ptr<Dog> f = std::make_shared<Dog>("Bob", ball, 7);
    std::shared_ptr<Dog> g = std::make_shared<Dog>("Pes", ball, 8);
    std::shared_ptr<Dog> h = std::make_shared<Dog>("Shrek", ball, 9);

    f->setBestie(g);
    g->setBestie(f);
    Dog* pf = f.get();
    Dog* pg = g.get();
    f.reset();
    g.reset();





    e.copyLovelyToy(c);

    //Toy* f = bone.get(); // сырой указатель, тоже удалиться
    d.copyLovelyToy(c);

    ball.reset();
    bone.reset();

    return 0;
}
