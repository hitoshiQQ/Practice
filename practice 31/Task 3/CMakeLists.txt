cmake_minimum_required (VERSION 3.8)
project ("Graph")

set(CMAKE_CXX_STANDARD 20)

if(POLICY CMP0079 )
  cmake_policy(SET CMP0079 NEW)
endif()

add_subdirectory(src)
