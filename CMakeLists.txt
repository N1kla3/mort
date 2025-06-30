cmake_minimum_required(VERSION 3.31)
project(mort)

set(CMAKE_CXX_STANDARD 20)

set(MORT_DEV)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_library(mort INTERFACE
        src/vec.hpp
        src/vec2.hpp
        src/vec3.hpp
)
set_target_properties(mort PROPERTIES LINKER_LANGUAGE CXX)

if (MORT_DEV)
    enable_testing()
    add_subdirectory(googletest)
    include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
    add_subdirectory(tests)
endif ()
