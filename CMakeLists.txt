cmake_minimum_required(VERSION 3.15)

set(QML_IMPORT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/src" CACHE STRING "Creator qml path")
add_subdirectory(src EXCLUDE_FROM_ALL)
add_subdirectory(exampleapp EXCLUDE_FROM_ALL)
