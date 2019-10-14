cmake_minimum_required(VERSION 3.14)
project(normprintf C)

set(CMAKE_C_STANDARD 99)

add_executable(normprintf main.c)

add_library(ftprintf.a
			)