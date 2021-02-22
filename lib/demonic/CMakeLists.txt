cmake_minimum_required(VERSION 3.13)
project(demonic C CXX)

set(CMAKE_CXX_STANDARD 14)
include_directories(.)
add_library(demonic demonic.h)

foreach (dir IN ITEMS containers helpmaker math strings)
    add_subdirectory(${dir})
endforeach ()

foreach (tar IN ITEMS vectors helpmaker math strings)
    target_link_libraries(demonic ${tar})
endforeach ()
