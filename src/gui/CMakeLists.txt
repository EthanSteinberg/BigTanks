set(HDRS
   tanksGui.h
   )

set(SRCS
   tanksGui.cpp
   onMessage.cpp
   )

add_library(TanksGui ${HDRS} ${SRCS})
target_link_libraries(TanksGui util ${GTK2_LIBRARIES})



