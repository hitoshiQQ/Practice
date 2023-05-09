cmake_minimum_required(VERSION 3.8)

set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(Computer "main.cpp" hdd.cpp cpu.cpp memory.cpp keyboard.cpp gpu.cpp)

target_include_directories(Computer PUBLIC ${MY_INCLUDE})
