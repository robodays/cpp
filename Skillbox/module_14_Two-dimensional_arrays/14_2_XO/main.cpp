#include <iostream>

char ChekWin(char arr[][3]);
bool Output(char arr[][3], char win);

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
                    oneGo = (oneGo == 'X'?'O':'X');

                    win = ChekWin(fields);
                    drawGame = Output(fields, win);
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

char ChekWin(char arr[][3]) {
    char win = ' ';
    for (int i = 0; i < 3; ++i) {
        if (arr[i][0] != ' ' && arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
            win = arr[i][0];
        }
        if (arr[0][i] != ' ' && arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {
            win = arr[0][i];
        }
    }
    if (arr[0][0] != ' ' && arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
        win = arr[0][0];
    }
    if (arr[1][1] != ' ' && arr[1][1] == arr[2][0] && arr[2][0] == arr[0][2]) {
        win = arr[1][1];
    }
    return win;
}

bool Output(char arr[3][3], char win) {
    bool nobody = true;
    std::cout << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << arr[i][j] << (j == 2?"":" | ");
            if (win == ' ' && arr[i][j] == ' ') {
                nobody = false;
            }
        }
        std::cout << (i == 2?"\n\n":"\n---------\n");
    }
    std::cout << "=========\n";
    return nobody;
}