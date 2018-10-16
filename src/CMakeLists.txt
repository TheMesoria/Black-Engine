ADD_EXECUTABLE( build
				main.cpp
				model/Object.cpp
				model/hunt/HuntObject.cpp
				implementation/Generators.cpp
				model/hunt/controller/Hound.cpp ../include/model/hunt/controller/Hound.hpp )

ADD_DEPENDENCIES( build SFML SPDLOG )

TARGET_LINK_LIBRARIES( build
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-audio.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-graphics.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-window.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-system.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-network.so
					   pthread )
