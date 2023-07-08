cmake_minimum_required(VERSION 3.8)
set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(Shape main.cpp Shape.cpp Circle.cpp Triangle.cpp Rectangle.cpp printParams.cpp)
target_include_directories(Shape PUBLIC ${MY_INCLUDE})