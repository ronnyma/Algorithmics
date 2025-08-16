cmake_minimum_required(VERSION 3.26)
project(avl_tree C)

set(CMAKE_C_STANDARD 11)

# Export compile commands for CLion/clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Define all source files explicitly
set(AVL_TREE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/avl_tree.c
    ${CMAKE_CURRENT_SOURCE_DIR}/binary_tree.c
    ${CMAKE_CURRENT_SOURCE_DIR}/log.c
    ${CMAKE_CURRENT_SOURCE_DIR}/tree.c
)

# Define all header files explicitly
set(AVL_TREE_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/include/avl_tree.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/binary_tree.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/log.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/tree.h
)

# Create a library that CLion will recognize
add_library(avl_tree_lib STATIC
    ${AVL_TREE_SOURCES}
    ${AVL_TREE_HEADERS}
)

# Set include directories for the library
target_include_directories(avl_tree_lib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Original executable
add_executable(avl_tree
    ${CMAKE_CURRENT_SOURCE_DIR}/entry.c
)
target_link_libraries(avl_tree avl_tree_lib)

# Test executable  
add_executable(test_avl
    ${CMAKE_CURRENT_SOURCE_DIR}/test_avl.c
)
target_link_libraries(test_avl avl_tree_lib)

# Ensure CLion recognizes all files
set_property(TARGET avl_tree_lib PROPERTY SOURCES ${AVL_TREE_SOURCES} ${AVL_TREE_HEADERS})
set_property(TARGET avl_tree PROPERTY SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/entry.c)
set_property(TARGET test_avl PROPERTY SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/test_avl.c)
