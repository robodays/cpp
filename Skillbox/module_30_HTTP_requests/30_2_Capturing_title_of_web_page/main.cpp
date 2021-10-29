#include <iostream>
#include <cpr/cpr.h>

int main() {
    std::cout << "Capturing title of web page" << std::endl;

    cpr::Response getRequest = cpr::Get(cpr::Url("https://httpbin.org"),
                                 cpr::Header({{"accept", "text/html"}}));


    std::cout << getRequest.text << std::endl;

    auto begin = getRequest.text.find("<h2>") + 4;
    auto end = getRequest.text.find("</h2>",begin) - begin;

    std::string contentStr = getRequest.text.substr(begin, end);

    std::cout << "Find content <h2></h2>: " << contentStr << std::endl;

    return 0;
}



/*
Задание 2. Захват заголовка веб-страницы


Что нужно сделать
Запросите с сервера HTML-страницу. Для этого изучите документацию о запросах, поддерживаемых сервисом httpbin.org.
 Найдите там запрос, который выдаёт именно HTML-страницу. Затем сделайте запрос, явным образом используя заголовок
 “accept: text/html”. В полученном ответе найдите заголовок статьи и выведите его в консоль.



Советы и рекомендации
Заголовок статьи размещается между HTML-тегами <h1></h1>



Что оценивается
Корректность работы программы и полученного результата.


 */