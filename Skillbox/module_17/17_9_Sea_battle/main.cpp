#include <iostream>
#include <cmath>

void scrolling(int row) {
    for (int i = 0; i < row; ++i) {
        std::cout << std::endl;
    }

}
void username(std::string arr[]) {
    std::cout << "Enter the name of the first player: " ;
    std::cin >> arr[0];
    std::cout << "Enter the name of the second player: " ;
    std::cin >> arr[1];
}
void initial(int arr[][10]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            arr[i][j] = 0;
        }
    }
}

void printBattlefield(int arr[][10]) {
    std::cout << "_0__1__2__3__4__5__6__7__8__9_\n";
    //std::cout << "______________________________\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (arr[i][j] == 0) {
                std::cout << " O ";
            } else if (arr[i][j] == 1) {
                std::cout << " 1 ";

            } else if (arr[i][j] == 8) {
                std::cout << " * ";

            } else if (arr[i][j] == 9) {
                std::cout << " Ж ";
            }
        }
        std::cout << "|" << i << std::endl;
    }
}

bool printBattlefieldNoShips(int arr[][10]) {
    bool game = false;
    int count = 0;
    std::cout << "_0__1__2__3__4__5__6__7__8__9_\n";
    //std::cout << "______________________________\n";
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (arr[i][j] == 0) {
                std::cout << " ~ ";
                game = true;
            } else if (arr[i][j] == 1) {
                std::cout << " ~ ";
                game = true;
            } else if (arr[i][j] == 8) {
                std::cout << " * ";
            } else if (arr[i][j] == 9) {
                std::cout << " Ж ";
                count++;
            }
        }
        std::cout << "|" << i << std::endl;
    }
    if (count >= 20 || !game) {
        return false;
    } else {
        return true;
    }

}

bool instOneShip(int arr[][10], int deck) {
    int x1, y1;
    int x2, y2;
    if (deck == 1) {
        std::cout << "Enter coordinates for the output of 1 deck ship (x y): ";
        std::cin >> x1 >> y1;
        if (x1 >= 0 && x1 <= 9 && y1 >= 0 && y1 <= 9 && arr[x1][y1] == 0) {
            arr[x1][y1] = 1;
            return true;
        } else {
            return false;
        }
    } else if (deck <= 4) { // ПРОВЕРИТЬ
        std::cout << "Enter BEGIN coordinates for the output of " << deck << " deck ship (x y): ";
        std::cin >> x1 >> y1;
        std::cout << "Enter END coordinates for the output of " << deck << " deck ship (x y): ";
        std::cin >> x2 >> y2;
        if (x1 >= 0 && x1 <= 9 && y1 >= 0 && y1 <= 9 && arr[x1][y1] == 0 &&
                x2 >= 0 && x2 <= 9 && y2 >= 0 && y2 <= 9 && arr[x2][y2] == 0) {
            if (x1 == x2 && abs(y1 - y2) == deck - 1) {
                for (int i = fmin(y1, y2); i <= fmax(y1, y2); ++i) {
                    if (arr[x1][i] != 0) {
                        return false;
                    }
                }
            } else if (y1 == y2 && abs(x1 - x2) == deck - 1) {
                for (int i = fmin(x1, x2); i <= fmax(x1, x2); ++i) {
                    if (arr[i][y1] != 0) {
                        return false;
                    }
                }
            } else {
                return false;
            }
            for (int i = fmin(x1, x2); i <= fmax(x1, x2); ++i) {
                for (int j = fmin(y1, y2); j <= fmax(y1, y2); ++j) {
                    arr[i][j] = 1;
                }
            }
            return true;
        } else {
            return false;
        }

    } else {
        return false;
    }
}

void installingShips(int arr[][10]) {
    printBattlefield(arr);
    for (int i = 0; i < 4; ++i) {
        if (instOneShip(arr, 1)) {
            printBattlefield(arr);
        } else {
            i--;
            std::cout << "Error! Enter again!\n";
        }
    }
    for (int i = 0; i < 3; ++i) {
        if (instOneShip(arr, 2)) {
            printBattlefield(arr);
        } else {
            i--;
            std::cout << "Error! Enter again!\n";
        }
    }
    for (int i = 0; i < 2; ++i) {
        if (instOneShip(arr, 3)) {
            printBattlefield(arr);
        } else {
            i--;
            std::cout << "Error! Enter again!\n";
        }
    }
    for (int i = 0; i < 1; ++i) {
        if (instOneShip(arr, 4)) {
            printBattlefield(arr);
        } else {
            i--;
            std::cout << "Error! Enter again!\n";
        }
    }

}


int main() {
    int battlefield[2][10][10]; // этот закомментировать для теста без расстановки кораблей
 /* // этот раскомментировать для теста без расстановки кораблей
    int battlefield[2][10][10] =    {{{1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                                      {1, 0, 1, 0, 1, 0, 1, 0, 1, 0},
                                      {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
                                      {1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},

                                      {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
                                       {0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
                                       {1, 1, 1, 1, 0, 0, 1, 0, 1, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                       {1, 1, 0, 1, 1, 0, 1, 1, 0, 0},
                                       {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                                       {1, 0, 1, 0, 1, 0, 1, 0, 0, 0}}};
*/
   std::string user[2];
    username(user);

/*    Закомментировать от сюда .....  для теста без расстановки кораблей*/
    initial(battlefield[0]);
    initial(battlefield[1]);
    std::cout << "Installing Ships 1Player " << user[0] << std::endl;
    installingShips(battlefield[0]);
    scrolling(20);
    std::cout << "Installing Ships 2Player " << user[1] << std::endl;
    installingShips(battlefield[1]);
    scrolling(20);
/*  до  сюда, чтобы воспользоваться готовым массивом для теста без расстановки кораблей*/

    // battle
    int player = 0;
    int x, y;
    bool exit;
    int field;
    do {
        std::cout << "Shoots " << player + 1 << " Player " << user[player] << std::endl;
        field = player == 0 ? 1 : 0;
        printBattlefieldNoShips(battlefield[field]);
        std::cout << "Enter the point of the shot (x y)(for exit to -1): ";
        std::cin >> x >> y;
        if (x >= 0 && x <= 9 && y >= 0 && y <= 9 &&
                battlefield[field][x][y] != 8 && battlefield[field][x][y] != 9) {
            if (battlefield[field][x][y] == 0) {
                battlefield[field][x][y] = 8;
                player = player==0?1:0;
                std::cout << "I didn't hit it!!! Before the move.\n";
            } else if (battlefield[field][x][y] == 1){
                battlefield[field][x][y] = 9;
                std::cout << "Hit!!! You can shoot again.\n";
            } else {
                std::cout << "Attention! Incorrect input! Enter it again.\n";
            }
        } else {
            std::cout << "Attention! Incorrect input! Enter it again.\n";
        }
        exit = printBattlefieldNoShips(battlefield[field]);
    } while (x != -1 && y != -1 && exit);

    if (!exit) {
        std::cout << "Win " << player + 1 << " Player " << user[player] << "!!!\n";
    }


    return 0;
}
