#include <iostream>
#include <cassert>

class TrainCar {
    int passengersMax = 0;
    int passengers = 0;

    class Train* train = nullptr;
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
    TrainCar(class Train* inTrain, int passengersMax):
             train(inTrain) {
        assert(inTrain != nullptr);
        assert(passengersMax >= 0);
        this->passengersMax = passengersMax;
    }

    int getNumber();

};

class Train {
    int count = 0;

    TrainCar** cars = nullptr;

public:
    TrainCar* getCarAt(int index) {
        if (this == nullptr) return nullptr;
        if (index < 0) return nullptr;
        if (index >= this->count) return nullptr;
        return this->cars[index];
    }

    int getCount() {
        return count;
    }

    Train(int inCount, int inPassengersMax): count(inCount) {
        assert(inCount >= 0);
        cars = new TrainCar*[inCount];
        for (int i = 0; i < count; ++i) {
            cars[i] = new TrainCar(this, inPassengersMax);
        }
    }
};

int TrainCar::getNumber() {
    for (int i = 0; i < train->getCount(); ++i) {
        TrainCar* car = train->getCarAt(i);
        if (car == this) return i;
    }
    assert(false);
    return 0;
}

int main() {

    assert(0<1);

    Train* train = nullptr;
    train->getCarAt(2);
    train = new Train(10, 30);
//    Train* train = new Train(10, 30);
    for (int i = 0; i < train->getCount(); ++i) {
        int passengers = 0;
        std::cin >> passengers;
        train->getCarAt(i)->load(passengers);
    }
    for (int i = 0; i < train->getCount(); ++i) {
        int passengers = train->getCarAt(i)->getPassenger();
        std::cout << "car " << i << ": " << passengers << std::endl;
    }
    TrainCar* car2 = train->getCarAt(2);
    std::cout  << car2->getNumber() << ": " << car2->getPassenger() << std::endl;

    return 0;
}
