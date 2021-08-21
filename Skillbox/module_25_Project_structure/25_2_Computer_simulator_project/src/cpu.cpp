#include <iostream>
#include "cpu.h"
#include "ram.h"

void sum() {
    std::cout << "Command: sum" << std::endl;

    int array[8];
    read(array);

    int sum_array = 0;
    for (int i = 0; i < 8; ++i) {
        sum_array += array[i];
    }

    std::cout << "Sum: " << sum_array << std::endl;
}