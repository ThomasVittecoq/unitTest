cmake_minimum_required(VERSION 3.12)
project(MyProject)

enable_testing()

include_directories(include)

# Add your source files here
file(GLOB SOURCES "src/*.cpp")

# Add the executable target
add_executable(MyProject ${SOURCES})

add_subdirectory(documentation)