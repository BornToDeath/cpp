cmake_minimum_required(VERSION 3.4.1)
project(Test)
set(CMAKE_CXX_STANDARD 17)

find_package(GTest CONFIG REQUIRED)
aux_source_directory(. SRCS)
add_executable(run_test ${SRCS})
target_link_libraries(run_test GTest::gmock_main)