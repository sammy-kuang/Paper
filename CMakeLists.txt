cmake_minimum_required(VERSION 3.0)
project(Paper)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp") # Define PROJECT_SOURCES as a list of all source files
set(PROJECT_INCLUDE "${CMAKE_CURRENT_LIST_DIR}/src/") # Define PROJECT_INCLUDE to be the path to the include directory of the project

set(paper_public_headers
    ${CMAKE_CURRENT_LIST_DIR}/src/Paper.h
    ${CMAKE_CURRENT_LIST_DIR}/src/PaperApp.h
    ${CMAKE_CURRENT_LIST_DIR}/src/PaperObjects.h
    ${CMAKE_CURRENT_LIST_DIR}/src/PaperUI.h
    ${CMAKE_CURRENT_LIST_DIR}/src/PaperUtils.h
)

include(FetchContent)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
set(PLATFORM	   "Desktop")
FetchContent_Declare(raylib GIT_REPOSITORY https://github.com/raysan5/raylib.git GIT_TAG 4.2.0)
FetchContent_MakeAvailable(raylib)

add_library(${PROJECT_NAME} STATIC ${paper_public_headers})
target_sources(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_INCLUDE})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include/)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER ${paper_public_headers})

target_include_directories(raylib
                           PUBLIC
                           $<INSTALL_INTERFACE:include>
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
                           PRIVATE
                           ${CMAKE_CURRENT_SOURCE_DIR}
                           )

file(COPY ${paper_public_headers} DESTINATION "include")