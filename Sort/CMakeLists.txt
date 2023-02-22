cmake_minimum_required(VERSION 3.24)
project(Sort)

set(CMAKE_CXX_STANDARD 17)

add_executable(Sort main.cpp InsertSort.cpp BinInsertSort.cpp shellSort.cpp BubbleSort.cpp selectSort.cpp shiftDown.cpp heapSort.cpp Heap.cpp)
