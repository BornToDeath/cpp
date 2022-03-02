cmake_minimum_required(VERSION 3.4.1)
project(BoostTest)
set(CMAKE_CXX_STANDARD 11)

include_directories(../../../boost_1_77_0)
add_executable(main test04_any.cpp)