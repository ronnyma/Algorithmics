cmake_minimum_required(VERSION 3.6)
project(Algorithmics)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    node.c
    tree.c
    tree.h utility.c)

add_executable(Algorithmics ${SOURCE_FILES})