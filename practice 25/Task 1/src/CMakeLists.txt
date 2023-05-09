cmake_minimum_required(VERSION 0.1)

set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable (CMakeProject1 main.cpp surgical_tools.cpp coordinate.cpp enter_check.cpp operation_process.cpp )
target_include_direcories (CMakeProject1 PUBLIC ${CMAKE_SOURCE_DIR}/include)
