#include <iostream>
#include <fstream>
//https://github.com/nlohmann/json
//JSON for Modern C++
// https://developers.google.com/protocol-buffers
#include <nlohmann/json.hpp>

// for convenience
using json = nlohmann::json;

struct Record {
    std::string name;
    std::string family;
    int age;
    bool married;
};

int main() {
    Record record;
    Record record4;

    std::cout << "Enter name family age married: " << std::endl;
    //std::cin >> record.name >> record.family >> record.age >> record.married;

    //std::ofstream file("record.json");

    //file << R"({ "name": ")" << record.name << R"(", "family": ")" << record.family << "\"}" << std::endl;

    // запись в файл
    //nlohmann::json dict;
    json dict;
    dict["name"] = record.name;
    dict["family"] = record.family;
    dict["age"] = record.age;
    dict["married"] = record.married;

    nlohmann::json dict2{
        {"name", record.name},
        {"family", record.family},
        {"age", record.age},
        {"married", record.married}
    };

    //file << dict;
    //file << dict2;

    // считывание из строки
    json dict3 = R"({"name": "Vladimir"})"_json;
    std::cout << dict3["name"] << std::endl;

    json dict4;
    std::fstream file2("record.json");
    file2 >> dict4;

    // считываем из файла
    record4.name = dict4["name"];
    record4.family = dict4["family"];
    record4.age = dict4["age"];
    record4.married = dict4["married"];
    std::cout << record4.name << " " << record4.family << " " << record4.age << " " << record4.married << std::endl;

    return 0;
}
