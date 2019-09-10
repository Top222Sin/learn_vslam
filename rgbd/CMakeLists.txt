
cmake_minimum_required(VERSION 2.8)
project(rgbd)

find_package(Pangolin REQUIRED)
set(CMAKE_BUILD_TYPE "Release")
# 添加c++ 11标准支持
set(CMAKE_CXX_FLAGS "-std=c++11 -O2")

# Eigen
include_directories("/usr/include/eigen3")

# 寻找OpenCV库
find_package(OpenCV REQUIRED)
# 添加头文件
include_directories(${OpenCV_INCLUDE_DIRS})


# 为使用 sophus，需要使用find_package命令找到它
find_package(Sophus REQUIRED)
# include_directories(${Sophus_INCLUDE_DIRS})
include_directories("/home/jyang/SLAM/slambook2/3rdparty/Sophus")

find_package(Pangolin REQUIRED)

add_executable(joinMap joinMap.cpp)
target_link_libraries(joinMap ${OpenCV_LIBS} ${Pangolin_LIBRARIES})