cmake_minimum_required(VERSION 3.20)
project(30_3_Queries_with_arguments)


set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CPR_BUILD_TESTS_SSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR} )

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG f4622efcb59d84071ae11404ae61bd821c1c344b) # the commit hash for 1.6.2
FetchContent_MakeAvailable(cpr)


set(CMAKE_CXX_STANDARD 14)

add_executable(30_3_Queries_with_arguments main.cpp)

target_link_libraries(30_3_Queries_with_arguments PRIVATE cpr::cpr)