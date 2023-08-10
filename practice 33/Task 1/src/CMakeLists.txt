cmake_minimum_required(VERSION 3.8)
set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable("Shopping_Cart_Operation" "main.cpp" "online_market.cpp" )
target_include_directories(Shopping_Cart_Operation PUBLIC ${MY_INCLUDE})