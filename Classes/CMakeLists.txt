cmake_minimum_required(VERSION 3.5)
project(persons)

include_directories(${CMAKE_SOURCE_DIR}/include)

# library
add_library(allpersons SHARED
	src/persons/Person.cpp
	src/persons/Pepita.cpp
	src/persons/Juanito.cpp
)
target_link_libraries(allpersons)

# prgram A
add_executable(check_persons
	src/check_persons.cpp
)
add_dependencies(check_persons
	allpersons
)
target_link_libraries(check_persons
	allpersons
)

# program B
add_executable(named_persons
	src/named_persons.cpp
)
add_dependencies(named_persons
	allpersons
)
target_link_libraries(named_persons
	allpersons
)
