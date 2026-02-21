cmake_minimum_required(VERSION 3.16)

project(Polynoms)
set(INCLUDE "${CMAKE_SOURCE_DIR}/include")
set(SRC "${CMAKE_SOURCE_DIR}/src")

file(GLOB SRCS "${SRC}/*.cpp")

add_executable(${PROJECT_NAME} ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE})
target_compile_options(${PROJECT_NAME} PRIVATE -g)