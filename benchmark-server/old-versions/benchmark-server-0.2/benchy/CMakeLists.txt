# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project( benchy )

# flags

# files

# include
include_directories( ./include ./src )


file(GLOB benchy_SRC
    "./src/main.cpp"
    "./src/*.h"
    "./src/*.cpp"
)

# target
add_executable( benchy.exe  ${benchy_SRC} )

# external libs
#add_subdirectory( ./libs/Logger )
#target_link_libraries( binary logger )

# add_subdirectory( ./libs/Randomize )
# target_link_libraries( binary randomize )

#add_library(randomize STATIC IMPORTED)
#set_property(TARGET randomize PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/Randomize/librandomize.a)
#target_link_libraries( binary randomize )

#check this website for details -> https://medium.com/heuristics/c-application-development-part-3-cmakelists-txt-from-scratch-7678253e5e24
