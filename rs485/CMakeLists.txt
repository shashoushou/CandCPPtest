
cmake_minimum_required(VERSION 3.10)

PROJECT(rs485)

find_package(Threads)
SET(SRC_LIST main.c)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lpthread")
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall -lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O3 -lpthread ")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -lpthread")

set(CMAKE_SYSTEM_NAME linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)
set(CMAKE_CROSSCOMPILING TRUE)

set(CMAKE_C_COMPILER "/usr/bin/aarch64-linux-gnu-gcc")
set(CMAKE_CXX_COMPILER "/usr/bin/aarch64-linux-gnu-g++")

# Where to look for the target environment. (More paths can be added here)a
set(CMAKE_FIND_ROOT_PATH /usr/aarch64-linux-gnu)
set(CMAKE_INCLUDE_PATH  /usr/aarch64-linux-gnu/include)
set(CMAKE_LIBRARY_PATH  /usr/lib/aarch64-linux-gnu)
set(CMAKE_PROGRAM_PATH  /usr/bin/aarch64-linux-gnu)

#set(CMAKE_C_FLAGS "-lpthread")

# Adjust the default behavior of the FIND_XXX() commands:
# search programs in the host environment only.
#set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH /usr/aarch64-linux-gnu)

# Search headers and libraries in the target environment only.
#set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE arm64)

MESSAGE(STATUS "THis is BINARY dir "${L600_BINARY_DIR})
MESSAGE(STATUS "THis is SOURCE dir "${L600_SOURCE_DIR})

#target_link_libraries(rs485 -lpthread) 
ADD_EXECUTABLE(rs485 ${SRC_LIST})
target_link_libraries(rs485 ${CMAKE_THREAD_LIBS_INIT})

