cmake_minimum_required(VERSION 3.20)
project(CompiWet1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(CompiWet1
        hw1.cpp
        tokens.hpp
        lex.yy.c)
