#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

struct Personage {
    std::string name;
    int id;
    int level;
    int armor;
    int damage;
    bool isHero = false;
    int positionXY[2] = {0,0};
};

void CreateHero(std::vector<std::vector<char>>& field, Personage& hero, int xMax, int yMax);
void GeneratePositionPersonage(std::vector<std::vector<char>>& field, int positionXY[], int xMax, int yMax);
void CreateEnemy(std::vector<std::vector<char>>& field, Personage& enemy, int xMax, int yMax);
void PrintGameField(const std::vector<std::vector<char>>& field, int xMax, int yMax);
void CreateGameField(std::vector<std::vector<char>>& field, int xMax, int yMax);
void PrintPersonages(const std::vector<Personage>& allPersonages);
bool MovingOnField(std::vector<Personage>& allPersonages, int positionXYTmp[]);
void GenerateMovingForEnemy(int positionXYTmp[]);
void CheckingMoving(std::vector<std::vector<char>>& field, std::vector<Personage>& allPersonages, int positionXYTmp[],
                    int walking, int xMax, int yMax);
void Attack(const Personage& attacker, Personage& defender);
bool CheckingEndgame(std::vector<std::vector<char>>& field, std::vector<Personage>& allPersonages);
void SaveGame(const std::vector<Personage>& allPersonages);
void LoadGame(std::vector<Personage>& allPersonages);
void CheckingInputData(int& value, int min, int max);

int main() {
    int sizeFieldX = 10;
    int sizeFieldY = 10;
    int quantityEnemies = 5;
    std::srand((unsigned) std::time(nullptr));
    std::cout << "Turn-based role-playing game." << std::endl;
    std::vector<std::vector<char>> field(40,std::vector<char> (40,'.'));
    CreateGameField(field, sizeFieldX, sizeFieldY);

    // Create Hero
    std::vector<Personage> allPersonages(quantityEnemies + 1);
    allPersonages[0].id = 0;
    CreateHero(field, allPersonages[0], sizeFieldX, sizeFieldY);

    // Create Enemies
    for (int i = 1; i < quantityEnemies+1; ++i) {
        allPersonages[i].id = i;
        CreateEnemy(field, allPersonages[i], sizeFieldX, sizeFieldY);
    }

    PrintGameField(field, sizeFieldX, sizeFieldY);
    PrintPersonages(allPersonages);

    int walking = 0;
    while(CheckingEndgame(field, allPersonages)) {
        int positionXYTmp[2] = {allPersonages[walking].positionXY[0],allPersonages[walking].positionXY[1]};

        if (allPersonages[walking].isHero) {
            if (MovingOnField(allPersonages, positionXYTmp)) {
                CheckingMoving(field, allPersonages, positionXYTmp, walking, sizeFieldX, sizeFieldY);
                walking++;
            } else {
                CreateGameField(field, sizeFieldX, sizeFieldY);
                for (auto & personage : allPersonages) {
                    field[personage.positionXY[0]][personage.positionXY[1]] = personage.isHero ? 'P' : 'E';
                }
                std::cout << "Made Load/Save game!" << std::endl;
            }
        } else {
            GenerateMovingForEnemy(positionXYTmp);
            CheckingMoving(field, allPersonages, positionXYTmp, walking, sizeFieldX, sizeFieldY);
            walking++;
        }

        if (walking >= allPersonages.size()) {
            walking = 0;
        }

        PrintGameField(field, sizeFieldX, sizeFieldY);
        PrintPersonages(allPersonages);
    }
    return 0;
}

void CreateHero(std::vector<std::vector<char>>& field, Personage& hero, const int xMax, const int yMax) {
    hero.isHero = true;
    std::cout << "Enter name hero: " << std::endl;
    std::cin >> hero.name;
    std::cout << "Enter level hero: " << std::endl;
    std::cin >> hero.level;
    CheckingInputData(hero.level, 0, 200);
    std::cout << "Enter armor hero: " << std::endl;
    std::cin >> hero.armor;
    CheckingInputData(hero.armor, 0, 100);
    std::cout << "Enter damage hero: " << std::endl;
    std::cin >> hero.damage;
    CheckingInputData(hero.damage, 1, 50);
    GeneratePositionPersonage(field, hero.positionXY, xMax, yMax);
    field[hero.positionXY[0]][hero.positionXY[1]] = 'P';
    std::cout << hero.name << " creat!" << std::endl;

}

void CreateEnemy(std::vector<std::vector<char>>& field, Personage& enemy, const int xMax, const int yMax) {
    enemy.isHero = false;
    enemy.name = "Enemy #" + std::to_string(enemy.id);
    enemy.level = std::rand() % 101 + 50;
    enemy.armor = std::rand() % 51;
    enemy.damage = std::rand() % 16 + 15;
    GeneratePositionPersonage(field, enemy.positionXY, xMax, yMax);
    field[enemy.positionXY[0]][enemy.positionXY[1]] = 'E';
    std::cout << enemy.name << " creat!" << std::endl;
}

void CreateGameField(std::vector<std::vector<char>>& field, const int xMax, const int yMax) {
    for (int i = 0; i < xMax; i++) {
        for (int j = 0; j < yMax; ++j) {
            field[i][j] = '.';
        }
    }
}

