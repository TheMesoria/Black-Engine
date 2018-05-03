cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)
include(ExternalProject)

project(Black-Engine)
enable_testing()

set(ERROR_FLAGS "-Wall -Werror -Wextra -Wfatal-errors -pedantic-errors")

set(GTEST_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/gtest)
set(SFML_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/sfml)

ExternalProject_Add(GTEST
        GIT_REPOSITORY https://github.com/google/googletest
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${GTEST_INSTALL_LOCATION}
        )
ExternalProject_Add(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${SFML_INSTALL_LOCATION}
        )

include_directories(${GTEST_INSTALL_LOCATION}/include)
link_directories(${GTEST_INSTALL_LOCATION}/lib)

include_directories(${SFML_INSTALL_LOCATION}/include)
link_directories(${SFML_INSTALL_LOCATION}/lib)

add_subdirectory(src)
add_subdirectory(test)
