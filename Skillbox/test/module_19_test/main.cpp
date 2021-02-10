#include <iostream>

enum test {
    NUM1 = 1,
    NUM2 = 2,
    NUM4 = 4,
    NUM8 = 8,
    NUM16 = 16,
    NUM32 = 32
};

int main() {

    int bit;

    bit |= NUM2;
    bit |= NUM4;
   // bit &= NUM8;

    if (bit & NUM4) {
        std::cout << bit << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}
