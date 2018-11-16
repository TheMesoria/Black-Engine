ADD_LIBRARY( BLACK-HUNTSMAN
			 src/model/Object.cpp
			 src/model/hunt/HuntObject.cpp
			 src/model/hunt/controller/Hound.cpp
			 src/model/hunt/controller/Houndmaster.cpp
			 src/global/Generators.cpp
			 src/engine/Huntsman.cpp
			 src/engine/utility/SettingsFacade.cpp
			 src/engine/utility/StartupManager.cpp
			 include/engine/utility/LoggerHelper.hpp
			 src/engine/view/HuntingGround.cpp
			 include/engine/view/HuntingGround.hpp
			 src/engine/view/components/HuntingGroundChunk.cpp
			 include/engine/view/components/HuntingGroundChunk.hpp
			 include/global/Macros.hpp
			 src/global/Macros.cpp
			 include/global/Logger.hpp
			 src/engine/view/Falconer.cpp include/engine/view/Falconer.hpp )

ADD_DEPENDENCIES( BLACK-HUNTSMAN SFML SPDLOG JSON )