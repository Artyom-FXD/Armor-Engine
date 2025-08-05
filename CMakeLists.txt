cmake_minimum_required(VERSION 3.20)

project(armor_engine)

target_include_directories(ArmorEngine PRIVATE vulkan)

add_custom_command(
  OUTPUT shader.vert.spv
  COMMAND ${Vulkan_GLSLC_EXECUTABLE} shader.vert -o shader.vert.spv
  DEPENDS shader.vert
)

set(EXE main.cpp)

add_executable(Armor ${EXE})