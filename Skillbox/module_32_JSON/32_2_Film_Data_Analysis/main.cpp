#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

int main() {
    std::cout << "Film Data Analysis" << std::endl;

    nlohmann::json films;

    std::ifstream file("films.json");

    file >> films;

    //Anthony
    //Olivia
    std::cout << "Enter actor name: " << std::endl;
    std::string actor;
    std::cin >> actor;

    for (auto itFilms = films.begin(); itFilms != films.end(); ++itFilms)
    {
        for (auto itActors = films[itFilms.key()]["actors"].begin(); itActors != films[itFilms.key()]["actors"].end(); ++itActors) {
            std::string str = (*itActors)["actor"];
            if (str.find(actor) != -1) {
                std::cout << "Found:" << std::endl;
                std::cout << "\tFilm: " << films[itFilms.key()]["title"] << std::endl;
                std::cout << "\tActor name: " << (*itActors)["actor"] << std::endl;
                std::cout << "\tCharacter: " << (*itActors)["character"] << std::endl;
                std::cout << "+++++++++++++++++++++++++" << std::endl;
            }
        }
    }

    return 0;
}
/*
Задача 2. Анализ данных о фильмах


Что нужно сделать
Используя модель данных из задачи №1, создайте JSON-документ, но теперь уже для пяти различных кинолент. Ключи в этой
 JSON-базе данных должны быть названиями фильмов, а значениями служить уже словари с информацией о картинах.

Загрузите базу данных в C++-программу для последующего анализа. Предусмотрите следующий функционал: поиск актёра по
 имени (или фамилии) и вывод в консоль названий кинолент, в которых снимался актёр, и роль, которую он исполнял.



Что оценивается
Валидность созданного JSON-документа с базой данных о фильмах. Корректность работы программы поиска актёра.


 */