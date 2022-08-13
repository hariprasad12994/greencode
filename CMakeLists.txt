project("hello cmake")
cmake_minimum_required(VERSION 3.10)

add_definitions("-std=c++14")

add_subdirectory(dsa)
add_subdirectory(stl)

