cmake_minimum_required(VERSION 3.5)

project(catbrow)

file (GLOB 
		R_SRC "src/*.c")


include_directories(${PROJECT_NAME} inc/)
add_executable(${PROJECT_NAME} ${R_SRC})
message(" Source directiry is ${R_SRC}")



set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
        ${CMAKE_BINARY_DIR}/../bin)

