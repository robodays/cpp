#include <iostream>
#include <vector>

template<typename T>
struct Message {
    T data;

    Message(const char* inData): data(inData) {}

    void print() const {
        std::cout << data << std::endl;
    }
};

template<typename T>
class MessageClass {
    T data;
public:
    MessageClass(const T inData): data(inData) {}

    void print() const {
        std::cout << data << std::endl;
    }
};


template<typename T1, typename T2>
T1 max(T1 a, T2 b) {
    return a > b ? a : b;
}

template<typename T>
T max(const std::vector<T>& vec) {
    if (vec.empty()) {
        throw std::invalid_argument("vector can't be empty");
    }
    T max = vec[0];
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }
    return max;
}

int main() {

    std::cout << max(10, 20) << std::endl;
    std::cout << max(10, 20.5) << std::endl;
    std::cout << max(10.0, 20.5) << std::endl;

    std::vector<int> vec1 = {10, 15, 20};
    std::vector<double> vec2 = {10.5, 15.7, 20.3};

    std::cout << max(vec1) << std::endl;
    std::cout << max(vec2) << std::endl;

    Message<std::string> message("Hello!");
    message.print();

    MessageClass<std::string> messageClass("Hello class");
    messageClass.print();


    return 0;
}
