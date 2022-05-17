cmake_minimum_required(VERSION 3.21)
project(PRG2 C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(ex3_5.c Chap3/ex3_5.c)
add_executable(ex3_6.c Chap3/ex3_6.c)
add_executable(ex3_8.c Chap3/ex3_8.c)
