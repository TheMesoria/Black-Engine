ADD_EXECUTABLE( build
				main.cpp
				model/Object.cpp
				model/hunt/HuntObject.cpp
				implementation/Generators.cpp
				model/hunt/controller/Hound.cpp
				../include/model/hunt/controller/Hound.hpp
				model/hunt/controller/Houndmaster.cpp ../include/model/hunt/controller/Houndmaster.hpp engine/Huntsman.cpp ../include/engine/Huntsman.hpp engine/utility/Settings.cpp ../include/engine/utility/Settings.hpp )

ADD_DEPENDENCIES( build SFML SPDLOG JSON )

ADD_CUSTOM_COMMAND( TARGET build PRE_BUILD
					COMMAND ${CMAKE_COMMAND} -E copy_directory
					${CMAKE_SOURCE_DIR}/config $<TARGET_FILE_DIR:build> )

TARGET_LINK_LIBRARIES( build
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-audio.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-graphics.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-window.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-system.so
					   ${SFML_INSTALL_LOCATION}/lib/libsfml-network.so
					   pthread )
