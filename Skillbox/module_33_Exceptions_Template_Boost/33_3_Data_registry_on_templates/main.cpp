#include <iostream>
#include <vector>

template<typename T1, typename T2>
class Registry {
    std::vector<std::pair<T1,T2>> reg;
public:
    void add(std::pair<T1,T2> pairValue) {
        std::cout << "Add element!" << std::endl;
        reg.push_back(pairValue);
    }

    void remove(T1 key) {
        std::cout << "Deleting an element by key: " << key << std::endl;
        auto it = reg.begin();
        bool isNotFound = true;
        while (it != std::end(reg)) {
            if (it->first == key) {
                it = reg.erase(it);
                std::cout << "Successful deletion!" << std::endl;
                isNotFound = false;
            } else {
                ++it;
            }
        }
        if (isNotFound) {
            std::cout << "Key not found!" << std::endl;
        }
    }

    void print() {
        std::cout << "Print Registry: " << std::endl;
        for (int i = 0; i < reg.size(); ++i) {
            std::cout << reg[i].first << " " << reg[i].second << std::endl;
        }
    }

    void find(T1 key) {
        std::cout << "Find an element by key: " << key << std::endl;
        bool isNotFound = true;
        for (int i = 0; i < reg.size(); ++i) {
            if (reg[i].first == key) {
                std::cout << reg[i].first << " " << reg[i].second << std::endl;
                isNotFound = false;
            }
        }
        if (isNotFound) {
            std::cout << "Key not found!" << std::endl;
        }
    }
};

int main() {
    std::cout << "Data registry on templates" << std::endl;

    auto* registry = new Registry<int,std::string>();
    std::string command;
    do {
        std::cout << std::endl << "Enter command (add, remove, print, find or exit):";
        std::cin >> command;
        if (command == "add") {
            std::pair<int,std::string> pair;
            std::cout << "Enter key and value:";
            std::cin >> pair.first >> pair.second;
            registry->add(pair);

        } else if (command == "remove") {
            int key;
            std::cout << "Enter key for delete:";
            std::cin >> key;
            registry->remove(key);

        } else if (command == "print") {
            registry->print();

        } else if (command == "find") {
            int key;
            std::cout << "Enter key for find:";
            std::cin >> key;
            registry->find(key);

        }

    } while(command != "exit");

    delete registry;
    return 0;
}

/*
Реестр данных на шаблонах


Что нужно сделать
С помощью шаблонов реализуйте простой класс реестра, хранящий произвольные типы значений по ключам произвольного типа.
 Ключи могут повторяться.

Реестр должен поддерживать следующие операции: добавление элемента с ключом, удаление элемента по ключу, вывод всех
 значений с ключами в консоль, поиск элемента по ключу.

Данный словарь должен работать на значениях и ключах следующих типов: int, double, std::string.

Для тестирования программы предусмотрите ввод данных и команд из стандартной консоли:

add — добавить элемент с ключом;
remove — удалить элемент по ключу;
print — напечатать на экране все элементы с их ключами;
find — найти элемент по ключу.


Советы и рекомендации
Для реализации вы можете использовать стандартный шаблон std::vector, который будет хранить ваши шаблонизированные
 пары ключей и значений.



Что оценивается
Корректность работы логики программы, реализованной с помощью шаблонов.
 */