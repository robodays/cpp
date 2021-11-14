#include <iostream>
#include <nlohmann/json.hpp>
#include <fstream>

int main() {
    std::cout << "Information about film" << std::endl;

    nlohmann::json film{
        {"title", "The Shawshank Redemption"},
        {"country", "United States"},
        {"release-date", "1994"},
        {"studio", "Castle Rock Entertainment"},
        {"script-writer", "Frank Darabont"},
        {"director", "Frank Darabont"},
        {"producer", "Liz Glotzer"},
        {"actors", {
            {"Andy-Dufresne", "Tim Robbins"},
            {"Ellis-Boyd", "Morgan Freeman"}}
        }
    };

    std::ofstream file("film.json");
    file << film;

    return 0;
}

/*
Задача 1. Информация о фильме с кинопортала


Что нужно сделать
Запишите подробную информацию о киноленте в виде JSON-файла. Выберите понравившуюся вам картину на любимом портале,
 проанализируйте информацию о ней и составьте JSON-словарь.

В информации должны присутствовать: страна и дата создания киноленты, студия, которая вела съёмки, автор сценария,
 режиссёр и продюсер киноленты. Обязательно добавьте информацию обо всех главных действующих лицах и тех актёрах,
 которые их сыграли.



Что оценивается
Валидность созданного JSON-документа.
 */