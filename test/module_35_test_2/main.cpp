#include <iostream>
#include <array>
#include <algorithm>
#include <tuple>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <memory>


int main() {

    /// array

    std::array<int,5> arr = {6,3,5,2,4};
    std::sort(arr.begin(),arr.end());

    std::for_each(arr.begin(),arr.end(),[](int i ){std::cout << i << " ";});
    std::cout << std::endl;

    /// кортеж

    std::tuple<int,int,int> tuple = {};
    auto averageAndExtremums = [](std::vector<int> temperatures) {
        if(temperatures.empty()) {
            return std::tuple<int,int,int>{};
        }
        int max, min, avg;
        max = min = avg = temperatures.front();
        int sum = 0;
        for ( int i : temperatures) {
            sum += i;
            if (min > i ) min = i;
            if (max < i) max = i;
        }
        avg = sum / temperatures.size();

        return std::tuple<int,int,int>(avg,min,max);
    };
    std::vector<int> v1= {5,2,6,8,7,3};
    tuple = averageAndExtremums(v1);

    std::cout << "average " << std::get<0>(tuple) << "\tmin " << std::get<1>(tuple) << "\tmax "
                << std::get<2>(tuple) << std::endl;

    auto min = std::min_element(v1.begin(),v1.end());
    auto max = std::max_element(v1.begin(),v1.end());

    std::cout << "average " << std::get<0>(tuple) << "\tmin " << *min << "\tmax "
        << *max << std::endl;


    /// Ассоциативные контейнеры set multiset map multimap
    std::set<std::string> set;
    std::map<std::string,int> map;
    std::unordered_map<std::string,int> u_map;

    std::unordered_set<std::string> strings = {"first", "second", "third"};
    if(strings.count("second")) {
        std::cout <<  "already exist" << std::endl;
    }

    /// умные указатели

    //Unit *u1 = new Unit();
    //delete u1;

    //auto u1 = std::make_unique<Unit>(); // уникальный указатель для использования в пределах своего класса
    //auto u2 = std::make_shared<Unit>(); // расшаренный указатель


    return 0;
}
