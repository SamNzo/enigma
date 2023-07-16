cmake_minimum_required(VERSION 3.12)
project(EnigmaProject)

set(CMAKE_CXX_STANDARD 11)

# Add the source files
set(SOURCES
    Rotor.cpp
    Reflector.cpp
    Enigma.cpp
    main.cpp
)

# Add the include directories
include_directories(${PROJECT_SOURCE_DIR})

# Create the executable
add_executable(Enigma ${SOURCES})
