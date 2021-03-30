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
    int countRoom;
    float heightFloat;
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

int main() {
    std::cout << "Data model for village" << std::endl;
    int countLendPlots;
    std::cout << "Enter the number of land plots in the village:" << std::endl;
    std::cin >> countLendPlots;
    std::vector<LandPlots> landPlot;
    for (int i = 0; i < countLendPlots; i++) {
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
            std::cout << "Information on the house " << landPlot[i].house[j].numHouse << ": " << std::endl;
            landPlot[i].house[j].isStove = isStove();
            std::cout << "Enter the number of floors: " << std::endl;
            std::cin >> landPlot[i].house[j].countFloor;
            landPlot[i].house[j].countFloor = checkEnterNum(landPlot[i].house[j].countFloor, 1, 3);
            for (int k = 0; k < landPlot[i].house[j].countFloor; ++k) {
                landPlot[i].house[j].floor.push_back(Floors());
                landPlot[i].house[j].floor[k].numFloor = k + 1;
                std::cout << "Information on the floor " << landPlot[i].house[j].floor[k].numFloor << ": " << std::endl;


                //TODO
               // int numFloor;
               // int countRoom;
               // float heightFloat;
               // Rooms room[4] = {UNKNOWN,UNKNOWN,UNKNOWN,UNKNOWN};
               // float squareRoom[4] = {0};

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



    //Вначале работы программы пользователь заполняет данные о посёлке: вводит общее количество участков и далее начинает
    //детализировать каждый из участков.

    //Для каждого участка сначала заполняется общее количество построек, а затем детализируется каждая постройка, этажи,
    //комнаты на этажах.

    //По итогам введённых данных вы можете рассчитать некий суммарный параметр, например, процент земли, занимаемой
    //постройками, к общей площади всего посёлка. Главное в этой задаче не сама операция подсчёта, а структуры данных.
    return 0;
}

int checkEnterNum(int num, int min, int max) {
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