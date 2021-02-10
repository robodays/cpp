#include <iostream>
#include <unistd.h>

float radioWave[10] = {11.77, 21.52, 31.47, 41.73, 51.27, 61.17, 71.48, 81.87, 91.75, 101.28};


int main() {
    int oldChannel = 1;
    int radioChannel;
    do {
        std::cout << "Input radio channel (1-10): ";
        std::cin >> radioChannel;
        if (radioChannel < 0 || radioChannel > sizeof(radioWave) / sizeof(radioWave[0])) {
            std::cerr << "Error! This channel is not working!";
            sleep(1);
            std::cout << "\n";
            radioChannel = oldChannel;
        } else {
            oldChannel = radioChannel;
        }
        std::cout << "The channel is playing " << radioChannel << ".\n";
    } while (radioChannel != 0);
    std::cout << "Exit!" << std::endl;

    return 0;
}
/*
 * В радио-приёмнике настроено 10 частот-каналов, представленные в виде массива. Каждая из настроек частоты это число
 * с плавающей точкой. Настройка производится при старте приёмника. Приёмник проигрывает текущий настроенный канал,
 * устанавливая текущую активную чистоту, которая и показывается пользователю. Требуется организовать безопасный доступ
 * к каналам приёмника. Если канал набираемый пользователем находится за пределами массива каналов, приёмник не
 * переключается и выводит сообщение об ошибке. Если пользователь вводит 0, приёмник отключается.
 * */