#include <iostream>
#include <vector>
enum Rooms {
    UNKNOWN,
    BEAD_ROOM,
    KITCHEN,
    BATHROOM,
    CHILD_ROOM,
    GUEST_ROOM
};

struct Floors {
    int numFloor;
    float heightFloor;
    int countRooms;
    Rooms room[4] = {UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN};
    float squareRoom[4] = {0};
};

struct Houses {
    int numHouse;
    int countFloor;
    std::vector<Floors> floor;
    bool isStove;
};

struct LandPlots {
    int id;
    int countHouse = 1;
    std::vector<Houses> house;
    int garage = 0;
    int bathhouse = 0;
    bool isStoveBathhouse;
    int barn = 0;
};

bool isStove();
bool isObject(const std::string& question);
int square(const std::string& nameObject);
int checkEnterNum(int num, int min = 0, int max = 1000000);
float checkEnterNum(float num, float min = 0, float max = 1000000); // reloading the function
void printAllLendPlots(std::vector<LandPlots>& vector);

int main() {
    std::cout << "Data model for village" << std::endl;
    int countLendPlots;
    std::cout << "Enter the number of land plots in the village:" << std::endl;
    std::cin >> countLendPlots;
    std::vector<LandPlots> landPlot;
    for (int i = 0; i < countLendPlots; i++) {
        std::cout << "Information about land plot: " << std::endl;
        landPlot.push_back(LandPlots());
        std::cout << "id:" << std::endl;
        std::cin >> landPlot[i].id;
        landPlot[i].id = checkEnterNum(landPlot[i].id);
        std::cout << "Enter the number of houses on the land plot: " << std::endl;
        std::cin >> landPlot[i].countHouse;
        landPlot[i].countHouse = checkEnterNum(landPlot[i].countHouse, 1, 10);
        for (int j = 0; j < landPlot[i].countHouse; ++j) {
            landPlot[i].house.push_back(Houses());
            landPlot[i].house[j].numHouse = j + 1;
            std::cout << "Information about house No. " << landPlot[i].house[j].numHouse << ": " << std::endl;
            landPlot[i].house[j].isStove = isStove();
            std::cout << "Enter the number of floors(1-3): " << std::endl;
            std::cin >> landPlot[i].house[j].countFloor;
            landPlot[i].house[j].countFloor = checkEnterNum(landPlot[i].house[j].countFloor, 1, 3);
            for (int k = 0; k < landPlot[i].house[j].countFloor; ++k) {
                landPlot[i].house[j].floor.push_back(Floors());
                landPlot[i].house[j].floor[k].numFloor = k + 1;
                std::cout << "Information about floor No. " << landPlot[i].house[j].floor[k].numFloor << ": " << std::endl;
                std::cout << "Enter height the floor(mm): " << std::endl;
                std::cin >> landPlot[i].house[j].floor[k].heightFloor;
                landPlot[i].house[j].floor[k].heightFloor = checkEnterNum(landPlot[i].house[j].floor[k].heightFloor, 0., 5000.);
                std::cout << "Enter the number of rooms(2-4): " << std::endl;
                std::cin >> landPlot[i].house[j].floor[k].countRooms;
                landPlot[i].house[j].floor[k].countRooms = checkEnterNum(landPlot[i].house[j].floor[k].countRooms, 2, 4);
                for (int l = 0; l < landPlot[i].house[j].floor[k].countRooms; ++l) {
                    std::cout << "Choose name room No " << l+1 << " (BEAD_ROOM=>1, KITCHEN=>2, BATHROOM=>3, CHILD_ROOM=>4, GUEST_ROOM=>5): " << std::endl;
                    int room;
                    std::cin >> room;
                    room = checkEnterNum(room, 1, 5);
                    landPlot[i].house[j].floor[k].room[l] = static_cast<Rooms>(room);
                    landPlot[i].house[j].floor[k].squareRoom[l] = square("room");
                }
            }
        }
        if (isObject("Is there a garage?(yes/no)")) {
            landPlot[i].garage = square("garage");
        }
        if (isObject("Is there a bathhouse?(yes/no)")) {
            landPlot[i].bathhouse = square("bathhouse");
            landPlot[i].isStoveBathhouse = isStove();
        }
        if (isObject("Is there a barn?(yes/no)")) {
            landPlot[i].barn = square("barn");
        }
    }

    printAllLendPlots(landPlot);

    return 0;
}

