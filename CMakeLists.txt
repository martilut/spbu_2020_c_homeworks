cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
    library/commonUtils/numericOperations.c
)
add_library(library ${SOURCE_LIB})
add_executable(1spiral.c tasks/1spiral.c)
add_executable(2moving.c tasks/2moving.c)
add_executable(3substr.c tasks/3substr.c)
add_executable(4simp.c tasks/4simp.c)
add_executable(5max.c tasks/5max.c)
