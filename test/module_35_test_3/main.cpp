#include <iostream>
#include <filesystem>

/// !!!!!!! C++ 17
/// no work MinGW  -> module_35_test_3_qt


int main() {
    //std::filesystem::path p("E:\\GitHub");
    //std::filesystem::path p2("/home/user/file.txt");

    //p.extension();  // имя файла
/*

    p.begin(); // итераторы позволяют работать с путем, как с коллекцией
    p.end();

    std::filesystem::exists(p); // проверяет, существует ли путь bool
    std::filesystem::is_regular_file(p); // является ли файлом bool
    std::filesystem::space(p).capacity; // емкость диска
    std::filesystem::space(p).free; // свободное место на диске

    std::filesystem::path ourLink("/home/file2"); // создание ссылки
    std::filesystem::create_symlink(std::filesystem::absolute("/home/user/file.txt"),ourLink); // создание ярлыка(ссылки)
*/
    //    std::filesystem::create_directory(); // создание директории
    //    std::filesystem::create_hard_link(); // жесткие ссылки




    std::cout << "Hello, World!" << std::endl;


    return 0;
}
