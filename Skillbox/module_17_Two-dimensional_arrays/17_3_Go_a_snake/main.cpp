#include <iostream>

int main() {
    int matrix[5][5];
    int count = 0;

    for (int i = 0; i < 5; ++i) {
        if (i % 2 == 0) {
            for (int j = 0; j < 5; ++j) {
                matrix[i][j] = count;
                count++;
            }
        } else {
            for (int j = 4; j >= 0; --j) {
                matrix[i][j] = count;
                count++;
            }
        }
    }
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

}
/*
 *
 * */