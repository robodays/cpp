///
#include <iostream>
int mod(int a) {
    return (a < 0)? -a : a;
}

int main() {
    int n, cPoint, minWay = 0, sumWay = 0;
    std::cin >> n;
    int cHouses[n];
    for (int i = 0; i < n; i++) {
        std::cin >> cHouses[i];
    }
    bool isOneIt = true;
    for (int i = cHouses[0]; i <= cHouses[n-1]; i++) {
        for (int j = 0; j < sizeof(cHouses)/sizeof(cHouses[0]); j++){
            sumWay += mod((i - cHouses[j]));
        }
        if (isOneIt) {
            minWay = sumWay;
            cPoint = i;
            isOneIt = false;
        } else {
            if (sumWay < minWay) {
                minWay = sumWay;
                cPoint = i;
            }
        }
        sumWay = 0;
    }
    std::cout << cPoint;

}
