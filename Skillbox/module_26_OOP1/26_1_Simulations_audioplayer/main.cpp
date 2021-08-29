#include <iostream>
#include <string>
#include <ctime>
#include <vector>

class Track {
    std::string nameTrack;
    std::tm dateCreat{};
    int lengthTrackSec;
public:
    Track(std::string _nameTrack, std::tm _dateCreat, int _lengthTrackSec) {
        nameTrack = _nameTrack;
        dateCreat = _dateCreat;
        lengthTrackSec = _lengthTrackSec;
    }
    std::string getNameTrack() const {
        return nameTrack;
    }
    std::string getDateCreat() const {
        return std::asctime(&dateCreat);
    }
    int getLengthTrackSec() const {
        return lengthTrackSec;
    }
};

class Player {
    Track track[5];
    int idTrack = -1;
    bool isPlay = false;
public:
    int getIdTrack() {
        return idTrack;
    }
    void setIdTrack(int _idTrack) {
        idTrack = _idTrack;
    }
    bool getIsPlay() {
        return isPlay;
    }
    void setIsPlay(int _isPlay) {
        isPlay = _isPlay;
    }


    void play(const Track& oneTrack) {
        std::cout << "Play: " << std::endl;
        std::cout << "  Name track:" << oneTrack.getNameTrack() << std::endl;
        std::cout << "  Date Creat:" << oneTrack.getDateCreat() << std::endl;
        std::cout << "  Length track in sec:" << oneTrack.getLengthTrackSec() << std::endl;
    }
    void pause() {
        std::cout << "Pause: " << std::endl;

    }
    void next() {
        std::cout << "Next" << std::endl;

    }
    void stop() {
        std::cout << "Stop!" << std::endl;

    }

    Player(Track _track[]) {
        for (int i = 0; i < 5; ++i) {
            track[i] = _track[i];
        }


    }

};

int main() {
    std::cout << "Simulations audio player." << std::endl;
    std::tm tm{};
    int countTrack = 5;
    Track track[5] = {Track("name1",{tm.tm_year = 2000, tm.tm_mon = 1, tm.tm_mday = 15},50),
                      Track("name2",{tm.tm_year = 2001, tm.tm_mon = 2, tm.tm_mday = 16},60),
                      Track("name3",{tm.tm_year = 2002, tm.tm_mon = 3, tm.tm_mday = 17},70),
                      Track("name4",{tm.tm_year = 2003, tm.tm_mon = 4, tm.tm_mday = 18},80),
                      Track("name5",{tm.tm_year = 2004, tm.tm_mon = 5, tm.tm_mday = 19},90)};

    Player* player = new Player(track, nullptr);

    std::string command;
    do {
        std::cout << "Input command (play/pause/next/stop/exit):" << std::endl;
        std::cin >> command;
        if (command == "play") {
            std::cout << "Command Play" << std::endl;
            if (!player->getIsPlay()) {
                do {
                    std::cout << "Trek list: " << std::endl;
                    for (int i = 0; i < countTrack; ++i) {
                        std::cout << track[i].getNameTrack() << std::endl;
                    }

                    std::cout << "Input name track:" << std::endl;
                    std::string nameTrack;
                    std::cin >> nameTrack;
                    for (int i = 0; i < countTrack; ++i) {
                        if (nameTrack == track[i].getNameTrack()){
                            player->setIdTrack(i);
                            player->play(track[i]);
                            break;
                        }
                    }
                    if (player->getIdTrack() == -1) {
                        std::cout << "Track name not found. Try entering again.";
                    }
                } while(player->getIdTrack() == -1);

            } else {
                std::cout << "Track is already playing!" << std::endl;
            }
        } else if (command == "pause") {
            player->pause();
        } else if (command == "next") {
            player->next();
        } else if (command == "stop") {
            player->stop();
        } else {

        }

    } while(command != "exit");


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