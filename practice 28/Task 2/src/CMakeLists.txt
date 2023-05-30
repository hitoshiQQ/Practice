cmake_minimum_required(VERSION 3.8)
project(Station)
set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(Station "main.cpp" "Multithreading.cpp" "Enter.cpp" "Trains.cpp" "Station.cpp" "Timer.cpp")
target_include_directories(Station PUBLIC ${MY_INCLUDE})