#include <iostream>
#include <cassert>

class TrainCar {
    int passengersMax = 0;
    int passengers = 0;
public:
    void load(int value) {
        passengers += value;
        if (passengers > passengersMax){
            passengers = passengersMax;
        }

    }
    int getPassenger() {
        return passengers;
    }
    TrainCar(int inPassengersMax): passengersMax(inPassengersMax) {
        assert(inPassengersMax >= 0);
        //passengersMax = inPassengerMax;
    }

};

class Train {
    int count = 0;

    TrainCar** cars = nullptr;

public:
    TrainCar* getCarAt(int index) {
        if (index < 0) return nullptr;
        if (index >= count) return nullptr;
        return cars[index];
    }

    int getCount() {
        return count;
    }

    Train(int inCount, int inPassengersMax): count(inCount) {
        assert(inCount >= 0);
        cars = new TrainCar*[inCount];
        for (int i = 0; i < count; ++i) {
            cars[i] = new TrainCar(inPassengersMax);
        }
    }
};


int main() {

    assert(0<1);

    Train* train = new Train(10, 30);
    for (int i = 0; i < train->getCount(); ++i) {
        int passengers = 0;
        std::cin >> passengers;
        train->getCarAt(i)->load(passengers);
    }
    for (int i = 0; i < train->getCount(); ++i) {
        int passengers = train->getCarAt(i)->getPassenger();
        std::cout << "car " << i << ": " << passengers << std::endl;
    }

    return 0;
}
