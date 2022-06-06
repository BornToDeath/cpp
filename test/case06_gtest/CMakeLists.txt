cmake_minimum_required(VERSION 3.4.1)
project(Test)
set(CMAKE_CXX_STANDARD 11)

#aux_source_directory(sample1 SRCS)
#aux_source_directory(sample2 SRCS)
aux_source_directory(sample3 SRCS)

add_executable(test test.cpp ${SRCS})
target_include_directories(test PUBLIC gtest/include)
target_link_libraries(test ${CMAKE_CURRENT_LIST_DIR}/gtest/libs/libgtest.a)