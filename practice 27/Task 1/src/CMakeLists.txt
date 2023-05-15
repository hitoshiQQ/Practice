cmake_minimum_required(VERSION 3.8)
set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(ElfVillage "main.cpp" "Branch.cpp"  "Tree.cpp")
target_include_directories(ElfVillage PUBLIC ${MY_INCLUDE})