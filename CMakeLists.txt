cmake_minimum_required(VERSION 3.16)

project(Polynoms)
set(INCLUDE "${CMAKE_SOURCE_DIR}/include")
set(SRC "${CMAKE_SOURCE_DIR}/src")


find_library(ANTLR4_RUNTIME NAMES antlr4-runtime REQUIRED)
find_path(ANTLR4_INCLUDE_DIR antlr4-runtime.h PATH_SUFFIXES antlr4-runtime)

file(GLOB SRCS "${SRC}/*.cpp")

file(GLOB ANTLR_SRCS "${CMAKE_SOURCE_DIR}/generated_grammar/*.cpp")
add_library(ArithmeticGen ${ANTLR_SRCS})

target_include_directories(ArithmeticGen PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/generated_grammar/")
target_include_directories(ArithmeticGen PUBLIC ${ANTLR4_INCLUDE_DIR})
target_link_libraries(ArithmeticGen ${ANTLR4_RUNTIME})

add_executable(${PROJECT_NAME} ${SRCS})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE})
target_link_libraries(${PROJECT_NAME} ArithmeticGen)
target_compile_options(${PROJECT_NAME} PRIVATE -g)