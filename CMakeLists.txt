cmake_minimum_required(VERSION 3.16)

project(ft_containers)

set(CMAKE_CXX_STANDARD 11)

include_directories(includes)

add_executable(ft_containers srcs/main.cpp srcs/ll_tests.cpp)
