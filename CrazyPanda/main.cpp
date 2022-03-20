#include <iostream>
#include <vector>
#include <memory>

#include "item.h"
#include "buff.h"

int main() {

    std::vector<std::shared_ptr<Item>> inventory;

    // Добавление инвентаря
    inventory.push_back(std::make_shared<Melee>("axe_01", MELEE, 3, COMMON, 12.0, 0.9));
    inventory.push_back(std::make_shared<Range>("revolver_01", RANGE, 5, COMMON, 42.0, 2.0));
    inventory.push_back(std::make_shared<Range>("revolver_02", RANGE, 3, RARE, 50.0, 2.1));
    inventory.push_back(std::make_shared<Range>("machinegun_01", RANGE, 5, EPIC, 83.1, 10.0));
    inventory.push_back(std::make_shared<Armour>("jacket_01", ARMOUR, 2, COMMON, 2.0));
    inventory.push_back(std::make_shared<Armour>("bulletprof_vest_01", ARMOUR, 5, RARE, 30.0));

    // Вывод инвентаря
    std::cout << "Inventory: " << std::endl;
    for (auto &item : inventory) {
        std::cout << "ident: " << item->getIdent() << ", type: " << item->getTypeStr() << ", level: "
                    << item->getLevel() << ", rarity: " << item->getRarityStr();
        if (item->getType() == MELEE || item->getType() == RANGE) {
            std::cout << ", damage: " <<  item->getDamage() << ", speed: " << item->getSpeed() << std::endl;
        } else {
            std::cout << ", protection: " <<  item->getProtection() << std::endl;
        }
    }

    std::vector<std::shared_ptr<Buff>> buffs;

    // добавление модификаторов
    std::vector<std::vector<std::string>> b2 = {{ "level", ">=", "4"}, { "type", "Range"}};
    buffs.push_back(std::make_shared<Buff>("eagle_eye", std::vector<std::vector<std::string>>{{ "level", ">=", "4"}, { "type", "Range"}}, DamageBuff, 10));
    buffs.push_back(std::make_shared<Buff>("donatium_steel", std::vector<std::vector<std::string>>{{"rarity", "Rare"}}, ProtectionBuff, 15));
    buffs.push_back(std::make_shared<Buff>("rage_drink", std::vector<std::vector<std::string>>{{"type", "Range"}, {"type", "Melee"}}, SpeedBuff, 0.4));

    // вывод модификаторов
    std::cout << std::endl;
    std::cout << "Buffs: " << std::endl;

    for (auto &buff : buffs) {
        std::cout << "ident: " << buff->getIdent() << ", filters: {";

        std::string filtersStr;
        for (auto &filter : buff->getFilters()) {
            filtersStr += "{";
            for (auto &parameters : filter) {
                filtersStr += parameters + ", ";
            }
            filtersStr = filtersStr.substr(0,(filtersStr.size() - 2));
            filtersStr += "}, ";
        }
        filtersStr = filtersStr.substr(0,(filtersStr.size() - 2));

        std::cout << filtersStr << "}, type: " << buff->getTypeStr() << ", value: " << buff->getValue() << std::endl;
    }

    // Модификация инвентаря
    Modify modify(inventory, buffs);
    modify.checkingModify();

    // Вывод модифицированного инвентаря
    std::cout << std::endl;
    std::cout << "Modified inventory:" << std::endl;
    for (auto &item : inventory) {
        std::cout << "ident: " << item->getIdent() << ", type: " << item->getTypeStr() << ", level: "
                  << item->getLevel() << ", rarity: " << item->getRarityStr();
        if (item->getType() == MELEE || item->getType() == RANGE) {
            std::cout << ", damage: " <<  item->getDamage() << ", speed: " << item->getSpeed() << std::endl;
        } else {
            std::cout << ", protection: " <<  item->getProtection() << std::endl;
        }
    }

    return 0;
}

