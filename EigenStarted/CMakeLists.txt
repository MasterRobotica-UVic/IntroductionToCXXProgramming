cmake_minimum_required(VERSION 3.5)
project(eigen_started)

find_package(Eigen3 REQUIRED)

include_directories(${EIGEN3_INCLUDE_DIR})

add_executable(eigen_started
	main.cpp
)
target_link_libraries(eigen_started)
