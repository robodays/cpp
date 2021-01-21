#include <iostream>

int main() {
    int matrix1[4][4] = {{5, 2, 3, 4},
                         {1, 2, 3, 4},
                         {1, 2, 3, 4},
                         {1, 2, 3, 4}};
    int matrix2[4][4] = {{1, 2, 3, 4},
                         {1, 2, 3, 4},
                         {1, 2, 3, 4},
                         {1, 2, 3, 4}};

    bool equal = true;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (matrix1[i][j] != matrix2[i][j]) {
                equal = false;
                break;
            }
        }
    }
    std::cout << (equal?"matrix1 == matrix2":"matrix1 != matrix2");

}
