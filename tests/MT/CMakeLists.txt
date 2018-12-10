ADD_EXECUTABLE( mt
				ModuleTests.cpp
				startup/StartupTest.cpp
				../COMMON/TestBase.hpp
				runtime/FancierTests.cpp)
ADD_DEPENDENCIES( mt GTEST SFML SPDLOG )

TARGET_LINK_LIBRARIES( mt
					   BLACK-HUNTSMAN
					   gtest
					   gtest_main
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-audio.so.2.5.1
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-graphics.so.2.5.1
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-window.so.2.5.1
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-system.so.2.5.1
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-network.so.2.5.1
					   pthread )

ADD_TEST( MT mt )