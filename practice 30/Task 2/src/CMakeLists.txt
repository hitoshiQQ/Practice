set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(User requests "main.cpp" "http_cpr.cpp")

target_include_directories("User requests" PUBLIC ${MY_INCLUDE})