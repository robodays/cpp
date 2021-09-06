#include <iostream>
#include <vector>

class AddressBook {

    int64_t numberPhone;
    std::string contactName;
public:
    int64_t getNumberPhone() const {
        return numberPhone;
    }
    std::string getContactName() {
        return contactName;
    }
    void setNumberPhone(int64_t _numberPhone) {
        numberPhone = _numberPhone;
    }
    void setContactName(std::string _contactName) {
        contactName = _contactName;
    }
    AddressBook(int64_t _numberPhone = 0, std::string _contactName = "") {
        numberPhone = _numberPhone;
        contactName = _contactName;
    }
};
class Phone {
    std::vector<AddressBook*> addressBook;

public:
    void call(int64_t numberPhone) {
        std::cout << "CALL +7" <<  numberPhone << std::endl;
    }

    void sms(int64_t numberPhone) {
        std::cout << "SMS +7" <<  numberPhone << std::endl;
        std::cout << "Enter text sms: " << std::endl;
        std::string textSMS;
        std::cin.ignore(32767, '\n');
        std::getline(std::cin, textSMS);
        std::cout << "Send SMS!" << std::endl;
    }


    void addInAddressBook( int64_t _numberPhone, std::string _contactName) {
        AddressBook* addressBook_tmp = new AddressBook(_numberPhone,_contactName);
        //addressBook_tmp->setContactName(_contactName); // заменено на конструктор
        //addressBook_tmp->setNumberPhone(_numberPhone); // заменено на конструктор
        addressBook.push_back(addressBook_tmp);
        //delete(addressBook_tmp); // не могу очистить, т.к. также вычищается из addressBook и данные превращаются в мусор
    }

    int getSizeAddressBook() {
        return  addressBook.size();
    }
    std::vector<AddressBook*> getAddressBook() {
        return  addressBook;
    }
    int searchContact(std::string _contactName) {
        for (int i = 0; i < addressBook.size(); ++i) {
            if (addressBook[i]->getContactName() == _contactName) {
                return addressBook[i]->getNumberPhone();
            }
        }
        std::cout << _contactName << " this contact is not in the address book!";
        return 0;
    }

    std::string inputContactName() {
        std::string contactName;
        std::cout << "Enter the contact name: " << std::endl;
        std::cin >> contactName;
        return contactName;
    }

    int64_t inputNumberPhone() {
        int64_t numberPhone;
        do {
            std::cout << "Enter the contact's phone number (10 digits): " << std::endl;
            std::cout << "+7";
            std::cin >> numberPhone;
        } while (numberPhone < 1000000000 || numberPhone > 9999999999);
        return numberPhone;
    }
};

int main() {
    std::cout << "Simulations mobile phone!" << std::endl;

    Phone* phone = new Phone;

    std::string command;
    do {
        std::cout << "Enter the command (call/sms/add/print/exit):" << std::endl;
        std::cin >> command;

        if (command == "call") {
            std::cout << "Are we calling by the phone number(1) or by the name of the contact(2)? " << std::endl;
            std::string option;
            std::cin >> option;
            if (option == "1") {
                phone->call(phone->inputNumberPhone());
            } else if (option == "2"){
                int numberPhone = phone->searchContact(phone->inputContactName());
                if (numberPhone != 0) {
                    phone->call(numberPhone);
                }
            }
        } else if (command == "sms") {
            std::cout << "Do we send sms by phone number (1) or by contact name (2)? " << std::endl;
            std::string option;
            std::cin >> option;
            if (option == "1") {
                phone->sms(phone->inputNumberPhone());
            } else if (option == "2"){
                int numberPhone = phone->searchContact(phone->inputContactName());
                if (numberPhone != 0) {
                    phone->sms(numberPhone);
                }
            }
        } else if (command == "add") {
            phone->addInAddressBook(phone->inputNumberPhone(), phone->inputContactName());
        } else if (command == "print") {
            //test print all contacts
            for (int i = 0; i < phone->getSizeAddressBook(); ++i) {
                std::cout << "Name: " << phone->getAddressBook()[i]->getContactName() << " "
                          << "Phone: +7" << phone->getAddressBook()[i]->getNumberPhone() << std::endl;
            }
        } else {
            std::cout << "Incorrect command! Try entering again." << std::endl;
        }

    } while(command != "exit");


    delete(phone);
    phone = nullptr;
    return 0;
}
/*
Задание 2. Реализация программы симуляции мобильного телефона


Что нужно сделать
Реализуйте программу простой симуляции работы мобильного телефона.

По мобильному телефону можно звонить и отправлять СМС. Также мобильный телефон содержит адресную книгу. Телефон и
 отдельные записи адресной книги должны быть реализованы с помощью классов. Все номера телефонов задаются в
 формате +7 <10 цифр>.

Пользователь взаимодействует с программой с помощью команд:

Команда add добавляет в адресную книгу новый номер телефона и ассоциирует его с именем контакта. Оба эти параметра
 команда получает от пользователя через стандартный ввод.
Команда call запрашивает у пользователя имя контакта или номер телефона, на который требуется позвонить. Сам по себе
 звонок симулируется с помощью вывода в консоль сообщения CALL с номером телефона, на который осуществляется вызов.
Команда sms. Запрашивает у пользователя номер телефона (или имя контакта), на который требуется послать сообщение.
 Само сообщение также вводится через стандартный ввод.
Команда exit — выход из программы.


Советы и рекомендации
Сам по себе тип номера телефона вы тоже можете реализовать с помощью отдельного класса.



Что оценивается
Корректность работы программы.


 */