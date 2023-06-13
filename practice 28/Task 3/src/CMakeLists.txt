cmake_minimum_required(VERSION 3.23)
set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(Kitchen main.cpp courier.cpp Enter.cpp kitchen.cpp onlineTrade.cpp threading.cpp)
target_include_directories(Kitchen PUBLIC ${MY_INCLUDE})