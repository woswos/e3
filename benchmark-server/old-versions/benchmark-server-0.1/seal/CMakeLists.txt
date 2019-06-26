# Copyright (c) Microsoft Corporation. All rights reserved.
# Licensed under the MIT license.

cmake_minimum_required(VERSION 3.10)

project(SEALExamples VERSION 3.3.0 LANGUAGES CXX)

# Executable will be in ../bin
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

add_executable(scheme.exe scheme.cpp)
#target_sources(scheme.exe)

# Import Microsoft SEAL
find_package(SEAL 3.3.0 EXACT REQUIRED)

# Link Microsoft SEAL
target_link_libraries(scheme.exe SEAL::seal)




include_directories("../../benchy")
