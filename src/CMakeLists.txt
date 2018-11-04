#ADD_EXECUTABLE( runner main.cpp )

ADD_LIBRARY( BLACK-HUNTSMAN
			 src/model/Object.cpp
			 src/model/hunt/HuntObject.cpp
			 src/model/hunt/controller/Hound.cpp
			 src/model/hunt/controller/Houndmaster.cpp
			 src/implementation/Generators.cpp
			 src/engine/Huntsman.cpp
			 src/engine/utility/Settings.cpp
			 src/engine/utility/StartupManager.cpp
			 include/engine/utility/LoggerHelper.hpp
			 )

ADD_DEPENDENCIES( BLACK-HUNTSMAN SFML SPDLOG JSON )

#TARGET_LINK_LIBRARIES( runner
#					   BLACK-HUNTSMAN
#					   ${SFML_INSTALL_LOCATION}/lib/libsfml-audio.so
#					   ${SFML_INSTALL_LOCATION}/lib/libsfml-graphics.so
#					   ${SFML_INSTALL_LOCATION}/lib/libsfml-window.so
#					   ${SFML_INSTALL_LOCATION}/lib/libsfml-system.so
#					   ${SFML_INSTALL_LOCATION}/lib/libsfml-network.so
#					   pthread )
