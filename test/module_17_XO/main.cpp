#include <iostream>



int main() {

    char fields[3][3] = {{' ', ' ', ' '},
                         {' ', ' ', ' '},
                         {' ', ' ', ' '}};
    char x;
    char y;
    char oneGo = 'X';
    char win = ' ';
    bool drawGame = false;
    do {
        std::cout << "Go " << oneGo << "\n";
        std::cout << "Enter x (e => exit): ";
        std::cin >> x;
        if (x != 'e') {
            std::cout << "Enter y (e => exit): ";
            std::cin >> y;
            if (y != 'e') {
                if (x >= '0' && x < '3' && y >= '0' && y < '3' && fields[int(x - '0')][int(y - '0')] == ' ') {
                    fields[int(x - '0')][int(y - '0')] = oneGo;
                    if (oneGo == 'X') {
                        oneGo = 'O';
                    } else {
                        oneGo = 'X';
                    }

                    for (int i = 0; i < 3; ++i) {
                        if (fields[i][0] != ' ' && fields[i][0] == fields[i][1] && fields[i][1] == fields[i][2]) {
                            win = fields[i][0];
                        }
                        if (fields[0][i] != ' ' && fields[0][i] == fields[1][i] && fields[1][i] == fields[2][i]) {
                            win = fields[0][i];
                        }
                    }
                    if (fields[0][0] != ' ' && fields[0][0] == fields[1][1] && fields[1][1] == fields[2][2]) {
                        win = fields[0][0];
                    }
                    if (fields[1][1] != ' ' && fields[1][1] == fields[2][0] && fields[2][0] == fields[0][2]) {
                        win = fields[1][1];
                    }
                    std::cout << std::endl;

                    drawGame = true;
                    for (int i = 0; i < 3; ++i) {
                        for (int j = 0; j < 3; ++j) {
                            std::cout << fields[i][j] << (j == 2 ? "" : " | ");
                            if (drawGame && win == ' ' && fields[i][j] == ' ') {
                                drawGame = false;
                            }

                        }
                        std::cout << "\n---------\n";
                    }
                    std::cout << "=========\n";
                }
            }
        }
    } while (x != 'e' && y != 'e' && win == ' ' && !drawGame);
    if (win != ' ') {
        std::cout << ">>> Win " << win << "!!!! <<<\n";
    } else if (drawGame) {
        std::cout << ">>> Draw game!!! Friendship won!!!! <<<\n";

    }
    std::cout << "Exit!";

    return 0;
}