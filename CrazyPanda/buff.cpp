#include <string>
#include <vector>

#include "buff.h"

Buff::Buff(std::string _ident, std::vector<std::vector<std::string>> _filters, TypeBuffs _type, double _value) :
ident(_ident), filters(_filters), type(_type), value(_value) {}

Buff::~Buff() = default;

std::string Buff::getIdent() const {
    return ident;
}

// получение строки для поля type
std::string Buff::getTypeStr() const {
    if (type == DamageBuff) {
        return "DamageBuff";
    } else if (type == ProtectionBuff) {
        return "ProtectionBuff";
    } else if (type == SpeedBuff) {
        return "SpeedBuff";
    }
    return "NO TYPE";
}

std::vector<std::vector<std::string>> Buff::getFilters() const {
    return filters;
}

double Buff::getValue() const {
    return value;
}


Modify::Modify(std::vector<std::shared_ptr<Item>> &_inventory, std::vector<std::shared_ptr<Buff>> &_buffs) : inventory(_inventory), buffs(_buffs) {}

Modify::~Modify() = default;

// подбор предметов подходящего для модификации по фильтру и модификация его
void Modify::checkingModify() {
    std::map<int,int> filterTrueMap;
    for (auto &buff : buffs) {
        for (auto &oneFilter: buff->getFilters()) {
            if (oneFilter[0] == "level") {
                for (int i = 0; i < inventory.size(); ++i) {
                    if (compareLevel(oneFilter, i)) {
                        addFilter(filterTrueMap, i);
                    }
                }
            } else if (oneFilter[0] == "type") {
                for (int i = 0; i < inventory.size(); ++i) {
                    if (inventory[i]->getTypeStr() == oneFilter[1]) {
                        addFilter(filterTrueMap, i);
                    }
                }
            } else if (oneFilter[0] == "rarity") {
                for (int i = 0; i < inventory.size(); ++i) {
                    if (inventory[i]->getRarityStr() == oneFilter[1]) {
                        addFilter(filterTrueMap, i);
                    }
                }
            }
        }

        // модификация отобранных предметов инвентаря
        for(auto &oneFilterTrueMap : filterTrueMap) {
            if (oneFilterTrueMap.second == buff->getFilters().size()) {
                inventory[oneFilterTrueMap.first]->update(buff->getValue());
            }
        }
    }
}

// фиксируем фильтр к подходящему предмету
void Modify::addFilter(std::map<int, int> &filterTrueMap, int i) {
    if (filterTrueMap.count(i)) {
        filterTrueMap[i]++;
    } else {
        filterTrueMap[i] = 1;
    }
}

// сравнение фильтра для level
bool Modify::compareLevel(std::vector<std::string> &filter, int i) {
    if (filter[1] == "<")       {return inventory[i]->getLevel() < std::stoi(filter[2]);}
    else if (filter[1] == ">")  {return inventory[i]->getLevel() > std::stoi(filter[2]);}
    else if (filter[1] == "<=") {return inventory[i]->getLevel() <= std::stoi(filter[2]);}
    else if (filter[1] == ">=") {return inventory[i]->getLevel() >= std::stoi(filter[2]);}
    else if (filter[1] == "==") {return inventory[i]->getLevel() == std::stoi(filter[2]);}
    else if (filter[1] == "!=") {return inventory[i]->getLevel() != std::stoi(filter[2]);}
    assert(false && "filter error");
    return false;
}
