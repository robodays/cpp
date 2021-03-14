#include <iostream>
#include <string>



int main()
{
    long long password = 1234567890;
    long long i;
    for ( i = 0; i < 999999999999999; ++i) {
        if (i == password) {
            std::cout << "password = " << i;
        }
    }

}


/*
//#include <fstream>
#include <iostream>
#include <string>

static int result = 0;
static int longStep;
static int countStep;
//static std::string str;

void funcCount(int step) {
    if (step == countStep) {
        result++;
        //std::cout << str << std::endl;
        return;
    }

    for (int i = 1; i <= longStep; ++i) {
        step += i;
        if (step <= countStep) {
            //str += std::to_string(i);
            funcCount(step);
            //str = str.substr(0,str.length()-1);
            step -= i;
        }
    }
}

int main()
{

    std::cout << "longStep: " << std::endl;
    std::cin >> longStep;
    std::cout << "countStep: " << std::endl;
    std::cin >> countStep;

    funcCount(0);

    std::cout << "result: " << result << std::endl;
 *
 * */