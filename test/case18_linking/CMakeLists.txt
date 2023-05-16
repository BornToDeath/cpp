cmake_minimum_required(VERSION 3.4.1)
project(case18)
set(CMAKE_CXX_STANDARD 11)
add_compile_options(-g)

add_library(lib1 STATIC lib1/func.cpp)
add_library(lib2 STATIC lib2/a.cpp lib2/c.cpp)

add_library(lib3 SHARED Print.cpp)
target_link_libraries(lib3 lib1 lib2)

add_executable(test main.cpp)
target_link_libraries(test lib3)
#target_link_libraries(test lib1 lib2)
#target_link_libraries(test lib2 lib1)