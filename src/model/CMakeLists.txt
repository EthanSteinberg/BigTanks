set(HDRS
   tanksModel.h
   )

set(SRCS
   tanksModel.cpp
   )

add_library(TanksModel ${HDRS} ${SRCS})
target_link_libraries(TanksModel util ${GTK2_LIBRARIES})


