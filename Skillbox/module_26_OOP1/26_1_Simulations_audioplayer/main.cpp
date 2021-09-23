#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>

class Track {
    std::string nameTrack;
    std::tm dateCreat{};
    int lengthTrackSec;

public:
    Track(std::string _nameTrack = " ", std::tm _dateCreat = {}, int _lengthTrackSec = 0) {
        nameTrack = _nameTrack;
        dateCreat = _dateCreat;
        lengthTrackSec = _lengthTrackSec;
    }

    std::string getNameTrack() const {
        return nameTrack;
    }

    std::tm getDateCreat() const {
        return dateCreat;
    }

    int getLengthTrackSec() const {
        return lengthTrackSec;
    }
};

class Player {
    std::vector<Track>*  track = nullptr;
    int idTrack = -1;
    bool isPlay = false;

public:
    Player(std::vector<Track>* _track) {
        track = _track;
    }

    void play() {
        std::cout << "Command Play" << std::endl;
        if (!isPlay) {
            do {
                std::cout << "Trek list: " << std::endl;

                for (int i = 0; i < track->size(); ++i) {
                    //std::cout << track[i].getNameTrack << std::endl; // так не заработало! ???
                    std::cout << track->at(i).getNameTrack() << std::endl;
                }

                /*for (const Track& track1 :  *track) {
                    std::cout << track1.getNameTrack() << " - " << track1.<< std::endl;
                }*/

                std::cout << "Input name track:" << std::endl;
                std::string nameTrackInput;
                std::cin >> nameTrackInput;

                for (int i = 0; i < track->size(); ++i) {
                    if (nameTrackInput == track->at(i).getNameTrack()){
                        playTrackId(i);
                        break;
                    }
                }

                if (idTrack == -1) {
                    std::cout << "Track name not found. Try entering again.";
                }
            } while(idTrack == -1);
        }
    }

    void pause() {
        std::cout << "Command Pause" << std::endl;
        if (idTrack >= 0) {
            if (isPlay) {
                isPlay = false;
                std::cout << "  Recording is paused!" << std::endl;
            } else {
                isPlay = true;
                std::cout << "  Recording is played!" << std::endl;
            }
        }
    }

    void next() {
        std::cout << "Command Next" << std::endl;
        srand(time(0));
        int nextId;
        do {
            nextId = rand() % track->size();
        } while (nextId == idTrack);
        playTrackId(nextId);
    }

    void stop() {
        std::cout << "Command Stop" << std::endl;
        if (idTrack >= 0) {
            idTrack = -1;
            isPlay = false;
            std::cout << "  Recording is stop!" << std::endl;
        }
    }

    void playTrackId(int id) {
            idTrack = id;
            isPlay = true;
            std::cout << "Play: " << std::endl;
            std::cout << "  Name track:" << track->at(id).getNameTrack() << std::endl;
            std::tm dateCreat = track->at(id).getDateCreat();
            std::cout << "  Date Creat:" << dateCreat.tm_year << "/" << dateCreat.tm_mon << "/"
            << dateCreat.tm_mday << std::endl;
            std::cout << "  Length track in sec:" << track->at(id).getLengthTrackSec() << std::endl;
    }
};



int main() {
    std::cout << "Simulations audio player." << std::endl;
    std::tm tm{};

    std::vector<Track>* track = new std::vector<Track>;
    track->push_back(Track("name1",{0, 0, 0, 15, 1, 2000},50));
    track->push_back(Track("name2",{0, 0, 0, 16, 2, 2001},60));
    track->push_back(Track("name3",{0, 0, 0, 17, 3, 2002},70));
    track->push_back(Track("name4",{0, 0, 0, 18, 4, 2003},80));
    track->push_back(Track("name5",{0, 0, 0, 19, 5, 2004},90));

    //Player* player = new Player(track, nullptr);
    Player* player = new Player(track);
    //player.readTrack(track);
    std::string command;
    do {
            std::cout << "Input command (play/pause/next/stop/exit):" << std::endl;
            std::cin >> command;
            if (command == "play") {
                player->play();
            } else if (command == "pause") {
                player->pause();
            } else if (command == "next") {
                player->next();
            } else if (command == "stop") {
                player->stop();
            }

        } while(command != "exit");

    delete track;
    track = nullptr;
    delete player;
    player = nullptr;
    return 0;
}

/*
Задание 1. Реализация имитации аудиоплеера


Что нужно сделать
С помощью классов реализуйте программу имитации работы аудиоплеера. В плеере находится несколько аудиозаписей,
 доступных для воспроизведения. Для них вы должны создать отдельный класс Track. Полями этого класса должны быть:
 название, дата создания (здесь вы можете использовать тип std::tm) и продолжительность записи в секундах.

Сам плеер тоже реализуйте с помощью класса. Внутри он должен содержать список доступных записей и нужные для логики
 работы плеера поля.

Пользователь взаимодействует с программой с помощью команд:

Команда play запрашивает у пользователя название записи для воспроизведения и начинает её воспроизведение.
 Воспроизведение симулируется с помощью вывода в консоль всей информации о записи. Если произведение какой-то записи
 уже начато, ничего не происходит.
Команда pause. Ставит запись на паузу, о чём выводит соответствующее сообщение в консоль. Если запись уже на паузе или
 не воспроизводится вовсе, ничего не происходит.
Команда next переходит к следующей записи для воспроизведения. Запись при этом выбирается случайно, как будто плеер
 работает в режиме shuffle.
Команда stop прекращает воспроизведение текущей записи, если таковая имеется. Об этом выводится сообщение в консоль.
 Два раза остановить воспроизведение невозможно, так что команда должна срабатывать только в первом случае.
Команда exit — выход из программы.


Советы и рекомендации
Забудьте про отдельные глобальные функции и используйте возможности классов и методов по максимуму.



Что оценивается
Корректность работы программы.
 */