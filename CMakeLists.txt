cmake_minimum_required(VERSION 3.16)
project(Operation-Null-Mind)

# Set the output directory for built objects.
# This makes sure that the dynamic library goes into the build directory automatically.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

# Specify the CMake toolchain file for vcpkg
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Find SDL3 and SDL3_image packages
find_package(SDL2 REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)

# Create your game executable target as usual
add_executable(Operation-Null-Mind WIN32 src/main.c)

# Link to the actual SDL3 library.
target_link_libraries(Operation-Null-Mind PRIVATE 
$<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static> 
$<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)

# Copy assets to the build output directory
add_custom_command(TARGET Operation-Null-Mind POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    "${CMAKE_SOURCE_DIR}/Assets"
    "$<TARGET_FILE_DIR:Operation-Null-Mind>/Assets"
)