cmake_minimum_required(VERSION 3.10)

project(game)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(game 
    src/main.cc
    src/board.cc
)