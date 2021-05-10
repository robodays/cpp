#include <iostream>

int main() {
    float matrix1[4][4] =   {{5.35, 2.57, 3.25, 4.547},
                             {1.945, 2.656, 3.56, 4.856},
                             {1.415, 2.265, 3.879, 4.48},
                             {1.98, 2.381, 3.816, 4.482}};
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (i == j) {
                std::cout << matrix1[i][j] << " ";
            } else {
                std::cout << "  " << 0 << "   ";
            }
        }
        std::cout << std::endl;
    }
}
