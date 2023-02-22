cmake_minimum_required(VERSION 3.24)
project(Search)

set(CMAKE_CXX_STANDARD 17)

add_executable(Search seqSearch.cpp BinSearch.cpp BinSearch2.cpp BlkSearch.cpp BinarySearchTree.cpp "AVLTree.cpp" BKDRHhash.cpp)
