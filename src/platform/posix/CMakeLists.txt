cmake_minimum_required(VERSION 3.20)

ty_library_sources(${CMAKE_CURRENT_SOURCE_DIR}/mqtt.posix.cpp)

ty_library_include_directories(${CMAKE_CURRENT_SOURCE_DIR})

if(CONFIG_TYNET_LOG_LEVEL)
  set(CONFIG_TYNET_LOG_LEVEL ${CONFIG_TYNET_LOG_LEVEL})
else()
  set(CONFIG_TYNET_LOG_LEVEL TY_LOG_LEVEL_CRIT)
endif()

target_compile_definitions(
  tynet
  PUBLIC -DTYNET_CONFIG_LOG_LEVEL=${CONFIG_TYNET_LOG_LEVEL}
         -DTYNET_CONFIG_FILE="${CMAKE_CURRENT_SOURCE_DIR}/tynet-posix-config.h")
