cmake_minimum_required(VERSION 3.23)
project(E C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(E
        prog_one.c
        read_input.c
        read_input.h
        read_int.c read_double.c prog_two.c)
