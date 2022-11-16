cmake_minimum_required(VERSION 3.23)
project(polynome)

set(CMAKE_CXX_STANDARD 14)

add_executable(polynome Polynome.cpp PolynomeAdd.cpp Polynome_a.in Polynome_b.in PolynomeAdd.out)
