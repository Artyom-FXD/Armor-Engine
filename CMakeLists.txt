cmake_minimum_required(VERSION 3.20)

project(armor_engine)

target_include_directories(ArmorEngine PRIVATE libs)

add_custom_command(
  OUTPUT vert.spv frag.spv
  COMMAND ${Vulkan_GLSLC_EXECUTABLE} shader.vert -o vert.spv
  COMMAND ${Vulkan_GLSLC_EXECUTABLE} shader.frag -o frag.spv
  DEPENDS shader.vert shader.frag
)

set(EXE main.cpp)

add_executable(ArmorEngine main.cpp vert.spv frag.spv)