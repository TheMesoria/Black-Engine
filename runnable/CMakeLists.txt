ADD_EXECUTABLE( runnable main.cpp )

#TARGET_LINK_LIBRARIES( runnable  )
#ADD_DEPENDENCIES( runnable BLACK-HUNTSMAN )
TARGET_LINK_LIBRARIES( runnable BLACK-HUNTSMAN )
TARGET_LINK_LIBRARIES( runnable -L/home/black/Work/Black-Engine/cmake-build-debug/sfml/lib )