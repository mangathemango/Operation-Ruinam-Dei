cmake_minimum_required(VERSION 3.10)
project(DantesResurrection VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set compiler flags
add_compile_options(-Wall)
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")

# Include directories
include_directories(src)

# Add library directory
link_directories(lib)

# Find all source files in src directory
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(DantesResurrection ${SOURCES})

# Find all DLLs in lib folder and copy them
file(GLOB DLL_FILES "${CMAKE_SOURCE_DIR}/*.dll")
file(COPY ${CMAKE_SOURCE_DIR}/lib/ DESTINATION ${CMAKE_BINARY_DIR} FILES_MATCHING PATTERN "*.dll")


# Copy entire directory during configure time
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})


# Link libraries
target_link_libraries(DantesResurrection
    SDL2main
    SDL2
    SDL2_image
    SDL2_mixer
    SDL2_ttf
)