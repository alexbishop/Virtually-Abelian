cmake_minimum_required(VERSION 3.14)

project(virtually-heisenberg VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(vheis STATIC)
add_executable(virtually-heisenberg)

target_link_libraries(virtually-heisenberg
        PUBLIC vheis)

target_include_directories(vheis
    PUBLIC include lib/SafeInt
    PRIVATE src)

add_subdirectory(src)
add_subdirectory(include)
