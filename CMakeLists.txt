cmake_minimum_required(VERSION 3.28)
project(untitled3 C)

set(CMAKE_C_STANDARD 11)

add_library(untitled3 STATIC
        geometry.h
        main.c
        geometry.c)
