cmake_minimum_required(VERSION 2.8)
project(example)

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS "-O3")


find_package(Pangolin REQUIRED)
include_directories(${Pangolin_INCLUDE_DIRS})

# 为使用 sophus，需要使用find_package命令找到它
find_package(Sophus REQUIRED)
# include_directories(${Sophus_INCLUDE_DIRS})
include_directories("/home/jyang/SLAM/slambook2/3rdparty/Sophus")


add_executable(trajectoryError trajectoryError.cpp)
target_link_libraries(trajectoryError ${Pangolin_LIBRARIES})
