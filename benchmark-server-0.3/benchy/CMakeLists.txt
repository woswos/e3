# cmake version to be used
cmake_minimum_required( VERSION 3.10 )

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

set_target_properties(benchy.exe  PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS ON
)



##########################
## FOR SEAL
# Import Microsoft SEAL
find_package(SEAL 3.3.0 EXACT REQUIRED)
target_link_libraries( benchy.exe SEAL::seal)
##########################



# external libs
#add_subdirectory( ./libs/Logger )
#target_link_libraries( binary logger )

# add_subdirectory( ./libs/Randomize )
# target_link_libraries( binary randomize )

#add_library(randomize STATIC IMPORTED)
#set_property(TARGET randomize PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/Randomize/librandomize.a)
#target_link_libraries( binary randomize )

#check this website for details -> https://medium.com/heuristics/c-application-development-part-3-cmakelists-txt-from-scratch-7678253e5e24
