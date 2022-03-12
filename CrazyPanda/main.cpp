/*
Напишите консольную программу, которая будет считать модифицированные характеристики предметов.
Есть инвентарь, в котором хранится несколько предметов разного свойства, которые имеют общие характеристики (
название, тип, уровень (целое число), редкость ( Common, Rare, Epic ) )
и числовые <double> характеристики, специфичные для каждого типа ( например, урон у оружия или уровень защиты у
брони ).
Также есть модификаторы (Buffs), которые имеют фильтры по характеристикам предметов. Например "уровень больше N"
или "редкость равна Rare". Фильтров может быть несколько.
Программа должна заполнять инвентарь, создавать модификаторы и выводить на экран значение модифицированных
характеристик для всех предметов.

Входные данные:
Инвентарь:
{ident: "axe_01", type: Melee, level: 3, rarity: Common, damage: 12.0, speed: 0.9 },
{ident: "revolver_01", type: Range, level: 5, rarity: Common, damage: 42.0, speed: 2.0 },
{ident: "revolver_02", type: Range, level: 3, rarity: Rare, damage: 50.0, speed: 2.1 },
{ident: "machinegun_01", type: Range, level: 5, rarity: Epic, damage: 83.1, speed: 10.0 },
{ident: "jacket_01", type: Armour, level: 2, rarity: Common, protection: 2.0 },
{ident: "bulletprof_vest_01", type: Armour, level: 5, rarity: Rare, protection: 30.0 }
Модификаторы:
{ ident: "eagle_eye", filters: [{"level", ">=", 4}, { "type", Range}], type: DamageBuff, value: 10 },
{ ident: "donatium_steel", filters: [{"rarity", Rare}], type: ProtectionBuff, value: 15 },
{ ident: "rage_drink", filters: [{"type", Range}, {"type", Melee}], type: SpeedBuff, value: 0.4 }

P.S. Рекомендуется использовать C++17 или новее
*/
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

