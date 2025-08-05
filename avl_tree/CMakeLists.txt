cmake_minimum_required(VERSION 3.26)
project(avl_tree C)

set(CMAKE_C_STANDARD 11)

add_executable(avl_tree
        entry.c
        log.c
        tree.c
        binary_tree.c
        avl_tree.c
    )
