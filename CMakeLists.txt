project								(adimx)
cmake_minimum_required(VERSION 2.8)


include_directories (
	${CMAKE_CURRENT_SOURCE_DIR}/include
)


add_definitions(-std=c++11)
add_subdirectory(include)
add_subdirectory(examples)