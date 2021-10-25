#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtxKitchen;

enum StatusOrder {
    ACCEPTED,
    WAITING_COOKING,
    COOKING,
    WAITING_DELIVERY,
    DELIVERY
};

class Order {
    std::vector<std::string> menuNames = {"PIZZA","SOUP","STEAK","SALAD","SUSHI"};
    int menuID;
    StatusOrder status;
    int timeCookingSec;
public:
    Order () {
        status = ACCEPTED;
        menuID = std::rand() % 5;
        timeCookingSec = std::rand() % 11 + 5;
    }
    StatusOrder getStatus() const {
        return status;
    }

    std::string getMenuName() const {
        return menuNames[menuID];
    }

    int getTimeCookingSec() const {
        return timeCookingSec;
    }

    void setStatus(StatusOrder inStatus) {
        status = inStatus;
    }

    std::string getStatusStr() {
        if (status == ACCEPTED) return "New. Order accepted";
        else if (status == WAITING_COOKING) return "Order waiting in line cooking";
        else if (status == COOKING) return "Order cooking";
        else if (status == WAITING_DELIVERY) return "Order is awaiting delivery";
        else if (status == DELIVERY) return "Order delivery";
        return "Error";
    }

};

class Kitchen {
    std::vector<Order*> orders;
    int countDoneOrder = 0;
public:

    void orderAcceptance() {
        while (countDoneOrder < 10) {
            mtxKitchen.lock();
            orders.emplace_back(new Order());
            mtxKitchen.unlock();

            printAllOrders();

            mtxKitchen.lock();
            orders.back()->setStatus(WAITING_COOKING);
            mtxKitchen.unlock();

            printAllOrders();

            std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 6 + 5)); // 5-10 sec

        }
    }

    int firstWaitingCooking() {
        //std::lock_guard<std::mutex> mtx(mtxKitchen);
        for (int i = 0; i < orders.size(); ++i) {
            if (orders[i]->getStatus() == WAITING_COOKING) {
                return i;
            }
        }

        return -1;
    }

    void cookingFood() {
        while (countDoneOrder < 10) {
            int idFirstWaitingCooking = firstWaitingCooking();

            if (idFirstWaitingCooking != -1) {
                mtxKitchen.lock();
                orders[idFirstWaitingCooking]->setStatus(COOKING);
                mtxKitchen.unlock();

                printAllOrders();

                std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 11 + 5)); // 5-15 sec

                mtxKitchen.lock();
                orders[idFirstWaitingCooking]->setStatus(WAITING_DELIVERY);
                mtxKitchen.unlock();

                printAllOrders();
            } else {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            };

        }
    }

    int firstWaitingDelivery() {
        //std::lock_guard<std::mutex> mtx(mtxKitchen);
        for (int i = 0; i < orders.size(); ++i) {
            if (orders[i]->getStatus() == WAITING_DELIVERY) {
                return i;
            }
        }
        return -1;
    }

    void deliveryCourier() {
        while (countDoneOrder < 10) {

            int idFirstWaitingDelivery = firstWaitingDelivery();

            if (idFirstWaitingDelivery != -1) {

                mtxKitchen.lock();
                orders[idFirstWaitingDelivery]->setStatus(DELIVERY);
                countDoneOrder++;
                mtxKitchen.unlock();

                printAllOrders();

                std::this_thread::sleep_for(std::chrono::seconds(10)); /// изменить на 30


            } else {
                std::this_thread::sleep_for(std::chrono::seconds(1));
            };
        }
    }

    void printAllOrders() {
        mtxKitchen.lock();
        std::cout << "\n<<<<<<<<<<<<<<<<<<<< Print All Order >>>>>>>>>>>>>>>>>>>>" << std::endl;;
        for (int i = 0; i < orders.size(); ++i) {
            std::cout << i << " "  << orders[i]->getMenuName() << "\t STATUS: " << orders[i]->getStatusStr() << "("
            << orders[i]->getStatus() << ")" << "\t TIME COOKING: " << orders[i]->getTimeCookingSec() << std::endl;
        }
        std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n" << std::endl;
        mtxKitchen.unlock();
    }

};

int main() {

    std::srand(std::time(nullptr));

    std::cout << "Online restaurant kitchen." << std::endl;

    auto* kitchen = new Kitchen();

    std::thread orderAcceptance(&Kitchen::orderAcceptance, kitchen);
    orderAcceptance.detach();

    std::thread orderCooking(&Kitchen::cookingFood, kitchen);
    orderCooking.detach();

    std::thread orderDelivery(&Kitchen::deliveryCourier, kitchen);
    orderDelivery.join();

    delete kitchen;
    return 0;
}

/*\
Задание 3. Симуляция работы кухни онлайн-ресторана


Что нужно сделать
Требуется реализовать упрощённую модель работы кухни ресторана, работающего в режиме онлайн-доставки.

Онлайн-заказ поступает каждые 5–10 секунд. Это случайное блюдо из пяти: пицца, суп, стейк, салат, суши. Официант,
 принявший заказ онлайн, оставляет его у кухни. Если кухня свободна, она принимает заказ и спустя 5–15 секунд возвращает
 уже готовое блюдо на выдачу. Время определяется случайным образом с помощью функции std::rand() в указанных диапазонах.

Курьер приезжает каждые 30 секунд, забирает готовые блюда на выдаче и развозит их по заказчикам.

Программа завершается после 10 успешных доставок. На каждом из этапов, будь то заказ, или готовка, или доставка заказа,
 выводятся соответствующие сообщения в консоль.



Советы и рекомендации
Для симуляции готовки, используйте отдельный мьютекс и запускайте отдельную нить ожидания с вызовом detach для неё.



Что оценивается
Корректность работы программы и безопасность использования общих ресурсов.
 */