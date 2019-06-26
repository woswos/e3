################################################################################
# OPTIONS AND VARIABLES THAT NEED TO BE MODIFIED:

# Turn this ON if the scheme supports gate operations
option(GATE "" ON)

# Turn this ON if the scheme supports arithmetic operations
option(ARITHMETIC "" OFF)


# Set this the location of your library
set(libraryLocation "/usr/local/lib")

# Set this the name of your library
set(libraryName "-ltfhe-spqlios-fma")

################################################################################

# Rest of the cmake file
cmake_minimum_required (VERSION 3.10)

project (benchy)

# Bring the headers into the project
include_directories(src scheme)

#For the shared library:
include_directories(${libraryLocation})

#For the static library:
link_directories(${libraryLocation})

# Include gate or arithmetic api based on the selection
if(GATE)
    file(GLOB SOURCES
        "src/*.cpp"
        "scheme/api-gate.cpp"
    )
endif(GATE)
unset(GATE CACHE)

if(ARITHMETIC)
    file(GLOB SOURCES
        "src/*.cpp"
        "scheme/api-arithmetic.cpp"
    )
endif(ARITHMETIC)
unset(ARITHMETIC CACHE)

# Generate executable file
add_executable(benchy ${SOURCES})

# Include following libraries
target_link_libraries (benchy ${libraryName})



################################################################################
#### Can manually add the sources using the set command as follows:
####set(SOURCES src/main.cpp scheme/api-gate.cpp)

if(FALSE) # fake a block comment

include_directories(${PROJECT_SOURCE_DIR}/src /usr/local/lib)

add_executable(benchy ${PROJECT_SOURCE_DIR}/src/main.cpp)
target_link_libraries (benchy -ltfhe-spqlios-fma)

# cmake version to be used
cmake_minimum_required( VERSION 3.10 )

# project name
project( benchy )

# include headers
include_directories( ./include ./src /usr/local/lib )

# include libraries
link_directories( /usr/local/include /usr/local/lib )

file(GLOB benchy_SRC
    "./src/main.cpp"
    "./src/*.h"
    "./src/*.cpp"
)

# target
add_executable( benchy.exe  ${benchy_SRC} )

target_link_libraries( benchy.exe -ltfhe-spqlios-fma )

set_target_properties(benchy.exe  PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)


##########################
# FOR HELIB
#target_link_libraries( benchy.exe helib )
#find_package(helib 1.0.0 EXACT REQUIRED)
##########################

##########################
## FOR SEAL
# Import Microsoft SEAL
#find_package(SEAL 3.3.0 EXACT REQUIRED)
#target_link_libraries( benchy.exe SEAL::seal)
##########################


#check this website for details -> https://medium.com/heuristics/c-application-development-part-3-cmakelists-txt-from-scratch-7678253e5e24
endif()
