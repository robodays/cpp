#include <iostream>

class Cat;
class Dog;
class Animal;

class Animal {
public:
    virtual void voice(Animal* a) = 0;
    virtual void voice(Cat* a) = 0;
    virtual void voice(Dog* a) = 0;
};

class Cat : public Animal {
    virtual void voice(Animal* a) {
        a->voice(this);
    }

    virtual void voice(Dog* a) {
        std::cout << "Meow";
    }

    virtual void voice(Cat* a) {
        std::cout << "Purr";
    }
};

class Dog : public Animal {
    virtual void voice(Animal* a) {
        a->voice(this);
    }

    virtual void voice(Cat* a) {
        std::cout << "Bark";
    }

    virtual void voice(Dog* a) {
        std::cout << "Woof";
    }
};

void meeting(Animal* animal1, Animal* animal2) {
    animal1->voice(animal2);
    animal2->voice(animal1);
}
int main() {
    std::cout << "Meeting of animals" << std::endl;

    Animal* a = new Dog();
    Animal* b = new Cat();

    meeting(a,a);
    std::cout << std::endl;
    meeting(b,b);
    std::cout << std::endl;
    meeting(a,b);
    std::cout << std::endl;
    meeting(b,a);

    return 0;
}

/*
Решите задачу «Встреча животных».

Встречаясь, животные реагируют друг на друга. Реализуйте базовый класс Animal, классы-наследники Dog и Cat, и напишите
 функцию meeting, принимающую два указателя на базовый класс, по которому лежат элементы классов-наследников, которая
 выводит в консоль разные фразы в зависимости от того, какие конкретные классы встретились.



Dog + Dog → “Woof-Woof”

Dog + Cat → “Bark Meow”

Cat + Dog → “Meow Bark”

Cat + Cat → “Purr Purr”



Пример:

Animal* a = new Dog();
Animal* b = new Cat();
meeting(a,b);


Вывод:

Bark Meow



Чек-лист для проверки задачи
Функция принимает корректные типы данных, тип возвращаемого значения — void.
Решение выполнено через двойную диспетчеризацию или кастование к базовому классу.
Сигнатура функции void meeting (Animal* a, Animal* b), любая другая некорректна.
 */