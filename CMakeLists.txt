cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
)
add_library(library ${SOURCE_LIB})
add_executable(1spiral.c 1.1/1spiral.c)
add_executable(2moving.c 1.2/2moving.c)
add_executable(3substr.c 1.3/3substr.c)
add_executable(4simp.c 1.4/4simp.c)
add_executable(5max.c 1.5/5max.c)
