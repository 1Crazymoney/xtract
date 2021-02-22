cmake_minimum_required(VERSION 3.17)
project(xtract)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/demonic)

file(COPY ${CMAKE_SOURCE_DIR}/data/english.txt DESTINATION ${CMAKE_BINARY_DIR})
add_executable(xtract src/main.cpp)
target_link_libraries(xtract demonic)