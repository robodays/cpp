#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// function adding in basket
void AddInBasket(const std::string& nameFish);
// function checked catch again or exit
bool CheckedNext();
// function outputs contents of basket
bool OutputBasket();

int main() {
    std::cout << "Game Fishing." << std::endl;
    do {
        std::cout << "Enter the name of the fish you want to catch." << std::endl;
        std::string userNameFish;
        std::cin >> userNameFish;
        std::string fileNameFish;
        bool isCatch = false;

        std::ifstream file("river.txt");
        if (file.is_open()) {
            while (!file.eof()){
                file >> fileNameFish;
                if (userNameFish == fileNameFish) {
                    std::cout << "You catch fish " << userNameFish << std::endl;
                    AddInBasket(userNameFish);
                    isCatch = true;
                    break;
                }
            }
            if (!isCatch) {
                std::cout << "You didn't catch a fish!" << std::endl;
            }
            file.close();
        } else {
            std::cerr << "File river.txt no open!" << std::endl;
            return 1;
        }
        if (!OutputBasket()) return 1;
    } while (CheckedNext());
    return 0;
}
// function outputs contents of basket
bool OutputBasket() {
    int count = 0;
    std::vector<std::string> fishVec;
    std::ifstream file("basket.txt");
    if (file.is_open()) {
        while (!file.eof()) {
            std::string nameFish;
            file >> nameFish;
            fishVec.push_back(nameFish);
            count++;
        }
        std::cout << "========================" << std::endl;
        std::cout << "All catch fish: " << count - 1 << std::endl;
        std::cout << "All content basket: " << std::endl;
        for (int i = 0; i < count - 1; ++i) {
            std::cout << fishVec[i] << std::endl;
        }
        std::cout << "========================" << std::endl;
        return true;
    } else{
        std::cerr << "File basket.txt no open!" << std::endl;
        return false;
    }
}

// function checked catch again or exit
bool CheckedNext() {
    while (true) {
        std::cout << R"(Will you be fishing again? To continue, enter "yes". For exit, enter "exit".)" << std::endl;
        std::string next;
        std::cin >> next;
        if (next == "yes") return true;
        else if (next == "exit") return false;
    }
}

// function adding in basket
void AddInBasket(const std::string& nameFish) {
    std::ofstream file ("basket.txt", std::ios::app);
    file << nameFish << std::endl;
    file.close();
}
/*
Задание 3. Реализация симуляции игры «Рыбалка»


Что нужно сделать

Реализуйте простую симуляцию игры в рыбалку. В исходном текстовом файле реки (river.txt) задаётся список из видов рыб,
 которые можно в ней поймать. Рыбок может быть сколько угодно, разных видов. Виды при этом могут повторяться.

В начале программы пользователь указывает, какую именно рыбу он сейчас будет ловить — вид этой рыбы. После этого из
 первого файла друг за другом осуществляется чтение его содержимого, вид за видом. Если на отдельных шагах вид совпал
 с указанным пользователем, в выходной файл basket.txt (корзинка) записывается этот вид.

В конце программы показывается, сколько было поймано рыб за текущую ловлю. Программу можно запускать несколько раз,
 при этом уже пойманные рыбы должны сохраняться в файле-корзинке.



Пример содержания исходного файла

sunfish
shad
carp
bass
bullhead
carp
walleye
catfish
carp


Что оценивается

Корректность работы программы симуляции игры в рыбалку. Пойманные рыбы должны записываться в выходной файл.



Как отправить задание на проверку

Выполните задание в Google Docs, откройте доступ для комментирования. Ссылку пришлите через форму для сдачи домашнего
 задания.


 * */