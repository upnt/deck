cmake_minimum_required(VERSION 3.1)

project(deck CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp)

enable_testing()

add_test(
    NAME ${PROJECT_NAME}
    COMMAND ${PROJECT_NAME}
    CONFIGURATIONS Release
)
