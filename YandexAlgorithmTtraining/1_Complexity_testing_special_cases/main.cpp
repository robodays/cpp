/// A
/*
#include <iostream>

int main() {
    int r, i, c, v;

    std::cin >> r >> i >> c;
*/
/*
    std::cin >> r;
    std::cin >> i;
    std::cin >> c;
*//*


    if (i == 0) {
        if (r != 0) {
            v = 3;
        }
        else {
            v = c;
        }
    }
    else if (i == 1) {
        v = c;
    }
    else if (i == 4) {
        if (r != 0) {
            v = 3;
        }
        else {
            v = 4;
        }
    }
    else if (i == 6) {
        v = 0;
    }
    else if (i == 7) {
        v = 1;
    }
    else {
        v = i;
    }
    std::cout << v;
}
*/

/// B
/*
#include <iostream>
int main() {
    int n, i, j, min1, min2;
    std::cin >> n >> i >> j;
    if (i > j) {
        min1 = i - j - 1;
        min2 = n - i + j - 1;
    } else {
        min1 = j - i - 1;
        min2 = n - j + i - 1;
    }
    if (min1 < min2) {
        std::cout << min1;
    } else {
        std::cout << min2;
    }

}
*/
/// B2
/*#include <iostream>
int main() {
    int n, i, j, min1, min2;
    std::cin >> n >> i >> j;
    min1 = std::abs(j - i) - 1;
    min2 = n - 2 - min1;
    std::cout << ((min1 < min2) ? min1 : min2);
}*/

/// C
/*
#include <iostream>

int main() {
    int x, y, z;
    std::cin >> x >> y >> z;
    if (x > 12 || y > 12 || x == y) {
        std::cout << 1;
    } else {
        std::cout << 0;
    }
}
*/

/// D
/*
#include <iostream>
int mod(int a) {
    return (a < 0)? -a : a;
}

int main() {
    int n, cPoint = 0, minWay = 0, sumWay;
    std::cin >> n;
    if (n != 0) {
        int cHouses[n];
        for (int i = 0; i < n; i++) {
            std::cin >> cHouses[i];
        }
        bool isOneIt = true;
        for (int i = cHouses[0]; i <= cHouses[n - 1]; i++) {
            sumWay = 0;
            for (int j = 0; j < sizeof(cHouses) / sizeof(cHouses[0]); j++) {
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
        }
    }
    std::cout << cPoint;

}
*/

/// D2
/*#include <iostream>
int mod(int a) {
    return (a < 0)? -a : a;
}

int main() {
    int n, cPoint = 0, minWay = 0, sumWay;
    std::cin >> n;

    if (n != 0) {
        int cHouses[n];
        int sumAllPoint = 0, average;

        for (int i = 0; i < n; i++) {
            std::cin >> cHouses[i];
            sumAllPoint += cHouses[i];
        }
        average = sumAllPoint / n;
        cPoint = average;
        std::cout << cPoint;
        bool firstCycle = false;

        for (int j = 0; j < sizeof(cHouses) / sizeof(int); j++) {
            minWay += mod((cPoint - cHouses[j]));
        }

        for (int i = average + 1; i <= cHouses[n - 1]; i++) {
            sumWay = 0;
            for (int j = 0; j < sizeof(cHouses) / sizeof(int); j++) {
                sumWay += mod((i - cHouses[j]));
            }
            if (sumWay == minWay) {
                std::cout << "+ " << cPoint;
                continue;
            } else if (sumWay < minWay) {
                minWay = sumWay;
                firstCycle = true;
                cPoint = i;
                std::cout << " !+! "<< cPoint;
            } else {
                break;
            }
        }
        if (!firstCycle) {
            for (int i = average - 1; i >= cHouses[0]; i--) {
                sumWay = 0;
                for (int j = 0; j < sizeof(cHouses) / sizeof(int); j++) {
                    sumWay += mod((i - cHouses[j]));
                }

                if (sumWay == minWay) {
                    std::cout << "- "<< cPoint;
                    continue;
                } else if (sumWay < minWay) {
                    minWay = sumWay;
                    cPoint = i;
                    std::cout << " !-! "<< cPoint;

                } else {
                    break;
                }
            }
        } 
    }
    std::cout << cPoint;

}*/
/// D3
/*
#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int cHouses[n];

    for (int i = 0; i < n; i++) {
        std::cin >> cHouses[i];
    }

    std::cout << cHouses[n/2];
}
*/


//10
//-5 -3 -2 0 3 5 8 9 15 21
//-500 -3 -2 0 3 5 8 9 15 210
//-50 -3 -2 0 3 5 8 9 15 210

/// E
/*

#include <iostream>
#include <cmath>


struct Coordinate{
    int x,y;
};

int main() {

    Coordinate coord;
    int result = -1;
    int d;

    std::cin >> d;

    std::cin >> x >> y;

    int x = 0;
    int y = d;
    if (x >= 0 && y >= 0) {
        for (int i = 0; i <= d; ++i) {
            if (x <= x && y <= y) {
                result = 0;
            }
            x++;
            y--;
        }
    }
    if (result == -1) {
        double a, b, c;
        a = std::abs(std::sqrt((pow(x, 2) + pow(y, 2))));
        b = std::abs(std::sqrt(pow(x - d, 2) + pow(y, 2)));
        c = std::abs(std::sqrt(pow(x, 2) + pow(y - d, 2)));

        if (a <= b && a <= c) {
            result = 1;
        } else if (b <= a && b <= c) {
            result = 2;
        } else {
            result = 3;
        }
    }
    std::cout << result;
}
*/

/// E2
#include <iostream>

struct Coordinate{
    int x,y;
};

int main() {

    int result;
    int d, x, y;

    std::cin >> d;

    std::cin >> x >> y;
    
    if (x >= 0 && y >= 0 && (x + y <= d)) {
        result = 0;
    } else {
        int a, b, c;
        a = x * x + y * y;
        b = (x - d) * (x - d) + y * y;
        c = x * x + (y - d) * (y - d);

        if (a <= b && a <= c) {
            result = 1;
        } else if (b <= a && b <= c) {
            result = 2;
        } else {
            result = 3;
        }
    }
    std::cout << result;
}

