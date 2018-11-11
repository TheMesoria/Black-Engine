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
			 ../config/CmakeVariables.h.in
			 src/engine/view/HuntingGround.cpp include/engine/view/HuntingGround.hpp )

ADD_DEPENDENCIES( BLACK-HUNTSMAN SFML SPDLOG JSON )