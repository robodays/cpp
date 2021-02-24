#include <iostream>
#include <string>
#include <fstream>

bool FileOpen(std::ifstream&);
bool IsPNG(const std::string&);

int main() {
    std::string fileName;
    std::ifstream file;
    do {
        std::cout << "Enter the file path or file name: " << std::endl;
        std::cout << "(for test: paint.png, paint_new.png, paint_new.jpg, dir\\paint1.png, notpng.png)" << std::endl;
        std::cin >> fileName;
        if (!IsPNG(fileName)) continue;
        file.open(fileName, std::ios::binary);
    } while (!FileOpen(file));
    char buffer[4];
    file.read(buffer, 4);

    // output
    if (buffer[0] == -119 && buffer[1] == 'P' && buffer[2] == 'N' && buffer[3] == 'G') {
        std::cout << "File totally is PNG!" << std::endl;
    } else {
        std::cout << "File not is PNG!" << std::endl;
    }
    return 0;
}

// checking file open
bool FileOpen(std::ifstream& file) {
    if (file.is_open()) {
        std::cout << "File open!" << std::endl;
        return true;
    } else {
        std::cout << "File no open!" << std::endl;
        return false;
    }
}

// checking file extension
bool IsPNG (const std::string& str) {
    if (str.substr(str.size()-4, 4) == ".png") {
        std::cout << "File name extension is PNG!!" << std::endl;
        return true;
    } else {
        std::cout << "File name extension is not PNG!" << std::endl;
        return false;
    }
}

/*
������� 4. ���������� ��������� PNG-�����
��� ����� �������
������������ ���������, ������� �������� �� ����, � ����������� ����, ���� � �����. �� ������ ��������� ������
 ����������, �������� �� ������ ���� PNG-������������. ������ ��������� �� ������ ������ �������� �� ���������� �����,
 �� � ���������� ����������� ������ ��� �������������, � �������� ������.

������������ ��������� ��������� ����� ���������� �� ������������ 8-��������� ���������. ��� ����� ������������ ������
 ������ �����. ������ ���� ������ ����� �������� ?119 (����� �� ������ �����), � ��������� � ��� ������
 ������� �P�, �N�, �G�, ������������� ���� �� ������. �������� ��������, ��� ��� ��� � ������� ��������.

�� ����������� �������� ���� � ������������� ��������� �������� ������������ � ���������� �������� � ����������� �����.



������ � ������������
����� ���������� ���������� �����, ����������� ������� substr, ������� �������� ����� � ����� ��������� � ���������� �.



��� �����������
��� ������������ ����� ������, �������� �������������, ��������� �������� ���������� ��������� � �������� �� ���
 PNG-������� ��� ���.


��� ��������� ������� �� ��������
��������� ������� � Google ����������, �������� ������ ��� ���������������. ������ �������� ����� ����� ��� �����
 ��������� �������.
 */