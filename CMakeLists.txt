cmake_minimum_required(VERSION 3.21)
project(PRG2 C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(ex2_14 Chap2/ex2_14.c)
