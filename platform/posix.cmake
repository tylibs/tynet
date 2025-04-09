cmake_minimum_required(VERSION 3.20)
# include(build) include(kconfig) __build_init(${TYCOMMON_DIR}) __kconfig_init()
# Generate config values in different formats
#
# build_set_property(BUILD_DIR ${BUILD_DIR}) build_get_property(sdkconfig
# SDKCONFIG) build_get_property(sdkconfig_defaults SDKCONFIG_DEFAULTS)
# __kconfig_generate_config("${sdkconfig}" "${sdkconfig_defaults}")
# __ty_build_import_configs()

ty_library_named(tynet)
ty_library_link_libraries(tiny)
ty_library_include_directories_public(${PROJECT_DIR}/include)
ty_library_include_directories_public(${PROJECT_DIR}/lib/lwip/src/include)
ty_library_include_directories_public(
  ${PROJECT_DIR}/lib/lwip/contrib/ports/unix/posixlib
  ${PROJECT_DIR}/lib/lwip/contrib/ports/unix/port/include)

# include MQTT library
find_package(PahoMqttCpp REQUIRED)
ty_library_link_libraries(PahoMqttCpp::paho-mqttpp3)

add_subdirectory(${PROJECT_DIR}/src)
