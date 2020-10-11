cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
        library/commonUtils/numericOperations.c
        library/commonUtils/arrayOperations.c)

set(LIST_LIB library/dataStructures/List/list.c)

add_library(library ${SOURCE_LIB})
add_library(listLibrary ${LIST_LIB})

add_executable(1.1spiral.c tasks/1.1spiral.c)
add_executable(1.2moving.c tasks/1.2moving.c)
add_executable(1.3substr.c tasks/1.3substr.c)
add_executable(1.4simp.c tasks/1.4simp.c)
add_executable(1.5max.c tasks/1.5max.c)
target_link_libraries(1.2moving.c library)

add_executable(3.2_murders tasks_3/3.2_murders.c)
target_link_libraries(3.2_murders listLibrary)