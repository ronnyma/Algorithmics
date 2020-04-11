cmake_minimum_required(VERSION 3.8)
project(binarytree)

include_directories("../../log.c")
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(SOURCE_FILES
        avl/avl_tree.c
        include/avl/avl_tree.h
        binary_tree.c
        include/binary_tree.h
        entry.c
        tree.c
        include/tree.h
        include/log.h
        log.c)

add_executable(binarytree ${SOURCE_FILES})