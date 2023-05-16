cmake_minimum_required(VERSION 3.8)
set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(Company "main.cpp" "Employee.cpp" "Manager.cpp" "Boss.cpp")
target_include_directories(Company PUBLIC ${MY_INCLUDE})