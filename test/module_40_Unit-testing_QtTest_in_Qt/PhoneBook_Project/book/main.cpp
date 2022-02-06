#include <QCoreApplication>

#include <iostream>
#include <phonebook.h>

int main(int argc, char *argv[])
{
    std::cout << "Hello world1" << std::endl;

    PhoneBook pBook;
    pBook.add({"John", "Smith", "+79091234567"});
    pBook.add({"Martin", "Chase", "+79261234567"});
    pBook.add({"Luke", "Bradly", "+79857654321"});

    pBook.getAll();

    std::cout << pBook.getAll().size() << std::endl;
//    for (auto it = pBook.begin; it < pBook.end; it++) {
//        std::cout << it;
//    }
//    for (auto &b : pBook) {

//    }


}
