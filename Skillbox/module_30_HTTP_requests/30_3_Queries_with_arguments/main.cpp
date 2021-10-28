#include <iostream>
#include <cpr/cpr.h>
#include <vector>

int main() {
    std::cout << "Queries with arguments!" << std::endl;

    std::string argument;
    std::string value;
    std::vector<std::pair<std::string,std::string>> pairs;
    //std::vector<std::pair<std::string,std::string>> test = {{"1","2"},{"3","4"}};
    //std::initializer_list<cpr::Pair> test2 = {{"1","2"},{"3","4"}};
    //cpr::Pair test2[2] = {{"1","2"},{"3","4"}};
    //std::initializer_list<cpr::Pair> pairs;

    do {
        std::cout << "Enter name argument: " << std::endl;
        std::cin >> argument;

        if (argument != "post" && argument != "get") {
            std::cout << "Enter name value: " << std::endl;
            std::cin >> value;

            pairs.emplace_back(argument, value);

        } else if (argument == "get") {
            std::string str;

            if (!pairs.empty()) {
                for (int i = 0; i < pairs.size(); i++) {
                    if (i == 0) {
                        str += "?" + pairs[i].first + "=" + pairs[i].second;
                    } else {
                        str += "&" + pairs[i].first + "=" + pairs[i].second;
                    }
                }

                cpr::Response get;
                get = cpr::Get(cpr::Url("https://httpbin.org/get" + str));
                std::cout << get.text << std::endl;

            }

        } else if (argument == "post") {
            std::string str;

            if (!pairs.empty()) {
                //std::initializer_list<cpr::Pair> cprPairs;
                std::string str;

                for (int i = 0; i < pairs.size(); i++) {
                    //cpr::Payload({{pairs[i].first.c_str(),pairs[i].second.c_str()}});
                    //cpr::Payload::Add({pairs[i].first.c_str(),pairs[i].second.c_str()});
                    //cpr::Pair x = {pairs[i].first.c_str(),pairs[i].second.c_str()};
                    //cpr::Payload::Add({{pairs[i].first.c_str(),pairs[i].second.c_str()}});
                    //cpr::Pair p(pairs[i].first,pairs[i].second);
                    //p.key = pairs[i].first;
                    //p.value = pairs[i].second;
                    //cpr::Payload(x);
                    //cpr::Pair y = {pairs[i].first,pairs[i].second}
                    str += "\"" + pairs[i].first + "\" = \"" + pairs[i].second + "\"\n";
                }
                cpr::Pair p(pairs[0].first,pairs[0].second);
                //std::initializer_list<cpr::Pair> ps[3] = {{p},{p},{p}};
                cpr::Response post;
                post = cpr::Post(cpr::Url("http://httpbin.org/post"),
                                 cpr::Payload({p}));
                std::cout << post.text << std::endl;

            }
        }
    } while(argument != "post" && argument != "get" );
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