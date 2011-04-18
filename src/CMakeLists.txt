set(HDRS
   )

set(SRCS
   main.cpp
   )

add_executable(BigTanks ${HDRS} ${SRCS})
target_link_libraries(BigTanks util ${GTK2_LIBRARIES} TanksGui TanksMid TanksModel)

add_subdirectory(util)
include_directories(util)

add_subdirectory(gui)
add_subdirectory(model)
add_subdirectory(mid)




