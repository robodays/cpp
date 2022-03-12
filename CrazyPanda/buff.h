#pragma once

#include <map>
#include <memory>
#include "item.h"

enum TypeBuffs {
    DamageBuff,
    ProtectionBuff,
    SpeedBuff
};

class Buff {
    std::string ident;
    std::vector<std::vector<std::string>> filters;
    TypeBuffs type;
    double value;

public:
    Buff(std::string _ident, std::vector<std::vector<std::string>> _filters, TypeBuffs _type, double _value);
    ~Buff();

    std::string getIdent() const;
    std::string getTypeStr() const;
    std::vector<std::vector<std::string>> getFilters() const;
    double getValue() const;

};


class Modify {
    std::vector<std::shared_ptr<Item>> inventory;
    std::vector<std::shared_ptr<Buff>> buffs;

public:
    Modify(std::vector<std::shared_ptr<Item>> &_inventory, std::vector<std::shared_ptr<Buff>> &_buffs);
    ~Modify();

    void checkingModify();
    void addFilter(std::map<int, int> &filterTrueMap, int i);
    bool compareLevel(std::vector<std::string> &filter, int i);
};

