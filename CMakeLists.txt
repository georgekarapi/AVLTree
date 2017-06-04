cmake_minimum_required(VERSION 3.7)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 11)


set(SOURCE_FILES main.cpp tree.h)
add_executable(BinaryTree ${SOURCE_FILES} tree.h)