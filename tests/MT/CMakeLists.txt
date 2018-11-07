ADD_EXECUTABLE( mt
				ModuleTests.cpp
				startup/StartupTest.cpp
				../COMMON/TestBase.hpp )
ADD_DEPENDENCIES( mt GTEST SFML SPDLOG )

TARGET_LINK_LIBRARIES( mt
					   BLACK-HUNTSMAN
					   gtest
					   gtest_main
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-audio.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-graphics.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-window.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-system.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-network.so
					   pthread )

ADD_TEST( MT mt )