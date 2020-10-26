cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
        library/commonUtils/numericOperations.c
        library/commonUtils/arrayOperations.c library/commonUtils/arrayOperations.h)
set(STACK_LIB library/dataStructures/Stack/stack.c library/dataStructures/Stack/stack.h)
set(BST_LIB library/dataStructures/BinarySearchTree/binarySearchTree.c library/dataStructures/BinarySearchTree/binarySearchTree.h)
add_library(library ${SOURCE_LIB})
add_library(stackLibrary ${STACK_LIB})
add_library(bstLibrary ${BST_LIB})

add_executable(1.1spiral.c tasks/1.1spiral.c)
add_executable(1.2moving.c tasks/1.2moving.c)
add_executable(1.3substr.c tasks/1.3substr.c)
add_executable(1.4simp.c tasks/1.4simp.c)
add_executable(1.5max.c tasks/1.5max.c)
target_link_libraries(1.2moving.c library)

add_executable(2.1_decompose.c tasks_2/2.1_decompose.c)
add_executable(2.2_bulls_and_cows.c tasks_2/2.2_bulls_and_cows.c)
add_executable(2.3_zeros.c tasks_2/2.3_zeros.c)
add_executable(2.4_sorting.c tasks_2/2.4_sorting.c)
add_executable(2.5_factorial.c tasks_2/2.5_factorial.c)
target_link_libraries(2.2_bulls_and_cows.c library)
target_link_libraries(2.3_zeros.c library)
target_link_libraries(2.4_sorting.c library)

add_executable(4.1_postfix tasks_4/4.1_postfix.c)
target_link_libraries(4.1_postfix stackLibrary)
target_link_libraries(4.1_postfix library)
add_executable(4.2_double tasks_4/4.2_double.c)
target_link_libraries(4.2_double PRIVATE m)

add_executable(5.1_testBST tasks_5/5.1_testBST.c)
target_link_libraries(5.1_testBST bstLibrary)