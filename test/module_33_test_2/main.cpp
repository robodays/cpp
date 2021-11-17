#include <iostream>
#include <cassert>
#include <exception>

class DivisionByZeroException: public std::exception {
public:
    const char* what() const noexcept override {
        return "Division by zero";
    };
};

int divide(int dividend, int divisor) {
    if (divisor == 0) {
        throw DivisionByZeroException();
    }
    return dividend / divisor;
}

int distribute (int apples, int count) {
    if (apples < 0 || count < 0) {
        throw std::invalid_argument(apples < 0 ? "apples" : "count");
    }
    if (apples > 100) {
        throw apples;
    }
    return divide(apples, count);
}

int main() {

    int apples;
    int count;
    bool  input = true;
    while (input) {
        std::cout << "Enter apples and count:" << std::endl;
        std::cin >> apples >> count;
        try {
            std::cout << "apples: " << distribute(apples, count) << std::endl;
            input = false;
        }
        catch (const DivisionByZeroException& x) {
            std::cerr << "Caught exception: " << x.what() << std::endl;
            input = false;
        }
        catch (const std::invalid_argument& x) {
            std::cerr << "Invalid argument supplied: " << x.what() << std::endl;
        }
        catch (...) {
            std::cerr << "Some kind of exception has happened... " << std::endl;
        }
    }

    return 0;
}
