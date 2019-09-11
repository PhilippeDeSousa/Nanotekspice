cmake_minimum_required (VERSION 3.0)
project (Nanotekspice)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")

add_executable(nanotekspice main.cpp ${SOURCES})