cmake_minimum_required(VERSION 3.30.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
      set(CMAKE_INCLUDE_CURRENT_DIR ON)
  endif()

project(Serial_port_tools)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)

set(Qt5_DIR C:/Qt/Qt5.14.2/5.14.2/mingw73_32/lib/cmake/Qt5/)

find_package(Qt5 COMPONENTS Widgets SerialPort REQUIRED)

add_executable(${PROJECT_NAME}
WIN32
main.cpp
mainwindow.cpp
mainwindow.h
myserialport.cpp
myserialport.h
)

# 链接Qt库
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::SerialPort)