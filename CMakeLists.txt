cmake_minimum_required(VERSION 3.17)
project(spbu_2020_c_homeworks C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_LIB
        library/commonUtils/numericOperations.c library/commonUtils/numericOperations.h
        library/commonUtils/arrayOperations.c library/commonUtils/arrayOperations.h)

set(LIST_LIB library/dataStructures/List/list.c)
set(STACK_LIB library/dataStructures/Stack/stack.c library/dataStructures/Stack/stack.h)
set(BST_LIB library/dataStructures/BinarySearchTree/binarySearchTree.c library/dataStructures/BinarySearchTree/binarySearchTree.h)
set(AVL_LIB library/dataStructures/BinarySearchTree/AVL.c library/dataStructures/BinarySearchTree/AVL.h)
set(HASHTABLE_LIB library/dataStructures/HashTable/hashTable.c library/dataStructures/HashTable/hashTable.h)
set(GRAPH_LIB library/dataStructures/Graph/graph.c library/dataStructures/Graph/graph.h)
set(LEXER_LIB library/analyzers/lexer.c library/analyzers/lexer.h)

add_library(library ${SOURCE_LIB})
add_library(stackLibrary ${STACK_LIB})
add_library(listLibrary ${LIST_LIB})
add_library(bstLibrary ${BST_LIB})
add_library(avlLibrary ${AVL_LIB})
add_library(hashTableLibrary ${HASHTABLE_LIB})
add_library(graphLibrary ${GRAPH_LIB})
add_library(lexerLibrary ${LEXER_LIB})

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

add_executable(3.1_list tasks_3/test_list.c)
target_link_libraries(3.1_list listLibrary)
add_executable(3.2_murders tasks_3/3.2_murders.c)
target_link_libraries(3.2_murders listLibrary)

add_executable(4.1_postfix tasks_4/4.1_postfix.c)
target_link_libraries(4.1_postfix stackLibrary)
target_link_libraries(4.1_postfix library)
add_executable(4.2_double tasks_4/4.2_double.c)
target_link_libraries(4.2_double PRIVATE m)

add_executable(4.3_binaries tasks_4/4.3_binaries.c)
target_link_libraries(4.3_binaries PRIVATE m)

add_executable(5.1_testBST tasks_5/5.1_testBST.c)
target_link_libraries(5.1_testBST bstLibrary)

add_executable(5.2_testAVL tasks_5/5.2_testAVL.c)
target_link_libraries(5.2_testAVL avlLibrary)

add_executable(6_testHashTable tasks_6/6_testHashTable.c)
target_link_libraries(6_testHashTable hashTableLibrary)

add_executable(7.1_students tasks_7/7.1_students.c)
target_link_libraries(7.1_students graphLibrary)

add_executable(7.2_cities tasks_7/7.2_cities.c)
target_link_libraries(7.2_cities graphLibrary)

add_executable(8_lexer tasks_8/8_lexer.c)
target_link_libraries(lexerLibrary library)
target_link_libraries(8_lexer library)
target_link_libraries(8_lexer lexerLibrary)

add_executable(test_1.1_sort test_1/1.1_sort.c)

add_executable(test_2.1_fibbonachi test_2/2.1_fibbonachi.c)
add_executable(test_2.2_dates test_2/2.2_dates.c)
