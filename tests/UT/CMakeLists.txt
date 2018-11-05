ADD_EXECUTABLE( ut
				UnitTests.cpp
				tests/engine/utility/StartupManagerTests.cpp
				mocks/SettingsMock.hpp
				mocks/HuntsmanMock.hpp

				../COMMON/TestBase.hpp )

INCLUDE_DIRECTORIES( mocks )

ADD_DEPENDENCIES( ut GTEST SFML SPDLOG )

TARGET_LINK_LIBRARIES( ut
					   BLACK-HUNTSMAN
					   gtest
					   gmock
					   gtest_main
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-audio.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-graphics.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-window.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-system.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-network.so
					   pthread )

ADD_TEST( UT ut )