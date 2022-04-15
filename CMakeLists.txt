cmake_minimum_required(VERSION 3.22)
project(Teste C)

set(CMAKE_C_STANDARD 99)

add_executable(Teste src/main.c headers/Employee.h src/Employee.c)
