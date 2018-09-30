ADD_EXECUTABLE( MT
				ModuleTests.cpp )
ADD_DEPENDENCIES( Black-Engine GTEST SFML SPDLOG )

TARGET_LINK_LIBRARIES( MT
					   gtest
					   gtest_main
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-audio.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-graphics.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-window.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-system.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-network.so
					   pthread )
