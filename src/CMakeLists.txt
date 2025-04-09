cmake_minimum_required(VERSION 3.20)

ty_library_include_directories(${CMAKE_CURRENT_SOURCE_DIR})
ty_library_sources(
  ${CMAKE_CURRENT_SOURCE_DIR}/network_interface.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/connection.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/mqtt.cpp)
add_subdirectory(platform)
