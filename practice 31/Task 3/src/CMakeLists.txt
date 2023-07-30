set(MY_INCLUDE ${CMAKE_SOURCE_DIR}/include)
add_executable("Graph" "main.cpp" "graph.cpp" "graph_list.cpp" "graph_matrix.cpp" )

target_include_directories("Graph" PUBLIC ${MY_INCLUDE})