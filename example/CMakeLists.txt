cmake_minimum_required(VERSION 3.0)
project(SampleProgram)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp") # Define PROJECT_SOURCES as a list of all source files
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

include(FetchContent)
# include Paper
FetchContent_Declare(Paper GIT_REPOSITORY https://github.com/thyliverman/Paper.git GIT_TAG dev)
FetchContent_MakeAvailable(Paper)

find_library(Paper Paper)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC Paper)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_INCLUDE})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include/)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)