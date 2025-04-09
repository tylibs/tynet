cmake_minimum_required(VERSION 3.20)

idf_component_register()

ty_library_named(tynet)
ty_library_include_directories_public(${PROJECT_DIR}/include)
ty_library_link_libraries(tiny)
ty_library_link_libraries(__idf_nvs_flash)
add_subdirectory(${PROJECT_DIR}/src)

target_link_libraries(${COMPONENT_LIB} INTERFACE tynet)
