cmake_minimum_required(VERSION 3.0)
project(Paper)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp") # Define PROJECT_SOURCES as a list of all source files
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

find_library(freeimage freeimage ${CMAKE_CURRENT_LIST_DIR}/lib/)
find_library(raylib raylib ${CMAKE_CURRENT_LIST_DIR}/lib/)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include/)
target_link_libraries(${PROJECT_NAME} PRIVATE ${raylib})
target_link_libraries(${PROJECT_NAME} PRIVATE ${freeimage})
