ADD_EXECUTABLE( ut
				UnitTests.cpp
				tests/SUCESSTests.cpp )
ADD_DEPENDENCIES( ut GTEST SFML SPDLOG )

TARGET_LINK_LIBRARIES( ut
					   gtest
					   gtest_main
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-audio.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-graphics.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-window.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-system.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-network.so
					   pthread )

ADD_TEST( UT ut )