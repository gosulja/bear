cmake_minimum_required(VERSION 3.10)

project(bear VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

file(GLOB SOURCES "${SRC_DIR}/*.c")

add_executable(${PROJECT_NAME} ${SOURCES})

if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
endif()

