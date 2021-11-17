#include <iostream>
#include <cassert>
#include <exception>

int divide(int dividend, int divisor) {
    if (divisor == 0) {
        throw std::exception();
    }
    return dividend / divisor;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    int apples = 10;
    int count;
    std::cin >> count;
    try {
        apples = divide(apples, count);
        std::cout << apples << std::endl;
    }
    catch (const std::exception& x) {
        std::cerr << "Caught exception: " << x.what() << std::endl;
    }


    return 0;
}
