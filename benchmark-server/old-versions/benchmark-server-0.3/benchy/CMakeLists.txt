# cmake version to be used
cmake_minimum_required( VERSION 3.10 )

# project name
project( benchy )

# include headers
include_directories( ./include ./src)

# include libraries
#link_directories( /usr/local/include )

file(GLOB benchy_SRC
    "./src/main.cpp"
    "./src/*.h"
    "./src/*.cpp"
)

# target
add_executable( benchy.exe  ${benchy_SRC} )

find_package(helib 1.0.0 EXACT REQUIRED)

target_link_libraries( benchy.exe helib )

set_target_properties(benchy.exe  PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)




##########################
## FOR SEAL
# Import Microsoft SEAL
#find_package(SEAL 3.3.0 EXACT REQUIRED)
#target_link_libraries( benchy.exe SEAL::seal)
##########################


#check this website for details -> https://medium.com/heuristics/c-application-development-part-3-cmakelists-txt-from-scratch-7678253e5e24
