#####################################################################################
#                                                                                   #
#                      CMake Configuration                                          #
#                                                                                   #
#####################################################################################

# Minimum version required
cmake_minimum_required(VERSION 2.8)

# Project Name
project(ceres_qt)

# Set bin output
set(CMAKE_BIN "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BIN})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BIN})

# c++11
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Add bin and build dir to include
set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(${CMAKE_SOURCE_DIR}/src)

# Ceres
find_package(Ceres REQUIRED)
include_directories(${CERES_INCLUDE_DIR})

# Qt
find_package(Qt4 REQUIRED)
INCLUDE         (${QT_USE_FILE})
ADD_DEFINITIONS (${QT_DEFINITIONS})

# Eigen
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN_INCLUDE_DIRS})
add_definitions(${EIGEN_DEFINITIONS})

add_subdirectory(src)
