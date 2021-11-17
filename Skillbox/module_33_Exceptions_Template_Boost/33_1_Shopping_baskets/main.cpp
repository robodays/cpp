#include <iostream>
#include <map>
#include <exception>

void add(const std::pair<std::string,int>& pair, std::map<std::string,int>& goods, std::map<std::string,int>& basket);
void remove(const std::pair<std::string,int>& pair, std::map<std::string,int>& goods, std::map<std::string,int>& basket);
std::pair<std::string,int> input();
void printMap(const std::map<std::string,int>& map, std::string nameMap);

int main() {
    std::cout << "Shopping baskets" << std::endl;

    std::string article;
    int quantity;
    std::map<std::string,int> basket;

    std::map<std::string,int> goods;

    do {
        std::cout << "Enter article of goods(or \"end\" to end the input ): " << std::endl;
        std::cin >> article;

        if (article != "end") {
            std::cout << "Enter quantity of goods: " << std::endl;
            std::cin >> quantity;
            goods.emplace(article,quantity);
        }

    } while(article != "end");

    //for fast test
    //std::map<std::string,int> goods{{"abc", 5}, {"cde", 3}, {"def", 1}};

    std::string command;
    do {
        std::cout << "==========================================" << std::endl;
        printMap(goods, "Goods list: ");
        printMap(basket, "Basket: ");

        std::cout << R"(Enter command("add", "remove", "exit"): )" << std::endl;
        std::cin >> command;

        if (command == "add") {
            std::cout << "  Add in basket" << std::endl;
            try {
                add(input(), goods, basket);
            }
            catch (std::invalid_argument& x){
                std::cerr << x.what();
            }
        } else if (command == "remove") {
            std::cout << "  Remove from basket" << std::endl;
            try {
                remove(input(), goods, basket);
            }
            catch (std::invalid_argument& x){
                std::cerr << x.what();
            }
        }


    } while(command != "exit");


    return 0;


}

void add(const std::pair<std::string,int>& pair, std::map<std::string,int>& goods, std::map<std::string,int>& basket) {
    auto it = goods.find(pair.first);
    if (it == goods.end()) {
        throw std::invalid_argument("This article is not in the database!\n");
    } else {
        if (pair.second > it->second) {
            throw std::invalid_argument("The quantity of the requested product exceeds the quantity in stock!\n");
        }
    }

    it->second -= pair.second;

    it = basket.find(pair.first);
    if(it == basket.end()) {
        basket.emplace(pair.first, pair.second);
    } else {
        it->second += pair.second;
    }

}

void remove(const std::pair<std::string,int>& pair, std::map<std::string,int>& goods, std::map<std::string,int>& basket) {
    auto it = basket.find(pair.first);
    if (it == basket.end()) {
        throw std::invalid_argument("This article is not in the basket!\n");
    } else {
        if (pair.second > it->second) {
            throw std::invalid_argument("The quantity of the item being deleted exceeds the quantity in the basket!\n");
        }
    }

    it->second -= pair.second;
    if (it->second == 0) {
        basket.erase(it);
    }

    it = goods.find(pair.first);
    it->second += pair.second;
}

std::pair<std::string,int> input() {
    std::string article;
    int quantity;

    std::cout << "Enter article of goods: " << std::endl;
    std::cin >> article;

    std::cout << "Enter quantity of goods: " << std::endl;
    std::cin >> quantity;

    return {article,quantity};
}

void printMap(const std::map<std::string,int>& map, std::string nameMap) {
    std::cout << nameMap << std::endl;
    if (!map.empty()) {
        for (const auto &oneGoods: map) {
            std::cout << "article: " << oneGoods.first << "\t quantity: " << oneGoods.second << std::endl;
        }
    } else {
        std::cout << "empty" << std::endl;
    }
}

/*
Работа корзины с покупками


Что нужно сделать
Реализуйте простую и безопасную модель работы корзины онлайн-магазина.

В начале программы вы заполняете базу данных самого магазина через стандартную консоль. Каждый элемент этой базы данных
 состоит из двух компонентов — артикула и количества штук.
Корзина должна поддерживать следующие операции: добавление товара с указанным его количеством — add, удаление товара с
 указанным количеством — remove. Обе операции принимают артикул товара в виде строки и количество в виде целого числа.
При вводе аргументов к операциям должна осуществляться их валидация. Артикул должен быть в базе данных магазина,
 количество не должно превышать количество доступного продукта на складе (при удалении — в корзине).


Советы и рекомендации
В качестве контейнера для базы данных и самой корзины можете использовать std::map.



Что оценивается
Корректность логики работы при использовании исключений.


 */