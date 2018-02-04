cmake_minimum_required(VERSION 3.4)
project(testLib)

INCLUDE_DIRECTORIES( ..)
set(src testmain.cpp)
add_executable( testLib ${src})
target_link_libraries(testLib baseservice)