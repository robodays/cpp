cmake_minimum_required(VERSION 3.20)

add_executable(25_2_Computer_simulator_project
        main.cpp cpu.cpp ram.cpp disk.cpp gpu.cpp kbd.cpp)
target_include_directories(25_2_Computer_simulator_project PUBLIC ${MY_INCLUDE_DIR})