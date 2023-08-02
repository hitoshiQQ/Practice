cmake_minimum_required(VERSION 3.8)
project(Film_Info)

set(CMAKE_CXX_STANDARD 20)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(Film_Info main.cpp)

target_link_libraries(Film_Info PRIVATE nlohmann_json::nlohmann_json)