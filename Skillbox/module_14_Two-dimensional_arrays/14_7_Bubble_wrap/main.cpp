#include <iostream>
//template<std::size_t U, std::size_t V>
//void AddElement(const bool(&arr)[U][V]) {
void AddElement(bool arr[][12]) {
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            arr[i][j] = true;
            //std::cout << arr[i][j] << " ";
        }
    }

}

bool printElement(bool arr[][12]) {
    bool  noExit = false;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 12; ++j) {
            if (arr[i][j] == true) {
                std::cout << "O" << " ";
                noExit = true;
            } else {
                std::cout << "X" << " ";
            }
        }
        std::cout << std::endl;
    }
    return noExit;
}

void popBubbles(bool arr[][12]) {
    int beginX, beginY, endX, endY;
    std::cout << "Enter begin x y: ";
    std::cin >> beginX >> beginY;
    std::cout << "Enter end x y: ";
    std::cin >> endX >> endY;
    if (beginX >= 0 && beginX < 12 && beginY >= 0 && beginY < 12 &&
            endX >= 0 && endX < 12 && endY >= 0 && endY < 12) {
        for (int i = beginX; i <= endX; ++i) {
            for (int j = beginY; j <= endY; ++j) {
                if (arr[i][j] == true) {
                    arr[i][j] = false;
                    std::cout << "Pop! ";
                }
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << std::endl;
        std::cerr << "Invalid data entry. Please try again.";
        std::cout << std::endl;
    }
}

int main() {
    bool bubbles[12][12];
    bool noExit = true;
    AddElement(bubbles);
    printElement(bubbles);
    do {
        popBubbles(bubbles);
        noExit = printElement(bubbles);
    } while (noExit);

    std::cout << "Exit! \n";
    return 0;
}
