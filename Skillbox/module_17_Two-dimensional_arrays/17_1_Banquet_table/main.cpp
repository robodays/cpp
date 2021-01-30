#include <iostream>

int main() {
    // Two rows of seats (5 and 11 Vip)
    int rows[2][6] = {{0, 1, 2, 3, 4, 5},
                      {6, 7, 8, 9, 10, 11}};

    int vip[2] = {5, 11};

    //  fork, spoon, knife, + VIP spoon for dessert.
    bool cutlery[12][4] = {{true, true, true, false},
                           {true, true, true, false},
                           {true, true, true, false},
                           {true, true, true, false},
                           {true, true, true, false},
                           {true, true, true, true},
                           {true, true, true, false},
                           {true, true, true, false},
                           {true, true, true, false},
                           {true, true, true, false},
                           {true, true, true, false},
                           {true, true, true, true}};

    int crockery[12][2] = {{2, 0},
                           {2, 0},
                           {2, 0},
                           {2, 0},
                           {2, 0},
                           {2, 1},
                           {2, 0},
                           {2, 0},
                           {2, 0},
                           {2, 0},
                           {2, 0},
                           {2, 1}};

    int chairs[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    chairs[rows[0][4]]++; // 1 row 5 place add one chairs
    cutlery[rows[1][2]][1] = false; // 2 row 3 place stolen spoon
    cutlery[vip[0]][1] = false; // The vip handed over his spoon
    cutlery[rows[1][2]][1] = true; // vip present spoon
    crockery[vip[0]][1] = 0; // dessert was taken away


    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cout << rows[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 2; ++i) {
        std::cout << vip[i] << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cout << cutlery[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 2; ++j) {
            std::cout << crockery[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for (int i = 0; i < 12; ++i) {
        std::cout << chairs[i] << " ";

    }
    std::cout << std::endl;
}
