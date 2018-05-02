cmake_minimum_required(VERSION 3.9)
project(Black-Engine)

set(CMAKE_CXX_STANDARD 17)
include(ExternalProject)

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

add_executable(Black-Engine src/main.cpp)
add_dependencies(Black-Engine GTEST SFML)

target_link_libraries(Black-Engine
        gtest
        gtest_main
        ${SFML_INSTALL_LOCATION}/lib/libsfml-audio.so.2.4.2
        ${SFML_INSTALL_LOCATION}/lib/libsfml-graphics.so.2.4.2
        ${SFML_INSTALL_LOCATION}/lib/libsfml-window.so.2.4.2
        ${SFML_INSTALL_LOCATION}/lib/libsfml-system.so.2.4.2
        ${SFML_INSTALL_LOCATION}/lib/libsfml-network.so.2.4.2
        pthread)