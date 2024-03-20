# CMakeList for HW2

cmake_minimum_required(VERSION 3.23)
project(AERSP_424_HW2)
set(CMAKE_CXX_STANDARD 20)

# PROBLEM 1
add_executable(Q1 Problem1.cpp Problem1_Classes.h Problem1_Classes.cpp)
add_executable(Q2 Problem2.cpp Problem2_Functions.h Problem2_Functions.cpp)
add_executable(Q3 Problem3.cpp Problem3_Functions.h Problem3_Functions.cpp)