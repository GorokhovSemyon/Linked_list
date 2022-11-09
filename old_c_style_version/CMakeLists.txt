cmake_minimum_required(VERSION 3.21)
project(Linked_lists)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(SOURCES main.cpp Linked_list_operations.cpp Linked_list_operations.h)

add_executable(Linked_lists ${SOURCES})