#include <iostream>
#include <ctime>
#include <cassert>

class Elf {
    std::string name;
public:
    std::string getName() {
        return name;
    }
    void setName(std::string inName) {
        name = inName;
    }
};

class Branch {
    Elf elf;
public:
    std::string getElfName() {
        return elf.getName();
    }
    void setElfName(std::string name) {
        elf.setName(name) ;
    }
};

class BigBranch : public Branch {

    int countMiddleBranch;
    Branch** middleBranch = nullptr;

    class Tree* tree = nullptr;

public:
    int getCountMiddleBranch() const {
        return countMiddleBranch;
    }

    Branch** getMiddleBranch(){
        return middleBranch;
    }

    BigBranch(class Tree* inTree, int inCountMiddleBranch): tree(inTree), countMiddleBranch(inCountMiddleBranch) {
        assert(inCountMiddleBranch >= 0);
        middleBranch = new Branch*[inCountMiddleBranch];
        for (int i = 0; i < inCountMiddleBranch; ++i) {
            middleBranch[i] = new Branch();
        }
    }
    int getCountElfOnBranch(std::string nameElf);
};

class Tree {
    int countBigBranch;
    BigBranch** bigBranch = nullptr;

public:

    int getCountBigBranch() const{
        return countBigBranch;
    }

    BigBranch** getBigBranch(){
        return bigBranch;
    }

    BigBranch* getBigBranchId(int id){
        return bigBranch[id];
    }

    Tree(int inCountBigBranch): countBigBranch(inCountBigBranch) {
        assert(inCountBigBranch >= 0);
        bigBranch = new BigBranch*[countBigBranch];
        for (int i = 0; i < countBigBranch; ++i) {
            int countMiddleBranch = std::rand() % 2 + 2;
            bigBranch[i] = new BigBranch(this, countMiddleBranch);
        }
    }

};

int BigBranch::getCountElfOnBranch(std::string nameElf) {
    int count = 0;
    std::cout << "Output names neighbors on big branch for elf " << nameElf << ": " << std::endl;
    if (this->getElfName() != nameElf && this->getElfName() != "None") {
        std::cout << this->getElfName() << std::endl;
        count++;
    }
    for (int i = 0; i <this->getCountMiddleBranch(); ++i) {
        if(this->getMiddleBranch()[i]->getElfName() != nameElf && this->getMiddleBranch()[i]->getElfName() != "None") {
            std::cout << this->getMiddleBranch()[i]->getElfName() << std::endl;
            count++;
        }
    }
    return count;
}


