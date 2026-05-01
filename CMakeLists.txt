cmake_minimum_required(VERSION 4.0)
project(labyrinth)

set(CMAKE_CXX_STANDARD 20)

add_executable(labyrinth main.cpp
        funcTest.h
        map_for_game.h
)
