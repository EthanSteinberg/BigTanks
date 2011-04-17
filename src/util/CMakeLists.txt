set(HDRS
   myQueue.h
   message.h
   )

set(SRCS
   myQueue.cpp
   message.cpp
   )

add_library(util ${HDRS} ${SRCS})
target_link_libraries(util)

