cmake_minimum_required(VERSION 3.4)
project(DecorationPattern)

set(CMAKE_CXX_STANDARD 11)

#aux_source_directory(src SRCS)
#add_library(DecorationPattern STATIC ${SRCS})
#target_include_directories(
#        DecorationPattern PUBLIC
#        inc
#)

add_executable(runDecorationPattern test/test.cpp)
target_include_directories(
        runDecorationPattern PUBLIC
        inc
        src
)