cmake_minimum_required(VERSION 3.31)
project(modular C)

set(CMAKE_C_STANDARD 11)


include_directories(/opt/homebrew/Cellar/gmp/6.3.0/include)
link_directories(/opt/homebrew/Cellar/gmp/6.3.0/lib)

add_executable(modular
        main.c
        modular.c
)

target_compile_options(modular PRIVATE -Wall -Wextra -pedantic)
add_compile_options(modular PRIVATE -Wall -Wextra -pedantic -Werror)
target_link_libraries(modular gmp)