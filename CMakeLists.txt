cmake_minimum_required(VERSION 3.7)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp headers/tree.h libs/Graph.cpp libs/Graph.h libs/hashtable.cpp libs/hashtable.h
        libs/maxheap.cpp libs/maxheap.h libs/minheap.cpp libs/minheap.h)
add_executable(BinaryTree ${SOURCE_FILES} headers/tree.h)