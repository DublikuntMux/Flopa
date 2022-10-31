cmake_minimum_required(VERSION 3.0.0)
project(Flopa VERSION 1.0.5)

add_executable(Flopa 
    src/main.cpp 
    src/additional.cpp
    src/additional.hpp
    src/effect.cpp
    src/effect.hpp
    src/killer.cpp
    src/killer.hpp
    src/misc.cpp
    src/misc.hpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