int main() {
    std::srand(std::time(nullptr));

    std::cout << "Elf village" << std::endl;
    Tree* tree[5] = {nullptr};

    int autofill = 0;
    std::string autofillName = "Name";

    for (int i = 0; i < 5; ++i) {
        int countBigBranch = std::rand() % 3 + 3;
        tree[i] = new Tree(countBigBranch);
        for (int j = 0; j < tree[i]->getCountBigBranch(); ++j) {
            std::cout << "Enter name Elf on tree id:" << i << ", big branch id:" << j << std::endl;

            //autofill
            std::string nameElf = (autofill % 7 == 0) ? "None" : (autofillName + std::to_string(autofill));
            std::cout << nameElf << std::endl;
            autofill++;

            // std::string nameElf;
            // std::cin >> nameElf;
            tree[i]->getBigBranch()[j]->setElfName(nameElf);
            for (int k = 0; k < tree[i]->getBigBranch()[j]->getCountMiddleBranch(); ++k) {
                std::cout << "Enter name Elf on tree id:" << i << ", big branch id:" << j << ", middle branch: " << k
                            << std::endl;

                //autofill
                std::string nameElf = (autofill % 7 == 0) ? "None" : (autofillName + std::to_string(autofill));
                std::cout << nameElf << std::endl;
                autofill++;

                //std::cin >> nameElf;
                tree[i]->getBigBranch()[j]->getMiddleBranch()[k]->setElfName(nameElf);
            }
        }

    }


    //output
    int countElfAll = 0;
    for (int i = 0; i < 5; ++i) {
        std::cout << std::endl << "TREE = tree id:" << i << std::endl;
        for (int j = 0; j < tree[i]->getCountBigBranch(); ++j) {
            std::cout << "BRANCH = tree id:" << i << " big branch id: " << j << std::endl;
            if (tree[i]->getBigBranchId(j)->getElfName() != "None") {
                std::cout << "Name Elf: " << tree[i]->getBigBranchId(j)->getElfName()
                        << " tree id:" << i << " big branch id: " << j << std::endl;
                countElfAll++;
            } else {
                std::cout << "Name ELF: None " << "tree id:" << i << " big branch id: " << j << std::endl;
            }

            for (int k = 0; k < tree[i]->getBigBranchId(j)->getCountMiddleBranch(); ++k) {
                if (tree[i]->getBigBranchId(j)->getMiddleBranch()[k]->getElfName() != "None") {
                    std::cout << "Name Elf: " << tree[i]->getBigBranchId(j)->getMiddleBranch()[k]->getElfName()
                    << " tree id:" << i << " big branch id: " << j << " middle branch: " << k << std::endl;
                    countElfAll++;
                } else {
                    std::cout << "Name ELF: None " << "tree id:" << i << " big branch id: " << j << " middle branch: "
                                << k << std::endl;
                }
            }
        }
    }
    std::cout << std::endl << "All elf's: " << countElfAll << std::endl << std::endl;

    std::string nameElf;
    do {
        std::cout << "Enter name elf for find('exit' for exit): " << std::endl;
        std::cin >> nameElf;
        bool noFind = true;

        int countNeighbors;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < tree[i]->getCountBigBranch(); ++j) {
                if (tree[i]->getBigBranch()[j]->getElfName() == nameElf
                && tree[i]->getBigBranch()[j]->getElfName() != "None"){
                    countNeighbors = tree[i]->getBigBranch()[j]->getCountElfOnBranch(nameElf);
                    noFind = false;
                    break;
                } else {
                    for (int k = 0; k < tree[i]->getBigBranch()[j]->getCountMiddleBranch(); ++k) {
                        if (tree[i]->getBigBranch()[j]->getMiddleBranch()[k]->getElfName() == nameElf
                        && tree[i]->getBigBranch()[j]->getMiddleBranch()[k]->getElfName() != "None"){
                            countNeighbors = tree[i]->getBigBranch()[j]->getCountElfOnBranch(nameElf);
                            noFind = false;
                            break;
                        }
                    }
                }
            }
        }
        if (noFind) {
            std::cout << "Name " << nameElf << " no find!" << std::endl;
        } else {
            std::cout << "Count neighbors: " << countNeighbors << std::endl;
        }
    } while (nameElf != "exit");

    return 0;
}

/*
Задание 1. Реализация деревни эльфов


Что нужно сделать
Лесные эльфы расположили свою деревню в лесу, прямо на деревьях. Нужно расселить эльфов по веткам деревьев, а затем
 подсчитать общее количество соседей определённого эльфа.

Всего в лесу пять деревьев, на каждом из деревьев 3–5 основных больших ветвей. На каждой из них расположены ещё по 2-3
 средние ветки. Дома эльфов построены только на больших и средних ветках.

В начале программы пользователь размещает в каждом доме по одному эльфу. Делается это с помощью последовательного
 перебора всех имеющихся домов и запроса имени заселяемого эльфа через стандартный ввод. Если было введено None в
 качестве имени, то дом пропускается и не заселяется вообще никем.

После этого требуется найти определённого эльфа по имени. Имя искомого эльфа вводится через стандартный ввод. Для
 данного эльфа, если таковой был найден, требуется вывести общее количество эльфов, живущих вместе с ним на одной
 большой ветви.



Советы и рекомендации
Реализуйте генерацию деревьев с помощью кода, используя случайные числа. Для организации структуры деревьев используйте
 указатель this.



Что оценивается
Корректность работы программы и элегантность принимаемых решений.
 */