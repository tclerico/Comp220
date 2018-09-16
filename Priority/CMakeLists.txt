cmake_minimum_required(VERSION 3.8)
project(220_27_PriorityQueue)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp LinkedPriorityQueue.cpp PriorityLinkedNode.cpp)
add_executable(220_27_PriorityQueue ${SOURCE_FILES})