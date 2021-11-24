#include <iostream>
#include <filesystem>

int main()
{

    std::filesystem::path p("E:\\GitHub\\cpp");
    //auto dirName = p.extension();  // // расширение файла
    //std::cout << "dir name: " << dirName << std::endl;
    for(auto i = p.begin(); i != p.end(); i++){ // < no work, != work
        std::cout << *i << " ";
    }
    for(auto c : p){
        std::cout << c << " ";
    }
    std::cout << std::endl;
    auto exists_p = std::filesystem::exists(p); // проверяет, существует ли путь bool
    auto is_regular_file_p = std::filesystem::is_regular_file(p); // является ли файлом bool
    std::cout << "exists_p: " << exists_p << std::endl;
    std::cout << "is_regular_file_p: " << is_regular_file_p << std::endl;

    auto capacity_p = std::filesystem::space(p).capacity; // емкость диска
    auto free_p = std::filesystem::space(p).free; // свободное место на диске
    std::cout << "capacity_p: " << capacity_p << std::endl;
    std::cout << "free_p: " << free_p << std::endl;


    std::cout << "===========================" << std::endl;

    std::filesystem::path f("E:\\GitHub\\cpp\\guide\\24_Time.txt");
    auto fileName = f.extension();  // расширение файла
    std::cout << "file name: " << fileName << std::endl;
    for(auto i = f.begin(); i != f.end(); i++){ // < no work, != work
        std::cout << *i << " ";
    }
    for(auto c : f){
        std::cout << c << " ";
    }
    std::cout << std::endl;

    auto exists = std::filesystem::exists(f); // проверяет, существует ли путь bool
    auto is_regular_file = std::filesystem::is_regular_file(f); // является ли файлом bool
    std::cout << "exists: " << exists << std::endl;
    std::cout << "is_regular_file: " << is_regular_file << std::endl;


    auto capacity = std::filesystem::space(f).capacity; // емкость диска
    auto free = std::filesystem::space(f).free; // свободное место на диске
    std::cout << "capacity_f: " << capacity << std::endl;
    std::cout << "free_f: " << free << std::endl;


//  std::filesystem::path ourLink("E:\\GitHub\\cpp\\guide\\24_Time1"); // создание ссылки
//  std::filesystem::create_symlink(std::filesystem::absolute("E:\\GitHub\\cpp\\guide\\24_Time.txt"),ourLink); // создание ярлыка(ссылки)

//  std::filesystem::create_directory("E:\\G"); // создание директории
    //    std::filesystem::create_hard_link(); // жесткие ссылки

}
