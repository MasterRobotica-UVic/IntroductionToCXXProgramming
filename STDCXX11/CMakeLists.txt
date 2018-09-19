cmake_minimum_required(VERSION 3.5)
project(stdcxx11)

# ensure the use of c++11
# it'd be better to check if the system can work with the standard though
add_definitions(-std=c++11)
find_package(Threads)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(std_containers
	std_containers.cpp
)
target_link_libraries(std_containers)

add_executable(std_thread
	std_thread.cpp
)
target_link_libraries(std_thread
	${CMAKE_THREAD_LIBS_INIT}
)
