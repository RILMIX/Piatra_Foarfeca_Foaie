cmake_minimum_required(VERSION 3.10)
project(RPS CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    AsciiRenderer.cpp
    Choice.cpp
    Computer.cpp
    Engine.cpp
    HumanPlayer.cpp
    Main.cpp
)
add_executable(app ${SOURCES})