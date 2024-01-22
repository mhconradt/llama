cmake_minimum_required(VERSION 3.27)
project(transformers C)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
# Set build features
set(CMAKE_BUILD_TYPE Debug)

###############################################################################

set(CMAKE_C_STANDARD 17)


configure_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/config.h.in
        ${CMAKE_CURRENT_BINARY_DIR}/config.h)
include_directories(BEFORE ${CMAKE_CURRENT_BINARY_DIR})
add_definitions(-DHAVE_CONFIG_H)
set(CONFIG_HEADER ${CMAKE_CURRENT_BINARY_DIR}/config.h)

add_subdirectory(src)
add_subdirectory(tests)

enable_testing()