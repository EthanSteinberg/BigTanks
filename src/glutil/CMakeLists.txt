set(HDRS 
   matrix.h
   glStuff.h
      )
 
set(SRCS
   matrix.cpp
   glStuff.cpp
   myVector2.cpp
   algoMaxRects.cpp
   myBox.cpp
)
 
add_library(glutil ${HDRS} ${SRCS})
target_link_libraries(glutil ${GLEW_LIBRARY} ${FREETYPE_LIBRARIES})
