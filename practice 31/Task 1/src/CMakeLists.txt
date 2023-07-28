set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(useSmartPointer "main.cpp" )

target_include_directories("useSmartPointer" PUBLIC ${MY_INCLUDE})