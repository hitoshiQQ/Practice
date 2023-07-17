cmake_minimum_required(VERSION 3.8)
project ("Requests arg")

set(CMAKE_CXX_STANDARD 20)



if(POLICY CMP0079 )
  cmake_policy(SET CMP0079 NEW)
endif()


# Enable Hot Reload for MSVC compilers if supported.
set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
set(CPR_ENABLE_SSL OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}")


add_subdirectory(src)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)


target_link_libraries("Requests arg" PRIVATE cpr::cpr)
