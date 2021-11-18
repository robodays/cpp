#include <iostream>
#include "base64/base64.h"
#include <windows.h>

int main() {


    // in main:
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::string str ="0JjQt9GD0YfQuNGC0Ywg0KErKyDQt9CwIDIxINC00LXQvdGMCg==";
    std::cout << "str: " << base64_decode(str) << std::endl;
    return 0;
}
