#include <iostream>
#include <cpr/cpr.h>


int main() {
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода
    cpr::Response get = cpr::Get(cpr::Url("http://httpbin.org/get"));
    cpr::Response headers = cpr::Get(cpr::Url("https://httpbin.org/headers"));
    cpr::Response headers2 = cpr::Get(cpr::Url("https://httpbin.org/headers"),
                                      cpr::Header({{"user-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.54 Safari/537.36"}}));
    cpr::Response headers3 = cpr::Get(cpr::Url("https://httpbin.org/headers"),
                                      cpr::Header({{"user-Agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/95.0.4638.54 Safari/537.36"},
                                                   {"accept", "text/html"}}));

    std::string name, city;
    std::cin >> name >> city;
    cpr::Response post = cpr::Post(cpr::Url("http://httpbin.org/post"),
                                   cpr::Payload({{"name", name.c_str()},
                                                 {"city", city.c_str()}}));


    cpr::Response post2 = cpr::Post(cpr::Url("https://www.jetbrains.com/"),
                                   cpr::Payload({{"name", name.c_str()},
                                                 {"city", city.c_str()}}));


    std::cout << get.text << std::endl;
    std::cout << get.status_code << std::endl;

    std::cout << headers.text << std::endl;
    std::cout << headers2.text << std::endl;
    std::cout << headers3.text << std::endl;

    std::cout << post.text << std::endl;
    //std::cout << post2.text << std::endl;

    return 0;
}
