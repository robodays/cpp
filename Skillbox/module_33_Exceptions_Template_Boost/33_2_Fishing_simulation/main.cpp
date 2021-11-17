#include <iostream>
#include <vector>
#include <ctime>
#include <exception>

class VictoryException: public std::exception {
    int count;
public:
    explicit VictoryException(int _count):count(_count) {};
    const char* what() const noexcept override {
        return "Victory! You caught a fish!";
    };
    int getCount() const {
        return count;
    }
};

class LosingException: public std::exception {
public:
    const char* what() const noexcept override {
        return "Losing! You caught the shoes!";
    };
};

class Game {
    std::vector<std::string> sectors;
    std::vector<std::string> fish;

public:
    Game() {
        for (int i = 0; i < 9; ++i) {
            sectors.emplace_back("X");
        }

        for (int i = 0; i < 9; ++i) {
            fish.emplace_back("empty");
        }

        bool isNotFilled = true;
        int count = 0;
        while(isNotFilled) {
            int i = std::rand() % 9;
            if (fish[i] != "shoes") {
                if (count < 3) {
                    fish[i] = "shoes";
                    count++;
                } else {
                    fish[i] = "fish";
                    isNotFilled = false;
                }
            }
        }
    }

    void print() {
        for (int i = 1; i < 10; ++i) {
            std::cout << i << "\t";
        }

        std::cout << std::endl;
        for (int i = 0; i < 9; ++i) {
            std::cout << sectors[i] << "\t";
        }
        std::cout << std::endl;

        //--> for test
        for (int i = 0; i < 9; ++i) {
            std::cout << fish[i] << "\t";
        }
        std::cout << std::endl;
        //<--

    }
    void fishing() {
        int sector;
        int count = 1;
        do {
            std::cout << "Enter sector for fishing: " << std::endl;
            std::cin >> sector;

            if (sector < 1 || sector > 9){
                throw std::invalid_argument("Invalid sector input");
            } else {
                if (fish[sector - 1] == "empty") {
                    sectors[sector - 1] = "empty";
                    count ++;
                } else if (fish[sector - 1] == "shoes") {
                    sectors[sector - 1] = "SHOES";
                    throw LosingException();
                } else if (fish[sector - 1] == "fish") {
                    sectors[sector - 1] = "FISH";
                    throw VictoryException(count);
                }
            }
            print();
        } while (true);
    }
};


int main() {
    std::cout << "Fishing simulation" << std::endl;

    std::srand(std::time(nullptr));

    Game* game = new Game();

    game->print();

    try {
        game->fishing();
    }
    catch (const std::invalid_argument& err) {
        std::cerr << "Invalid argument supplied: " << err.what() << std::endl;
    }
    catch (const VictoryException& err) {
        std::cout << err.what() << std::endl;
        std::cout << "Number of attempts:" << err.getCount() << std::endl;
    }
    catch (const LosingException& err) {
        std::cout << err.what() << std::endl;
    }

    delete game;
    return 0;
}

/*
Симуляция ловли рыбы


Что нужно сделать
Реализуйте простую игру-симуляцию ловли рыбы. Игровое поле представляет собой девять секторов условного пруда. В начале
 игры в одном из этих секторов с помощью генератора случайных чисел оказывается рыба. Точно так же, случайным образом,
 распределяются и три сапога. Сапог и рыба при этом не могут находиться в одном и том же секторе одновременно, как и
 несколько сапог сразу.

Игрок закидывает удочку с приманкой в один из секторов, номер которого вводится стандартным способом через консоль.
 Задача игрока — угадать сектор, в котором находится рыба и, таким образом, поймать её. Если игрок попал на пустой
 сектор, то удочку надо забросить повторно. Если игрок поймал сапог, то игра завершается с отрицательным результатом.

Реализовать задачу нужно с помощью исключений: когда успешный заброс удочки генерирует специальное пользовательское
 исключение, после чего программа должна завершиться и оповестить пользователя об успешной рыбалке и количестве
 попыток, которое ему для этого потребовалось. Если же был пойман сапог, то должно выводиться сообщение о неудачной
 ловле.



Что оценивается
Корректность работы игровой логики. Точность использования исключений.
 */