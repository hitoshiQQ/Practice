cmake_minimum_required(VERSION 3.8)
set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable("ArithmeticMean" "main.cpp"  )
target_include_directories(ArithmeticMean PUBLIC ${MY_INCLUDE})