#include <iostream>
#include <fstream>
#include "disk.h"
#include "ram.h"

void save() {
    std::cout << "Command: save" << std::endl;

    int array[8];
    read(array);

    std::ofstream file("data.txt");
    for (int i = 0; i < 8; ++i) {
        file << array[i] << std::endl;
    }
    file.close();
}

void load() {
    std::cout << "Command: load" << std::endl;

    int array[8];
    std::ifstream file("data.txt");
    if (file.is_open()) {
        for (int i = 0; i < 8; ++i) {
            file >> array[i];
        }
        file.close();
        write(array);
    } else {
        std::cerr << "File not open!" << std::endl;
    }
}