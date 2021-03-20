cmake_minimum_required(VERSION 3.17)
project(roman_numerals_cpp)

set(CMAKE_CXX_STANDARD 14)

enable_testing()
add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(test)