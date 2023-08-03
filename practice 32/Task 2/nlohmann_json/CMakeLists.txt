cmake_minimum_required(VERSION 3.8)
project(Film_Analysis)

set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)
add_executable(Film_Analysis "main.cpp" "find.h" "data_process.h" )

target_link_libraries(Film_Analysis PRIVATE nlohmann_json::nlohmann_json)