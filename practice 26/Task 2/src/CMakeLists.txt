cmake_minimum_required(VERSION 3.8)
add_executable (Mobile main.cpp)

set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(Mobile PUBLIC ${MY_INCLUDE})