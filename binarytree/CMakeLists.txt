cmake_minimum_required(VERSION 3.8)
project(binarytree)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_FILES
        avl_tree.c
        include/avl_tree.h
        binary_tree.c
        include/binary_tree.h
        entry.c
        tree.c
        include/tree.h)

add_executable(binarytree ${SOURCE_FILES})