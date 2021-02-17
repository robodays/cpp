#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file;
    do {
        std::cout << "Enter the file name or the full path to the file (words1.txt, words2.txt, words3.txt): " << std::endl;
        std::string fileName;
        std::cin >> fileName;

        file.open(fileName,std::ios::binary);
        std::cout << "File is open: " << (file.is_open() ? "YES" : "NO. Try again!") << std::endl;
    } while (!file.is_open());
    file.seekg (0, file.end);
    int length = file.tellg();
    file.seekg (0, file.beg);

    std::cout << "Length file: " << length << std::endl;
    std::cout << "Text: " << std::endl;
    while (!file.eof()) {
        char buffer[100] = ""; //zeroing array
        file.read(buffer, 100);
        std::cout << buffer;
    }
    file.close();
    return 0;
}
//gcount мне не понадобился


/*
Задание 2. Разработка просмотрщика текстовых файлов


Что нужно сделать
Разработайте простейший просмотрщик текстовых файлов. В начале программы пользователь вводит путь к текстовому файлу,
 который требуется открыть и просмотреть. Внутренности файла необходимо вывести в стандартный вывод. Программа должна
 работать для любых текстовых файлов в формате TXT, но вы можете создать и свой отдельный файл для теста. Главное,
 чтобы файл был англоязычным, дабы избежать проблем с кодировками.



Советы и рекомендации
Для проверки того, был ли на самом деле открыт файл, используйте метод is_open. Он вернёт true, если файл был
 благополучно открыт, и false, если что-то пошло не так, к примеру, если путь к файлу невалидный.
Файл надо считывать постепенно, отдельными фрагментами, ведь он может быть весьма большим. Для этого лучше всего
 пользоваться методом gcount, так как он ещё вернёт количество байт, которые были считаны по факту методом read. Сами
 эти фрагменты могут храниться в специальном буфере, как и в примере из лекций, но его размер и второй аргумент к
 функции read надо рассчитать так, чтобы выводились все символы, без обрезки последней буквы.
Файл можно открыть в бинарном формате.


Что оценивается
Показ файла на экране должен соответствовать тому, что мы наблюдаем в стандартном блокноте.



Как отправить задание на проверку
Выполните задание в Google Документах, откройте доступ для комментирования. Ссылку пришлите через форму для сдачи
 домашнего задания.


 */