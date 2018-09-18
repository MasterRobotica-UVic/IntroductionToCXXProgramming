project(helloworld)

### preprocess and compile ###
include_directories(
	# Intternal/External library declaration paths
)
add_executable(myHelloWorld
	helloworld.cpp
)

### linker ###
link_directories(
	# Internal/External Library paths
)
target_link_libraries(myHelloWorld
	# Internal/External Library names
)
