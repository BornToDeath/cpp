cmake_minimum_required(VERSION 3.4.1)
project(Epoll)
set(CMAKE_CXX_STANDARD 11)

#aux_source_directory(. SRCS)
add_executable(epoll_client client.cpp)
add_executable(epoll_server server.cpp)