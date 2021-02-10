#include <iostream>
#include <vector>

int main() {
    std::vector<float> listPrice = {100.25, 250.75, 150.50, 300.50, 200.25, 50.75};
    std::vector<int> listGoods = {1, 2, 3 , 0, 0, 10};
    float sum = 0;
    for (int i = 0; i < listGoods.size(); ++i) {
        if (listGoods[i] < listPrice.size() && listGoods[i] >= 0) {
            sum += listPrice[listGoods[i]];
        } else {
            std::cerr << "The product with ID: " << listGoods[i] << " is not included in the price list!" << std::endl;
        }
    }
    std::cout << "Purchase amount: "  << sum << std::endl;
    return 0;
}
/*
 *
 * Задача 2.

С помощью списка инициализации задаётся вектор цен на продукты (дробными числами). Так же, с помощью списка
 инициализации, задаётся вектор покупок (в виде индексов), которые совершает человек. Необходимо вывести на экран
 итоговую стоимость покупок

Пример:

Вектор цен выглядит так:  {2.5, 4.25, 3.0, 10.0}

Вектор покупок: {1, 1, 0, 3}, то есть два товара по индексу 1, и по одному — индексов 0 и 3.

Суммарная стоимость будет равна 21.0

*/