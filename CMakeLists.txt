cmake_minimum_required(VERSION 3.21)
project(D4P)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(LIBS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")

file(GLOB_RECURSE COMMON_SOURCES "${SOURCE_DIR}/*.cpp")
list(REMOVE_ITEM COMMON_SOURCES "${SOURCE_DIR}/main.cpp")

if(FLAGS STREQUAL "--debug")
  add_compile_options(-Wall -Wextra)
else()
  add_compile_options(-Wall -Wextra -Werror)
endif()

add_executable(D4P ${SOURCE_DIR}/main.cpp)
target_sources(D4P PRIVATE ${COMMON_SOURCES})
# TODO: fill libs once selected
#target_link_libraries(D4P)
target_include_directories(D4P PRIVATE ${LIBS_DIR} ${INCLUDE_DIR})

