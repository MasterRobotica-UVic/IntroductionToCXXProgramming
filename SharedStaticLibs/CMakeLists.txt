cmake_minimum_required(VERSION 3.5)
project(example)

include_directories(${CMAKE_SOURCE_DIR}/include)

### Using SHARED library ###
add_library(myFunctions_shared SHARED
	lib_src/functions.cpp
)
target_link_libraries(myFunctions_shared)

add_executable(example_shared
	src/example.cpp
)
# build internal library before linking the executable
add_dependencies(example_shared
	myFunctions_shared
)
# links the executable and library
target_link_libraries(example_shared
	myFunctions_shared
)


### Using a STATIC library ###
add_library(myFunctions_static
	lib_src/functions.cpp
)
target_link_libraries(myFunctions_static)

add_executable(example_static
	src/example.cpp
)

# build internal library before linking the executable
add_dependencies(example_static
	myFunctions_static
)

# links the executable and library
target_link_libraries(example_static
	myFunctions_static
)
