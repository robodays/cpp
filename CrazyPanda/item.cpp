#include <string>

#include "item.h"

Item::Item(std::string &_ident, Type _type, int _level, Rarity _rarity) :
ident(_ident), type(_type), level(_level), rarity(_rarity) {}

Item::~Item() = default;

std::string Item::getIdent() const {
    return ident;
}

Type Item::getType() const {
    return type;
}

// получение строки для поля type
std::string Item::getTypeStr() const {
    std::string typeStr;
    if (type == MELEE) {
        return "Melee";
    } else if (type == RANGE) {
        return "Range";
    } else if (type == ARMOUR) {
        return "Armour";
    }
    return "NO TYPE";
}

int Item::getLevel() const {
    return level;
}

// получение строки для поля rarity
std::string Item::getRarityStr() const {
    std::string typeStr;
    if (rarity == COMMON) {
        return "Common";
    } else if (rarity == RARE) {
        return "Rare";
    } else if (rarity == EPIC) {
        return "Epic";
    }
    return "NO RARITY";
}


Melee::Melee(std::string _ident, Type _type, int _level, Rarity _rarity, double _damage, double _speed) :
Item(_ident, _type, _level, _rarity) {
    damage = _damage;
    speed = _speed;
}

Melee::~Melee() = default;

// обновление характеристик предмета
void Melee::update(double value) {
    damage += value;
    speed += value;
}

double Melee::getDamage() const {
    return damage;
}

double Melee::getSpeed() const {
    return speed;
}


Range::Range(std::string _ident, Type _type, int _level, Rarity _rarity, double _damage, double _speed) :
Item(_ident, _type, _level, _rarity) {
    damage = _damage;
    speed = _speed;
}

Range::~Range() = default;

// обновление характеристик предмета
void Range::update(double value) {
    damage += value;
    speed += value;
}

double Range::getDamage() const {
    return damage;
}

double Range::getSpeed() const {
    return speed;
}


Armour::Armour(std::string _ident, Type _type, int _level, Rarity _rarity, double _protection) :
Item(_ident, _type, _level, _rarity) {
    protection = _protection;
}

Armour::~Armour() = default;

// обновление характеристик предмета
void Armour::update(double value) {
    protection += value;
}

double Armour::getProtection() const{
    return protection;
}


