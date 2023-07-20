cmake_minimum_required(VERSION 3.12)
project(EnigmaProject)

set(CMAKE_CXX_STANDARD 11)

# Add the source files
set(SOURCES
    src/Rotor.cpp
    src/Reflector.cpp
    src/Plugboard.cpp
    src/Enigma.cpp
    src/main.cpp
)

# Add the include directories
include_directories(${PROJECT_SOURCE_DIR})

# Create the executable
add_executable(enigma ${SOURCES})
