#include <iostream>
#include <string>


//static std::string str;

void funcCount(int step, int &longStep, int &countStep, int &result) {
    if (step == countStep) {
        result++;
        //std::cout << str << std::endl;
        return;
    }

    for (int i = 1; i <= longStep; ++i) {
        step += i;
        if (step <= countStep) {
            //str += std::to_string(i);
            funcCount(step, longStep, countStep, result);
            //str = str.substr(0,str.length()-1);
            step -= i;
        }
    }
}

int main()
{
    int longStep;
    int countStep;

    std::cout << "longStep: " << std::endl;
    std::cin >> longStep;
    std::cout << "countStep: " << std::endl;
    std::cin >> countStep;
    int result = 0;
    funcCount(0, longStep, countStep, result);

    std::cout << "result: " << result << std::endl;
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