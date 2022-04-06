cmake_minimum_required(VERSION 3.21)
project(Flopa VERSION 1.0.7.3)

set(CMAKE_CXX_STANDARD 11)

include_directories(Source)

add_executable(Flopa
        Source/Additional.cpp
        Source/Effect.cpp
        Source/Killer.cpp
        Source/Misc.cpp
        Source/Virs.cpp
        Source/VirsHad.hpp)
