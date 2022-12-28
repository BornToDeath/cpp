cmake_minimum_required(VERSION 3.4.1)
project(Sanitizer)
set(CMAKE_CXX_STANDARD 11)

add_compile_options(-g)

# thread sanitizer
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread")
add_executable(runThreadSanitizer test.cpp)