void printAllLendPlots(std::vector<LandPlots>& landPlot) {
    int squareSum = 0;
    std::cout << "=========================" << std::endl;
    std::cout << "Output of all land plots." << std::endl;
    std::cout << "=========================" << std::endl;
    std::cout << "Number of land plots in the village: " << landPlot.size() << std::endl;
    for (int i = 0; i < landPlot.size(); i++) {
        std::cout << "Id land plot: " << landPlot[i].id << std::endl;
        std::cout << "The number of houses on the land plot: " << landPlot[i].countHouse << std::endl;///----------------------
        for (int j = 0; j < landPlot[i].house.size(); ++j) {
            std::cout << "Information about house No. " << landPlot[i].house[j].numHouse << ": " << std::endl;
            std::cout << "  The presence of a stove: " << (landPlot[i].house[j].isStove ? "yes" : "no") << std::endl;
            std::cout << "  The number of floors: " << landPlot[i].house[j].countFloor << std::endl;///----------------------------
            for (int k = 0; k < landPlot[i].house[j].floor.size(); ++k) {
                std::cout << "  Information about floor No. " << landPlot[i].house[j].floor[k].numFloor << ": " << std::endl;
                std::cout << "    Height the floor(mm): " << landPlot[i].house[j].floor[k].heightFloor << std::endl;
                std::cout << "    The number of rooms: " << landPlot[i].house[j].floor[k].countRooms << std::endl;
                for (int l = 0; l < landPlot[i].house[j].floor[k].countRooms; ++l) {
                    std::cout << "    Room No " << l+1 << ": ";
                    if (BEAD_ROOM == landPlot[i].house[j].floor[k].room[l])  std::cout << "BEAD_ROOM" << std::endl;
                    else if (KITCHEN == landPlot[i].house[j].floor[k].room[l])  std::cout << "KITCHEN" << std::endl;
                    else if (BATHROOM == landPlot[i].house[j].floor[k].room[l])  std::cout << "BATHROOM" << std::endl;
                    else if (CHILD_ROOM == landPlot[i].house[j].floor[k].room[l])  std::cout << "CHILD_ROOM" << std::endl;
                    else if (GUEST_ROOM == landPlot[i].house[j].floor[k].room[l])  std::cout << "GUEST_ROOM" << std::endl;
                    std::cout << "    Square room: " << landPlot[i].house[j].floor[k].squareRoom[l] << std::endl;
                    squareSum += landPlot[i].house[j].floor[k].squareRoom[l];
                }
            }
        }
        if (landPlot[i].garage != 0) {
            std::cout << "Square garage: " << landPlot[i].garage << std::endl;
            squareSum += landPlot[i].garage;
        }
        if (landPlot[i].bathhouse != 0) {
            std::cout << "Square bathhouse: " << landPlot[i].bathhouse << std::endl;
            std::cout << "  The presence of a stove in bathhouse: " << (landPlot[i].isStoveBathhouse ? "yes" : "no") << std::endl;
            squareSum += landPlot[i].bathhouse;
        }
        if (landPlot[i].barn != 0) {
            std::cout << "Square barn: " << landPlot[i].barn << std::endl;
            squareSum += landPlot[i].barn;
        }
        std::cout << std::endl;
    }
    std::cout << "Square all buildings: " << squareSum << std::endl;
}

int checkEnterNum(int num, int min, int max) {
    while (num < min || num > max) {
        std::cout << "Enter again(> " << min << " and < " << max << "): " << std::endl;
        std::cin >> num;
    }
    return num;
}

float checkEnterNum(float num, float min, float max) {
    while (num < min || num > max) {
        std::cout << "Enter again(> " << min << " and < " << max << "): " << std::endl;
        std::cin >> num;
    }
    return num;
}

bool isObject(const std::string& question) {
    std::string answer;
    do {
        std::cout << question << std::endl;
        std::cin >> answer;
    } while (answer != "yes" && answer != "no");
    return answer == "yes";
}

int square(const std::string& nameObject) {
    int square;
    do {
        std::cout << "Enter square " << nameObject << ": " << std::endl;
        std::cin >> square;
        if (std::cin.fail()) { // if the previous extraction failed,
            std::cin.clear(); // then we return cin to the 'normal' mode of operation
            std::cin.ignore(32767,'\n'); // and delete the values of the previous input from the input buffer
        }
    } while (square <= 0);
    return square;
}

bool isStove() {
    std::string stove;
    do {
        std::cout << "Is there a stove?(yes/no)" << std::endl;
        std::cin >> stove;
    } while (stove != "yes" && stove != "no");
    return stove == "yes";
}
/*
Задание 2. Модель данных для посёлка


Что нужно сделать

С помощью структур данных создайте подробную модель посёлка.

В посёлке есть множество участков. Каждый из них имеет свой уникальный номер. На каждом из участков должен быть
 расположен как минимум один жилой дом, но возможны и другие сооружения, такие как гараж, сарай (бытовка) и баня. Для
 каждого здания предусмотрена информация о площади, которую он занимает на участке.

В жилом доме может быть 1–3 этажа. На каждом из этажей может быть 2–4 комнаты. Каждая комната при этом может быть
 разных типов: спальня, кухня, ванная, детская, гостиная. Для каждой комнаты предусмотрены данные о её площади. Для
 каждого этажа также есть данные о высоте потолка. В жилом доме и бане может быть печь с трубой, информация об этом
 также должна быть предусмотрена в данных.

Для всех упомянутых сущностей надо объявить соответствующие структуры данных.

Вначале работы программы пользователь заполняет данные о посёлке: вводит общее количество участков и далее начинает
 детализировать каждый из участков.

Для каждого участка сначала заполняется общее количество построек, а затем детализируется каждая постройка, этажи,
 комнаты на этажах.

По итогам введённых данных вы можете рассчитать некий суммарный параметр, например, процент земли, занимаемой
 постройками, к общей площади всего посёлка. Главное в этой задаче не сама операция подсчёта, а структуры данных.



Советы и рекомендации

Используйте все имеющиеся у вас знания о типах данных в C++. Можно  использовать уже изученные перечисления и массивы,
 создавать структуры внутри структур и так далее.



Что оценивается

Полнота структур, описывающих данные посёлка.



Как отправить задание на проверку

Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.


 */