cmake_minimum_required(VERSION 3.0)

project(vector)

add_library(vector SHARED vector.cc)

add_executable(main main.cc)

target_link_libraries(main vector)