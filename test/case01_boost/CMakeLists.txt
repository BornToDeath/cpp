cmake_minimum_required(VERSION 3.4.1)
project(BoostTest)
set(CMAKE_CXX_STANDARD 11)

include_directories("/Users/lixiaoqing/Desktop/Projects/boost/boost_1_79_0/")
add_executable(main test03_asio.cpp)