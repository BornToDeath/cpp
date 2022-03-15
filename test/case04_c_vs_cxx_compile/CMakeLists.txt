cmake_minimum_required(VERSION 3.4.1)
project(Test)
set(CMAKE_CXX_STANDARD 11)

aux_source_directory(src SRCS)
add_library(TestLib SHARED ${SRCS})
target_include_directories(
        TestLib PUBLIC
        inc
)

add_executable(runTest main.cpp)
target_link_libraries(runTest TestLib)