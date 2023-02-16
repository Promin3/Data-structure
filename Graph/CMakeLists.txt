cmake_minimum_required(VERSION 3.24)
project(Graph)

set(CMAKE_CXX_STANDARD 17)

add_executable(Graph MatGraph.cpp problem8_2.cpp AdjGraph.cpp problem8_3.cpp DFS.cpp BFS.cpp problem8_4.cpp problem8_5.cpp problem8_6.cpp shortdis.cpp shortdis2.cpp prim.cpp kruskal.cpp kruskal_pro.cpp dijkstra.cpp floyd.cpp topsort.cpp)
