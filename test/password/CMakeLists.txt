cmake_minimum_required(VERSION 3.17)
project(password)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

add_executable(password main.cpp)