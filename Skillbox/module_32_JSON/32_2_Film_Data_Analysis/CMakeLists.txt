cmake_minimum_required(VERSION 3.20)
project(32_2_Film_Data_Analysis)

set(CMAKE_CXX_STANDARD 14)

set(JSON_BuildTests OFF CACHE INTERNAL "")
add_subdirectory(nlohmann_json)

add_executable(32_2_Film_Data_Analysis main.cpp)

target_link_libraries(32_2_Film_Data_Analysis PRIVATE nlohmann_json::nlohmann_json)