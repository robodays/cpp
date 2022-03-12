#pragma once

#include <cassert>
#include <string>


enum Type {
    MELEE,
    RANGE,
    ARMOUR
};
enum Rarity {
    COMMON,
    RARE,
    EPIC
};

class Item {
    std::string ident;
    Type type;
    int level;
    Rarity rarity;
public:
    Item(std::string &_ident, Type _type, int _level, Rarity _rarity);
    ~Item();

    std::string getIdent() const;
    Type getType() const;
    std::string getTypeStr() const;
    int getLevel() const;
    std::string getRarityStr() const;

    virtual void update(double value) = 0;
    virtual double getDamage() const {return 0;}
    virtual double getSpeed() const {return 0;}
    virtual double getProtection() const {return 0;}
};

class Melee : public Item {
    double damage;
    double speed;
public:
    Melee(std::string _ident, Type _type, int _level, Rarity _rarity, double _damage, double _speed);
    ~Melee();

    void update(double value) override;
    double getDamage() const override;
    double getSpeed() const override;
};

class Range : public Item {
    double damage;
    double speed;
public:
    Range(std::string _ident, Type _type, int _level, Rarity _rarity, double _damage, double _speed);
    ~Range();

    void update(double value) override;
    double getDamage() const override;
    double getSpeed() const override;
};

class Armour : public Item {
    double protection;
public:
    Armour(std::string _ident, Type _type, int _level, Rarity _rarity, double _protection);
    ~Armour();

    void update(double value) override;
    double getProtection() const override;
};