void PrintGameField(const std::vector<std::vector<char>>& field, const int xMax, const int yMax) {
    for (int i = 0; i < yMax+2; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
    for (int i = 0; i < xMax; i++) {
        std::cout << "|";
        for (int j = 0; j < yMax; ++j) {
            std::cout << field[i][j];
        }
        std::cout << "|" << std::endl;
    }
    for (int i = 0; i < yMax+2; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}

void GeneratePositionPersonage(std::vector<std::vector<char>>& field, int positionXY[], const int xMax, const int yMax) {
    while (true) {
        int generateXY = std::rand() % (xMax * yMax);
        int x = generateXY / xMax;
        int y = generateXY % yMax;
        if (field[x][y] == '.') {
            positionXY[0] = x;
            positionXY[1] = y;
            break;
        }
    }
}

void PrintPersonages(const std::vector<Personage>& allPersonages) {
    for (int i = 0; i < allPersonages.size(); ++i) {
        std::cout << "   name: " << allPersonages[i].name;
        std::cout << "   level: " << allPersonages[i].level;
        std::cout << "   armor: " << allPersonages[i].armor;
        std::cout << "   damage: " << allPersonages[i].damage;
        std::cout << "   x: " << allPersonages[i].positionXY[0];
        std::cout << "   y: " << allPersonages[i].positionXY[1] << std::endl;
    }
}

bool MovingOnField(std::vector<Personage>& allPersonages, int positionXYTmp[]) {
    std::cout << "Enter command for moving (left, right, top, bottom, save, load): " << std::endl;
    std::string command;
    std::cin >> command;
    while (command != "left" &&  command != "right" && command != "top" && command != "bottom"
            && command != "save" && command != "load") {
        std::cout << "Please enter again command for moving (left, right, top, bottom, save, load): " << std::endl;
        std::cin >> command;
    }
    if (command == "left") {
        positionXYTmp[1]--;
    } else if (command == "right") {
        positionXYTmp[1]++;
    } else if (command == "top") {
        positionXYTmp[0]--;
    } else if (command == "bottom"){
        positionXYTmp[0]++;
    } else if (command == "save"){
        SaveGame(allPersonages);
        return false;
    } else if (command == "load"){
        LoadGame(allPersonages);
        return false;
    }
    return true;
}

void GenerateMovingForEnemy(int positionXYTmp[]) {
    int generatingDirection = rand() % 4;
    if (generatingDirection == 0) {
        positionXYTmp[1]--;
    } else if (generatingDirection == 1) {
        positionXYTmp[1]++;
    } else if (generatingDirection == 2) {
        positionXYTmp[0]--;
    } else {
        positionXYTmp[0]++;
    }
}

void CheckingMoving(std::vector<std::vector<char>>& field, std::vector<Personage>& allPersonages, int positionXYTmp[],
                    const int walking, const int xMax, const int yMax) {
    if (positionXYTmp[0] < 0) {
        positionXYTmp[0]++;
    } else if (positionXYTmp[0] >= xMax) {
        positionXYTmp[0]--;
    } else if (positionXYTmp[1] < 0) {
        positionXYTmp[1]++;
    } else if (positionXYTmp[1] >= yMax) {
        positionXYTmp[1]--;
    } else if (field[positionXYTmp[0]][positionXYTmp[1]] != '.') {
        for (int i = 0; i < allPersonages.size(); ++i) {
            if (i != walking && allPersonages[i].isHero != allPersonages[walking].isHero
                    && allPersonages[i].positionXY[0] == positionXYTmp[0]
                    && allPersonages[i].positionXY[1] == positionXYTmp[1]) {
                Attack(allPersonages[walking], allPersonages[i]);
                break;
            }
        }
    } else {
        int oldX = allPersonages[walking].positionXY[0];
        int oldY = allPersonages[walking].positionXY[1];
        field[oldX][oldY] = '.';
        allPersonages[walking].positionXY[0] = positionXYTmp[0];
        allPersonages[walking].positionXY[1] =  positionXYTmp[1];
        field[positionXYTmp[0]][positionXYTmp[1]] = (allPersonages[walking].isHero) ? 'P' : 'E';
    }
}

void Attack(const Personage& attacker, Personage& defender) {
    defender.armor -= attacker.damage;
    if (defender.armor < 0 ) {
        defender.level += defender.armor;
        defender.armor = 0;
    }
    if (defender.level < 0) defender.level = 0;
}

bool CheckingEndgame(std::vector<std::vector<char>>& field, std::vector<Personage>& allPersonages) {
    if (allPersonages[0].level <= 0) {
        std::cout << "Winner Enemy!" << std::endl;
        return false;
    } else {
        for (int i = 1; i < allPersonages.size(); ++i) {
            if (allPersonages[i].level <= 0) {
                field[allPersonages[i].positionXY[0]][allPersonages[i].positionXY[1]] = '.';
                std::cout << allPersonages[i].name << " dead!" << std::endl;
                allPersonages.erase(allPersonages.begin()+i);
                break;
            }
        }
        if (allPersonages.size() == 1) {
            std::cout << "Winner Hero!" << std::endl;
            return false;
        }
    }
    return true;
}

void SaveGame(const std::vector<Personage>& allPersonages) {
    std::ofstream file("save.bin", std::ios::binary);
    int quantityAllPersonages = (int) allPersonages.size();
    file.write((char *)&quantityAllPersonages, sizeof(quantityAllPersonages));
    for (int i = 0; i < quantityAllPersonages; ++i) {
        int len = allPersonages[i].name.length();
        file.write((char *) &len, sizeof(len));
        file.write((char *) allPersonages[i].name.c_str(), len);
        file.write((char *) &allPersonages[i].id, sizeof(allPersonages[i].id));
        file.write((char *) &allPersonages[i].level, sizeof(allPersonages[i].level));
        file.write((char *) &allPersonages[i].armor, sizeof(allPersonages[i].armor));
        file.write((char *) &allPersonages[i].damage, sizeof(allPersonages[i].damage));
        file.write((char *) &allPersonages[i].isHero, sizeof(allPersonages[i].isHero));
        file.write((char *) &allPersonages[i].positionXY, sizeof(allPersonages[i].positionXY[0]) * 2);
    }
}

void LoadGame (std::vector<Personage>& allPersonages) {
    std::ifstream file("save.bin", std::ios::binary);
    int quantityAllPersonages;
    file.read((char *)&quantityAllPersonages, sizeof(quantityAllPersonages));
    allPersonages.clear();
    allPersonages.resize(quantityAllPersonages);
    for (int i = 0; i < quantityAllPersonages; ++i) {
        int len;
        file.read((char *) &len, sizeof(len));
        allPersonages[i].name.clear();
        allPersonages[i].name.resize(len);
        file.read((char *) allPersonages[i].name.c_str(), len);
        file.read((char *) &allPersonages[i].id, sizeof(allPersonages[i].id));
        file.read((char *) &allPersonages[i].level, sizeof(allPersonages[i].level));
        file.read((char *) &allPersonages[i].armor, sizeof(allPersonages[i].armor));
        file.read((char *) &allPersonages[i].damage, sizeof(allPersonages[i].damage));
        file.read((char *) &allPersonages[i].isHero, sizeof(allPersonages[i].isHero));
        file.read((char *) &allPersonages[i].positionXY, sizeof(allPersonages[i].positionXY[0]) * 2);
    }
}

void CheckingInputData(int& value, const int min, const int max) {
    while(value < min || value > max) {
        std::cout << "Enter again (" << min << " - " << max << "): " << std::endl;
        std::cin >> value;
    }
}


/*
Задание 4. Реализация ролевой пошаговой игры


Что нужно сделать

Реализуйте сильно упрощённую версию ролевой пошаговой игры:

Игра происходит на карте размером 40 на 40 клеток. По клеткам перемещаются враги и персонаж игрока.

После каждого хода игрока карта показывается вновь со всеми врагами на ней. Игрок помечается буквой P. Враги буквой E.
 Пустые места — точкой.

Каждый персонаж игры представлен в виде структуры с полями: имя, жизни, броня, урон.

Вначале игры создаются 5 случайных врагов в случайных клетках карты. Имена врагам задаются в формате “Enemy #N”,
 где N — это порядковый номер врага. Уровень жизней врагам задаётся случайно, от 50 до 150. Уровень брони варьируется
 от 0 до 50. Урон тоже выбирается случайно от 15 до 30 единиц.

Игрок конструирует своего персонажа самостоятельно. Задаёт все его параметры, включая имя.

Все персонажи появляются в случайных местах карты.

Игрок осуществляет ход с помощью команд: left, right, top, bottom. В зависимости от команды и выбирается направление
 перемещения персонажа: влево, вправо, вверх, вниз.

Враги перемещаются в случайном направлении.

Если персонаж (враг или игрок) перемещается в сторону, где уже находится какой-то персонаж, то он бьёт этого персонажа
 с помощью своего урона. Враги при этом никогда не бьют врагов, а просто пропускают ход и остаются на своём месте.

 За пределы карты (40 на 40 клеток) ходить нельзя никому. Если кто-то выбрал направление за гранью дозволенного, ход
 пропускается.

Формула для расчёта урона совпадает с той, что была в самом уроке. Жизни уменьшаются на оставшийся после брони урон.
 При этом сама броня тоже сокращается на приведённый урон.

Игра заканчивается тогда, когда либо умирают все враги, либо персонаж игрока. В первом случае на экран выводится
 сообщение о поражении, во втором — победа.

Если в начале хода игрок вводит команду save или load вместо направления перемещения, то игра либо делает сохранение
 своего состояния в файл, либо загружает это состояние из файла соответственно.



Советы и рекомендации

Для определения команды персонажа можно завести специальный флаг внутри структуры данных персонажа.

Для отображения координат персонажей можете использовать структуру вектора из другой задачи, но заменить типы координат.



Что оценивается

Корректность работы игры.



Как отправить задание на проверку

Пришлите ссылку на repl.it или файл .срр с решением через форму для сдачи домашнего задания.
 */
