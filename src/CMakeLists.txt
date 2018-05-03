add_executable(Black-Engine main.cpp)
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
