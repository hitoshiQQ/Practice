cmake_minimum_required(VERSION 3.8)
add_executable (Window main.cpp)

set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(Window PUBLIC ${MY_INCLUDE})