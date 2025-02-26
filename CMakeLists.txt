cmake_minimum_required(VERSION 3.10)
project(Operation-Ruinam-Dei VERSION 1.0)

# Set compiler flags
add_compile_options(-Wall)


# Include directories
include_directories(src)

# Add library directory
link_directories(lib)

# Find all source files in src directory
file(GLOB SOURCES "src/*.c")

# Create executable
add_executable(Operation-Ruinam-Dei ${SOURCES})

# Find all DLLs in lib folder and copy them
file(COPY ${CMAKE_SOURCE_DIR}/lib/ DESTINATION ${CMAKE_BINARY_DIR} FILES_MATCHING PATTERN "*.dll")


# Copy entire directory during configure time
file(COPY ${CMAKE_SOURCE_DIR}/Assets DESTINATION ${CMAKE_BINARY_DIR})


# Link libraries
target_link_libraries(Operation-Ruinam-Dei
    SDL2main
    SDL2
    SDL2_image
    SDL2_mixer
    SDL2_ttf
)