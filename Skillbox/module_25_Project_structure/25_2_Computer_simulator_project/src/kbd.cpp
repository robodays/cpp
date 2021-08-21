#include <iostream>
#include "kbd.h"
#include "ram.h"

void input() {
    std::cout << "Command: input" << std::endl;

    int array[8];
    std::cout << "Input 8 numbers:" << std::endl;
    for (int i = 0; i < 8; ++i) {
        std::cout << "Number # " << i + 1<< ": ";
        std::cin >> array[i];
    }
    write(array);
}
