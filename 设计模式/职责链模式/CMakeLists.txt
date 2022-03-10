cmake_minimum_required(VERSION 3.4)
project(ChainOfResponsibility)

set(CMAKE_CXX_STANDARD 11)

add_executable(runChainOfResponsibility test/test.cpp)
target_include_directories(
        runChainOfResponsibility PUBLIC
        inc
)