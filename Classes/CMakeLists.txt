cmake_minimum_required(VERSION 3.5)
project(persons)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(allpersons SHARED
	src/persons/Person.cpp
	src/persons/Pepita.cpp
	src/persons/Juanito.cpp
)
target_link_libraries(allpersons)

add_executable(check_persons
	src/main.cpp
)
add_dependencies(check_persons
	allpersons
)
target_link_libraries(check_persons
	allpersons
)
