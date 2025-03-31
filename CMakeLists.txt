cmake_minimum_required(VERSION 3.10)

project(L LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

option(L_BUILD_TEST "Build L test application" OFF)
message(STATUS "Building L")
message(STATUS "L_BUILD_TEST: ${L_BUILD_TEST}")
message(STATUS "[${PROJECT_NAME}] SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
message(STATUS "[${PROJECT_NAME}] CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "[${PROJECT_NAME}] BINARY_DIR: ${CMAKE_BINARY_DIR}")

set(L_DIR core)
set(LLEXER_TARGET louise_lexer)
set(LPARSER_TARGET louise_parser)

add_executable(${PROJECT_NAME})

add_subdirectory(core)

# L compiler.
add_subdirectory(louise)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_SOURCE_DIR}
  ${CMAKE_BINARY_DIR}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
  louise::louise
)

if(L_BUILD_TEST)
  message(STATUS "Building test application")
  target_sources(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/test/L_test.c
  )
endif()
