#include <iostream>
#include "gpu.h"
#include "ram.h"

void display() {
    std::cout << "Command: display" << std::endl;

    int array[8];
    read(array);

    std::cout << "Output 8 numbers:" << std::endl;
    for (int i = 0; i < 8; ++i) {
        std::cout << "Number # " << i + 1 << ": " << array[i] << std::endl;
    }


}