cmake_minimum_required(VERSION 3.13)
project(logging)
set(CMAKE_CXX_STANDARD 17)

set(PROJECT_VERSION 0.1.0)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wswitch-enum")

include_directories(include)

# LOGGING ####################################################################

add_library(logger_lib src/logger.cpp include/logger.hpp)

# EXAMPLES ####################################################################

add_executable(example src/example_logger.cpp)
target_link_libraries(example logger_lib)
