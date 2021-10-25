#include <iostream>

/// Инкапсуляция 1
/// Инкапсуляция (encapsulation) - это механизм, который объединяет данные и код, манипулирующий этими данными, а также
/// защищает и то, и другое от внешнего вмешательства или неправильного использования.

class Dog {
    int age;
public:
    Dog(int _age) {
        if (_age > 30 || _age < 0) {
            std::cout << "Incorrect age" << std::endl;
        } else {
            age = _age;
        }
    }

    void setAge(int _age) {
        if (_age > 30 || _age < 0) {
            std::cout << "Incorrect age" << std::endl;
        } else {
            age = _age;
        }
    }

    int getAge() {
        return age;
    }
};

int main() {

    Dog dog(10);
    std::cout << dog.getAge() << std::endl;
    dog.setAge(11);
    std::cout << dog.getAge() << std::endl;

    return 0;
}
