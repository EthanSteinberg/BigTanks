set(HDRS
   myQueue.h
   message.h
   shared.h
   myPool.h
   util.h
   )

set(SRCS
   myQueue.cpp
   message.cpp
   myPool.cpp
   util.cpp
   )

add_library(util ${HDRS} ${SRCS})
target_link_libraries(util)

