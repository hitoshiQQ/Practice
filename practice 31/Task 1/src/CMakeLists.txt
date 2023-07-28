set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(smartPointer "main.cpp" "shared_ptr_toy.cpp")

target_include_directories("smartPointer" PUBLIC ${MY_INCLUDE})