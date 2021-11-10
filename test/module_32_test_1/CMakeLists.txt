cmake_minimum_required(VERSION 3.20)
project(module_32_test_1)

set(CMAKE_CXX_STANDARD 14)


# Typically you don't care so much for a third party library's tests to be
# run from your own project's code.
set(JSON_BuildTests OFF CACHE INTERNAL "")

# If you only include this third party in PRIVATE source files, you do not
# need to install it when your main project gets installed.
# set(JSON_Install OFF CACHE INTERNAL "")

# Don't use include(nlohmann_json/CMakeLists.txt) since that carries with it
# unintended consequences that will break the build.  It's generally
# discouraged (although not necessarily well documented as such) to use
# include(...) for pulling in other CMake projects anyways.
add_subdirectory(nlohmann_json)

add_executable(module_32_test_1 main.cpp)

target_link_libraries(module_32_test_1 PRIVATE nlohmann_json::nlohmann_json)