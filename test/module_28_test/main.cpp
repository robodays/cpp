#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::vector<std::string> history;
std::mutex history_access;

void wait_for_call(int time, std::string name) {

    std::this_thread::sleep_for(std::chrono::seconds(time)); // засыпаем на определенное время.
    std::cout << "Id in foo: " << std::this_thread::get_id() << std::endl; // возвращаем id потока
    std::cout << "RING (" << name << ")" << std::endl;
    history_access.lock();
    history.push_back(name);
    history_access.unlock();
}

int main() {
    int time;
    std::cout << "Enter count sec:";
    std::cin >> time;

    std::string name;
    std::cout << "Enter name:";
    std::cin >> name;

    std::cout << "Id in main: " << std::this_thread::get_id() << std::endl;

    std::thread call(wait_for_call, time, name); // вызов функции в отдельном потоке
    std::cout << "test1" << std::endl;
    std::thread call2(wait_for_call, 6, "New");
    std::cout << "test1" << std::endl;

    call.detach(); //отправляем в свободное плаванье .join(); не требуется(ошибка)
    call2.detach();

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "CALL (Friend1)";
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "CALL (Friend2)";

    if (call.joinable()) call.join(); // ждем конца выполнения и объединяем потоки
    if (call2.joinable()) call2.join();// а можно ли джоинить или детачить объект потока&

    history_access.lock();
    std::cout << "=====================================\n";
    std::cout << "Missed calls:\n";
    for (int i = 0; i < history.size(); ++i) {
        std::cout << history[i] << std::endl;
    }
    history_access.unlock();

    return 0;
}
