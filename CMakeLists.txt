cmake_minimum_required(VERSION 3.1)

project(Snake)

set(CMAKE_CXX_FLAGS "-std=c++17 -g -pthread")


INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/inc/
)

set(LIBS
)

file(GLOB_RECURSE ${PROJECT_NAME}_SOURCE_FILES
	CSnake.cpp /
	kbhit.cpp /
    snake.cpp /	
)	

add_executable(Snake ${${PROJECT_NAME}_SOURCE_FILES})
target_link_libraries(Snake ${LIBS})
