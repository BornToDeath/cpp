cmake_minimum_required(VERSION 3.4)
set(CMAKE_CXX_STANDARD 11)

project(Test)

file(GLOB SRCS *.c *.cpp)
message(STATUS "SRCS=${SRCS}")

add_executable(main ${SRCS} main.cpp)