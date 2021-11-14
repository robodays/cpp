cmake_minimum_required(VERSION 3.20)
project(32_1_Information_about_film)

set(CMAKE_CXX_STANDARD 14)


set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)

add_executable(32_1_Information_about_film main.cpp)

target_link_libraries(32_1_Information_about_film PRIVATE nlohmann_json::nlohmann_json)