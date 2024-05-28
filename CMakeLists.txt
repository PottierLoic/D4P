cmake_minimum_required(VERSION 3.21)
project(D4P)
set(CMAKE_CXX_STANDARD 17)

# Var
set(SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(LIBS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")
set(SFML_DIR "${LIBS_DIR}/SFML")
set(IMGUI_DIR "${LIBS_DIR}/imgui")
set(IMGUI_SFML_DIR "${LIBS_DIR}/imgui-sfml")
set(JSON "${LIBS_DIR}/json")
file(GLOB_RECURSE COMMON_SOURCES "${SOURCE_DIR}/*.cpp")
list(REMOVE_ITEM COMMON_SOURCES "${SOURCE_DIR}/main.cpp")
file(GLOB_RECURSE SFML_HEADERS "${SFML_DIR}/include/*.hpp")

# SFML Options
option(SFML_BUILD_AUDIO OFF)
option(SFML_BUILD_NETWORK OFF)
add_subdirectory(${SFML_DIR})

# IMGUI options
option(IMGUI_SFML_FIND_SFML OFF)
option(SFML_BUILD_IMGUI_DEMO ON)
add_subdirectory(${IMGUI_SFML_DIR})

if(FLAGS STREQUAL "--debug")
  add_compile_options(-Wall -Wextra)
else()
  add_compile_options(-Wall -Wextra -Werror)
endif()

add_executable(D4P ${SOURCE_DIR}/main.cpp)
target_sources(D4P PRIVATE ${COMMON_SOURCES})
target_link_libraries(D4P PRIVATE sfml-system sfml-window sfml-graphics ImGui-SFML::ImGui-SFML)
target_include_directories(D4P PRIVATE 
  ${LIBS_DIR}
  ${INCLUDE_DIR}
  ${SFML_DIR}/include
  ${IMGUI_DIR}/include
  ${IMGUI_SFML_DIR}
  ${JSON}/single_include
)

