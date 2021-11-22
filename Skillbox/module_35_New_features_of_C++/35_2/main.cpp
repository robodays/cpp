#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <memory>

/*void foo(std::vector<int>& vec) {
    std::unordered_set<int> set(vec.begin(),vec.end());

    std::for_each(vec.begin(),vec.end(),[](int i) {std::cout << i << " ";});
    std::cout << std::endl;

    std::cout << std::count(vec.begin(), vec.end(), 5) << std::endl;
    std::for_each(set.begin(),set.end(),[](int i) {std::cout << i << " ";});
    std::cout << std::endl;

    std::cout << set.count(5) << std::endl;

}*/

int main() {
    std::vector<int> vec;
    vec = {1, 3, 5, 7, 5, 9, 4, 2, 7, 8, 11, 50};

    //foo(vec);

    auto foo2 { [](const std::vector<int>& vec) -> std::unique_ptr<std::vector<int>> {
        std::unordered_set<int> set(vec.begin(),vec.end());
        auto vec2 = std::make_unique<std::vector<int>>(set.begin(),set.end());
        return vec2;
    }};

    auto vec2_ptr = foo2(vec);
    std::cout << "new vector in *vec2_ptr:" << std::endl;
    for (auto v : *vec2_ptr) {
        std::cout << v << " ";
    }
    std::cout << "\n=========================\n" << std::endl;


    auto foo3 { [](const std::vector<int>& vec) -> std::unique_ptr<std::vector<int>> {
        std::unordered_set<int> set;
        for(auto v : vec) {
            if (set.count(v)) {
                std::cout << v << " already exist" << std::endl;
            } else {
                set.insert(v);
            }
        }
        auto vec2 = std::make_unique<std::vector<int>>(set.begin(),set.end());
        return vec2;
    }};

    auto vec3_ptr = foo3(vec);
    std::cout << "new vector in *vec3_ptr:" << std::endl;
    for (auto v : *vec3_ptr) {
        std::cout << v << " ";
    }

    return 0;
}
/*
Задание 2 (урок 3)


Цель задания
Поработать с новыми структурами данных.



Что нужно сделать
Так как std::unordered_set позволяет нам быстро определять, есть ли указанный ключ в контейнере, мы можем использовать
 его для фильтрации уникальных чисел.

Создайте лямбда-выражение, принимающее на вход std::vector<int>, в котором содержатся числа, которые могут повторяться.
 Внутри лямбды создайте unordered_set и при помощи него определяйте, сколько раз текущее число вам встречалось раньше.
 В результате верните std::unique_ptr<std::vector<int>>, содержащий числа без повторов. При проходе по контейнеру
 используйте новый формат цикла for и ключевое слово auto.
 */