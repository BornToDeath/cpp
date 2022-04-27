cmake_minimum_required(VERSION 3.4.1)
project(线程池)
set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. SRCS)
add_executable(test ${SRCS})