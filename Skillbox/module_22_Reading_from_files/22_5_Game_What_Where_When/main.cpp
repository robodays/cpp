#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <windows.h>

bool error = false; // global

int CheckingSector(int& activeSector, std::vector<bool>& sector); // function checks correctness sector
int CheckingResult (std::string& answerStr, std::string& inputAnswer, int& scoreAudience, int& scoreGamers); // function for checking and displaying the result
int LengthFile(std::ifstream& file); // function returns the length of the data in the file
bool OpenFile(std::ifstream& file, std::string& path); // function opens and checking file
bool ExitErrors(); // function exit on error
std::string Reading(std::ifstream& file, char buffer[], int& length); // function reading from the file
std::string GetData(std::ifstream& file, int& activeSector, std::string path); // Getting data from a file
void OutputNumberSector(std::vector<bool>& sector, int& activeSector, bool selSec = true); // function output active sector
void OutputScore(int& scoreAudience, int& scoreGamers); // function output score

int main() {
    std::vector<bool> sector(14, true);
    int activeSector = 1;
    int scoreAudience = 0;
    int scoreGamers = 0;
    int gameStatus = 0;

    std::string pathQuestion = "files_question\\sector_";
    std::string pathAnswer = "files_answer\\sector_";
    int offset;

    //for input rus
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Welcome to the game \" What? Where? When?\"" << std::endl;
    std::cout << "Pointer to the sector: " << activeSector << std::endl;
    while (gameStatus == 0) {
        std::ifstream questionFile;
        std::ifstream answerFile;

        std::cout << "Rotate point (offset forward): " << std::endl;
        std::cin >> offset;
        activeSector += offset;

        OutputNumberSector(sector,activeSector);
        OutputScore(scoreAudience,scoreGamers);
        std::string questionStr = GetData(questionFile,activeSector,pathQuestion);
        std::string answerStr = GetData(answerFile,activeSector,pathAnswer);
        if (ExitErrors()) return 0;
        sector[activeSector] = false;

        std::cout << "Question "  << activeSector << ": " << questionStr << std::endl;
        std::cout << "                                                          Answer: " << answerStr << std::endl;
        std::cout << "Enter answer: " << std::endl;
        std::string inputAnswer;
        std::cin >> inputAnswer;
        std::cout << "Correct answer: " << answerStr << std::endl;
//      std::cout << "Test comparison answer from files and answer input user. " << " Compare: (" << answerStr << " == "
//              << inputAnswer << ") -> "<< (answerStr == inputAnswer?"true":"false") << std::endl;// test
        gameStatus = CheckingResult (answerStr, inputAnswer, scoreAudience,scoreGamers);
        std::cout << std::endl;
        std::cout << "****************NEXT*ROUND****************" << std::endl;
    }
    OutputNumberSector(sector,activeSector, false);
    OutputScore(scoreAudience,scoreGamers);
    std::cout << "  <<<<<< Winner " << (gameStatus == 1?"Gamers":"Audience") << "! >>>>>>" << std::endl;
    return 0;
}

// function for checking and displaying the result
int CheckingResult (std::string& answerStr, std::string& inputAnswer, int& scoreAudience, int& scoreGamers) {
    std::cout << "---------------------------------" << std::endl;
    if (answerStr == inputAnswer) {
        scoreGamers++;
        std::cout << "  <<< Players get score! >>>" << std::endl;
    } else {
        scoreAudience++;
        std::cout << "  <<< Audience get score! >>>" << std::endl;
    }
    OutputScore(scoreAudience, scoreGamers);
    if (scoreGamers == 6) return 1;
    else if (scoreAudience == 6) return 2;
    else return 0;
}

// function output score
void OutputScore(int& scoreAudience, int& scoreGamers) {
    std::cout << "    Audience: " << scoreAudience << " | Gamers: " << scoreGamers << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

// function output active sector
void OutputNumberSector(std::vector<bool>& sector, int& activeSector, bool selSec) {
    activeSector = CheckingSector(activeSector, sector);
    if (selSec) std::cout << "Selected sector " << activeSector << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "  ";
    for (int i = 1; i < sector.size(); ++i) {
        if (i == activeSector) {
            std::cout << "(" << i << ") ";
        } else if(sector[i]) {
            std::cout <<  i << " ";
        } else {
            std::cout <<  '*' << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

// function exit on error
bool ExitErrors() {
    if (error) {
        std::cout << "Exit with an error." << std::endl;
        return true;
    }
    return false;
}

// Getting data from a file
std::string GetData(std::ifstream& file, int& activeSector, std::string path) {
    path += (std::to_string(activeSector)+".txt");
    if (!OpenFile(file,path)) {
        return "Warning! File opening error!";
    }
    int lengthBuffer = LengthFile(file);
    char buffer[lengthBuffer+1];
    buffer[lengthBuffer] = '\0'; // Иногда выводились непонятные символы после вывода вопроса. Это помогло!
    // memset(bufferQuestion, ' ',lengthBuffer);
    return Reading(file, buffer, lengthBuffer);
}

// function returns the length of the data in the file
int LengthFile(std::ifstream& file) {
    file.seekg (0, file.end);
    int length = file.tellg();
    file.seekg (0, file.beg);
    return length;
}

// function reading from the file
std::string Reading(std::ifstream& file, char buffer[], int& length) {
    file.read(buffer, length);
    file.close();
    return buffer;
}

// function opens and checking file
bool OpenFile(std::ifstream& file, std::string& path) {
    file.open(path, std::ios::binary);
    if (!file.is_open()) {
        error = true;
        std::cerr << "Warning! File opening error! (path:" + path + ")" << std::endl;
        return false;
    }
    return true;
}

// function checks correctness sector
int CheckingSector(int& activeSector, std::vector<bool>& sector) {
    if (activeSector > 13) activeSector %= 13;
    if (activeSector == 0) activeSector++;
    if (!sector[activeSector]) {
        activeSector++;
        CheckingSector(activeSector, sector);
    }
    return activeSector;
}



/*
Задание 5. Реализация игры «Что? Где? Когда?»
Что нужно сделать
Реализуйте простую версию интеллектуальной игры «Что? Где? Когда?».



Как происходит игра
В начале каждого хода игроки вращают волчок, то есть выбирают сектор на столе, который сейчас играет. Всего таких
 секторов 13. Сектор выбирается так: с клавиатуры вводится офсет (смещение) относительно текущего сектора на барабане.
 Исходя из этого офсета вычисляется новый активный сектор, который и будет играть в этом ходе. Если выпавший сектор
 уже играл, выбирает следующий неигравший за ним. В начале всей игры стрелка установлена на первом секторе.

Как только играет какой-то из секторов, с него берётся письмо с вопросом — то есть считывается из файла данного
 сектора. Вопрос показывается на экране.

После того как вопрос показан, от игрока ожидается ответ на него. Игрок вводит этот ответ с помощью стандартного
 ввода. То, что он ввёл, сравнивается с ответом, который хранится во втором файле, ассоциированном с активным
 сектором. Данный файл должен содержать лишь одно слово-ответ.

Если ответ знатока-игрока был правильным, ему начисляется один балл. Если неверен, то балл уходит телезрителям.

Игра продолжается до тех пор, пока или игрок, или зрители не наберут шесть баллов. После этого называется победитель и
 программа заканчивает работу.



Что оценивается
Игра должна корректно работать от первого хода до последнего. В результате обязательно должен выявляться победитель.



Как отправить задание на проверку
Выполните задание в Google Документах, откройте доступ для комментирования. Ссылку пришлите через форму для сдачи
 домашнего задания.

Не забудьте вводные данные самих писем с ответами!
 */