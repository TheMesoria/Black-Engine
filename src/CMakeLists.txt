add_executable(Black-Engine main.cpp)

add_dependencies(Black-Engine GTEST SFML)

target_link_libraries(Black-Engine
        gtest
        gtest_main
        ${SFML_INSTALL_LOCATION}/lib/libsfml-audio.so
        ${SFML_INSTALL_LOCATION}/lib/libsfml-graphics.so
        ${SFML_INSTALL_LOCATION}/lib/libsfml-window.so
        ${SFML_INSTALL_LOCATION}/lib/libsfml-system.so
        ${SFML_INSTALL_LOCATION}/lib/libsfml-network.so
        pthread)
