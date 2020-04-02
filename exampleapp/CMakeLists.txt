cmake_minimum_required(VERSION 3.15)

project(QmlCoolStuffExampleApp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(Qt5 COMPONENTS Core Quick REQUIRED)

add_executable(QmlCoolStuffExampleApp
  main.cpp
  qml.qrc
)


target_compile_definitions(QmlCoolStuffExampleApp
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(QmlCoolStuffExampleApp
  PRIVATE Qt5::Core Qt5::Quick)
