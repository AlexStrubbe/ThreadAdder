cmake_minimum_required(VERSION 3.10)

# Set the compiling mode flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG -s")

project(ThreadAdder)

# Include the current directory for header files
include_directories(include)

# Add the executable
add_executable(thread_adder
    src/threader.c
    src/functions.c
)

target_link_libraries(thread_adder  ${CURSES_LIBRARIES})
target_link_libraries(thread_adder  m)