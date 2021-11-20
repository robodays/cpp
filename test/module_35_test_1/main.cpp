#include <iostream>
#include <vector>
#include <algorithm>

/// для #3
class Part {
    int i = 1;
};
class Tool {
    std::vector<Part> parts;
public:
    Tool(std::initializer_list<Part> _parts) {
        parts = _parts;
    }
};

class Unit {
public:
    Unit(){};
};
class UnitTeam {
    std::vector<Unit> mUnits;
public:
    UnitTeam(std::initializer_list<Unit> units) {
        mUnits = units;
    }
};

/// для 4
class GeoPoint{
    float lon, lat;
public:
    GeoPoint(float  longitude, float latitude)
        :lon(longitude), lat(latitude) {}
};
class Route {
    std::vector<GeoPoint> points;
public:
    Route(std::initializer_list<GeoPoint> _points)
        :points(_points) {}
};

/// для 5
bool compare(int &i1, int &i2) {
    return i1 < i2;
}

int main() {

    /// 1. for range
    int arr[5] = {1,2,3,4,5};
    for(int i : arr){
        std::cout << i << " ";
    }
    std::cout << std::endl;
    /// 2. auto

    auto i = 5;
    auto str = "string";

    std::vector<int> v1 = {2,3,4,5,6};
    //for(std::vector<int>::const_iterator it = v1.begin(); it != v1.end(); it++) {
    for(auto it = v1.begin(); it != v1.end(); it++) {
        std::cout << (*it) << " ";
    }
    std::cout << std::endl;
    //auto result = sqrt(81);
    auto n21 = 2;
    auto n22 = 3.1;
    auto n23 = n21 + n22;
    std::cout << "n23 " << n23 << std::endl;
    std::cout << std::endl;

    /// 3. однотипная инициализация

    int arr2[] = {1,2,3};
    std::vector<int> arr3 = {1,2,3};
    Tool tool = {Part(),Part()};
    UnitTeam unitTeam = {Unit(),Unit()};

    /// 4.

    GeoPoint point1{50,50};
    auto route = Route{point1, {30, 40}, {30.5, 41}, {31, 41}};

    /// 5 лямбды
    std::vector<int> v2 = {3,8,7,4,5,9,2,1,6};
    //std::sort(v2.begin(),v2.end(), compare);
    std::sort(v2.begin(),v2.end(), [](int &i1, int &i2) {return i1 < i2;});  // [v2] - чтение, [&v2] - запись

    for(int i : v2){
        std::cout << i << " ";
    }
    std::cout << std::endl;

    /// 6

    //auto teleport = [](Unit &unit) {auto man = static_cast<Humman*>(&unit); if (man) { man->setGeoPos(random(),random());}}
    //std::vector<Unit> warriors;
    //std::for_each(warriors.begin, warriors.end(), teleport);


    ///

    return 0;
}
