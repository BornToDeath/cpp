cmake_minimum_required(VERSION 3.4.1)
project(Test)
set(CMAKE_CXX_STANDARD 14)

aux_source_directory(sample1 SRCS1)
aux_source_directory(sample2 SRCS2)
aux_source_directory(sample3 SRCS3)
aux_source_directory(sample4 SRCS4)
aux_source_directory(sample5 SRCS5)
aux_source_directory(sample6 SRCS6)

add_executable(test test.cpp ${SRCS1} ${SRCS2} ${SRCS3} ${SRCS4} ${SRCS5} ${SRCS6})
target_include_directories(test PUBLIC gtest/include sample1 sample3)
target_link_libraries(test ${CMAKE_CURRENT_LIST_DIR}/gtest/libs/libgtest.a)