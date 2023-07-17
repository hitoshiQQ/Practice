set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)

add_executable(Requests arg "main.cpp" "http_web_page.cpp")

target_include_directories("Requests arg" PUBLIC ${MY_INCLUDE})