cmake_minimum_required(VERSION 3.4.1)
project(编译链接原理)
set(CMAKE_CXX_STANDARD 11)
#add_compile_options(-ffunction-sections -fdata-sections)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ffunction-sections -fdata-sections -fvisibility=hidden")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --gc-sections")
#add_link_options(--gc-sections)

#add_link_options(--gc-sections)

# 由于 world.cpp 中的符号没被 main.cpp 用到，所以 world.cpp 中的符号不会被添加到可执行文件中
add_library(hello STATIC hello.cpp world.cpp)
add_executable(runHello main.cpp)
target_link_libraries(
        runHello
        hello
#        -Wl,-dead_strip  # 添加此选项，则可执行文件中只有使用的符号，没被使用的符号不会被添加。注意：这个选项只是mac上的，linux上可能不适用
)