/// A
/*
#include <iostream>
#include <vector>

int cntMax(const std::vector<int> &v) {
    if (v.empty() || v[0] == 0) {
        return 0;
    } else {
        int max = v[0];
        int cnt = 1;
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] > max) {
                max = v[i];
                cnt = 1;
            } else if (v[i] == max) {
                cnt++;
            } else if (v[i] == 0) {
                return cnt;
            }
        }
    }
    return 0;
}

int main() {
    std::vector<int> vector;
    int x;
    do {
        std::cin >> x;
        vector.push_back(x);
    } while (x != 0);

    std::cout << cntMax(vector);
}
*/

/// B

/*#include <iostream>
#include <unordered_map>
#include <vector>

int maxDistance(const std::vector<int> &v);

int main() {
    std::vector<int> houses;
    int x;
    for (int i = 0; i < 10; i++) {
        std::cin >> x;
        houses.push_back(x);
    }
    std::cout << maxDistance(houses);
}
int maxDistance(const std::vector<int> &v) {
    std::unordered_map<int,int> m;
    int cnt = 0;
    bool isShop = false;
    for(int i = 0; i < v.size(); i++) {
        if (v[i] == 2) {
            cnt = 0;
            isShop = true;
        }
        if (isShop) {
            if (v[i] == 1) {
                m[i] = cnt;
            }
            cnt++;
        }
    }

    cnt = 0;
    isShop = false;
    for (int i = v.size(); i >= 0; i--) {
        if (v[i] == 2) {
            cnt = 0;
            isShop = true;
        }
        if (isShop) {
            if (v[i] == 1 && (m.count (i) == 0 || m[i] > cnt)) {
                m[i] = cnt;
            }
            cnt++;
        }
    }

    int max = 0;
    for (auto it = m.begin(); it != m.end(); it++) {
        if (max < it->second) {
            max = it->second;
        }
    }
    return max;
}*/
//1 0 0 0 0 0 0 0 0 2

/// C
/*

#include <iostream>
#include <string>

int foo(const std::string &s);

int main() {
    std::string str;
    std::cin >> str;

    std::cout << foo(str);

}

int foo(const std::string &s) {
    int cnt = 0;
    int j = s.length() - 1;
    for (int i = 0; i < s.length() / 2; i++) {
        if (s[i] != s[j]) {
            cnt++;
        }
        j--;
    }
    return cnt;
}
*/

/// D
/*
#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> foo(int l, const std::vector<int> &v);
int main() {
    int l, k;
    std::vector<int> n;
    std::cin >> l >> k;
    for (int i = 0; i < k; i++) {
        int x;
        std::cin >> x;
        n.push_back(x);
    }

    for (int i : foo(l, n)) {
        std::cout << i << " ";
    }
}

std::vector<int> foo(int l, const std::vector<int> &v) {
    std::vector<int> result;
    int middle = (int) l / 2;
    if (l % 2 != 0) {
        auto it = std::find(v.begin(), v.end(), middle);

        if (it != v.end()) {
            result.push_back(*it);
            return result;
        }
    }

    int minMiddle1 = 0;
    int minMiddle2 = l;

    for (int i = 0; i < v.size(); i++) {
        if (v[i] < middle && v[i] >= minMiddle1) {
            minMiddle1 = v[i];
        } else if (v[i] < minMiddle2) {
            minMiddle2 = v[i];
        }
    }

    result.push_back(minMiddle1);
    result.push_back(minMiddle2);

    return result;
}*/

/// E

/*
#include <iostream>
#include <set>

int foo(std::multiset<int> &ms);

int main() {
    int cntDirectories;
    std::multiset<int> cntDiplomas;
    std::cin >> cntDirectories;
    int x;
    for (int i = 0; i < cntDirectories; i++) {
        std::cin >> x;
        cntDiplomas.insert(x);
    }
    std::cout << foo(cntDiplomas);
}

int foo(std::multiset<int> &ms) {
    int cnt = 0;
    ms.erase(std::prev(ms.end()));
    for (auto it = ms.begin(); it != ms.end(); it++) {
        cnt += *it;
    }
    return cnt;
}*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int foo(std::vector<int> &v);

int main() {
    int cntDirectories;
    std::vector<int> cntDiplomas;
    std::cin >> cntDirectories;
    int x;
    for (int i = 0; i < cntDirectories; i++) {
        std::cin >> x;
        cntDiplomas.push_back(x);
    }
    std::cout << foo(cntDiplomas);
}

int foo(std::vector<int> &v) {
    return std::accumulate(v.begin(), v.end(), 0) - *std::max_element(v.begin(), v.end());
}