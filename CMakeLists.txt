cmake_minimum_required(VERSION "3.19.5")

project("BunnyFarm")

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable("${PROJECT_NAME}" src/Source.cpp src/Definitions include/Header.h)