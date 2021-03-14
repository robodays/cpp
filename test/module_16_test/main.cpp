#include <iostream>
#include <vector>

std::vector<int> del(std::vector<int> vec, int pos) {
    std::vector<int> newVec = vec;
    newVec.resize(newVec.size() - 1);
    for (int i = pos; i < vec.size(); ++i) {
        newVec[i] = vec[i + 1];
    }
    return newVec;
}
std::vector<int> add(std::vector<int> vec, int val) {
    vec.resize(vec.size() + 1);
    vec[vec.size() - 1] = val;
    return vec;
}

int main() {
    std::cout << "How many robots are on display? ";
    int count;
    std::cin >> count;
    int realSize = count;
    std::vector<int> robots(count);

    for (int i = 0; i < realSize; ++i) {
        std::cout << "Input robot № " << i << ": ";
        std::cin >> robots[i];
    }
    int number = 0;
    while (number != -1 && realSize != 0) {
        std::cout << "What kind of robot did you buy (exit -1)? ";
        std::cin >> number;
        if (number >=0 && number < realSize) {
            for (int i = number; i < realSize-1; ++i) {
                robots[i] = robots[i + 1];
            }
            realSize--;
        }
        if (number == - 2) {
            int value;
            std::cout << "Input № robot : ";
            std::cin >> value;
            if (robots.size() == realSize) {
                robots.resize(robots.size()+10);
            }
            robots[realSize] = value;
            realSize++;
        }
        std::cout << "Robots are on display: \n";
        for (int i = 0; i < realSize; ++i) {
            std::cout << "pos " << i << "  № " << robots[i] << "\n";
        }
    }
    std::cout << "exit";
}
/**
 *


 *
 *
 */