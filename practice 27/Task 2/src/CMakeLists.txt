cmake_minimum_required(VERSION 3.8)

add_executable(Figure "main.cpp" "Figure.cpp" "circle.cpp" "triangle.cpp" "square.cpp" "rectangle.cpp" "Enter.cpp")

target_include_directories(Figure PUBLIC ${INCLUDE_DIR})