#include <iostream>
char Row(char ch1, char ch2, char ch3) {
      if (ch1 != '.' && ch1 ==  ch2 &&  ch2 ==  ch3) {
            return ch1;
        }
   return '0';
}

char Column(std::string str) {
    if (str[0] != '.' && str[0] == str[1] && str[1] == str[2]) {
        return str[0];
    }
    return '0';
}

char Diagonal1(std::string str1, std::string str2, std::string str3) {
    if (str1[0] != '.' && str1[0] == str2[1] && str2[1] == str3[2]) {
        return str1[0];
    }
    return '0';
}

char Diagonal2(std::string str1, std::string str2, std::string str3) {
    if (str3[0] != '.' && str3[0] == str2[1] && str2[1] == str1[2]) {
        return str3[0];
    }
    return '0';

}

bool CheckInput(std::string str) {
    if (str.length() == 3) {
        for (int i = 0; i < 3; ++i) {
            if (str[i] == 'X' || str[i] == 'O' || str[i] == '.') {
                return true;
            }
        }
    }
    return false;
}

int main() {
    bool noCorrect = true;
    std::string line1, line2, line3;
    do {
        std::cout << "Enter three lines tic tac toe" << std::endl;
        std::cout << "Line 1:";
        std::cin >> line1;
        std::cout << "Line 2:";
        std::cin >> line2;
        std::cout << "Line 3:";
        std::cin >> line3;
        if (CheckInput(line1) && CheckInput(line2) && CheckInput(line3)) {
            noCorrect = false;
        } else {
            std::cout << "Incorrect!!! Try again!"<< std::endl;
        }
    } while (noCorrect);

    char won = 0;
    int count = 0;

    for (int i = 0; i < 3; ++i) {
        if (Row(line1[i], line2[i], line3[i]) != '0') {
            won = Row(line1[i], line2[i], line3[i]);
            count++;
        }
    }
    if (Column(line1) != '0') {
        won = Column(line1);
        count++;
    }
    if (Column(line2) != '0') {
        won = Column(line2);
        count++;
    }
    if (Column(line3) != '0') {
        won = Column(line3);
        count++;
    }
    if (Diagonal1(line1, line2, line3) != '0') {
        won = Diagonal1(line1, line2, line3);
        count++;
    }
    if (Diagonal2(line1, line2, line3) != '0') {
        won = Diagonal2(line1, line2, line3);
        count++;
    }

    if (count == 1 && won != '0') {
        std::cout << (won == 'X'? "Petya won" : "Vanya won") <<  std::endl;
    } else if (count > 2)  { // 3 winning lines are not real, 2 are real
        std::cout << "Incorrect!!!"<< std::endl;
    } else {
        std::cout << "Nobody!!!"<< std::endl;
    }
    return 0;
}

/*
 * 1. Крестики-нолики

Петя и Вася играли в крестики-нолики и не стерли после себя результаты своей игры. Теперь перед вами табличка 3х3,
 которая осталась после их поединка. Вы хотите понять, выиграл ли кто-то из них, или они не доиграли.

На вход программе дается три строки, кодирующие верхнюю, среднюю и нижнюю строчки игрового поля. Крестик обозначается
 символом X (английская заглавная буква X), нолик - символом O (заглавная английская буква O), пустая клетка - точкой.

Если ввод некорректен (то есть такая таблица не могла получиться в ходе настоящей игры), то надо написать в ответ
 слово Incorrect.

Если таблица корректна и выиграли крестики, то нужно вывести в ответ слова Petya won, если нолики - то Vanya won, а
 иначе (то есть они не доиграли или сыграли вничью) надо написать Nobody.


Примеры:

X..
OXO
OOO


X..
.X.
OO.



XXO
XOX
OOX



OX.
XOX
X.O



..X
OX.
X.O



0..
...
...



 * */