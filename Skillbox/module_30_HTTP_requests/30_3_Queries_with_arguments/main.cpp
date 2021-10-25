#include <iostream>
#include <cpr/cpr.h>
#include <vector>

int main() {
    std::cout << "Queries with arguments!" << std::endl;

    std::string argument;
    std::string value;
    std::vector<std::pair<std::string,std::string>> pairs;

    std::cout << "Enter name argument: " << std::endl;
    std::cin >> argument;

    if (argument != "post" && argument != "get") {
        std::cout << "Enter name argument: " << std::endl;
        std::cin >> value;

        pairs.emplace_back(argument,value);
    } else if (argument == "get"){
        cpr::Response request;
        request = cpr::Get(cpr::Url("https://httpbin.org/headers"),
                           cpr::Header({{"user-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.54 Safari/537.36"},
                                        {"accept", "text/html"}}));
    } else if(argument == "post") {
        std::string str;
        if (pairs.size() != 0) {
            for (auto pair: pairs) {
                str = std:: /// https://docs.libcpr.org/
            }
        }
        cpr::Response post = cpr::Post(cpr::Url("http://httpbin.org/post"),
                                       cpr::Payload({{"name", name.c_str()},
                                                     {"city", city.c_str()}}));
    }
    return 0;
}


/*
Задание 3. Запросы с аргументами


Что нужно сделать
Сделайте запрос к сервису httpbin.org, отправив при этом несколько дополнительных аргументов с данными.

Все названия аргументов и их значения — строковые, и принимаются от пользователя. Пользователь последовательно вводит
 их названия вместе со значениями, пока не встретится аргумент с названием «post» или «get», что будет означать, что
 ввод аргументов закончен и требуется отправить их на сервер выбранным способом.

Если пользователь выбрал «post», то выполняется POST-запрос и аргументы отправляются POST-способом (как форма). Если
 «get», то GET-запрос с GET-аргументами (прямо в URL).

По результатам выполнения запроса, выведите ответ сервера в стандартную консоль и обратите внимание на поля form или
 args, в зависимости от типа запроса в которых должны быть перечислены все введённые вами аргументы.



Советы и рекомендации
Согласно HTTP-стандарту, аргументы в GET-запросах перечисляются прямо в URL запроса после вопросительного знака.
 Названия аргументов отделяются от их значений с помощью символа «=»), а сами аргументы разделены символами «&».

Пример аргументов, заданных в URL запроса: ?foo=first&animal=cat&bar=third



Что оценивается
Корректность работы программы при различных пользовательских данных.


 */