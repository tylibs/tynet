cmake_minimum_required(VERSION 3.20)

ty_library_sources(${CMAKE_CURRENT_SOURCE_DIR}/mqtt.esp.cpp)

ty_library_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

ty_library_compile_definitions(
  -DTYNET_CONFIG_LOG_LEVEL=${CONFIG_TYNET_LOG_LEVEL}
  -DTYNET_CONFIG_FILE="tynet-esp-config.h")
