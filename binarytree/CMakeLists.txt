cmake_minimum_required(VERSION 3.8)
project(binarytree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        avl_tree.c
        avl_tree.h
        binary_tree.c
        binary_tree.h
        entry.c
        entry.h
        tree.c
        tree.h)

add_executable(binarytree ${SOURCE_FILES})