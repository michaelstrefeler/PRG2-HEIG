cmake_minimum_required(VERSION 3.21)
project(PRG2 C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(ex5_1 Chap5/ex5_1.c)
add_executable(ex5_2 Chap5/ex5_2.c)
add_executable(ex5_3 Chap5/ex5_3.c)
add_executable(ex5_4 Chap5/ex5_4.c)
