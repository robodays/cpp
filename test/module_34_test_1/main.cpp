#include <iostream>

struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a; // прозрачность
};

// Color frameBuffer[1920 * 1080]; // массив пикселей на экране
Color frameBuffer[1080][1920]; // двухмерный массив пикселей на экране

struct Message {
    std::string type;
    char key;
    int x;
    int y;
};

int main() {
    Color red {255, 0, 0};
    Color grin {0, 255, 0};
    Color blue {0, 0, 255};

    Color white {255, 255, 255};
    Color black {0, 0, 0};

    frameBuffer[40][100] = red; // точка

    // линия
    for (int i = 100; i < 800; ++i) {
        frameBuffer[40][i].b = 255;
    }

    // квадрат
    for (int i = 100; i < 800; ++i) {
        for (int j = 40; j < 1000; ++j) {
            frameBuffer[j][i] = blue;
        }
    }

    while (true) {
        std::string command;
        std::cin >> command;
        if (command == "add") {
            // ...
        } else if (command == "exit") {
            return 0;
        }
    }

    while (true) {
        Message message = GetMessage();
        if (message == "exit") {
            break;
        } else {
            DispatchMassage(message);
        }
    }


    return 0;
}
