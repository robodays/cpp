#include <iostream>
#include <vector>


int main() {
    std::vector<int> vec = {8, 7, 6, 5};
    std::vector<int> newVec(4);
    int arr[4][4] = {{1, 2, 3, 4},    // 8+14+18+20 = 60
                     {5, 6, 7, 8},    // 40+42+42+40 = 164
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    int sum = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            sum += vec[j] * arr[i][j];
        }
        newVec[i] = sum;
        sum = 0;
    }
    for (int i = 0; i < 4; ++i) {
        std::cout << newVec[i] << " ";
    }
    return 0;
}
