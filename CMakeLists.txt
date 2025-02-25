cmake_minimum_required(VERSION 3.16)
project(Operation-Null-Mind)

# set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(lib/SDL EXCLUDE_FROM_ALL)
add_subdirectory(lib/SDL_image EXCLUDE_FROM_ALL)

# Create your game executable target as usual
add_executable(Operation-Null-Mind WIN32 src/main.c)

# Link to the actual SDL3 library.
target_link_libraries(Operation-Null-Mind PRIVATE SDL3::SDL3 SDL3_image::SDL3_image)