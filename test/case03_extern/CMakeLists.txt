cmake_minimum_required(VERSION 3.4.1)
project(Test)
set(CMAKE_CXX_STANDARD 11)

aux_source_directory(aaa AAA_SRCS)
add_library(aaa STATIC ${AAA_SRCS})

aux_source_directory(bbb BBB_SRCS)
add_library(bbb SHARED ${BBB_SRCS})
target_link_libraries(bbb aaa)

add_executable(runMain main.cpp)
target_link_libraries(runMain bbb)