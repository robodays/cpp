#include <iostream>

class Monster {
public:
    std::string name = "unknown";
    double attackDamage = 10;
    double health = 100;

    void attack() {
        std::cout << name << " is attacking: " << attackDamage << std::endl;
    }
};

class FlyingMonster: public Monster {
public:
    double flightSpeed = 50;
    void fly() {
        std::cout << name << "is flying: " << flightSpeed << std::endl;
    }
};

class ShootingMonster: public Monster {
    double attackRange = 30;
    void shoot() {
        attack();
        std::cout << name << " shooting: " << attackRange << std::endl;
    }
};

int main() {
    FlyingMonster* flyingMonster = new FlyingMonster();
    flyingMonster->fly();
    flyingMonster->attack();
    delete flyingMonster;
    return 0;
}





















