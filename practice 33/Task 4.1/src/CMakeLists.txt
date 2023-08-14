cmake_minimum_required(VERSION 3.8)
set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable("Arithmetic_Mean" "main.cpp")
target_include_directories(Arithmetic_Mean PUBLIC ${MY_INCLUDE})