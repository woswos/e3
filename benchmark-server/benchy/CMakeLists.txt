cmake_minimum_required (VERSION 3.1)

project (benchy LANGUAGES CXX)

# Bring the headers into the project
include_directories(src src/base scheme/oleg)

#For the shared library:
include_directories(${libraryLocation})

# Include gate or arithmetic api based on the selection
file(GLOB SOURCES
    "src/*.cpp"
)

# Generate executable file
add_executable(benchy ${SOURCES})

# Include following libraries
target_link_libraries (benchy ${libraryName})

set_target_properties(benchy  PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
