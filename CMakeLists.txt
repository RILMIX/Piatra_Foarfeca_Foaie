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

# copy resources to build directory
add_custom_command(TARGET app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:app>/resources
)