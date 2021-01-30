#include <iostream>
#include <vector>
int main() {
    std::vector<int> vec {1, 1, 2, 1, 5, 2, 4, 5, 1, 2, 2, 2};
    int max = vec[0];
    int countMax = 1;
    for (int i = 0; i < vec.size(); ++i) {
        int count = 1;
        if (vec[i] != -1) {
            for (int j = i + 1; j < vec.size(); ++j) {
                if (vec[i] == vec[j]) {
                    count++;
                    vec[j] = -1;
                }
            }
            if (count > countMax) {
                countMax = count;
                max = vec[i];
            }
        }
    }
    std::cout << "countMax = " << countMax << std::endl;
    std::cout << "max = " << max << std::endl;
   /* for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] != -1) {
            for (int j = i + 1; j < vec.size(); j++) {
                if (vec[j] == vec[i]) {
                    vec[j] = -1;
                }
            }
        }
    }
    int count = 0;
    for (int i : vec) {
        if (i != -1) {
            count++;
        }
    }
    std::cout << "count = " << count << std::endl;*/
    return 0;
}
