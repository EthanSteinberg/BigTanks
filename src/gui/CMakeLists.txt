set(HDRS
   tanksGui.h
   gameWindow.h
   )

set(SRCS
   tanksGui.cpp
   onMessage.cpp

   gameWindow.cpp
   )

add_library(TanksGui ${HDRS} ${SRCS})
target_link_libraries(TanksGui util glutil ${GTK2_LIBRARIES} ${SFML_LIBRARY} ${PNG_LIBRARIES} ${GLEW_LIBRARY} rt GL)




