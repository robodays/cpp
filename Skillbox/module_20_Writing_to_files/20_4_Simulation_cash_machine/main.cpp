#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
//#include <algorithm>

// function select mode run program
bool SelectMode();
// add cash in cash machine
void AddCash(int bNInCM[], int sizeBNInCM, const int typeBN[], int sizeTypeBN);
// sort in descending order
void ReverseSort(int array[], int size);
// write in file
void WriteInFile(const int array[], int size, const std::string& path);
// read in file
bool ReadInFile(int array[], int size, const std::string& path, bool error = true);
// print status cash machine
void PrintStatus(const int banknotes[], int sizeBanknotes, int typeBanknotes[], int sizeType);
// withdraw cash
void DelCash(int banknotes[], int sizeBanknotes);

int main() {
    std::srand(time(nullptr));
    std::cout << "Cash machine." << std::endl;
    std::string path = "banknotes.bin";
    int typeBanknotes[6] = {100, 200, 500, 1000, 2000, 5000};
    int banknotesInCashMachine [1000] = {};
    int sizeBNInCM = sizeof(banknotesInCashMachine)/sizeof(int);
    int sizeTypeBN = sizeof(typeBanknotes)/sizeof(int);

    if (SelectMode()) { // +
        ReadInFile(banknotesInCashMachine, sizeBNInCM, path, false);
        AddCash(banknotesInCashMachine, sizeBNInCM, typeBanknotes, sizeTypeBN);
        ReverseSort(banknotesInCashMachine, sizeBNInCM);
        WriteInFile(banknotesInCashMachine, sizeBNInCM, path);
        PrintStatus(banknotesInCashMachine,sizeBNInCM,typeBanknotes,sizeTypeBN);
    } else { // -
        if (ReadInFile(banknotesInCashMachine, sizeBNInCM, path)) {
            PrintStatus(banknotesInCashMachine, sizeBNInCM, typeBanknotes, sizeTypeBN);
            DelCash(banknotesInCashMachine, sizeBNInCM);
            ReverseSort(banknotesInCashMachine, sizeBNInCM);
            WriteInFile(banknotesInCashMachine, sizeBNInCM, path);
            PrintStatus(banknotesInCashMachine, sizeBNInCM, typeBanknotes, sizeTypeBN);
        }
    }
    std::cout << "Cash Machine finished work!" << std::endl;
    return 0;
}

// withdraw cash
void DelCash(int banknotes[], int sizeBanknotes) {
    int cash;
    std::cout << "Enter the amount to withdraw cash (multiple of 100)" << std::endl;
    std::cin >> cash;
    while (cash < 100 || cash % 100 != 0) {
        std::cout << "The entered cash amount is not a multiple of 100. Enter the cash amount again." << std::endl;
        std::cin >> cash;
    }
    int newCash = cash;
    std::vector<int> vecIdZero;
    int count = 0;
    while (newCash != 0 && count != sizeBanknotes) {
        if (banknotes[count] <= newCash) {
            vecIdZero.push_back(count);
            newCash -= banknotes[count];
        }
        count++;
    }
    if (newCash == 0) {
        for (int value : vecIdZero) {
            banknotes[value] = 0;
        }
        std::cout << "<<< Cash withdrawal: " << cash << " RUB >>>" << std::endl;
    } else {
        std::cout << "<<< Not enough cash in the cash machine! >>>" << std::endl;
    }
}

// print status cash machine
void PrintStatus(const int banknotes[], int sizeBanknotes, int typeBanknotes[], int sizeType) {
    int allCountBanknotes = 0;
    int allSumCash = 0;
    std::cout << "-------------------- "<< std::endl;
    std::cout << "Status cash machine: "<< std::endl;
    for (int i = 0; i < sizeType; ++i) {
        int count = 0;
        for (int j = 0; j < sizeBanknotes; ++j) {
            if (typeBanknotes[i] == banknotes[j]) {
                count++;
                allCountBanknotes++;
                allSumCash += banknotes[j];
            }
        }
        std::cout << "\t" << typeBanknotes[i] << " = " << count << " banknotes"<< std::endl;
    }
    std::cout << "All banknotes in cash machine" << " = " << allCountBanknotes << " of " << sizeBanknotes << " banknotes" << std::endl;
    std::cout << "Sum total in cash machine" << " = " << allSumCash << " RUB"<< std::endl;
    std::cout << "----------------------------------------------"<< std::endl;
    // output array banknotesInCashMachine
    //for (int i = 0; i < sizeBNInCM; ++i) {
    //    std::cout << banknotesInCashMachine[i] << (i % 20 == 19 ? "\n" : " ");
    //}
}

// read in file
bool ReadInFile(int array[], int size, const std::string& path, bool error) {
    std::ifstream file(path, std::ios::binary);
    if (file.is_open()) {
        file.read((char *) array, size * sizeof(int));
        file.close();
        return true;
    } else {
        if (error) {
            std::cerr << "File not open!(Cash Machine is empty. When starting the program, press\"+\".)" << std::endl;
        }
        return false;
    }
}

// write in file
void WriteInFile(const int array[], int size, const std::string& path) {
    std::ofstream file(path, std::ios::binary);
    file.write((char*)array, size * sizeof(int));
    file.close();
}

// sort in descending order
void ReverseSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++){
        for (int j = i + 1; j < size; j++){
            if (array[i] < array[j]) {
                int tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
            }
        }
    }
}

// add cash in cash machine
void AddCash(int bNInCM[], int sizeBNInCM, const int typeBN[], int sizeTypeBN) {
    for (int i = 0; i < sizeBNInCM; ++i) {
        if (bNInCM[i] == 0) {
            int idBanknote;
            idBanknote = std::rand() % sizeTypeBN;
            bNInCM[i] = typeBN[idBanknote];
        }
    }
}

// function select mode run program
bool SelectMode() {
    std::string mode;
    do {
        std::cout << R"(Enter the operating mode("+" - cash replenishment, "-" - cash withdrawal): )" << std::endl;
        std::cin >> mode;
    } while (mode != "+" && mode != "-");
    return mode == "+";
}
/*
Задание 4. Реализация симуляции банкомата


Что нужно сделать

Требуется реализовать упрощённую симуляцию работы банкомата. В банкомате могут храниться только бумажные купюры
 номиналом от 100 до 5000 рублей. Максимально в банкомате может храниться только 1000 купюр. Все они записываются в
 отдельный файл. У банкомата, как у устройства, две основных операции — снятие денег пользователем и наполнение
 деньгами инкассаторами банка.

Наполнение банкомата происходит, если при старте программы в консоль вводится символ плюс “+”.  Количество купюр
 рассчитывается так, чтобы банкомат был заполнен полностью. Все купюры при этом выбираются случайным образом.

Если на старте программы в консоль вводится минус (“-”), то симулируется снятие пользователем денег. Пользователь
 указывает сумму с точностью до 100 рублей. Мы будем считать, что каждый клиент обладает неограниченным балансом в
 системе и теоретически может снять любую сумму. На практике, если данная сумма не может быть снята из-за отсутствия
 подходящих денег в машине, показывается сообщение, что эта операция невозможна.

После выполнения любой из операций программа завершает выполнение. Состояние банкомата должно храниться в отдельном
 бинарном файле, автономно.



Советы и рекомендации

Вы можете хранить массив купюр целиком, помечая отсутствующие позиции нулями.



Что оценивается

Корректность работы программы симуляции банкомата. Инкассация и снятие денег должны работать корректно.



Как отправить задание на проверку

Выполните задание в Google Docs, откройте доступ для комментирования. Ссылку пришлите через форму для сдачи домашнего
 задания.
 */