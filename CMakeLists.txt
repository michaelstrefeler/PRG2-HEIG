cmake_minimum_required(VERSION 3.21)
project(PRG2 C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(ex2_15 Chap2/ex2_15.c)
add_executable(ex2_16 Chap2/ex2_16.c)
add_executable(ex2_21 Chap2/ex2_21.c)
add_executable(ex2_22 Chap2/ex2_22.c)
add_executable(ex2_23 Chap2/ex2_23.c)
