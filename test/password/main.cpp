#include <iostream>
#include <string>
#include <ctime>

int find(char& search, char arr[], int begin, int& size);
void recurs(std::string& str, char arr[], int i, int& size);

int iter = 0;

int main() {
    char arr[62] = { '0','1','2','3','4','5','6','7','8','9'
            ,'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' //36
            ,'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};//62
    std::string password = "Andrey";
    std::string newStr;
    std::string str = "0";
    int lengthStr;
    bool flag = true;
    while (flag) {
        lengthStr = str.length();
        for (int j = 0; j < sizeof(arr); ++j) {
            str[iter] = arr[j];
            //std::cout << str[iter] << " ";
            //std::cout << str << std::endl;
            if (str == password) {
                std::cout << "+++" << str << "(" << str.length() << ")" << " Time " << clock() / 1000 << std::endl;
                std::cout << "!!! PASSWORD = " << str << std::endl;
                flag = false;
                break;
            }
        }
        int size = sizeof(arr);
        str[iter] = arr[0];
        if (0 == lengthStr - 1) {
            str += "0";
            iter++;
        }
        recurs(str, arr, iter, size);
        if (iter == 10) {
            flag = false;
        }
    }
    system("pause");
}

void recurs(std::string& str, char arr[], int i, int& size) {
    if (i > 0) {
        int indexMinus = find(str[i - 1], arr, 0, size);
        if (indexMinus == size - 1) {
            str[i] = '0';
            if (i > 1) {
                recurs(str, arr, i - 1, size);
            }
            else {
                str[0] = '0';
                str += "0";
                iter++;
                std::cout << str << "(" << str.length() << ")" << " Time " << clock() / 1000 << std::endl;
            }
        }
        else {
            str[i - 1] = arr[indexMinus + 1];
            str[i] = '0';
        }
    }
}

int find(char& search, char arr[], int begin, int& size) {
    for (int i = begin; i < size; ++i) {
        if (arr[i] == search) {
            return i;
        }
    }
    return -1;
}