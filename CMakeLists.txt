cmake_minimum_required(VERSION 3.21)
project(PRG2 C)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS "-Wall -Wextra -Wconversion -Wsign-conversion -pedantic")

add_executable(ex4_2 Chap4/ex4_2.c)
add_executable(ex4_3 Chap4/ex4_3.c)
add_executable(ex4_4 Chap4/ex4_4.c)
add_executable(ex4_5 Chap4/ex4_5.c)
add_executable(Q5 old_test_exercises/question5_TE2_20-21.c)