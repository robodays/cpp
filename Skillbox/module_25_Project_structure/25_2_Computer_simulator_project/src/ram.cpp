#include <iostream>
#include "ram.h"

int g_buffer[8];

void write(int array[]) {
    //std::cout << "Command: write" << std::endl;
    for (int i = 0; i < 8; ++i) {
        g_buffer[i] = array[i];
    }
}

void read(int array[]) {
    //std::cout << "Command: read" << std::endl;
    for (int i = 0; i < 8; ++i) {
        array[i] = g_buffer[i];
    }
}