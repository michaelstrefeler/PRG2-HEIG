cmake_minimum_required(VERSION 3.21)
project(PRG2 C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(ex3_1.c Chap3/ex3_1.c)
add_executable(ex3_2.c Chap3/ex3_2.c)
add_executable(ex3_3.c Chap3/ex3_3.c)
add_executable(ex3_4.c Chap3/ex3_4.c)
