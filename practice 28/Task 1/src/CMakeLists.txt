cmake_minimum_required(VERSION 3.8)
set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(Swimmers main.cpp Threading.cpp Enter.cpp Swimmers.cpp)
target_include_directories(Swimmers PUBLIC ${MY_INCLUDE})
