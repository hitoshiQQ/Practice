cmake_minimum_required(VERSION 3.8)
set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable("Fishing" "main.cpp" "fishing.cpp" )
target_include_directories(Fishing PUBLIC ${MY_INCLUDE})