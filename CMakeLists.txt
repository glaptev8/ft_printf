cmake_minimum_required(VERSION 3.14)
project(normprintf)

set(CMAKE_C_STANDARD 99)

add_executable(main.c libftprintf.a)