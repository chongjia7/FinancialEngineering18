cmake_minimum_required(VERSION 3.10)
project(5_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("/usr/local/Cellar/boost/1.67.0/include/boost")

set(SOURCE_FILES main.cpp ./test.cpp)

add_executable(5_1 main.cpp)



